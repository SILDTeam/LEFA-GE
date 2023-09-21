/*Open LEFA Project
2023*/
//contains resources that the rest of the libraries need

#ifndef MATH_GENERIC_H
#define MATH_GENERIC_H

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


#define G_ABS(a)  (((a)<0)?-(a):(a))
#define G_MIN(a,b) ((a)<(b)?(a):(b))
#define G_MAX(a,b) ((a)>(b)?(a):(b))
#define G_CLAMP(val,min,max) ((val)<(min)?(min):(val)>(max)?(max):(val))
#define G_INFINITE 1.0f/0.0f

#define VECTOR_EPSILON 0.0001f

//WATCOM dont have a finite in math.h
static inline int 
is_finite(float x) {
    return isnan(x) == 0 && isinf(x) == 0;
}


static inline float 
generic_mix (
	float value0,
	float value1,
	float mix)
{
	return (1.0f - mix) * value0 + mix * value1;
}

static inline float 
smoothstep(
	float value,
	float edge0,
	float edge1)
{
	float x = (value - edge0) / (edge1 - edge0);
	x = G_CLAMP (x, 0.0f, 1.0f);
	return x * x * (3.0f - 2.0f * x);
}

static inline float 
quantize(
	float value,
	float resolution)
{
	float tmp;

	if (resolution <= G_EPSILON)
		return value;
	tmp = fmod (value, resolution);
	if (tmp >= 0.5f * resolution)
		return value - tmp + resolution;
	else if (tmp <= -0.5f * resolution)
		return value - tmp - resolution;
	else
		return value - tmp;
}

static inline float 
number_bilinear (
	float x,
	float z,
	float v00,
	float v10,
	float v01,
	float v11)
{
	float t0;
	float t1;

	t0 = (1.0f - x) * v00 + x * v10;
	t1 = (1.0f - x) * v01 + x * v11;
	return (1.0f - z) * t0 + z * t1;
}

static inline float 
number_is_finite (
	float value)
{
	if (is_finite(value))
		return 1;
	return 0;
}

static inline float 
number_validate (
	float value)
{
	if (is_finite (value))
		return value;
	return 0.0f;
}

#endif

