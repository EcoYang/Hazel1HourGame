#pragma once


/*-----------------------------------------------------------------------------
	Floating point constants.
-----------------------------------------------------------------------------*/

#undef  PI
#define PI 					(3.1415926535897932f)
#define SMALL_NUMBER		(1.e-8f)
#define KINDA_SMALL_NUMBER	(1.e-4f)
#define BIG_NUMBER			(3.4e+38f)
#define EULERS_NUMBER       (2.71828182845904523536f)

// Copied from float.h
#define MAX_FLT 3.402823466e+38F

// Aux constants.
#define INV_PI			(0.31830988618f)
#define HALF_PI			(1.57079632679f)

// Magic numbers for numerical precision.
#define DELTA			(0.00001f)

/**
 * Lengths of normalized vectors (These are half their maximum values
 * to assure that dot products with normalized vectors don't overflow).
 */
#define FLOAT_NORMAL_THRESH				(0.0001f)

 //
 // Magic numbers for numerical precision.
 //
#define THRESH_POINT_ON_PLANE			(0.10f)		/* Thickness of plane for front/back/inside test */
#define THRESH_POINT_ON_SIDE			(0.20f)		/* Thickness of polygon side's side-plane for point-inside/outside/on side test */
#define THRESH_POINTS_ARE_SAME			(0.00002f)	/* Two points are same if within this distance */
#define THRESH_POINTS_ARE_NEAR			(0.015f)	/* Two points are near if within this distance and can be combined if imprecise math is ok */
#define THRESH_NORMALS_ARE_SAME			(0.00002f)	/* Two normal points are same if within this distance */
#define THRESH_UVS_ARE_SAME			    (0.0009765625f)/* Two UV are same if within this threshold (1.0f/1024f) */
													/* Making this too large results in incorrect CSG classification and disaster */
#define THRESH_VECTORS_ARE_NEAR			(0.0004f)	/* Two vectors are near if within this distance and can be combined if imprecise math is ok */
													/* Making this too large results in lighting problems due to inaccurate texture coordinates */
#define THRESH_SPLIT_POLY_WITH_PLANE	(0.25f)		/* A plane splits a polygon in half */
#define THRESH_SPLIT_POLY_PRECISELY		(0.01f)		/* A plane exactly splits a polygon */
#define THRESH_ZERO_NORM_SQUARED		(0.0001f)	/* Size of a unit normal that is considered "zero", squared */
#define THRESH_NORMALS_ARE_PARALLEL		(0.999845f)	/* Two unit vectors are parallel if abs(A dot B) is greater than or equal to this. This is roughly cosine(1.0 degrees). */
#define THRESH_NORMALS_ARE_ORTHOGONAL	(0.017455f)	/* Two unit vectors are orthogonal (perpendicular) if abs(A dot B) is less than or equal this. This is roughly cosine(89.0 degrees). */

#define THRESH_VECTOR_NORMALIZED		(0.01f)		/** Allowed error for a normalized vector (against squared magnitude) */
#define THRESH_QUAT_NORMALIZED			(0.01f)		/** Allowed error for a normalized quaternion (against squared magnitude) */

namespace Hazel
{
	struct Math
	{
	public:
		/** Multiples value by itself */
		template< class T >
		static inline T Square(const T A)
		{
			return A * A;
		}

		/** Computes absolute value in a generic way */
		template< class T >
		static constexpr inline T Abs(const T A)
		{
			return (A >= (T)0) ? A : -A;
		}

		// Only works on Windows
		static inline float InvSqrt(float F)
		{
			// Performs two passes of Newton-Raphson iteration on the hardware estimate
			//    v^-0.5 = x
			// => x^2 = v^-1
			// => 1/(x^2) = v
			// => F(x) = x^-2 - v
			//    F'(x) = -2x^-3

			//    x1 = x0 - F(x0)/F'(x0)
			// => x1 = x0 + 0.5 * (x0^-2 - Vec) * x0^3
			// => x1 = x0 + 0.5 * (x0 - Vec * x0^3)
			// => x1 = x0 + x0 * (0.5 - 0.5 * Vec * x0^2)
			//
			// This final form has one more operation than the legacy factorization (X1 = 0.5*X0*(3-(Y*X0)*X0)
			// but retains better accuracy (namely InvSqrt(1) = 1 exactly).

			const __m128 fOneHalf = _mm_set_ss(0.5f);
			__m128 Y0, X0, X1, X2, FOver2;
			float temp;

			Y0 = _mm_set_ss(F);
			X0 = _mm_rsqrt_ss(Y0);	// 1/sqrt estimate (12 bits)
			FOver2 = _mm_mul_ss(Y0, fOneHalf);

			// 1st Newton-Raphson iteration
			X1 = _mm_mul_ss(X0, X0);
			X1 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X1));
			X1 = _mm_add_ss(X0, _mm_mul_ss(X0, X1));

			// 2nd Newton-Raphson iteration
			X2 = _mm_mul_ss(X1, X1);
			X2 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X2));
			X2 = _mm_add_ss(X1, _mm_mul_ss(X1, X2));

			_mm_store_ss(&temp, X2);
			return temp;
		}

		static inline int TruncToInt(float F)
		{
			return _mm_cvtt_ss2si(_mm_set_ss(F));
		}

		static inline float TruncToFloat(float F)
		{
			return (float)TruncToInt(F); // same as generic implementation, but this will call the faster trunc
		}
	};
}