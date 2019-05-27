// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace aie {
	class Renderer2D;
	class Texture;
};

class Animation;

class Entity
{
protected:
	Entity();
public:
	Entity(const char* animFilename, unsigned int frames, float interval, bool loop = true, bool playing = true);
	~Entity();
	
	void setPosition(glm::vec2 position) { m_position = position; }
	void setVelocity(glm::vec2 velocity) { m_velocity = velocity; }
	void setSize(glm::vec2 size) { m_size = size; }
	void setColour(glm::vec4 colour) { m_colour = colour; }
	void setAlive(bool state);

	glm::vec2 getPosition() { return m_position; }
	glm::vec2 getVelocity() { return m_velocity; }
	glm::vec2 getSize() { return m_size; }
	glm::vec4 getColour() { return m_colour; }
	bool isAlive() { return m_isAlive; }

	bool isColliding(Entity* other);
	
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);

	void setAnimation(const char* animFilename, unsigned int frames, float interval, bool loop = true, bool playing = true);

protected:
	Animation* m_animation;

	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec2 m_velocity;
	glm::vec4 m_colour;

	bool m_isAlive;
};

#endif // _ENTITY_H_