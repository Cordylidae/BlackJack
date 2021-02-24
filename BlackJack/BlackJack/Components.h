#ifndef COMPONENTS_H
#define COMPONENTS_H

#include"ECS.h"

class PositionComponent : public Component
{
private:
	double xpos;
	double ypos;

public:

	double x() { return xpos; }
	double y() { return ypos; }

	void init() override
	{
		xpos = 0;
		ypos = 0;
	}

	void update() override
	{
		xpos++;
		ypos++;
	}

	void setPos(double x, double y)
	{
		xpos = x;
		ypos = y;
	}
};

#endif
