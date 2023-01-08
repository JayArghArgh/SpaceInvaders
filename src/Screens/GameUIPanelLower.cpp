#include "GameUIPanelLower.h"
#include <sstream>
#include "WorldState.h"

// int WorldState::SCORE;
int WorldState::LIVES;

GameUIPanelLower::GameUIPanelLower(Vector2i res) :
	UIPanel(res,
		res.x / 3,
		(res.y * 0.9),  // 90% of screen
		res.x / 3, // 1/3 width screen
		res.y * 0.1,  // 10% of screen
		50, 255, 255, 255) // a, r, g, b 
{

	//m_Text.setString("Score: 0 Lives: 3 Wave: 1");
	m_Text.setString("Lives: 3");
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(Vector2f(15, 15));
	m_Text.setCharacterSize(25);
}

void GameUIPanelLower::draw(RenderWindow& window)
{

	UIPanel::draw(window);

	std::stringstream ss;

	ss << "LIVES "
		<< WorldState::LIVES
		<< " CREDIT 00"
		;

	m_Text.setString(ss.str());

	window.draw(m_Text);
}