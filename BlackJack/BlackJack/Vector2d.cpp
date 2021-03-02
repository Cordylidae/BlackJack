#include"Vector2d.h"
#include<iostream>

Vector2D::Vector2D()
{
	x = 0.0;
	y = 0.0;
}

Vector2D::Vector2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(const Vector2D& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

Vector2D& Vector2D::operator=(const Vector2D& vec)
{
	this->x = vec.x;
	this->y = vec.y;

	return *this;
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2D& Vector2D::Sub(const Vector2D& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2D& Vector2D::Mul(double k)
{
	this->x *= k;
	this->y *= k;

	return *this;
}

Vector2D& Vector2D::Div(double k)
{
	try {
		if (k == 0) {
			throw "divide by 0\n";
		}
		this->x /= k;
		this->y /= k;
	}
	catch (const char* s)
	{
		std::cout << s;
	}

	return *this;
}

Vector2D operator+(Vector2D& v1, const Vector2D& v2)
{
	Vector2D v3;
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;

	return v3;
}

Vector2D operator-(Vector2D& v1, const Vector2D& v2)
{
	Vector2D v3;
	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;

	return v3;
}

Vector2D operator*(Vector2D& v1, double k)
{
	Vector2D v3;
	v3.x = v1.x * k;
	v3.y = v1.y * k;

	return v3;
}

Vector2D operator/(Vector2D& v1, double k)
{
	Vector2D v3 = v1;

	return v3.Div(k);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	return this->Add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	return this->Sub(vec);
}

Vector2D& Vector2D::operator*=(double k)
{
	return this->Mul(k);
}

Vector2D& Vector2D::operator/=(double k)
{
	return this->Div(k);
}