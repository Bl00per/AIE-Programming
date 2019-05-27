#include "Application2D.h"


Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new aie::Renderer2D();
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_font = new aie::Font("./font/consolas_bold.ttf", 32);
	
	toddchan_texture = new aie::Texture("./textures/todd_chan.png");
	toddchan = new game_object(toddchan_texture, { 840.0f, 525.0f }, 0.0f);

	// Planet Doom data
	planetDoom_texture = new aie::Texture("./textures/PlanetDoom.png");
	planetDoom = new game_object(planetDoom_texture, { 350.0f, 350.0f }, 0.0f, 2.0f, 0.9f);
	planetDoom->set_parent(toddchan);

	// Planet Skyrim data
	planetSkyrim_texture = new aie::Texture("./textures/PlanetSkyrim.png");
	planetSkyrim = new game_object(planetSkyrim_texture, { 700.0f, 0.0f }, 0.0f, 3.14159f, 0.3f);
	planetSkyrim->set_parent(toddchan);

	// Planet F4 data
	planetF4_texture = new aie::Texture("./textures/PlanetFallout4.png");
	planetF4 = new game_object(planetF4_texture, { 280.0f, 0.0f }, 0.0f, 2.0f, 3.14159f);
	planetF4->set_parent(toddchan);

	// Planet F76 data
	planetF76_texture = new aie::Texture("./textures/PlanetFallout76.png");
	planetF76 = new game_object(planetF76_texture, { 100.0f, 0.0f },  0.0f,  -3.14159, -3.14159f * 0.5f);
	planetF76->set_parent(planetF4);

	energy_ball_texture = new aie::Texture("./textures/energyBallBlue.png");
	energy_ball = new game_object(energy_ball_texture, { 840.0f, 525.0f }, 0.0f);

	toddchan->m_world_matrix = matrix_3x3();

	m_timer = 0;
	planetF4->m_acceleration = 10.0f;

	return true;
}

void Application2D::shutdown() {
	
	delete m_2dRenderer;
	delete m_shipTexture;
	delete m_font;
	delete toddchan_texture;
	delete planetDoom_texture;
	delete planetF4_texture;
	delete planetF76_texture;
	delete planetSkyrim_texture;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;
	
	toddchan->update(deltaTime);
	planetDoom->update(deltaTime);
	planetSkyrim->update(deltaTime);
	planetF4->update(deltaTime);
	planetF76->update(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		planetF4->m_speed = 20.0f;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		planetF4->m_speed = -20.0f;
	}
	else
	{
		planetF4->m_speed = 0.0f;
	}

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		planetF4->m_spin_speed = 2.0f;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		planetF4->m_spin_speed = -2.0f;
	}
	else
	{
		planetF4->m_spin_speed = 0.0f;
	}


	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		planetF76->m_speed = 10.0f;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		planetF76->m_speed = -10.0f;
	}
	else
	{
		planetF76->m_speed = 0.0f;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		planetF76->m_spin_speed = 2.0f;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		planetF76->m_spin_speed = -2.0f;
	}
	else
	{
		planetF76->m_spin_speed = 0.0f;
	}


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->setUVRect(0, 0, 1, 1);

	// demonstrate spinning sprite	
	// Todd sun
	m_2dRenderer->drawSpriteTransformed3x3(toddchan->m_texture, toddchan->m_world_matrix, 480.0f, 270.0f, 0.0f, 0.55f, 0.6f);
	
	// Planet doom
	m_2dRenderer->drawSpriteTransformed3x3(planetDoom->m_texture, planetDoom->m_world_matrix, 100.0f, 100.0f);
	
	// Planet skyrim
	m_2dRenderer->drawSpriteTransformed3x3(planetSkyrim->m_texture, planetSkyrim->m_world_matrix, 130.0f, 130.0f);
	
	// Planet F4
	m_2dRenderer->drawSpriteTransformed3x3(planetF4->m_texture, planetF4->m_world_matrix, 100.0f, 100.0f);
	
	// Moon F76
	m_2dRenderer->drawSpriteTransformed3x3(planetF76->m_texture, planetF76->m_world_matrix, 50.0f, 50.0f);

	//m_2dRenderer->drawSpriteTransformed3x3(energy_ball->m_texture, energy_ball->m_world_matrix, 50.0f, 50.0f);


	plane p{ {1,0}, -10 };
	vector_2 centre = p.m_normal * p.m_distance;
	vector_2 perpendicular = { p.m_normal.y, -p.m_normal.x };
	vector_2 end_1 = centre + perpendicular * 500.0f;
	vector_2 end_2 = centre - perpendicular * 500.0f;

	m_2dRenderer->drawLine(end_1.x, end_2.y, end_2.x, end_2.y);

	circle c{ {400,400}, 50 };
	m_2dRenderer->drawCircle(c.m_position.x, c.m_position.y, c.m_radius);

	//AABB aabb{ {200,400}, {50, 100} };
	//m_2dRenderer->drawBox(aabb.m_position.x, aabb.m_position.y, );


	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 1680 - 64);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 1680 - 96);

	// done drawing sprites
	m_2dRenderer->end();
}
