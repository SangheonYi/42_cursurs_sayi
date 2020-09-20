#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <thread>

#include <iostream>
using namespace std;

// Image

const auto aspect_ratio = 4.0 / 3.0;
const int image_width = 200;
const int image_height = static_cast<int>(image_width / aspect_ratio);
const int samples_per_pixel = 50;
const int max_depth = 50;

color ray_color(const ray &r, const hittable &world, int depth)
{
	hit_record rec;

	// If we've exceeded the ray bounce limit, no more light is gathered.
	if (depth <= 0)
		return color(0, 0, 0);

	if (world.hit(r, 0.001, infinity, rec))
	{
		ray scattered;
		color attenuation;
		if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
			return attenuation * ray_color(scattered, world, depth - 1);
		return color(0, 0, 0);
	}

	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

hittable_list random_scene()
{
	hittable_list world;

	auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
	world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			auto choose_mat = random_double();
			point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

			if ((center - point3(4, 0.2, 0)).length() > 0.9)
			{
				shared_ptr<material> sphere_material;

				if (choose_mat < 0.8)
				{
					// diffuse
					auto albedo = color::random() * color::random();
					sphere_material = make_shared<lambertian>(albedo);
					world.add(make_shared<sphere>(center, 0.2, sphere_material));
				}
				else if (choose_mat < 0.95)
				{
					// metal
					auto albedo = color::random(0.5, 1);
					auto fuzz = random_double(0, 0.5);
					sphere_material = make_shared<metal>(albedo, fuzz);
					world.add(make_shared<sphere>(center, 0.2, sphere_material));
				}
				else
				{
					// glass
					sphere_material = make_shared<dielectric>(1.5);
					world.add(make_shared<sphere>(center, 0.2, sphere_material));
				}
			}
		}
	}

	auto material1 = make_shared<dielectric>(1.5);
	world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

	auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
	world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

	auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
	world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

	return world;
}

int calc_ray(hittable_list world, camera cam, int start, int end, string &buf) {
	for (int j = start; j >= end; --j)
	{
		std::cerr << "\rScanlines from " << start << " remaining: " << j - end << ' ' << std::flush;

		for (int i = 0; i < image_width; ++i)
		{
			color pixel_color(0, 0, 0);
			for (int s = 0; s < samples_per_pixel; ++s)
			{
				auto u = (i + random_double()) / (image_width - 1);
				auto v = (j + random_double()) / (image_height - 1);
				ray r = cam.get_ray(u, v);
				pixel_color += ray_color(r, world, max_depth);
			}
			write_color(buf, pixel_color, samples_per_pixel);
		}
	}
}

int main()
{
	time_t start, end;
	double result;
	int i, j;
	int sum = 0;

	start = time(NULL); // 시간 측정 시작

	// World
	auto world = random_scene();

	// Camera

	point3 lookfrom(13, 2, 3);
	point3 lookat(0, 0, 0);
	vec3 vup(0, 1, 0);
	auto dist_to_focus = 10.0;
	auto aperture = 0.1;

	camera cam(lookfrom, lookat, vup, 20, aspect_ratio, aperture, dist_to_focus);

	// Render
	string buffer = "";
/* 	string buf1 = "";
	string buf2 = "";
	string buf3 = ""; */

	// std::cout << "P3\n"
	// 		  << image_width << ' ' << image_height << "\n255\n";
	buffer += "P3\n" + to_string(image_width) + ' ' + to_string(image_height) + "\n255\n";

	std::cerr << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	//thread
	vector<thread> threads;
	vector<string> buffers(11);
	int thread_num = 10;

	for (size_t t = thread_num; t > 0; t--) {
		buffers[10 - t] = "";
		// printf("size: %d and %d th buffer: =%s= \n",buffers.size(), (int)(buffers.size() - 1), buffers[buffers.size() - 1]);
		threads.push_back(thread(calc_ray, world, cam,
		t * (image_height - 1) / thread_num, (t - 1) * (image_height - 1) / thread_num,
		 std::ref(buffers[10 - t])));
	}
/*
	std::thread thread1(calc_ray, world, cam, image_height - 1, 2 * (image_height - 1) / 3, std::ref(buf1));
	std::thread thread2(calc_ray, world, cam, 2 * (image_height - 1) / 3, (image_height - 1) / 3, std::ref(buf2));
	std::thread thread3(calc_ray, world, cam, (image_height - 1) / 3, 0, std::ref(buf3));
	thread1.join();
	thread2.join();
	thread3.join();
 */

	for (size_t t = 0; t < thread_num; t++)
		threads[t].join();
	for (size_t t = 0; t < thread_num; t++)
		buffer += buffers[t];

	std::cout << buffer;
	std::cerr << "\nDone.\n";

	end = time(NULL); // 시간 측정 끝
	result = (double)(end - start);
	std::cout << "\n" + to_string(image_width) + ' ' + to_string(image_height) + " " + to_string(result);
}
