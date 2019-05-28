#include "collider.h"


collider::collider(shape a_shape) : m_shape(a_shape)
{

}


const collider::shape collider::get_shape() const
{
	return m_shape;
}

