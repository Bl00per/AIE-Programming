#pragma once

class Powerup
{
public:
	Powerup();
	Powerup(const char name[30], float health, float attack, float defence);
	~Powerup();

	char* getName();
	float getHealthMultiplier();
	float getAttackMultiplier();
	float getDefenceMultiplier();

	void setName(const char* pStr);
	void setHealthMultiplier(float health) { m_healthMultiplier = health; }
	void setAttackMultiplier(float attack) { m_attackMultiplier = attack; }
	void setDefenceMultiplier(float defence) { m_defenceMultiplier = defence; }

	static bool compare(const Powerup* p1, const Powerup* p2);

private:
	char m_name[30];

	float m_healthMultiplier;
	float m_attackMultiplier;
	float m_defenceMultiplier;
};

