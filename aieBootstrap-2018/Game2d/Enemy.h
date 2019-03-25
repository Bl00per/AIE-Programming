#include "Renderer2D.h"
#include "Bullet.h"
#include <vector>

class Enemy
{
public:
	Enemy();

	~Enemy();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

	std::vector<Bullet> bulletList;

protected:
	aie::Texture*		m_shipTexture2;
	aie::Texture*		m_ammo;
	float positionX = 1180;
	float positionY = 360;
	float rotation = 2; //radians
	float direction = 0;
	float PI = 3.14159;
	int screenWidth = 1280;
	int screenHeight = 720;

};

