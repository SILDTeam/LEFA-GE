/*Open LEFA Project
2023 - Sub MIT*/

#include"Vector2.h"
#include"Generic.h"

GVector2 
vector2_init(float x, float y)
{
    GVector2 result = { x, y };
    return result;
}

int 
vector2_compare(GVector2 self, 
                GVector2 vector, 
                float threshold)
{
    GVector2 tmp =
    {
        self.x - vector.x,
        self.y - vector.y
    };
    if (-threshold <= tmp.x && tmp.x < threshold &&
        -threshold <= tmp.y && tmp.y < threshold)
        return 1;
    return 0;
}

GVector2 
vector2_invert(GVector2 self)
{
    GVector2 result = { -self.x, -self.y };
    return result;
}

float 
vector2_get_length(GVector2 self)
{
    return sqrt(self.x * self.x + self.y * self.y);
}

GVector2 
vector2_add(GVector2 self, 
            GVector2 vector)
{
    GVector2 result;

    result.x = self.x + vector.x;
    result.y = self.y + vector.y;
    return result;
}

GVector2 
vector2_subtract(GVector2 self,
                 GVector2 vector)
{
    GVector2 result;

    result.x = self.x - vector.x;
    result.y = self.y - vector.y;
    return result;
}

GVector2 
vector2_multiply(GVector2 self, float scalar)
{
    GVector2 result;

    result.x = self.x * scalar;
    result.y = self.y * scalar;
    return result;
}

GVector2 
vector2_normalize(GVector2 self)
{
    GVector2 result;
    float len = vector2_get_length (self);

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

GVector2 
vector2_validate (
    GVector2 self)
{
    GVector2 result =
    {
        number_validate (self.x),
        number_validate (self.y)
    };
    return result;
}

float 
vector2_dot (
    GVector2 self,
    GVector2 vector)
{
    return self.x * vector.x + self.y * vector.y;
}

/**
 * \brief Gets the normal of the vector.
 * \param self Vector.
 * \return Vector.
 */
GVector2 
vector2_get_normal(GVector2 self)
{
    GVector2 result;

    result.x = self.y;
    result.y = -self.x;
    result = vector2_normalize (result);
    return result;
}

GVector2 
vector2_lerp(GVector2 self, GVector2 vector,float weight)
{
    float a = weight;
    float b = 1.0f - weight;
    GVector2 result;

    result.x = a * self.x + b * vector.x;
    result.y = a * self.y + b * vector.y;

    return result;
}
