#ifndef QUATERNION_H
#define QUATERNION_H

#include<math.h>
#include"Vector3.h";

typedef struct _Quaternion Quaternion;
struct _Quaternion
{
    float x;
    float y;
    float z;
    float w;
};

Quaternion quaternion_init(float x,float y,float z,float w);

Quaternion quaternion_init_vectors(vec3 v1, vec3 v2);

Quaternion quaternion_identity();

Quaternion quaternion_euler(float phi,float theta,float psi);

Quaternion quaternion_look(vec3 dir, vec3 up);

Quaternion quaternion_lookat(vec3 position, vec3 center, vec3 up);

Quaternion quaternion_rotation(float angle, vec3 axis);

Quaternion quaternion_conjugate(Quaternion self);

Quaternion quaternion_add(Quaternion self, Quaternion quat);

Quaternion quaternion_subtract(Quaternion self, Quaternion quat);

Quaternion quaternion_multiply(Quaternion self, Quaternion quat);

float quaternion_dot(Quaternion self, Quaternion quat);

Quaternion quaternion_normalize(Quaternion self);

Quaternion quaternion_nlerp(Quaternion self, Quaternion quat, float weight);

vec3 quaternion_transform(Quaternion self, vec3 vector);

vec3 quaternion_get_basis(Quaternion self, int basis);

void quaternion_get_euler(Quaternion self, float* phi, float* theta, float* psi);

float quaternion_get_length(Quaternion self);

Quaternion quaternion_validate(Quaternion self);

Quaternion quaternion_get_nearest(const Quaternion self, const Quaternion quat);

float quaternion_get_rotation(const Quaternion self, vec3* axis);

#endif // QUATERNION_H