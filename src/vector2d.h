// Liam Wynn, 7/11/2020, Fyodor

#ifndef VECTOR_2D
#define VECTOR_2D

namespace fyodor {
	class vector2d {
		public:
			float x, y;

			vector2d() : x(0), y(0) { }
			vector2d(const float x_val, const float y_val) : x(x_val), y(y_val) { }

			vector2d& operator+= (const vector2d& to_add);
			vector2d& operator*= (const float& scalar);

			float magnitude() const;

			void normalize();
			vector2d get_normalized() const;
	};
}

fyodor::vector2d operator+ (const fyodor::vector2d& a, const fyodor::vector2d& b);
fyodor::vector2d operator* (const float& scalar, const fyodor::vector2d& vect);
fyodor::vector2d operator* (const fyodor::vector2d& vect, const float& scalar);
#endif
