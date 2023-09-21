#ifndef MATH_GENERIC_H
#define MATH_GENERIC_H

#include<math.h>

#define M_PI 3.14159265358979323846f;
//#define M_PI 				3.141592653589793238462643383279f		// PI
#define M_PIDIV2			1.570796326794896619231321691639f		// PI / 2
#define M_2PI				6.283185307179586476925286766559f		// 2 * PI
#define M_PI2				9.869604401089358618834490999876f		// PI au carre
#define M_PIDIV180			0.01745329251994329576923690768488f		// PI / 180
#define M_180DIVPI			57.295779513082320876798154814105f		// 180 / PI

#define G_ABS(a) (((a)<0)?-(a):(a))
#define G_MIN(a,b) ((a)<(b)?(a):(b))
#define G_MAX(a,b) ((a)>(b)?(a):(b))
#define G_CLAMP(val,min,max) ((val)<(min)?(min):(val)>(max)?(max):(val))
#define G_EPSILON 1E-20f
#define G_INFINITE 1.0f/0.0f

//WATCOM dont have a finite in math.h
static int is_finite(float x) {
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

