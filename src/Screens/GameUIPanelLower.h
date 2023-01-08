#pragma once
#include "UIPanel.h"

class GameUIPanelLower : public UIPanel
{
public:
	GameUIPanelLower(Vector2i res);
	void draw(RenderWindow& window) override;
};