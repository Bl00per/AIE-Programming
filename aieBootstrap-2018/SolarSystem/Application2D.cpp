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
	
	m_toddchan = new aie::Texture("./textures/todd_chan.png");
	todd_local_transform = matrix_3x3();
	todd_local_transform.forward = { 840.0f, 525.0f, 1.0f };

	// Planet Doom data
	m_PlanetDoom = new aie::Texture("./textures/PlanetDoom.png");
	doom_local_transform = matrix_3x3();
	doom_local_transform.forward = { 350.0f, 350.0f, 1.0f };
	doom_rotation = 2.0f;
	doom_orbit = 0.9f; // 90deg / second

	// Planet Skyrim data
	m_PlanetSkyrim = new aie::Texture("./textures/PlanetSkyrim.png");
	skyrim_local_transform = matrix_3x3();
	skyrim_local_transform.forward = { 700.0f, 0.0f, 1.0f };
	skyrim_rotation = 3.14159f;
	skyrim_orbit = 0.3f; // 90deg / second

	// Planet F4 data
	m_PlanetF4 = new aie::Texture("./textures/PlanetFallout4.png");
	fallout4_local_transform = matrix_3x3();
	fallout4_local_transform.forward = { 280.0f, 0.0f, 1.0f };
	fallout4_rotation = 2.0f;
	fallout4_orbit = 3.14159f * 0.5f; // 90deg / second

	// Planet F76 data
	m_PlanetF76 = new aie::Texture("./textures/PlanetFallout76.png");
	fallout76_local_transform = matrix_3x3();
	fallout76_local_transform.forward = { 100.0f, 0.0f, 1.0f };
	fallout76_rotation = 3.14159f * 0.5f;
	fallout76_orbit = fallout4_rotation; // 90deg / second

	todd_world_transform = matrix_3x3();

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_2dRenderer;
	delete m_shipTexture;
	delete m_font;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;
	
	// ***TODD SUN***
	todd_world_transform = matrix_3x3() * todd_local_transform;

	// ***PLANET DOOM***
	// Concatinate my local matrix with my parent's
	matrix_3x3 rotation_matrix;
	rotation_matrix.setRotateZ(deltaTime * doom_rotation);
	// Spin the planet
	doom_local_transform = doom_local_transform * rotation_matrix;

	// Orbit the sun
	rotation_matrix.setRotateZ(deltaTime * doom_orbit);
	doom_local_transform = rotation_matrix * doom_local_transform;
	// Final location 
	doom_world_transform = todd_world_transform * doom_local_transform;


	// ***PLANET F4***
	rotation_matrix.setRotateZ(deltaTime * fallout4_rotation);
	// Spin the planet
	fallout4_local_transform = fallout4_local_transform * rotation_matrix;

	// Orbit the sun
	rotation_matrix.setRotateZ(deltaTime * fallout4_orbit);
	fallout4_local_transform = rotation_matrix * fallout4_local_transform;
	// Final location 
	fallout4_world_transform = todd_world_transform * fallout4_local_transform;


	// ***MOON F76***
	rotation_matrix.setRotateZ(fallout76_rotation * deltaTime);
	// Spin the moon
	fallout76_local_transform = fallout76_local_transform * rotation_matrix;

	// Orbit the planet doom
	rotation_matrix.setRotateZ(-deltaTime * fallout76_orbit * 5);
	fallout76_local_transform = rotation_matrix * fallout76_local_transform;

	// Final location 
	fallout76_world_transform = fallout4_world_transform * fallout76_local_transform;


	// ***PLANET SKYRIM***
	rotation_matrix.setRotateZ(skyrim_rotation * deltaTime);
	// Spin the moon
	skyrim_local_transform = skyrim_local_transform * rotation_matrix;

	// Orbit the planet doom
	rotation_matrix.setRotateZ(-deltaTime * skyrim_orbit * 5);
	skyrim_local_transform = rotation_matrix * skyrim_local_transform;

	// Final location 
	skyrim_world_transform = todd_world_transform * skyrim_local_transform;


	

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Update the camera position using the arrow keys
	//float camPosX;
	//float camPosY;
	//m_2dRenderer->getCameraPos(camPosX, camPosY);

	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//	camPosY += 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//	camPosY -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	//	camPosX -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//	camPosX += 500.0f * deltaTime;

	//m_2dRenderer->setCameraPos(camPosX - 640.0f, camPosY - 360.0f);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate spinning sprite	
	m_2dRenderer->drawSpriteTransformed3x3(m_toddchan, todd_world_transform, 480.0f, 270.0f, 0.0f, 0.6f, 0.6f);
	m_2dRenderer->drawSpriteTransformed3x3(m_PlanetDoom, doom_world_transform, 100.0f, 100.0f);
	m_2dRenderer->drawSpriteTransformed3x3(m_PlanetSkyrim, skyrim_world_transform, 130.0f, 130.0f);
	m_2dRenderer->drawSpriteTransformed3x3(m_PlanetF4, fallout4_world_transform, 100.0f, 100.0f);
	m_2dRenderer->drawSpriteTransformed3x3(m_PlanetF76, fallout76_world_transform, 50.0f, 50.0f);



	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 1680 - 64);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 1680 - 96);

	// done drawing sprites
	m_2dRenderer->end();
}
