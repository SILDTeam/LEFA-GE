/*Open LEFA Project
2023*/

//Math LIB - MATRIX.C
//two-dimensional Struct 

#include<math.h>

#include"Matrix44.h";

#include"Vector3.h";
#include"Generic.h";

GMatrix4 
matrix4_identity()
{
    GMatrix4 mat;

    mat.m[0][0] = 1.0f; mat.m[0][1] = 0.0f; mat.m[0][2] = 0.0f; mat.m[0][3] = 0.0f;
    mat.m[1][0] = 0.0f; mat.m[1][1] = 1.0f; mat.m[1][2] = 0.0f; mat.m[1][3] = 0.0f;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = 1.0f; mat.m[2][3] = 0.0f;
    mat.m[3][0] = 0.0f; mat.m[3][1] = 0.0f; mat.m[3][2] = 0.0f; mat.m[3][3] = 1.0f;
    return mat;
}


GMatrix4
matrix4_frustum(float left,
               float right,
               float bottom,
               float top,
               float nearz, //near is a reserved word, so z at the end
               float farz)  //far is a reserved word, so z at the end
{
    GMatrix4 mat;

    float width = right - left;
    float height = top - bottom;
    float depth = farz - nearz;

    mat.m[0][0] = 2.0f / width; mat.m[0][1] = 0.0f;          mat.m[0][2] = 0.0f;          mat.m[0][3] = -(right + left) / width;
    mat.m[1][0] = 0.0f;         mat.m[1][1] = 2.0f / height; mat.m[1][2] = 0.0f;          mat.m[1][3] = -(top + bottom) / height;
    mat.m[2][0] = 0.0f;         mat.m[2][1] = 0.0f;          mat.m[2][2] = -2.0f / depth; mat.m[2][3] = -(farz + nearz) / depth;
    mat.m[3][0] = 0.0f;         mat.m[3][1] = 0.0f;          mat.m[3][2] = 0.0f;          mat.m[3][3] = 1.0f;
    return mat;
}

GMatrix4
matrix4_look(float eyex, 
            float eyey, 
            float eyez,
            float dirx, 
            float diry, 
            float dirz,
            float upx, 
            float upy, 
            float upz)
{
    float len;
    float sidex;
    float sidey;
    float sidez;

    GMatrix4 mat;

    /* Normalize direction. */
    len = sqrt (dirx * dirx + diry * diry + dirz * dirz);
    dirx = dirx / len;
    diry = diry / len;
    dirz = dirz / len;

    /* Calculate side. */
    sidex =  (diry * upz - dirz * upy);
    sidey = -(dirx * upz - dirz * upx);
    sidez =  (dirx * upy - diry * upx);
    len = sqrt (sidex * sidex + sidey * sidey + sidez * sidez);
    sidex = sidex / len;
    sidey = sidey / len;
    sidez = sidez / len;

    /* Calculate up. */
    upx =  (sidey * dirz - sidez * diry);
    upy = -(sidex * dirz - sidez * dirx);
    upz =  (sidex * diry - sidey * dirx);
    len = sqrt (upx * upx + upy * upy + upz * upz);
    upx = upx / len;
    upy = upy / len;
    upz = upz / len;

    /* Fill matrix. */
    mat.m[0][0] = sidex;
    mat.m[0][1] = upx;
    mat.m[0][2] = -dirx;
    mat.m[0][3] = 0.0f;
    mat.m[1][0] = sidey;
    mat.m[1][1] = upy;
    mat.m[1][2] = -diry;
    mat.m[1][3] = 0.0f;
    mat.m[2][0] = sidez;
    mat.m[2][1] = upz;
    mat.m[2][2] = -dirz;
    mat.m[2][3] = 0.0f;
    mat.m[3][0] = -sidex * eyex - sidey * eyey - sidez * eyez;
    mat.m[3][1] = -upx * eyex - upy * eyey - upz * eyez;
    mat.m[3][2] = dirx * eyex + diry * eyey + dirz * eyez;
    mat.m[3][3] = 1.0f;
    return mat;
}

GMatrix4
matrix4_lookat (float eyex,
               float eyey,
               float eyez,
               float centerx,
               float centery,
               float centerz,
               float upx,
               float upy,
               float upz)
{
    float dirx = centerx - eyex;
    float diry = centery - eyey;
    float dirz = centerz - eyez;

    return matrix4_look (
        eyex, eyey, eyez,
        dirx, diry, dirz,
        upx, upy, upz);
}

GMatrix4
matrix4_Orthographic(float left,
                     float right,
                     float bottom,
                     float top,
                     float nearz,
                     float farz)
{
    GMatrix4 mat;

    float width = right - left;
    float height = top - bottom;
    float depth = farz - nearz;

    mat.m[0][0] = 2.0f / width; mat.m[0][1] = 0.0f;          mat.m[0][2] = 0.0f;          mat.m[0][3] = -(right + left) / width;
    mat.m[1][0] = 0.0f;         mat.m[1][1] = 2.0f / height; mat.m[1][2] = 0.0f;          mat.m[1][3] = -(top + bottom) / height;
    mat.m[2][0] = 0.0f;         mat.m[2][1] = 0.0f;          mat.m[2][2] = -2.0f / depth; mat.m[2][3] = -(farz + nearz) / depth;
    mat.m[3][0] = 0.0f;         mat.m[3][1] = 0.0f;          mat.m[3][2] = 0.0f;          mat.m[3][3] = 1.0f;
    return mat;
}

GMatrix4
matrix4_perspective (float fov,
                    float aspectRatio,
                    float nearz,
                    float farz)
{
    GMatrix4 mat;

    float tanHalfFOV = tan(fov / 2.0f);
    float rangez = nearz - farz;
    
    mat.m[0][0] = 1.0f / (tanHalfFOV * aspectRatio); mat.m[0][1] = 0.0f;              mat.m[0][2] = 0.0f;           mat.m[0][3] = 0.0f;
    mat.m[1][0] = 0.0f;                              mat.m[1][1] = 1.0f / tanHalfFOV; mat.m[1][2] = 0.0f;           mat.m[1][3] = 0.0f;
    mat.m[2][0] = 0.0f;                              mat.m[2][1] = 0.0f;              mat.m[2][2] = -farz / rangez; mat.m[2][3] = (2.0f * farz * nearz) / rangez;
    mat.m[3][0] = 0.0f;                              mat.m[3][1] = 0.0f;              mat.m[3][2] = 1.0f;           mat.m[3][3] = 0.0f;
    return mat;
}

GMatrix4
matrix4_rotation(float radians,
                float x, 
                float y, 
                float z)
{
    GMatrix4 mat;
    float s0 = sin(-radians);
    float c0 = cos(-radians);
    float c1 = 1 - c0;

    mat.m[0][0] = x * x * c1 + c0;
    mat.m[0][1] = x * y * c1 - z * s0;
    mat.m[0][2] = x * z * c1 + y * s0;
    mat.m[0][3] = 0.0f;
    mat.m[1][0] = x * y * c1 + z * s0;
    mat.m[1][1] = y * y * c1 + c0;
    mat.m[1][2] = y * z * c1 - x * s0;
    mat.m[1][3] = 0.0f;
    mat.m[2][0] = x * z * c1 - y * s0;
    mat.m[2][1] = y * z * c1 + x * s0;
    mat.m[2][2] = z * z * c1 + c0;
    mat.m[2][3] = 0.0f;
    mat.m[3][0] = 0.0f;
    mat.m[3][1] = 0.0f;
    mat.m[3][2] = 0.0f;
    mat.m[3][3] = 1.0f;
    return mat;
}


GMatrix4
matrix4_scale(float x,
             float y,
             float z)
{
    GMatrix4 mat;
    mat.m[0][0] = x;    mat.m[0][1] = 0.0f; mat.m[0][2] = 0.0f; mat.m[0][3] = 0.0f;
    mat.m[1][0] = 0.0f; mat.m[1][1] = y;    mat.m[1][2] = 0.0f; mat.m[1][3] = 0.0f;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = z;    mat.m[2][3] = 0.0f;
    mat.m[3][0] = 0.0f; mat.m[3][1] = 0.0f; mat.m[3][2] = 0.0f; mat.m[3][3] = 1.0f;
    return mat;
}

GVector3
matrix4_transform(GMatrix4 self,
                  GVector3 vector)
{
    GVector3 result;

    result.x = self.m[0][0] * vector.x + self.m[1][0] * vector.y + self.m[2][0] * vector.z + self.m[3][0];
    result.y = self.m[0][1] * vector.x + self.m[1][1] * vector.y + self.m[2][1] * vector.z + self.m[3][1];
    result.z = self.m[0][2] * vector.x + self.m[1][2] * vector.y + self.m[2][2] * vector.z + self.m[3][2];
    return result;
}

GMatrix4
matrix4_translation(float x,
                         float y,
                         float z)
{
    GMatrix4 self;

    self.m[0][0] = 1.0f;   self.m[1][0] = 0.0f;   self.m[2][0] = 0.0f;   self.m[3][0] = x;
    self.m[0][1] = 0.0f;   self.m[1][1] = 1.0f;   self.m[2][1] = 0.0f;   self.m[3][1] = y;
    self.m[0][2] = 0.0f;   self.m[1][2] = 0.0f;   self.m[2][2] = 1.0f;   self.m[3][2] = z;
    self.m[0][3] = 0.0f;   self.m[1][3] = 0.0f;   self.m[2][3] = 0.0f;   self.m[3][3] = 1.0f;
    return self;
}


GVector3
matrix4_get_basis (const GMatrix4 self, int basis)
{
    switch (basis)
    {
        case 0: return vector3_init(self.m[0][0], self.m[1][0], self.m[2][0]);
        case 1: return vector3_init(self.m[0][1], self.m[1][1], self.m[2][1]);
        case 2: return vector3_init(self.m[0][2], self.m[1][2], self.m[2][2]);
    }
    return vector3_init (0.0f, 0.0f, 0.0f);
}


GMatrix4
matrix4_get_rotation(const GMatrix4 self)
{
    GMatrix4 result;

    result.m[0][0] = self.m[0][0];
    result.m[0][1] = self.m[0][1];
    result.m[0][2] = self.m[0][2];
    result.m[0][3] = 0.0f;
    result.m[1][0] = self.m[1][0];
    result.m[1][1] = self.m[1][1];
    result.m[1][2] = self.m[1][2];
    result.m[1][3] = 0.0f;
    result.m[2][0] = self.m[2][0];
    result.m[2][1] = self.m[2][1];
    result.m[2][2] = self.m[2][2];
    result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f;
    result.m[3][1] = 0.0f;
    result.m[3][2] = 0.0f;
    result.m[3][3] = 1.0f;

    return result;
}

int 
matrix4_get_singular(const GMatrix4 self)
{
    float det;

    det = self.m[0][0] * (self.m[1][1] * self.m[2][2] - self.m[2][1] * self.m[1][2])
        - self.m[0][1] * (self.m[1][0] * self.m[2][2] - self.m[2][0] * self.m[1][2])
        + self.m[0][2] * (self.m[1][0] * self.m[2][1] - self.m[2][0] * self.m[1][1]);
    if (- VECTOR_EPSILON <= det && det <= VECTOR_EPSILON)
        return 1;
    return 0;
}

GMatrix4
matrix4_invert(const GMatrix4 self)
{
    int i, j;
    float det;
    float inv[4][4];
    //const float* m = self.m;
    //const float (*m)[4] = self.m;
    GMatrix4 ret;

/*
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            m[i][j] = self.m[i * 4 + j];
        }
    }*/

float m[4][4];
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        m[i][j] = self.m[i][j];
    }
}

    inv[0][0] =  m[1][1]*m[2][2]*m[3][3] - m[1][1]*m[2][3]*m[3][2] - m[1][2]*m[2][1]*m[3][3] +
                 m[1][2]*m[2][3]*m[3][1] + m[1][3]*m[2][1]*m[3][2] - m[1][3]*m[2][2]*m[3][1];
    inv[0][1] = -m[0][1]*m[2][2]*m[3][3] + m[0][1]*m[2][3]*m[3][2] + m[0][2]*m[2][1]*m[3][3] -
                 m[0][2]*m[2][3]*m[3][1] - m[0][3]*m[2][1]*m[3][2] + m[0][3]*m[2][2]*m[3][1];
    inv[0][2] =  m[0][1]*m[1][2]*m[3][3] - m[0][1]*m[1][3]*m[3][2] - m[0][2]*m[1][1]*m[3][3] +
                 m[0][2]*m[1][3]*m[3][1] + m[0][3]*m[1][1]*m[3][2] - m[0][3]*m[1][2]*m[3][1];
    inv[0][3] = -m[0][1]*m[1][2]*m[2][3] + m[0][1]*m[1][3]*m[2][2] + m[0][2]*m[1][1]*m[2][3] -
                 m[0][2]*m[1][3]*m[2][1] - m[0][3]*m[1][1]*m[2][2] + m[0][3]*m[1][2]*m[2][1];

    inv[1][0] = -m[1][0]*m[2][2]*m[3][3] + m[1][0]*m[2][3]*m[3][2] + m[1][2]*m[2][0]*m[3][3] -
                 m[1][2]*m[2][3]*m[3][0] - m[1][3]*m[2][0]*m[3][2] + m[1][3]*m[2][2]*m[3][0];
    inv[1][1] =  m[0][0]*m[2][2]*m[3][3] - m[0][0]*m[2][3]*m[3][2] - m[0][2]*m[2][0]*m[3][3] +
                 m[0][2]*m[2][3]*m[3][0] + m[0][3]*m[2][0]*m[3][2] - m[0][3]*m[2][2]*m[3][0];
    inv[1][2] = -m[0][0]*m[1][2]*m[3][3] + m[0][0]*m[1][3]*m[3][2] + m[0][2]*m[1][0]*m[3][3] -
                 m[0][2]*m[1][3]*m[3][0] - m[0][3]*m[1][0]*m[3][2] + m[0][3]*m[1][2]*m[3][0];
    inv[1][3] =  m[0][0]*m[1][2]*m[2][3] - m[0][0]*m[1][3]*m[2][2] - m[0][2]*m[1][0]*m[2][3] +
                 m[0][2]*m[1][3]*m[2][0] + m[0][3]*m[1][0]*m[2][2] - m[0][3]*m[1][2]*m[2][0];

    inv[2][0] =  m[1][0]*m[2][1]*m[3][3] - m[1][0]*m[2][3]*m[3][1] - m[1][1]*m[2][0]*m[3][3] +
                 m[1][1]*m[2][3]*m[3][0] + m[1][3]*m[2][0]*m[3][1] - m[1][3]*m[2][1]*m[3][0];
    inv[2][1] = -m[0][0]*m[2][1]*m[3][3] + m[0][0]*m[2][3]*m[3][1] + m[0][1]*m[2][0]*m[3][3] -
                 m[0][1]*m[2][3]*m[3][0] - m[0][3]*m[2][0]*m[3][1] + m[0][3]*m[2][1]*m[3][0];
    inv[2][2] =  m[0][0]*m[1][1]*m[3][3] - m[0][0]*m[1][3]*m[3][1] - m[0][1]*m[1][0]*m[3][3] +
                 m[0][1]*m[1][3]*m[3][0] + m[0][3]*m[1][0]*m[3][1] - m[0][3]*m[1][1]*m[3][0];
    inv[2][3] = -m[0][0]*m[1][1]*m[2][3] + m[0][0]*m[1][3]*m[2][1] + m[0][1]*m[1][0]*m[2][3] -
                 m[0][1]*m[1][3]*m[2][0] - m[0][3]*m[1][0]*m[2][1] + m[0][3]*m[1][1]*m[2][0];

    inv[3][0] = -m[1][0]*m[2][1]*m[3][2] + m[1][0]*m[2][2]*m[3][1] + m[1][1]*m[2][0]*m[3][2] -
                 m[1][1]*m[2][2]*m[3][0] - m[1][2]*m[2][0]*m[3][1] + m[1][2]*m[2][1]*m[3][0];
    inv[3][1] =  m[0][0]*m[2][1]*m[3][2] - m[0][0]*m[2][2]*m[3][1] - m[0][1]*m[2][0]*m[3][2] +
                 m[0][1]*m[2][2]*m[3][0] + m[0][2]*m[2][0]*m[3][1] - m[0][2]*m[2][1]*m[3][0];
    inv[3][2] = -m[0][0]*m[1][1]*m[3][2] + m[0][0]*m[1][2]*m[3][1] + m[0][1]*m[1][0]*m[3][2] -
                 m[0][1]*m[1][2]*m[3][0] - m[0][2]*m[1][0]*m[3][1] + m[0][2]*m[1][1]*m[3][0];
    inv[3][3] =  m[0][0]*m[1][1]*m[2][2] - m[0][0]*m[1][2]*m[2][1] - m[0][1]*m[1][0]*m[2][2] +
                 m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1] - m[0][2]*m[1][1]*m[2][0];

    det = m[0][0]*inv[0][0] + m[0][1]*inv[1][0] + m[0][2]*inv[2][0] + m[0][3]*inv[3][0];
    det = 1.0f / det;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ret.m[i][j] = inv[i][j] * det;
        }
    }
    return ret;
}

GMatrix4 
matrix4_multiply(const GMatrix4 self,
                 const GMatrix4 matrix) 
{

    GMatrix4 result;
    //const float* A = self.m;
    //const float* B = matrix.m;

    const float (*A)[4] = self.m;
    const float (*B)[4] = matrix.m;

    result.m[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0] + A[0][3] * B[3][0];
    result.m[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1] + A[0][3] * B[3][1];
    result.m[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2] + A[0][3] * B[3][2];
    result.m[0][3] = A[0][0] * B[0][3] + A[0][1] * B[1][3] + A[0][2] * B[2][3] + A[0][3] * B[3][3];

    result.m[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0] + A[1][3] * B[3][0];
    result.m[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1] + A[1][3] * B[3][1];
    result.m[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2] + A[1][3] * B[3][2];
    result.m[1][3] = A[1][0] * B[0][3] + A[1][1] * B[1][3] + A[1][2] * B[2][3] + A[1][3] * B[3][3];

    result.m[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0] + A[2][3] * B[3][0];
    result.m[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1] + A[2][3] * B[3][1];
    result.m[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2] + A[2][3] * B[3][2];
    result.m[2][3] = A[2][0] * B[0][3] + A[2][1] * B[1][3] + A[2][2] * B[2][3] + A[2][3] * B[3][3];

    result.m[3][0] = A[3][0] * B[0][0] + A[3][1] * B[1][0] + A[3][2] * B[2][0] + A[3][3] * B[3][0];
    result.m[3][1] = A[3][0] * B[0][1] + A[3][1] * B[1][1] + A[3][2] * B[2][1] + A[3][3] * B[3][1];
    result.m[3][2] = A[3][0] * B[0][2] + A[3][1] * B[1][2] + A[3][2] * B[2][2] + A[3][3] * B[3][2];
    result.m[3][3] = A[3][0] * B[0][3] + A[3][1] * B[1][3] + A[3][2] * B[2][3] + A[3][3] * B[3][3];
    return result;
}

GMatrix4
matrix4_pick(float x,
             float y,
             float w,
             float h,
             const int* viewport)
{
    GMatrix4 m0;
    GMatrix4 m1;

    m0 = matrix4_translation(
        (viewport[2] - 2.0f * (x - viewport[0])) / w,
        (viewport[3] - 2.0f * (y - viewport[1])) / h, 0.0f);
    m1 = matrix4_scale (
         viewport[2] / w, viewport[3] / h, 1.0f);

    return matrix4_multiply (m0, m1);
}

int
matrix4_project(const GMatrix4  projection,
                const GMatrix4  modelview,
                const int*      viewport,
                const GVector3* object,
                      GVector3* window)
{
    float w;
    GMatrix4 m;
    GVector3 v;
    GVector3 result;

    /* Multiply by modelview matrix. */
    w = 1.0f;
    v = *object;
    m = modelview;
    result.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0] * w;
    result.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1] * w;
    result.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2] * w;
    w = m.m[0][3] * v.x + m.m[1][3] * v.y + m.m[2][3] * v.z + m.m[3][3] * w;

    /* Multiply by projection matrix. */
    v = result;
    m = projection;
    result.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0] * w;
    result.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1] * w;
    result.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2] * w;
    w = m.m[0][3] * v.x + m.m[1][3] * v.y + m.m[2][3] * v.z + m.m[3][3] * w;

    /* Convert to window space. */
    if (- VECTOR_EPSILON < w && w < VECTOR_EPSILON)
        return 0;
    result.x /= w;
    result.y /= w;
    result.z /= w;
    window->x = viewport[0] + viewport[2] * (result.x + 1.0f) / 2.0f;
    window->y = viewport[1] + viewport[3] * (result.y + 1.0f) / 2.0f;
    window->z = (result.z + 1.0f) / 2.0f;

    return 1;
}


int
matrix4_unproject(const GMatrix4  projection,
                  const GMatrix4  modelview,
                  const int*      viewport,
                  const GVector3* window,
                        GVector3* object)
{
    float w;
    GMatrix4 m;
    GVector3 v;

    /* Get inverse matrix. */
    m = matrix4_multiply (projection, modelview);
    if (matrix4_get_singular (m))
        return 0;
    m = matrix4_invert (m);

    /* Vector to [-1,1] range. */
    v.x = 2.0f * (window->x - viewport[0]) / viewport[2] - 1.0f;
    v.y = 2.0f * (window->y - viewport[1]) / viewport[3] - 1.0f;
    v.z = 2.0f * window->z - 1.0f;

    /* Multiply by the inverse matrix. */
    w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3];
    if (- VECTOR_EPSILON < w && w < VECTOR_EPSILON)
        return 0;
    object->x = (m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3]) / w;
    object->y = (m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3]) / w;
    object->z = (m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3]) / w;

    return 1;
}

