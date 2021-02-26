#ifndef Animation_H
#define Animation_H

class Animation{

public:
	int index;
	int frame;
	int speed;

	Animation() {}
	Animation(int index_, int frame_, int speed_):index(index_),frame(frame_),speed(speed_)
	{
	}


};

#endif // !Anime_H