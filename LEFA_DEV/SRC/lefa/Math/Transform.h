#ifndef TRANSFORM_H
#define TRANSFORM_H

#include"Matrix44.h"
#include"Quaternion.h"
#include"Vector3.h"

typedef struct _GTransform GTransform;
struct _GTransform
{
	vec3 position;
	Quaternion rotation;
};

GTransform transform_init(vec3 position, Quaternion rotation);

GTransform transform_identity();

GTransform transform_look(vec3 position, vec3 direction, vec3 up);

GTransform transform_lookat(vec3 position, vec3 center, vec3 up);

GTransform transform_invert(GTransform self);

GTransform transform_conjugate(GTransform self);

GTransform transform_multiply(GTransform self, GTransform transform);

GTransform transform_relative(GTransform self, GTransform transform);

vec3 transform_transform(GTransform self, vec3  vector);

GTransform transform_snap(GTransform self, GTransform child);

GMatrix4 transform_get_modelview(GTransform self);

#endif //TRANSFORM_H
