/*Open LEFA Project
2023 - Sub MIT*/

#include"Vector2.h"
#include"Generic.h"

vec2 
vec2_init(float x, float y)
{
    vec2 result = { x, y };
    return result;
}

int 
vec2_compare(vec2 self, 
                vec2 vector, 
                float threshold)
{
    vec2 tmp =
    {
        self.x - vector.x,
        self.y - vector.y
    };
    if (-threshold <= tmp.x && tmp.x < threshold &&
        -threshold <= tmp.y && tmp.y < threshold)
        return 1;
    return 0;
}

vec2 
vec2_invert(vec2 self)
{
    vec2 result = { -self.x, -self.y };
    return result;
}

float 
vec2_get_length(vec2 self)
{
    return sqrt(self.x * self.x + self.y * self.y);
}

vec2 
vec2_add(vec2 self, 
            vec2 vector)
{
    vec2 result;

    result.x = self.x + vector.x;
    result.y = self.y + vector.y;
    return result;
}

vec2 
vec2_subtract(vec2 self,
                 vec2 vector)
{
    vec2 result;

    result.x = self.x - vector.x;
    result.y = self.y - vector.y;
    return result;
}

vec2 
vec2_multiply(vec2 self, float scalar)
{
    vec2 result;

    result.x = self.x * scalar;
    result.y = self.y * scalar;
    return result;
}

vec2 
vec2_normalize(vec2 self)
{
    vec2 result;
    float len = vec2_get_length (self);

    if (len < G_EPSILON)
    {
        result.x = 0.0f;
        result.y = 0.0f;
    }
    else
    {
        result.x = self.x / len;
        result.y = self.y / len;
    }
    return result;
}

vec2 
vec2_validate(vec2 self)
{
    vec2 result =
    {
        number_validate (self.x),
        number_validate (self.y)
    };
    return result;
}

float 
vec2_dot (
    vec2 self,
    vec2 vector)
{
    return self.x * vector.x + self.y * vector.y;
}

vec2 
vec2_get_normal(vec2 self)
{
    vec2 result;

    result.x = self.y;
    result.y = -self.x;
    result = vec2_normalize (result);
    return result;
}

vec2 
vec2_lerp(vec2 self, vec2 vector,float weight)
{
    float a = weight;
    float b = 1.0f - weight;
    vec2 result;

    result.x = a * self.x + b * vector.x;
    result.y = a * self.y + b * vector.y;

    return result;
}
