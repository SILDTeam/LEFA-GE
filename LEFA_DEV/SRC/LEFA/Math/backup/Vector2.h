#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

typedef struct _GVector2 GVector2;
struct _GVector2
{
    float x;
    float y;
};

GVector2 vector2_init(float x, float y);

int vector2_compare(GVector2 self, GVector2 vector, float threshold);

GVector2 vector2_invert(GVector2 self);

float vector2_get_length(GVector2 self);

GVector2 vector2_add(GVector2 self, GVector2 vector);

GVector2 vector2_subtract(GVector2 self, GVector2 vector);

GVector2 vector2_multiply(GVector2 self, float scalar);

GVector2 vector2_normalize(GVector2 self);

GVector2 vector2_validate(GVector2 self);

float vector2_dot(GVector2 self, GVector2 vector);

GVector2 vector2_get_normal(GVector2 self);

GVector2 vector2_lerp(GVector2 self, GVector2 vector, float weight);

#endif //VECTOR2_H