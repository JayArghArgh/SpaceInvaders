#include "MothershipUpdateComponent.h"
#include "SoundEngine.h"

void MothershipUpdateComponent::update(float fps)
{
	m_TC->getLocation().x += m_Speed * fps;

	// Update the collider
	m_RCC->setOrMoveCollider(m_TC->getLocation().x,
		m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);
}
