#include "SelectUIPanel.h"
#include <iostream>

SelectUIPanel::SelectUIPanel(Vector2i res) :
	// Create a new UIPanel  
	// by calling the super-class constructor
	UIPanel(res,
		(res.x / 10) * 2, // Start 2/10 accross
		res.y * 0.6, // from top
		(res.x / 10) * 6, // as wide as 6/10 of the resolution
		res.y * 0.2, // and as tall
		0, 255, 255, 255) // a, r, g, b
{
	m_ButtonWidth = res.x / 20;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Text.setFillColor(sf::Color(0, 255, 0, 255));
	m_Text.setString("SPACE INVADERS ++");

	// https://www.dafont.com/roboto.font
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);

	m_Text.setPosition(Vector2f(m_ButtonPadding,
		m_ButtonHeight + (m_ButtonPadding * 2)));

	m_Text.setCharacterSize(80);

	m_Subtext.setFillColor(sf::Color(0, 255, 0, 0));
	m_Subtext.setString("Press Player 1 Start Button");
	m_Subtext.setPosition(Vector2f(m_ButtonPadding, m_ButtonHeight + (m_ButtonPadding)));
	m_Subtext.setFont(m_Font);
	m_Subtext.setCharacterSize(40);

	//initialiseButtons();
}

void SelectUIPanel::initialiseButtons()
{
	// Buttons are positioned relative to the top left 
	// corner of the UI panel(m_View in UIPanel)
	addButton(m_ButtonPadding,
		m_ButtonPadding,
		m_ButtonWidth,
		m_ButtonHeight,
		0, 255, 0,
		"Play");

	addButton(m_ButtonWidth + (m_ButtonPadding * 2),
		m_ButtonPadding,
		m_ButtonWidth,
		m_ButtonHeight,
		255, 0, 0,
		"Quit");
}

void SelectUIPanel::draw(RenderWindow& window)
{
	show();
	UIPanel::draw(window);
	window.draw(m_Text);
	window.draw(m_Subtext);
}