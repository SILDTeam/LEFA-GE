#ifndef VECTOR3_H
#define VECTOR3_H

#define VECTOR_EPSILON 0.0001f

typedef struct _GVector3 GVector3;
struct _GVector3
{
    float x;
    float y;
    float z;
};

GVector3 vector3_init(float x, float y, float z);

int vector3_compare(GVector3 self, GVector3 vector, float threshold);

GVector3 vector3_invert(GVector3 self);

float vector3_get_length(GVector3 self);

GVector3 vector3_add(GVector3 self, GVector3 vector);

GVector3 vector3_subtract(GVector3 self, GVector3 vector);

GVector3 vector3_multiply(GVector3 self, float scalar);

GVector3 vector3_normalize(GVector3 self);

GVector3 vector3_validate(GVector3 self);

float vector3_dot(GVector3 self, GVector3 vector);

GVector3 vector3_cross(GVector3 self, GVector3 vector);

GVector3 vector3_lerp(GVector3 self, GVector3 vector, float weight);

#endif //VECTOR3_H

