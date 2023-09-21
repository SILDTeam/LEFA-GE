#include<math.h>;
#include"Quaternion.h";
#include"Vector3.h";
#include"Generic.h";

Quaternion 
quaternion_init(
    float x,
    float y,
    float z,
    float w)
{
    Quaternion self;

    self.x = x;
    self.y = y;
    self.z = z;
    self.w = w;

    return self;
}

Quaternion 
quaternion_init_vectors(vec3 v1,
                        vec3 v2)
{
    Quaternion self;
    vec3 c;

    c = vec3_cross (v1, v2);
    self.x = c.x;
    self.y = c.y;
    self.z = c.z;
    self.w = sqrt(vec3_dot (v1, v1) + vec3_dot (v2, v2)) + vec3_dot (v1, v2);

    return self;
}

/**
 * \brief Returns an identity quaternion.
 * \return Quaternion.
 */
Quaternion 
quaternion_identity ()
{
    Quaternion self;

    self.x = 0.0f;
    self.y = 0.0f;
    self.z = 0.0f;
    self.w = 1.0f;
    return self;
}

Quaternion 
quaternion_euler (
    float phi,
    float theta,
    float psi)
{
    float c1 = cos (0.5f * phi);
    float c2 = cos (0.5f * theta);
    float c3 = cos (0.5f * psi);
    float s1 = sin (0.5f * phi);
    float s2 = sin (0.5f * theta);
    float s3 = sin (0.5f * psi);
    Quaternion self;

    self.w = c1 * c2 * c3 - s1 * s2 * s3;
    self.x = s1 * s2 * c3 + c1 * c2 * s3;
    self.y = s1 * c2 * c3 + c1 * s2 * s3;
    self.z = c1 * s2 * s3 - s1 * c2 * s3;

    return self;
}


double my_copysign(double x, double y) {
    if (y < 0.0) {
        return (x < 0.0) ? x : -x;
    } else {
        return (x < 0.0) ? -x : x;
    }
}

Quaternion 
quaternion_look (
    vec3 dir,
    vec3 up)
{
    float len;
    Quaternion self;
    vec3 side;

    /* Normalize direction. */
    len = sqrt (dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    dir.x = dir.x / len;
    dir.y = dir.y / len;
    dir.z = dir.z / len;

    /* Calculate side. */
    side.x =  (dir.y * up.z - dir.z * up.y);
    side.y = -(dir.x * up.z - dir.z * up.x);
    side.z =  (dir.x * up.y - dir.y * up.x);
    len = sqrt (side.x * side.x + side.y * side.y + side.z * side.z);
    side.x = side.x / len;
    side.y = side.y / len;
    side.z = side.z / len;

    /* Calculate up. */
    up.x =  (side.y * dir.z - side.z * dir.y);
    up.y = -(side.x * dir.z - side.z * dir.x);
    up.z =  (side.x * dir.y - side.y * dir.x);
    len = sqrt (up.x * up.x + up.y * up.y + up.z * up.z);
    up.x = up.x / len;
    up.y = up.y / len;
    up.z = up.z / len;

    /* Convert to quaternion. */
    /* FIXME: Copied from math-convert. */
    /* FIXME: Surely there is a more direct way to do this. */
    self.x = 0.5f * sqrt (G_MAX (0.0f, 1.0f + side.x - up.y + dir.z));
    self.y = 0.5f * sqrt (G_MAX (0.0f, 1.0f - side.x + up.y + dir.z));
    self.z = 0.5f * sqrt (G_MAX (0.0f, 1.0f - side.x - up.y - dir.z));
    self.w = 0.5f * sqrt (G_MAX (0.0f, 1.0f + side.x + up.y - dir.z));
    self.x = my_copysign (self.x, -dir.y - up.z);
    self.y = my_copysign (self.y, side.z + dir.x);
    self.z = my_copysign (self.z, up.x - side.y);

    return self;
}

Quaternion 
quaternion_lookat(vec3 position,
                  vec3 center,
                  vec3 up)
{
    vec3 direction;

    direction = vec3_subtract (position, center);
    direction = vec3_normalize (direction);
    return quaternion_look (direction, up);
}

Quaternion 
quaternion_rotation(float   angle,
                    vec3 axis)
{
    Quaternion self;
    float w = cos (angle / 2);
    float q = sin (angle / 2);
    float len = sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);

    if (len >= G_EPSILON)
    {
        axis.x /= len;
        axis.y /= len;
        axis.z /= len;
    }
    self.x = q * axis.x;
    self.y = q * axis.y;
    self.z = q * axis.z;
    self.w = w;
    return self;
}

Quaternion
quaternion_conjugate(Quaternion self)
{
    Quaternion result;

    result.x = -self.x;
    result.y = -self.y;
    result.z = -self.z;
    result.w = self.w;
    return result;
}

Quaternion
quaternion_add(Quaternion self,
               Quaternion quat)
{
    Quaternion a = self;
    Quaternion b = quat;
    Quaternion result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

Quaternion
quaternion_subtract(Quaternion self,
                    Quaternion quat)
{
    Quaternion a = self;
    Quaternion b = quat;
    Quaternion result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}

Quaternion
quaternion_multiply(Quaternion self,
                    Quaternion quat)
{
    Quaternion a = self;
    Quaternion b = quat;
    Quaternion result;

    result.x = (a.w * b.x) + (a.x * b.w) + (a.y * b.z) - (a.z * b.y);
    result.y = (a.w * b.y) - (a.x * b.z) + (a.y * b.w) + (a.z * b.x);
    result.z = (a.w * b.z) + (a.x * b.y) - (a.y * b.x) + (a.z * b.w);
    result.w = (a.w * b.w) - (a.x * b.x) - (a.y * b.y) - (a.z * b.z);
    return result;
}

float
quaternion_dot(Quaternion self,
               Quaternion quat)
{
    return self.w * quat.w + self.x * quat.x + self.y * quat.y + self.z * quat.z;
}

Quaternion
quaternion_normalize(Quaternion self)
{
    Quaternion result;
    float len = sqrt (self.w * self.w +
                      self.x * self.x +
                      self.y * self.y +
                      self.z * self.z);

    if (len < G_EPSILON)
    {
        result.x = 0.0f;
        result.y = 0.0f;
        result.z = 0.0f;
        result.w = 1.0f;
    }
    else
    {
        result.x = self.x / len;
        result.y = self.y / len;
        result.z = self.z / len;
        result.w = self.w / len;
    }
    return result;
}

Quaternion
quaternion_nlerp(Quaternion self,
                 Quaternion quat,
                 float     weight)
{
    float a = weight;
    float b = 1.0f - weight;
    Quaternion result;

    result.w = a * self.w + b * quat.w;
    result.x = a * self.x + b * quat.x;
    result.y = a * self.y + b * quat.y;
    result.z = a * self.z + b * quat.z;

    return quaternion_normalize (result);
}

vec3
quaternion_transform(Quaternion self,
                     vec3  vector)
{
    vec3 result;
    Quaternion q1 = self;
    Quaternion q2 = self;
    Quaternion q3 = { vector.x, vector.y, vector.z, 0.0f };

    q2 = quaternion_conjugate (q2);
    q3 = quaternion_multiply (q1, q3);
    q3 = quaternion_multiply (q3, q2);
    result.x = q3.x;
    result.y = q3.y;
    result.z = q3.z;
    return result;
}

vec3
quaternion_get_basis(Quaternion self, int basis)
{
    vec3 result;

    switch (basis)
    {
        case 0:
            result.x = 1.0f - 2.0f * (self.y * self.y + self.z * self.z);
            result.y = 2.0f * (self.x * self.y - self.z * self.w);
            result.z = 2.0f * (self.x * self.z + self.y * self.w);
            break;
        case 1:
            result.x = 2.0f * (self.x * self.y + self.z * self.w);
            result.y = 1.0f - 2.0f * (self.x * self.x + self.z * self.z);
            result.z = 2.0f * (self.y * self.z - self.x * self.w);
            break;
        case 2:
            result.x = 2.0f * (self.x * self.z - self.y * self.w);
            result.y = 2.0f * (self.y * self.z + self.x * self.w);
            result.z = 1.0f - 2.0f * (self.x * self.x + self.y * self.y);
            break;
        default:
            result.x = 0.0f;
            result.y = 0.0f;
            result.z = 0.0f;
            break;
    }

    return result;
}

void
quaternion_get_euler(Quaternion self,
                     float* phi,
                     float* theta,
                     float* psi)
{
    float tmp;
    float xx = self.x * self.x;
    float yy = self.y * self.y;
    float zz = self.z * self.z;

    tmp = self.x * self.y + self.z * self.w;
    if (tmp >= 0.5f - G_EPSILON)
    {
        *phi = 2 * atan2 (self.x, self.w);
        *theta = 0.5f * M_PI;
        *psi = 0.0f;
    }
    else if (tmp <= -0.5f + G_EPSILON)
    {
        *phi = -2 * atan2 (self.x, self.w);
        *theta = -0.5f * M_PI;
        *psi = 0.0f;
    }
    else
    {
        *phi = atan2 (2 * (self.y * self.w - self.x * self.z), 1 - 2 * (yy + zz));
        *theta = asin (2 * tmp);
        *psi = atan2 (2 * (self.x * self.w - self.y * self.z), 1 - 2 * (xx + zz));
    }
}

float
quaternion_get_length(Quaternion self)
{
    return sqrt (self.w * self.w +
                 self.x * self.x +
                 self.y * self.y +
                 self.z * self.z);
}

Quaternion
quaternion_validate(Quaternion self)
{
    Quaternion result =
    {
        number_validate (self.x),
        number_validate (self.y),
        number_validate (self.z),
        number_validate (self.w)
    };
    if (quaternion_get_length (result) <= G_EPSILON)
        result.w = 1.0f;
    return result;
}

Quaternion
quaternion_get_nearest(const Quaternion self,
                       const Quaternion quat)
{
    Quaternion result = self;

    if (self.w * quat.w + self.x * quat.x + self.y * quat.y + self.z * quat.z < 0.0f)
    {
        result.w *= -1.0f;
        result.x *= -1.0f;
        result.y *= -1.0f;
        result.z *= -1.0f;
    }

    return result;
}

float
quaternion_get_rotation(const Quaternion self, vec3* axis)
{
    if (axis != 0) //0 = NULL
        *axis = vec3_normalize(vec3_init(self.x, self.y, self.z));

    return 2.0f * acos (self.w);
}
