#include "AnimatedGraphicsComponent.h"
#include "BitmapStore.h"
#include <iostream>
#include <vector>

int AnimatedGraphicsComponent::spriteIndex = 0;
int AnimatedGraphicsComponent::frameCount = 0;

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
) {
	const int animation_frame_count = 6400;
	const float frame_time = 1.f / 30;

	std::cout << "frameCount: " << frameCount << std::endl;
	std::cout << "spriteIndex: " << spriteIndex << std::endl;

	sf::Clock clock;
	float elapsed = clock.restart().asSeconds();

	frameCount += elapsed / frame_time;

	// Change the sprite every animation_frame_count frames
	if (frameCount >= animation_frame_count)
	{
		frameCount = 0;
		spriteIndex = (spriteIndex + 1) % 2;
	}

	m_Sprite.setTexture(BitmapStore::getBitmap("graphics/" + m_SpriteBitmaps[spriteIndex]));
	m_Sprite.setPosition(t->getLocation());
	window.draw(m_Sprite);

	bool disp_text = false;

	if (disp_text)
	{
		Text text;
		Font myFont;
		myFont.loadFromFile("fonts/Roboto-Bold.ttf");

		text.setFont(myFont);
		text.setString("frameCount: " + std::to_string(frameCount) + "\nspriteIndex: " + std::to_string(spriteIndex));
		text.setCharacterSize(5);
		text.setFillColor(Color::White);
		text.setPosition(10, 10);
		window.draw(text);
	}
	frameCount++;
}