// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "Animation.h"
#include <Renderer2D.h>
#include <Texture.h>

Animation::Animation()
{
	m_frames = 0;
	m_current = 0;
	m_interval = 0.0f;
	m_elapsed = 0.0f;
	m_loop = false;
	m_isPlaying = false;
}

Animation::Animation(const char* filename, unsigned int frames, float interval, bool loop, bool playing)
{
	m_texture = new aie::Texture(filename);

	m_frames = frames;
	m_current = 0;
	m_interval = interval;
	m_elapsed = 0.0f;
	m_loop = loop;
	m_isPlaying = playing;
}

Animation::~Animation()
{
	if(m_texture != nullptr)
		delete m_texture;
}

void Animation::play()
{
	m_isPlaying = true;
}

void Animation::stop()
{
	m_isPlaying = false;
	m_current = 0;
}

void Animation::pause()
{
	m_isPlaying = false;
}

bool Animation::isPlaying()
{
	return m_isPlaying;
}

void Animation::update(float deltaTime)
{
	if (!m_isPlaying)
		return;

	m_elapsed += deltaTime;

	if (m_elapsed > m_interval)
	{
		m_elapsed -= m_interval;

		m_current++;

		if (m_current >= m_frames)
		{
			if (m_loop)
			{
				m_current = 0;
			}
			else
			{
				m_current = m_frames;
				m_isPlaying = false;
			}
		}
	}
}

void Animation::draw(aie::Renderer2D* renderer, int x, int y)
{
	//float offset = (float)m_current / ((float)m_frames + 1.0f);
	
	float start = (float)m_current / (float)m_frames;
	int width = m_texture->getWidth() / m_frames;

	renderer->setUVRect(start, 0.0f, 1.0f / (float)m_frames, 1.0f);
	renderer->drawSprite(m_texture, x, y, width, m_texture->getHeight());
	renderer->setUVRect(0, 0, 1, 1);
}

glm::vec2 Animation::getFrameSize()
{
	float percent = 1.0f / ((float)m_frames + 1.0f);
	float width = m_texture->getWidth() * percent;
	float height = m_texture->getHeight();
	return glm::vec2(width, height);
}