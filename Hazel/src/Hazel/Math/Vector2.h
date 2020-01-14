#pragma once
 
#include "Hazel/Math/MathUtility.h" 

namespace Hazel 
{
	struct Vector2
	{
	public:
		union
		{
			struct
			{
				float X;
				float Y;
			};

			/** 0 = X, 1 = Y */
			float AsArray[2];
		};
	public:
		/** Checks for equality with error-tolerant comparison. */
		inline bool Equals(const Vector2& V, float Tolerance = KINDA_SMALL_NUMBER) const
		{
			return Math::Abs(X - V.X) <= Tolerance && Math::Abs(Y - V.Y) <= Tolerance;
		}

		inline void Normalize(float Tolerance = SMALL_NUMBER)
		{
			const float SquareSum = X * X + Y * Y;
			if (SquareSum > Tolerance)
			{
				const float Scale = Math::InvSqrt(SquareSum);
				X *= Scale;
				Y *= Scale;
				return;
			}
			X = 0.0f;
			Y = 0.0f;
		}

	public:
		/** Global 2D zero vector constant (0,0) */
		static const Vector2 ZeroVector;

		/** Global 2D unit vector constant (1,1) */
		static const Vector2 UnitVector;

		/** Calculates the dot product of two vectors.*/
		inline static float DotProduct(const Vector2& A, const Vector2& B)
		{
			return A | B;
		}

		inline static float DistSquared(const Vector2& V1, const Vector2& V2)
		{
			return Math::Square(V2.X - V1.X) + Math::Square(V2.Y - V1.Y);
		}

		inline static void Normalize(Vector2& V)
		{
			float Length = Math::Square(V.X * V.X * V.Y * V.Y);

			V.X /= Length;
			V.Y /= Length;
		}


	public:
		/************************************************************/
		/*Begin operator                                            */
		/************************************************************/

		/** Gets the result of adding two vectors together. */
		inline Vector2 operator+(const Vector2& V) const
		{
			return Vector2(X + V.X, Y + V.Y);
		}

		/**  Gets the result of subtracting a vector from this one. */
		inline Vector2 operator-(const Vector2& V) const
		{
			return Vector2(X - V.X, Y - V.Y);
		}

		/** Gets the result of scaling the vector (multiplying each component by a value).*/
		inline Vector2 operator*(float Scale) const
		{
			return Vector2(X * Scale, Y * Scale);
		}

		/** Gets the result of dividing each component of the vector by a value. */
		inline Vector2 operator/(float Scale) const
		{
			return Vector2(X / Scale, Y / Scale);
		}

		/** Gets the result of this vector + float A.*/
		inline Vector2 operator+(float A) const
		{
			return Vector2(X + A, Y + A);
		}

		/** Gets the result of subtracting from each component of the vector.*/
		inline Vector2 operator-(float A) const
		{
			return Vector2(X - A, Y - A);
		}

		/** Gets the result of component-wise multiplication of this vector by another.*/
		inline Vector2 operator*(const Vector2& V) const
		{
			return Vector2(X * V.X, Y * V.Y);
		}

		/** Gets the result of component-wise division of this vector by another.*/
		inline Vector2 operator/(const Vector2& V) const
		{
			return Vector2(X / V.X, Y / V.Y);
		}

		/** Calculates dot product of this vector and another. */
		inline float operator|(const Vector2& V) const
		{
			return X * V.X + Y * V.Y;
		}

		/**  Calculates cross product of this vector and another.  */
		inline float operator^(const Vector2& V) const
		{
			return X * V.Y - Y * V.X;
		}

		/** Check if Vector is equal to each other */
		inline bool operator==(const Vector2& V) const
		{
			return X == V.X && Y == V.Y;
		}

		/** Check if Vector is not Equal to each other */
		inline bool operator!=(const Vector2& V) const
		{
			return X != V.X || Y != V.Y;
		}

		/** Check if Vector is small then the other */
		inline bool operator<(const Vector2& Other) const
		{
			return X < Other.X && Y < Other.Y;
		}

		/** Check if vector is bigger then the other */
		inline bool operator>(const Vector2& Other) const
		{
			return X > Other.X&& Y > Other.Y;
		}

		/** Check if vector is smaller and equal then the other */
		inline bool operator<=(const Vector2& Other) const
		{
			return X <= Other.X && Y <= Other.Y;
		}

		/** Check if vector is Bigger and equal then the other */
		inline bool operator>=(const Vector2& Other) const
		{
			return X >= Other.X && Y >= Other.Y;
		}

		/** Adds another vector to this. */
		inline Vector2 operator+=(const Vector2& V)
		{
			X += V.X; Y += V.Y;
			return *this;
		}

		/** Subtracts another vector to this. */
		inline Vector2 operator-=(const Vector2& V)
		{
			X -= V.X; Y -= V.Y;
			return *this;
		}

		/** Scales this vector. */
		inline Vector2 operator*=(float Scale)
		{
			X *= Scale; Y *= Scale;
			return *this;
		}

		/** Divides this vector. */
		inline Vector2 operator/=(float V)
		{
			const float RV = 1.f / V;
			X *= RV; Y *= RV;
			return *this;
		}

		/** Scales another vector to this. */
		inline Vector2 operator*=(const Vector2& V)
		{
			X *= V.X; Y *= V.Y;
			return *this;
		}

		/** Divides another vector to this. */
		inline Vector2 operator/=(const Vector2& V)
		{
			X /= V.X; Y /= V.Y;
			return *this;
		}

		/** Get Through As Array */
		inline float& operator [](int x)
		{
			return AsArray[x];
		}

		/************************************************************/
		/*End operator                                              */
		/************************************************************/
	public:
		/************************************************************/
		/*Begin Constructor                                         */
		/************************************************************/
		inline Vector2()
			:X(0.f), Y(0.f)
		{}

		inline Vector2(float InFloat)
			: X(InFloat), Y(InFloat)
		{}

		inline Vector2(float X, float Y)
			: X(X), Y(Y)
		{}

		inline Vector2(const Vector2& V)
			: X(V.X), Y(V.Y)
		{}
		/************************************************************/
		/*End Constructor                                           */
		/************************************************************/

	public:
		/************************************************************/
		/* To String for Debug Purposes                             */
		/************************************************************/
		std::string ToString() const
		{ 
			std::stringstream ss;
			ss << "X: " << X << " Y : " << Y;
			 
			return ss.str();
		}

	};

	inline std::ostream& operator<<(std::ostream& os, const Vector2 & V)
	{
		return os << V.ToString();
	}
}
