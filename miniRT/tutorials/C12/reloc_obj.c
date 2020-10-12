#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"
#include <string.h>
#include <stdlib.h>

void reloc() {
	// for center move
	vec3 cc = center - ground.get()->center;
	vec3 unit_cc = unit_vector(cc);
	double hypo = cc.length() - (big_r - mini_r);
	double move_ver = hypo * unit_cc.y(); // len * cos
	double move_horiz = sqrt(hypo * sqrt(1 - unit_cc.y() * unit_cc.y())); // sqrt(len * sin)
	if (center.)
	{
		/* code */
	}

	center += vec3(move_horiz, move_ver, move_horiz);
}
