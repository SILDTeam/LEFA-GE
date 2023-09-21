#ifndef VECTOR2_H
#define VECTOR2_H

#include<math.h>

typedef struct _vec2 vec2;
struct _vec2
{
    float x;
    float y;
};

vec2 vec2_init(float x, float y);

int vec2_compare(vec2 self, vec2 vector, float threshold);

vec2 vec2_invert(vec2 self);

float vec2_get_length(vec2 self);

vec2 vec2_add(vec2 self, vec2 vector);

vec2 vec2_subtract(vec2 self, vec2 vector);

vec2 vec2_multiply(vec2 self, float scalar);

vec2 vec2_normalize(vec2 self);

vec2 vec2_validate(vec2 self);

float vec2_dot(vec2 self, vec2 vector);

vec2 vec2_get_normal(vec2 self);

vec2 vec2_lerp(vec2 self, vec2 vector, float weight);

#endif //VECTOR2_H