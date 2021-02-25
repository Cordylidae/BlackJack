#ifndef POS_COMP_H
#define POS_COMP_H

#include"Components.h"


class PositionComponent : public Component
{
private:
	double xpos;
	double ypos;

public:

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

	double x() { return xpos; }
	void x(double x_) { xpos = x_; }
	double y() { return ypos; }
	void y(double y_) { ypos = y_; }

};

#endif // !POS_COMP_H
