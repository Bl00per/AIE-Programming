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
	m_font = new aie::Font("./font/ARCADE.ttf", 32);

	// Race Track
	raceTrack = new aie::Texture("./textures/RaceTrack.png");

	// Race Car data
	car_texture = new aie::Texture("./textures/car.png");
	playerCar = new game_object(car_texture, { xPos, yPos }, (52 * M_PI / 180), 2/*, 3.14159f*/);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {

	delete m_2dRenderer;
	delete m_font;
	delete car_texture;
	delete raceTrack;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;

	playerCar->update(deltaTime);
	carControl(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Car out of bounds
	if (xPos > 1280.0f)
	{
		xPos = 1280.0f;
	}
	else if (xPos < 0)
	{
		xPos = 0.0f;
	}
	else if (yPos > 720.0f)
	{
		yPos = 720.0f;
	}
	else if (yPos < 0.0f)
	{
		yPos = 0.0f;
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
	m_2dRenderer->drawSprite(raceTrack, 640, 360, 0, 0, 0, 1);

	// Draw car sprite
	m_2dRenderer->drawSpriteTransformed3x3(playerCar->m_texture, playerCar->m_world_matrix);

	//m_2dRenderer->drawSpriteTransformed3x3(energy_ball->m_texture, energy_ball->m_world_matrix, 50, 50);

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(0, 0, 0, 1);
	char fps[32];
	char gear[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	sprintf_s(gear, 32, (getGear() == 0) ? "Gear: N" : "Gear: %i", getGear());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, gear, 0, 720 - 64);



	// done drawing sprites
	m_2dRenderer->end();
}

void Application2D::carControl(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// ***CONTROLLING THE CAR***
	std::cout << playerCar->m_speed << std::endl;

	switch (currentGear)
	{
	case 0:
		currentAcceleration = 0.0f;
		playerCar->m_max_speed = 0.0f;
		break;
	case 1:
		currentAcceleration = 10.0f;
		playerCar->m_max_speed = 54.0f;
		break;
	case 2:
		currentAcceleration = 20.0f;
		playerCar->m_max_speed = 108.0f;
		break;
	case 3:
		currentAcceleration = 30.0f;
		playerCar->m_max_speed = 162.0f;
		break;
	case 4:
		currentAcceleration = 40.0f;
		playerCar->m_max_speed = 216.0f;
		break;
	case 5:
		currentAcceleration = 50.0f;
		playerCar->m_max_speed = 270.0f;
		break;
	case 6:
		currentAcceleration = 60.0f;
		playerCar->m_max_speed = 324.0f;
		break;
	case 7:
		currentAcceleration = 70.0f;
		playerCar->m_max_speed = 378.0f;
		break;
	default:
		break;
	}

	// Gear change
	if (input->wasKeyPressed(aie::INPUT_KEY_UP) && currentGear != maxGear)
	{
		currentGear++;
		//currentAcceleration += 10;
		//playerCar->m_max_speed += 54;
	}
	else if (input->wasKeyPressed(aie::INPUT_KEY_DOWN) && currentGear != -1)
	{
		currentGear--;
		//currentAcceleration -= 10;
		//playerCar->m_max_speed -= 54;
	}

	// Acceleration
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		playerCar->m_acceleration = currentAcceleration;
	}
	// Apply inertia to car after "accelerating"
	else if (input->isKeyUp(aie::INPUT_KEY_W) && input->isKeyUp(aie::INPUT_KEY_S) && playerCar->m_speed > 0.0f)
	{
		if (playerCar->m_speed > 0.0f)
		{
			playerCar->m_acceleration = -80.0f;
		}
		else if (playerCar->m_speed == 0.0f)
		{
			currentGear = 0;
		}
	}

	// Reverse / Slowdown / Stopping
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		playerCar->m_acceleration = -200.0f;
		if (playerCar->m_speed > 324.0f)
			currentGear = 7;
		else if (playerCar->m_speed > 270.0f && playerCar->m_speed < 324.0f)
			currentGear = 6;
		else if (playerCar->m_speed > 216.0f && playerCar->m_speed < 270.0f)
			currentGear = 5;
		else if (playerCar->m_speed > 162.0f && playerCar->m_speed < 216.0f)
			currentGear = 4;
		else if (playerCar->m_speed > 108.0f && playerCar->m_speed < 162.0f)
			currentGear = 3;
		else if (playerCar->m_speed > 54.0f && playerCar->m_speed < 108.0f)
			currentGear = 2;
		else if (playerCar->m_speed > 0.0f && playerCar->m_speed < 54.0f)
			currentGear = 1;
		else
		{
			currentGear = 0;
		}
	}
	// Apply inertia to car after "reversing"
	else if (input->isKeyUp(aie::INPUT_KEY_W) && input->isKeyUp(aie::INPUT_KEY_S) && playerCar->m_speed > 0.0f)
	{
		playerCar->m_acceleration = 80.0f;
	}
	//else if (playerCar->m_speed <= 0.0f)
	//{
	//	currentGear = 0;
	//}
	// Keep the car stopped
	else if (playerCar->m_speed > 1.3f && playerCar->m_speed < 0.0f)
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

	// If the car isn't moving, you can't turn the car
	if (playerCar->m_speed <= 0.0f)
	{
		playerCar->m_spin_speed = 0.0f;
	}

	// Drifting / Tighter turns
	if (input->isKeyDown(aie::INPUT_KEY_A) &&
		input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT) &&
		playerCar->m_speed >= 0.0f)
	{
		playerCar->m_acceleration = -50.0f;
		playerCar->m_spin_speed = 5.5f;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_D) &&
		input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT)
		&& playerCar->m_speed >= 0.0f)
	{
		playerCar->m_acceleration = -50.0f;
		playerCar->m_spin_speed = -5.5f;
	}

}
