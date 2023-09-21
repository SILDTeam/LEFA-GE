/*Open Lefa Project
2023*/
#include<math.h>
#include"Vector3.h";
#include"Quaternion.h";
#include"Generic.h";

vec3 
vec3_init(float x,
          float y,
          float z)
{
    vec3 result = { x, y, z };
    return result;
}

int 
vec3_compare(vec3 self,
             vec3 vector,
             float threshold)
{
    vec3 tmp =
    {
        self.x - vector.x,
        self.y - vector.y,
        self.z - vector.z
    };
    if (-threshold <= tmp.x && tmp.x < threshold &&
        -threshold <= tmp.y && tmp.y < threshold &&
        -threshold <= tmp.z && tmp.z < threshold)
        return 1;
    return 0;
}

vec3 
vec3_invert(vec3 self)
{
    vec3 result = { -self.x, -self.y, -self.z };
    return result;
}

float 
vec3_get_length(vec3 self)
{
    return sqrt (self.x * self.x +
                 self.y * self.y + 
                 self.z * self.z);
}

float 
vec3_max(vec3 self)
{
    float max = self.x;
    
    if(self.y > max)
    {
        max = self.y;
    }
    
    if(self.z > max)
    {
        max = self.z;
    }
    return max;
}


vec3 
vec3_add(vec3 self,
         vec3 vector)
{
    vec3 result;

    result.x = self.x + vector.x;
    result.y = self.y + vector.y;
    result.z = self.z + vector.z;
    return result;
}

vec3 
vec3_subtract(vec3 self,
              vec3 vector)
{
    vec3 result;

    result.x = self.x - vector.x;
    result.y = self.y - vector.y;
    result.z = self.z - vector.z;
    return result;
}

vec3 
vec3_multiply(vec3 self,
              float scalar)
{
    vec3 result;

    result.x = self.x * scalar;
    result.y = self.y * scalar;
    result.z = self.z * scalar;
    return result;
}

vec3 
vec3_normalize(vec3 self)
{
    vec3 result;
    float len = vec3_get_length (self);

    if (len < VECTOR_EPSILON)
    {
        result.x = 0.0f;
        result.y = 0.0f;
        result.z = 0.0f;
    }
    else
    {
        result.x = self.x / len;
        result.y = self.y / len;
        result.z = self.z / len;
    }
    return result;
}



vec3 
vec3_validate(vec3 self)
{
    vec3 result =
    {
        number_validate(self.x),
        number_validate(self.y),
        number_validate(self.z)
    };
    return result;
}

float 
vec3_dot(vec3 self,
         vec3 vector)
{
    return self.x * vector.x + self.y * vector.y + self.z * vector.z;
}

vec3 
vec3_cross(vec3 self,
           vec3 vector)
{
    vec3 result;

    result.x =  (self.y * vector.z - self.z * vector.y);
    result.y = -(self.x * vector.z - self.z * vector.x);
    result.z =  (self.x * vector.y - self.y * vector.x);
    return result;
}


vec3 
vec3_lerp(vec3 self,
          vec3 vector,
          float weight)
{
    float a = weight;
    float b = 1.0f - weight;

    vec3 result;

    result.x = a * self.x + b * vector.x;
    result.y = a * self.y + b * vector.y;
    result.z = a * self.z + b * vector.z;
    return result;
}

