#ifndef TRANS_COMP_H
#define TRANS_COMP_H

#include"Components.h"
#include"Vector2d.h"

class TransformComponent : public Component
{
private:
	
public:

	Vector2D position;
	Vector2D velocity;

	double speed = 3;

	TransformComponent() :position(0,0) {}
	TransformComponent(double x, double y):position(x,y){}


	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};

#endif // !POS_COMP_H
