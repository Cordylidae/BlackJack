#ifndef VEC2D_H
#define VEC2D_H


class Vector2D
{
public:

	double x;
	double y;

	Vector2D();
	Vector2D(double x, double y);
	Vector2D(const Vector2D&);
	Vector2D& operator=(const Vector2D&);


	Vector2D& Add(const Vector2D& vec);
	Vector2D& Sub(const Vector2D& vec);
	Vector2D& Mul(double k);
	Vector2D& Div(double k);

	friend Vector2D operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator*(Vector2D& v1, double k);
	friend Vector2D operator/(Vector2D& v1, double k);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(double k);
	Vector2D& operator/=(double k);


};

#endif // !POS_COMP_H
