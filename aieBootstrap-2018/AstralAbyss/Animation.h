// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <glm/vec2.hpp>

namespace aie {
	class Renderer2D;
	class Texture;
};

class Animation
{
	Animation();

public:
	Animation(const char* filename, unsigned int frames, float interval, bool loop=true, bool playing=true);
	~Animation();

	void play();
	void stop();
	void pause();

	bool isPlaying();

	glm::vec2 getFrameSize();

	void setCurrentFrame(int frame) { m_current = frame; }

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer, int x, int y);

private:
	unsigned int m_frames;
	unsigned int m_current;
	float m_interval;
	float m_elapsed;
	bool m_loop;
	bool m_isPlaying;

	aie::Texture* m_texture;
};

#endif // _ANIMATION_H_