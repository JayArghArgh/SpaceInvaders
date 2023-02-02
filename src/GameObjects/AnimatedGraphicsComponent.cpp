#include "AnimatedGraphicsComponent.h"
#include "BitmapStore.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void AnimatedGraphicsComponent::initialiseGraphics(
	string bitmapName,
	Vector2f objectSize
)
{
	// Store all the different sprite bitmaps in a vector
	m_SpriteBitmaps = { bitmapName + "_1.png", bitmapName + "_2.png" };
	for (auto& bmp : m_SpriteBitmaps)
	{
		BitmapStore::addBitmap("graphics/" + bmp);
	}
	m_Sprite.setTexture(BitmapStore::getBitmap("graphics/" + m_SpriteBitmaps[0]));

	auto textureSize = m_Sprite.getTexture()->getSize();
	m_Sprite.setScale(float(objectSize.x) / textureSize.x,
		float(objectSize.y) / textureSize.y);
	m_Sprite.setColor(sf::Color(255, 0, 0));

}

void AnimatedGraphicsComponent::draw(
	RenderWindow& window,
	shared_ptr<TransformComponent> t
)
{
	static int spriteIndex = 0;
	static auto start = std::chrono::high_resolution_clock::now();

	// Change the sprite every 2 seconds
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	if (elapsed >= 1)
	{
		start = std::chrono::high_resolution_clock::now();
		spriteIndex = (spriteIndex + 1) % 2;
		m_Sprite.setTexture(BitmapStore::getBitmap("graphics/" + m_SpriteBitmaps[spriteIndex]));
	}

	m_Sprite.setPosition(t->getLocation());
	window.draw(m_Sprite);
}
