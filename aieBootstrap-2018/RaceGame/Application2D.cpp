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
	m_font = new aie::Font("./font/consolas_bold.ttf", 32);

	// Race Track
	raceTrack = new aie::Texture("./textures/RaceTrack.png");

	// Race Car data
	car_texture = new aie::Texture("./textures/car.png");
	playerCar = new game_object(car_texture, { 640.0f, 360.0f }, 0.0f, 2.0f/*, 3.14159f*/);

	//energy_ball_texture = new aie::Texture("./textures/energyBallBlue.png");
	//energy_ball = new game_object(energy_ball_texture, { 840.0f, 525.0f }, 0.0f);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_2dRenderer;
	delete m_font;
	delete car_texture;

}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;

	playerCar->update(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();

	// ***CONTROLLING THE CAR***
	std::cout << playerCar->m_speed << std::endl;
	// Acceleration
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		playerCar->m_acceleration = 100.0f;
	}
	else if (input->isKeyUp(aie::INPUT_KEY_W) && playerCar->m_speed >= 0.0f)
	{
		playerCar->m_acceleration = -80.0f;
	}
	// Reverse / Stopping
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		playerCar->m_acceleration = -200.0f;
	}
	// Keep the car stopped
	else
	{
		playerCar->m_speed = 0.0f;
	}

	// Turning the car
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		playerCar->m_spin_speed = 3.2f;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		playerCar->m_spin_speed = -3.2f;
	}
	// Keep the car facing its current direction
	else
	{
		playerCar->m_spin_speed = 0.0f;
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

	// Draw race track
	m_2dRenderer->drawSprite(raceTrack, 640, 360, 0.0f, 0.0f, 0.0f, 1.0f);
	
	// Draw car sprite
	m_2dRenderer->drawSpriteTransformed3x3(playerCar->m_texture, playerCar->m_world_matrix);
	
	//m_2dRenderer->drawSpriteTransformed3x3(energy_ball->m_texture, energy_ball->m_world_matrix, 50.0f, 50.0f);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);


	// done drawing sprites
	m_2dRenderer->end();
}
