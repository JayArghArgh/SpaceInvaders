#pragma once
#include "Component.h"
#include "GraphicsComponent.h"
#include <string>

class AnimatedGraphicsComponent : public GraphicsComponent {
private:
	sf::Sprite m_Sprite;
	string m_SpecificType = "animated";
	vector<string> m_SpriteBitmaps;

	// Create a static variable to store the sprite index
	static int spriteIndex;

	// Create a static variable to store the frame count
	static int frameCount;

public:

	/****************************************************
	*****************************************************
	From Component interface base class
	*****************************************************
	*****************************************************/

	string Component::getSpecificType() {
		return m_SpecificType;
	}

	void Component::start(
		GameObjectSharer* gos, GameObject* self) {
	}

	/****************************************************
	*****************************************************
	From GraphicsComponent
	*****************************************************
	*****************************************************/

	void draw(
		RenderWindow& window,
		shared_ptr<TransformComponent> t
	) override;

	void initialiseGraphics(
		string bitmapName,
		Vector2f objectSize) override;
};
