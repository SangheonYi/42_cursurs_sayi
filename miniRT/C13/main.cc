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
const auto aspect_ratio = 3.0 / 2.0;
const int image_width = 400;
const int image_height = static_cast<int>(image_width / aspect_ratio);
const int samples_per_pixel = 50;
const int max_depth = 50;
auto dist_to_focus = 1.0;
auto aperture = 0.001;
const double big_r = 1.0;
const double mini_r = 0.2;
const double ground_r = 200;

color ray_color(const ray &r, const hittable &world, int depth)
{
	hit_record rec;

	// If we've exceeded the ray bounce limit, no more light is gathered.
	if (depth <= 0) return color(0, 0, 0);

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
	auto ground = make_shared<sphere>(point3(0, -ground_r, 0), ground_r, ground_material);
	world.add(ground);
	for (int a = -5; a < 11; a++)
	{
		for (int b = -5; b < 11; b++)
		{
			point3 center(a + 0.9 * random_double(), mini_r, b + 0.9 * random_double());

			if (-1 <= b && b <= 1) {
				if (-5 <= a && a <= -3 && (center - point3(-4, 1, 0)).length() < mini_r + big_r) continue;
				else if (-1 <= a && a <= 1 && (center - point3(0, 1, 0)).length() < mini_r + big_r) continue;
				else if (3 <= a && a <= 5 && (center - point3(4, 1, 0)).length() < mini_r + big_r) continue;
			}

			// material
			auto choose_mat = random_double();
			shared_ptr<material> sphere_material;

			if (choose_mat < 0.8)
			{
				// diffuse
				auto albedo = color::random() * color::random();
				sphere_material = make_shared<lambertian>(albedo);
				world.add(make_shared<sphere>(center, mini_r, sphere_material));
			}
			else if (choose_mat < 0.95)
			{
				// metal
				auto albedo = color::random(0.5, 1);
				auto fuzz = random_double(0, 0.5);
				sphere_material = make_shared<metal>(albedo, fuzz);
				world.add(make_shared<sphere>(center, mini_r, sphere_material));
			}
			else
			{
				// glass
				sphere_material = make_shared<dielectric>(1.5);
				world.add(make_shared<sphere>(center, mini_r, sphere_material));
			}
		}
	}
	auto material1 = make_shared<dielectric>(1.5);
	world.add(make_shared<sphere>(point3(0, 1, 0), big_r, material1));

	auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
	world.add(make_shared<sphere>(point3(-4, 1, 0), big_r, material2));

	auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
	world.add(make_shared<sphere>(point3(4, 1, 0), big_r, material3));

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
				// ray r = cam.get_ray(u, v);
				ray r = cam.get_ray(u, v, dist_to_focus);
				pixel_color += ray_color(r, world, max_depth);
			}
			write_color(buf, pixel_color, samples_per_pixel);
		}
	}
}

int main()
{
/*
	time_t start, end;
	double result;
	int i, j;
	int sum = 0;

	start = time(NULL); // 시간 측정 시작
*/
	// World
	auto world = random_scene();

	// Camera
	point3 lookfrom(13, 1.7, 3);
	point3 lookat(0, 0, 0);
	vec3 vup(0, 1, 0);
	dist_to_focus = 13.5;

	camera cam(lookfrom, lookat, vup, 20, aspect_ratio, aperture, dist_to_focus);

	// Render
	string buffer = "P3\n" + to_string(image_width) + ' ' + to_string(image_height) + "\n255\n";
	std::cerr << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	//thread
	int thread_num = 100;
	vector<thread> threads;
	vector<string> buffers(thread_num + 1);

	for (size_t t = thread_num; t > 1; t--) {
		buffers[thread_num - t] = "";
		threads.push_back(thread(calc_ray, world, cam,
		t * (image_height - 1) / thread_num, (t - 1) * (image_height - 1) / thread_num + 1,
		std::ref(buffers[thread_num - t])));
	}
	threads.push_back(thread(calc_ray, world, cam,
		(image_height - 1) / thread_num, 0, std::ref(buffers[thread_num - 1])));
	for (size_t t = 0; t < thread_num; t++) threads[t].join();
	for (size_t t = 0; t < thread_num; t++) buffer += buffers[t];

	std::cout << buffer;
	std::cerr << "\nDone.\n";

/*	end = time(NULL); // 시간 측정 끝
	result = (double)(end - start);
	std::cout << "\n" + to_string(image_width) + ' ' + to_string(image_height) + " " + to_string(result);
*/
}
