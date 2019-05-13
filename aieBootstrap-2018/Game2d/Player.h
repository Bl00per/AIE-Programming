#include "Renderer2D.h"
#include "Bullet.h"
#include <vector>

class Player
{
public:
	Player();

	~Player();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

	std::vector<Bullet> bulletList;

	void setShipRadius(float a_radius);
	float getShipRadius() const;

	float getPlayerPosX();
	float getPlayerPosY();

protected:
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_ammo;
	aie::Font*			m_font;
	float positionX = 640;
	float positionY = 360;
	float rotation = 0; //radians
	float direction = 0;
	float PI = 3.14159;
	float m_radius = 20.0f;
	int screenWidth = 1280;
	int screenHeight = 720;

	// Ammo UI
	int ammo_count = 10;
	int across_sprite = 0;
	int down_sprite = 0;
	bool is_reloading = false;
};

