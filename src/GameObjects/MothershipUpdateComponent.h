#pragma once
#include "UpdateComponent.h"
#include "TransformComponent.h"
#include "GameObjectSharer.h"
#include "RectColliderComponent.h"
#include "GameObject.h"

class MothershipUpdateComponent : public UpdateComponent
{
private:
	string m_SpecificType = "mothership";
	shared_ptr<TransformComponent> m_TC;
	shared_ptr <RectColliderComponent> m_RCC;

	float m_Speed = 20.0f;

	bool m_MovingRight = true;

public:
	string Component::getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self)
	{
		// Where is the mothership
		m_TC = static_pointer_cast<TransformComponent>(self->getComponentByTypeAndSpecificType("transform", "transform"));
		m_RCC = static_pointer_cast<RectColliderComponent>(self->getComponentByTypeAndSpecificType("collider", "rect"));
	}

	/****************************************************
	*****************************************************
	From UpdateComponent
	*****************************************************
	*****************************************************/

	void update(float fps) override;
};