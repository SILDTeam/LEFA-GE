/*Open Lefa Project
2023*/
#include<math.h>
#include"Vector3.h";
#include"Quaternion.h";
#include"Generic.h";

GVector3 
vector3_init(float x,
             float y,
             float z)
{
    GVector3 result = { x, y, z };
    return result;
}

int 
vector3_compare(GVector3 self,
               GVector3 vector,
               float threshold)
{
    GVector3 tmp =
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

GVector3 
vector3_invert(GVector3 self)
{
    GVector3 result = { -self.x, -self.y, -self.z };
    return result;
}

float 
vector3_get_length(GVector3 self)
{
    return sqrt (self.x * self.x + self.y * self.y + self.z * self.z);
}

float 
vector3_max(GVector3 self)
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


GVector3 
vector3_add(GVector3 self,
            GVector3 vector)
{
    GVector3 result;

    result.x = self.x + vector.x;
    result.y = self.y + vector.y;
    result.z = self.z + vector.z;
    return result;
}

GVector3 
vector3_subtract(GVector3 self,
                 GVector3 vector)
{
    GVector3 result;

    result.x = self.x - vector.x;
    result.y = self.y - vector.y;
    result.z = self.z - vector.z;
    return result;
}

GVector3 
vector3_multiply(GVector3 self,
                 float scalar)
{
    GVector3 result;

    result.x = self.x * scalar;
    result.y = self.y * scalar;
    result.z = self.z * scalar;
    return result;
}

GVector3 
vector3_normalize(GVector3 self)
{
    GVector3 result;
    float len = vector3_get_length (self);

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



GVector3 
vector3_validate(GVector3 self)
{
    GVector3 result =
    {
        number_validate(self.x),
        number_validate(self.y),
        number_validate(self.z)
    };
    return result;
}

float 
vector3_dot(GVector3 self,
            GVector3 vector)
{
    return self.x * vector.x + self.y * vector.y + self.z * vector.z;
}

GVector3 
vector3_cross(GVector3 self,
              GVector3 vector)
{
    GVector3 result;

    result.x =  (self.y * vector.z - self.z * vector.y);
    result.y = -(self.x * vector.z - self.z * vector.x);
    result.z =  (self.x * vector.y - self.y * vector.x);
    return result;
}


GVector3 
vector3_lerp(GVector3 self,
             GVector3 vector,
             float weight)
{
    float a = weight;
    float b = 1.0f - weight;

    GVector3 result;

    result.x = a * self.x + b * vector.x;
    result.y = a * self.y + b * vector.y;
    result.z = a * self.z + b * vector.z;

    return result;
}

