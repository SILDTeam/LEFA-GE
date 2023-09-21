#ifndef MATRIX44_H
#define MATRIX44_H

#include<math.h>
#include"Vector3.h";

//two-dimensional Struct 
typedef struct _GMatrix4 GMatrix4;
struct _GMatrix4
{
    float m[4][4];
};


GMatrix4 matrix4_identity();

GMatrix4 matrix4_frustum(float left, float right, float bottom, float top, float nearz, float farz);

GMatrix4 matrix4_look(float eyex, float eyey, float eyez, float dirx,  float diry,  float dirz, float upx,  float upy,  float upz);

GMatrix4 matrix4_lookat(float eyex, float eyey, float eyez, float centerx, float centery, float centerz, float upx, float upy, float upz);

GMatrix4 matrix4_Orthographic(float left, float right, float bottom, float top, float nearz, float farz);

GMatrix4 matrix4_perspective(float fov, float aspectRatio, float nearz, float farz);

GMatrix4 matrix4_rotation(float radians, float x,  float y,  float z);

GMatrix4 matrix4_scale(float x, float y, float z);

vec3 matrix4_transform(GMatrix4 self, vec3 vector);

GMatrix4 matrix4_translation(float x, float y, float z);

vec3 matrix4_get_basis(const GMatrix4 self, int basis);

GMatrix4 matrix4_get_rotation(const GMatrix4 self);

int matrix4_get_singular(const GMatrix4 self);

GMatrix4 matrix4_invert(const GMatrix4 self);

GMatrix4 matrix4_multiply(const GMatrix4 self, const GMatrix4 matrix);

GMatrix4 matrix4_pick(float x, float y, float w, float h, const int* viewport);

int matrix4_project(const GMatrix4  projection, const GMatrix4  modelview, const int* viewport, const vec3* object, vec3* window);

int matrix4_unproject(const GMatrix4  projection, const GMatrix4  modelview, const int* viewport, const vec3* window, vec3* object);

#endif // MATRIX44_H