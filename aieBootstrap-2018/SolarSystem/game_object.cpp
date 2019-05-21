#include "game_object.h"



game_object::game_object(aie::Texture* a_texture,
	const vector_2& a_position,
	const float a_z_rotation,
	const float a_spin_speed /*= 0.0f*/,
	const float a_orbit_speed /*= 0.0f*/) :
	m_texture(a_texture),
	m_position(a_position),
	m_current_rotation(a_z_rotation),
	m_spin_speed(a_spin_speed),
	m_orbit_speed(a_orbit_speed)
{
	m_parent = nullptr;
	m_local_matrix.setRotateZ(m_current_rotation);
	m_local_matrix.forward = { a_position.x, a_position.y, 1 };
}

void game_object::update(const float deltaTime)
{
	// ***PLANET DOOM***
	// Spinning
	matrix_3x3 rotation_matrix;
	rotation_matrix.setRotateZ(deltaTime * m_spin_speed);
	// Spin the planet
	m_local_matrix = m_local_matrix * rotation_matrix;

	// Orbiting
	rotation_matrix.setRotateZ(deltaTime * m_orbit_speed);
	m_local_matrix = rotation_matrix * m_local_matrix;

	// Childing
	if (m_parent)
		m_world_matrix = m_parent->m_world_matrix * m_local_matrix;
	else
		m_world_matrix = m_local_matrix;
}

void game_object::set_parent(game_object* a_parent)
{
	m_parent = a_parent;
}

