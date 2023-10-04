// ----------------------------------------------------------------------------------------------------------------------------
//
// Version 2.04
//
// ----------------------------------------------------------------------------------------------------------------------------

#define _USE_MATH_DEFINES

#include<math.h>

// PI VALUE  				
#define M_PI 				3.14159265358979323846f
//#define M_PI 				3.141592653589793238462643383279f
//#define M_PI 			    3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f

// PI * 2
#define M_TAU				6.28318530717958647692f
//#define M_TAU				6.2831853071795864769252867665585f
//#define M_TAU				6.2831853071795864769252867665585057683943387987502116419498891846156328125724179972560696506842341359f

// PI / 2
#define M_HALF_PI			1.57079632679489661923f						
//#define M_HALF_PI			1.570796326794896619231321691639f		
//#define M_HALF_PI			1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339f 

// PI au carre
#define M_PI_SQUARED		9.86960440108935861883f
//#define M_PI_SQUARED		9.869604401089358618834490999876f		
//#define M_PI_SQUARED		9.86960440108935861883449099987615113531369940724079062671705757241606501973155666777675842503617386014f

// PI / 180
#define M_PIDIV180 			0.017453292519943295f
//#define M_PIDIV180		0.01745329251994329576923690768488f	
//#define M_PIDIV180		0.017453292519943295769236907684886127134428718885417254560f

// 180 / PI
#define M_180DIVPI			57.295779513082320876798154814105f	


#define G_EPSILON 1E-5f			
//#define G_EPSILON 1E-5		
//#define G_EPSILON 1E-20f

/*
1E-20f : This is a very small value, representing very high precision. 
Use this value if you are dealing with extremely precision-sensitive calculations, 
such as scientific calculations or simulations that require high precision. 
However, keep in mind that in some cases it can lead to numerical stability issues due to its small magnitude

1E-5f : This value is considerably higher and is suitable for most gaming and real-time graphics applications. 
It provides good accuracy in calculations, 
but is not excessively small, 
which generally avoids numerical stability problems. 
It's a safe value for most game development contexts.

*/


// ----------------------------------------------------------------------------------------------------------------------------

class vec2
{
public:
	union{
		struct{float x, y;};
		struct{float s, t;};
		struct{float r, g;};
	};
	vec2() : x(0.0f), y(0.0f){}
	~vec2(){}
	vec2(float num) : x(num), y(num){}
	vec2(float x, float y) : x(x), y(y){}
	vec2(const vec2 &u) : x(u.x), y(u.y){}
	vec2& operator = (const vec2 &u){x = u.x; y = u.y; return *this;}
	vec2 operator - (){return vec2(-x, -y);}
	float* operator & (){return (float*)this;};
	vec2& operator += (float num){x += num; y += num; return *this;}
	vec2& operator += (const vec2 &u){x += u.x; y += u.y; return *this;}
	vec2& operator -= (float num){x -= num; y -= num; return *this;}
	vec2& operator -= (const vec2 &u){x -= u.x; y -= u.y; return *this;}
	vec2& operator *= (float num){x *= num; y *= num; return *this;}
	vec2& operator *= (const vec2 &u){x *= u.x; y *= u.y; return *this;}
	vec2& operator /= (float num){x /= num; y /= num; return *this;}
	vec2& operator /= (const vec2 &u){x /= u.x; y /= u.y; return *this;}
	friend vec2 operator + (const vec2 &u, float num){return vec2(u.x + num, u.y + num);}
	friend vec2 operator + (float num, const vec2 &u){return vec2(num + u.x, num + u.y);}
	friend vec2 operator + (const vec2 &u, const vec2 &v){return vec2(u.x + v.x, u.y + v.y);}
	friend vec2 operator - (const vec2 &u, float num){return vec2(u.x - num, u.y - num);}
	friend vec2 operator - (float num, const vec2 &u){return vec2(num - u.x, num - u.y);}
	friend vec2 operator - (const vec2 &u, const vec2 &v){return vec2(u.x - v.x, u.y - v.y);}
	friend vec2 operator * (const vec2 &u, float num){return vec2(u.x * num, u.y * num);}
	friend vec2 operator * (float num, const vec2 &u){return vec2(num * u.x, num * u.y);}
	friend vec2 operator * (const vec2 &u, const vec2 &v){return vec2(u.x * v.x, u.y * v.y);}
	friend vec2 operator / (const vec2 &u, float num){return vec2(u.x / num, u.y / num);}
	friend vec2 operator / (float num, const vec2 &u){return vec2(num / u.x, num / u.y);}
	friend vec2 operator / (const vec2 &u, const vec2 &v){return vec2(u.x / v.x, u.y / v.y);}
};

// ----------------------------------------------------------------------------------------------------------------------------

float dot(const vec2 &u, const vec2 &v);
float length(const vec2 &u);
float length2(const vec2 &u);
vec2 mix(const vec2 &u, const vec2 &v, float a);
vec2 normalize(const vec2 &u);
vec2 reflect(const vec2 &i, const vec2 &n);
vec2 refract(const vec2 &i, const vec2 &n, float eta);
vec2 rotate(const vec2 &u, float angle);

// ----------------------------------------------------------------------------------------------------------------------------

class vec3
{
public:
	union{
		struct{float x, y, z;};
		struct{float s, t, p;};
		struct{float r, g, b;};
	};
	vec3() : x(0.0f), y(0.0f), z(0.0f){}
	~vec3(){}
	vec3(float num) : x(num), y(num), z(num){}
	vec3(float x, float y, float z) : x(x), y(y), z(z){}
	vec3(const vec2 &u, float z) : x(u.x), y(u.y), z(z){}
	vec3(const vec3 &u) : x(u.x), y(u.y), z(u.z){}
	vec3& operator = (const vec3 &u){x = u.x; y = u.y; z = u.z; return *this;}
	vec3 operator - (){return vec3(-x, -y, -z);}
	float* operator & (){return (float*)this;}
	vec3& operator += (float num){x += num; y += num; z += num; return *this;}
	vec3& operator += (const vec3 &u){x += u.x; y += u.y; z += u.z; return *this;}
	vec3& operator -= (float num){x -= num; y -= num; z -= num; return *this;}
	vec3& operator -= (const vec3 &u){x -= u.x; y -= u.y; z -= u.z; return *this;}
	vec3& operator *= (float num){x *= num; y *= num; z *= num; return *this;}
	vec3& operator *= (const vec3 &u){x *= u.x; y *= u.y; z *= u.z; return *this;}
	vec3& operator /= (float num){x /= num; y /= num; z /= num; return *this;}
	vec3& operator /= (const vec3 &u){x /= u.x; y /= u.y; z /= u.z; return *this;}
	friend vec3 operator + (const vec3 &u, float num){return vec3(u.x + num, u.y + num, u.z + num);}
	friend vec3 operator + (float num, const vec3 &u){return vec3(num + u.x, num + u.y, num + u.z);}
	friend vec3 operator + (const vec3 &u, const vec3 &v){return vec3(u.x + v.x, u.y + v.y, u.z + v.z);}
	friend vec3 operator - (const vec3 &u, float num){return vec3(u.x - num, u.y - num, u.z - num);}
	friend vec3 operator - (float num, const vec3 &u){return vec3(num - u.x, num - u.y, num - u.z);}
	friend vec3 operator - (const vec3 &u, const vec3 &v){return vec3(u.x - v.x, u.y - v.y, u.z - v.z);}
	friend vec3 operator * (const vec3 &u, float num){return vec3(u.x * num, u.y * num, u.z * num);}
	friend vec3 operator * (float num, const vec3 &u){return vec3(num * u.x, num * u.y, num * u.z);}
	friend vec3 operator * (const vec3 &u, const vec3 &v){return vec3(u.x * v.x, u.y * v.y, u.z * v.z);}
	friend vec3 operator / (const vec3 &u, float num){return vec3(u.x / num, u.y / num, u.z / num);}
	friend vec3 operator / (float num, const vec3 &u){return vec3(num / u.x, num / u.y, num / u.z);}
	friend vec3 operator / (const vec3 &u, const vec3 &v){return vec3(u.x / v.x, u.y / v.y, u.z / v.z);}
};

// ----------------------------------------------------------------------------------------------------------------------------

vec3 cross(const vec3 &u, const vec3 &v);
float dot(const vec3 &u, const vec3 &v);
float length(const vec3 &u);
float length2(const vec3 &u);
vec3 mix(const vec3 &u, const vec3 &v, float a);
vec3 normalize(const vec3 &u);
vec3 reflect(const vec3 &i, const vec3 &n);
vec3 refract(const vec3 &i, const vec3 &n, float eta);
vec3 rotate(const vec3 &u, float angle, const vec3 &v);

// ----------------------------------------------------------------------------------------------------------------------------

class vec4
{
public:
	union{
		struct{float x, y, z, w;};
		struct{float s, t, p, q;};
		struct{float r, g, b, a;};
	};
	vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f){}
	~vec4(){}
	vec4(float num) : x(num), y(num), z(num), w(num){}
	vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}
	vec4(const vec2 &u, float z, float w) : x(u.x), y(u.y), z(z), w(w){}
	vec4(const vec3 &u, float w) : x(u.x), y(u.y), z(u.z), w(w){}
	vec4(const vec4 &u) : x(u.x), y(u.y), z(u.z), w(u.w){}
	vec4& operator = (const vec4 &u){x = u.x; y = u.y; z = u.z; w = u.w; return *this;}
	vec4 operator - (){return vec4(-x, -y, -z, -w);}
	float* operator & (){return (float*)this;}
	vec4& operator += (float num){x += num; y += num; z += num; w += num; return *this;}
	vec4& operator += (const vec4 &u){x += u.x; y += u.y; z += u.z; w += u.w; return *this;}
	vec4& operator -= (float num){x -= num; y -= num; z -= num; w -= num; return *this;}
	vec4& operator -= (const vec4 &u){x -= u.x; y -= u.y; z -= u.z; w -= u.w; return *this;}
	vec4& operator *= (float num){x *= num; y *= num; z *= num; w *= num; return *this;}
	vec4& operator *= (const vec4 &u){x *= u.x; y *= u.y; z *= u.z; w *= u.w; return *this;}
	vec4& operator /= (float num){x /= num; y /= num; z /= num; w /= num; return *this;}
	vec4& operator /= (const vec4 &u){x /= u.x; y /= u.y; z /= u.z; w /= u.w; return *this;}
	friend vec4 operator + (const vec4 &u, float num){return vec4(u.x + num, u.y + num, u.z + num, u.w + num);}
	friend vec4 operator + (float num, const vec4 &u){return vec4(num + u.x, num + u.y, num + u.z, num + u.w);}
	friend vec4 operator + (const vec4 &u, const vec4 &v){return vec4(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);}
	friend vec4 operator - (const vec4 &u, float num){return vec4(u.x - num, u.y - num, u.z - num, u.w - num);}
	friend vec4 operator - (float num, const vec4 &u){return vec4(num - u.x, num - u.y, num - u.z, num - u.w);}
	friend vec4 operator - (const vec4 &u, const vec4 &v){return vec4(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);}
	friend vec4 operator * (const vec4 &u, float num){return vec4(u.x * num, u.y * num, u.z * num, u.w * num);}
	friend vec4 operator * (float num, const vec4 &u){return vec4(num * u.x, num * u.y, num * u.z, num * u.w);}
	friend vec4 operator * (const vec4 &u, const vec4 &v){return vec4(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w);}
	friend vec4 operator / (const vec4 &u, float num){return vec4(u.x / num, u.y / num, u.z / num, u.w / num);}
	friend vec4 operator / (float num, const vec4 &u){return vec4(num / u.x, num / u.y, num / u.z, num / u.w);}
	friend vec4 operator / (const vec4 &u, const vec4 &v){return vec4(u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w);}
};

// ----------------------------------------------------------------------------------------------------------------------------

class mat2x2;
class mat3x3;
class mat4x4;

// ----------------------------------------------------------------------------------------------------------------------------

class mat2x2
{
public:
	float M[4];
	mat2x2();
	~mat2x2();
	mat2x2(const mat2x2 &Matrix);
	mat2x2(const vec2 &col1, const vec2 &col2);
	mat2x2(float c1r1, float c1r2, float c2r1, float c2r2);
	explicit mat2x2(const mat3x3 &Matrix);
	explicit mat2x2(const mat4x4 &Matrix);
	mat2x2& operator = (const mat2x2 &Matrix);
	float& operator [] (int i);
	float* operator & ();
	friend mat2x2 operator * (const mat2x2 &Matrix1, const mat2x2 &Matrix2);
	friend vec2 operator * (const mat2x2 &Matrix, const vec2 &u);
};

// ----------------------------------------------------------------------------------------------------------------------------

mat2x2 inverse(const mat2x2 &Matrix);
mat2x2 transpose(const mat2x2 &Matrix);

// ----------------------------------------------------------------------------------------------------------------------------

class mat3x3
{
public:
	float M[9];
	mat3x3();
	~mat3x3();
	mat3x3(const mat3x3 &Matrix);
	mat3x3(const vec3 &col1, const vec3 &col2, const vec3 &col3);
	mat3x3(float c1r1, float c1r2, float c1r3, float c2r1, float c2r2, float c2r3, float c3r1, float c3r2, float c3r3);
	explicit mat3x3(const mat2x2 &Matrix);
	explicit mat3x3(const mat4x4 &Matrix);
	mat3x3& operator = (const mat3x3 &Matrix);
	float& operator [] (int i);
	float* operator & ();
	friend mat3x3 operator * (const mat3x3 &Matrix1, const mat3x3 &Matrix2);
	friend vec3 operator * (const mat3x3 &Matrix, const vec3 &u);
};

// ----------------------------------------------------------------------------------------------------------------------------

mat3x3 inverse(const mat3x3 &Matrix);
mat3x3 transpose(const mat3x3 &Matrix);

// ----------------------------------------------------------------------------------------------------------------------------

class mat4x4
{
public:
	float M[16];
	mat4x4();
	~mat4x4();
	mat4x4(const mat4x4 &Matrix);
	mat4x4(const vec4 &col1, const vec4 &col2, const vec4 &col3, const vec4 &col4);
	mat4x4(float c1r1, float c1r2, float c1r3, float c1r4, float c2r1, float c2r2, float c2r3, float c2r4, float c3r1, float c3r2, float c3r3, float c3r4, float c4r1, float c4r2, float c4r3, float c4r4);
	explicit mat4x4(const mat2x2 &Matrix);
	explicit mat4x4(const mat3x3 &Matrix);
	mat4x4& operator = (const mat4x4 &Matrix);
	float& operator [] (int i);
	float* operator & ();
	friend mat4x4 operator * (const mat4x4 &Matrix1, const mat4x4 &Matrix2);
	friend vec4 operator * (const mat4x4 &Matrix, const vec4 &u);
};

// ----------------------------------------------------------------------------------------------------------------------------

extern mat4x4 BiasMatrix;
extern mat4x4 BiasMatrixInverse;

// ----------------------------------------------------------------------------------------------------------------------------

mat4x4 inverse(const mat4x4 &Matrix);
mat4x4 look(const vec3 &eye, const vec3 &center, const vec3 &up);
mat4x4 ortho(float left, float right, float bottom, float top, float n, float f);
mat4x4 perspective(float fovy, float aspect, float n, float f);
mat4x4 rotate(float angle, const vec3 &u);
mat4x4 scale(float x, float y, float z);
mat4x4 translate(float x, float y, float z);
mat4x4 transpose(const mat4x4 &Matrix);
