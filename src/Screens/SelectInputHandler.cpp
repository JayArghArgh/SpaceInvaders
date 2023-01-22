#include "SelectInputHandler.h"
#include "SoundEngine.h"
#include "WorldState.h"
#include <iostream>

int WorldState::WAVE_NUMBER;
// int WorldState::CREDITS;

void SelectInputHandler::handleKeyPressed(
	Event& event, RenderWindow& window)
{
	// Quit the game
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		if (WorldState::CREDITS > 0)
		{
			SoundEngine::playClick();
			WorldState::WAVE_NUMBER = 0;
			WorldState::CREDITS--;
			getPointerToScreenManagerRemoteControl()
				->loadLevelInPlayMode("level1");
		}
		else {
			SoundEngine::playPlayerExplode();
		}
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num5))
	{
		SoundEngine::playShoot();
		WorldState::CREDITS++;
	}
}

void SelectInputHandler::handleLeftClick(
	std::string& buttonInteractedWith, RenderWindow& window)
{
	if (buttonInteractedWith == "Play") {
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;

		getPointerToScreenManagerRemoteControl()
			->loadLevelInPlayMode("level1");
	}

	if (buttonInteractedWith == "Quit") {
		SoundEngine::playClick();
		window.close();
	}
}
