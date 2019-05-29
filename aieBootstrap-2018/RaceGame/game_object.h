#pragma once
#include "matrix_3x3.h"
#include "vector_2.h"
#include "Renderer2D.h"

class game_object
{
public:
	game_object(aie::Texture* a_texture, 
		const vector_2& a_position, 
		const float a_z_rotation, 
		const float a_spin_speed = 0.0f, 
		const float a_orbit_speed = 0.0f);

	void update(const float deltaTime);

	void set_parent(game_object* a_parent);

	//void set_position(const vector_2& a_position);
	//void set_local_position(const vector_2& a_local_position);

	//void set_rotation(const float a_rotation);
	//void set_local_rotation(const float a_local_rotation);

public:
	matrix_3x3 m_world_matrix;
	matrix_3x3 m_local_matrix;

	vector_2 m_position;
	float m_current_rotation;	// Radians
	float m_orbit_speed;		// Radians / second
	float m_spin_speed;			// Radians / second
	float m_speed;
	float m_max_speed;
	float m_acceleration;

	aie::Texture* m_texture;
	vector_2 m_texture_size;

	game_object* m_parent;
};

