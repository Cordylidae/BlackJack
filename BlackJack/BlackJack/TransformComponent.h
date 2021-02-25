#ifndef TRANS_COMP_H
#define TRANS_COMP_H

#include"Components.h"
#include"Vector2d.h"

class TransformComponent : public Component
{
private:
	
public:

	Vector2D position;

	TransformComponent() :position(0,0) {}
	TransformComponent(double x, double y):position(x,y){}

	void update() override
	{
		
	}

};

#endif // !POS_COMP_H
