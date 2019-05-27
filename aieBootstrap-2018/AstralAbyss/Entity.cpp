// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "Entity.h"
#include "Animation.h"
#include <Renderer2D.h>

Entity::Entity(const char* animFilename, unsigned int frames, float interval, bool loop, bool playing)
{
	m_animation = new Animation(animFilename, frames, interval, loop, playing);

	m_size = m_animation->getFrameSize();
	m_velocity = glm::vec2(0, 0);
	m_colour = glm::vec4(1, 1, 1, 1);
	m_isAlive = true;
}

Entity::Entity()
{
	m_animation = nullptr;
	m_size = glm::vec2(0,0);
	m_velocity = glm::vec2(0, 0);
	m_colour = glm::vec4(1, 1, 1, 1);
	m_isAlive = true;
}

Entity::~Entity()
{
	if (m_animation != nullptr)
		delete m_animation;
}

void Entity::setAnimation(const char* animFilename, unsigned int frames, float interval, bool loop, bool playing)
{
	m_animation = new Animation(animFilename, frames, interval, loop, playing);
	m_size = m_animation->getFrameSize();
}

void Entity::setAlive(bool state)
{
	m_isAlive = state; 
	if (state && m_animation != nullptr) {
		m_animation->setCurrentFrame(0);
		m_animation->play();
	}
}

void Entity::update(float deltaTime)
{
	if (!m_isAlive)
		return;

	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;

	m_animation->update(deltaTime);	

	if (m_animation->isPlaying() == false)
		m_isAlive = false;
}

void Entity::draw(aie::Renderer2D* renderer)
{
	if (!m_isAlive)
		return;

	renderer->setRenderColour(m_colour.r, m_colour.b, m_colour.g, m_colour.a);
	m_animation->draw(renderer, m_position.x, m_position.y);
}

bool Entity::isColliding(Entity* other)
{
	return m_position.x < other->m_position.x + other->m_size.x &&		// Check left
		m_position.x + m_size.x > other->m_position.x &&				// Check right
		m_position.y - m_size.y < other->m_position.y &&				// Check top
		m_position.y > other->m_position.y - other->m_size.y;			// Check bottom
}