#ifndef TRANSFORM_H
#define TRANSFORM_H

#include"Matrix44.h"
#include"Quaternion.h"
#include"Vector3.h"

typedef struct _GTransform GTransform;
struct _GTransform
{
	GVector3 position;
	Quaternion rotation;
};

GTransform transform_init(GVector3 position, Quaternion rotation);

GTransform transform_identity();

GTransform transform_look(GVector3 position, GVector3 direction, GVector3 up);

GTransform transform_lookat(GVector3 position, GVector3 center, GVector3 up);

GTransform transform_invert(GTransform self);

GTransform transform_conjugate(GTransform self);

GTransform transform_multiply(GTransform self, GTransform transform);

GTransform transform_relative(GTransform self, GTransform transform);

GVector3 transform_transform(GTransform self, GVector3  vector);

GTransform transform_snap(GTransform self, GTransform child);

GMatrix4 transform_get_modelview(GTransform self);

#endif //TRANSFORM_H
