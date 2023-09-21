#ifndef VECTOR3_H
#define VECTOR3_H

#include"Generic.h";

typedef struct _vec3 vec3;
struct _vec3
{
    float x;
    float y;
    float z;
};

vec3 vec3_init(float x, float y, float z);

int vec3_compare(vec3 self, vec3 vector, float threshold);

vec3 vec3_invert(vec3 self);

float vec3_get_length(vec3 self);

vec3 vec3_add(vec3 self, vec3 vector);

vec3 vec3_subtract(vec3 self, vec3 vector);

vec3 vec3_multiply(vec3 self, float scalar);

vec3 vec3_normalize(vec3 self);

vec3 vec3_validate(vec3 self);

float vec3_dot(vec3 self, vec3 vector);

vec3 vec3_cross(vec3 self, vec3 vector);

vec3 vec3_lerp(vec3 self, vec3 vector, float weight);

#endif //VECTOR3_H

