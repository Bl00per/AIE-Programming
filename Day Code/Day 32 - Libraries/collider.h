#pragma once
class collider
{
public:
	enum class shape : char
	{
		none = 0,
		circle,
		aabb,
		line
	};

	const shape get_shape() const;

protected:
	shape m_shape = shape::none;
	collider(shape a_shape);

private:
	collider() = delete;
};

