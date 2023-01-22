#include "GameOverInputHandler.h"
#include "SoundEngine.h"
#include "WorldState.h"
#include <iostream>

int WorldState::CREDITS;


void GameOverInputHandler::handleKeyPressed(Event& event,
	RenderWindow& window)
{
	if (event.key.code == Keyboard::Escape)
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->
			SwitchScreens("Select");
	}
	else if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		if (WorldState::CREDITS > 0 && WorldState::LIVES<=0)
		{
			SoundEngine::playClick();
			WorldState::WAVE_NUMBER = 0;
			WorldState::CREDITS--;
			getPointerToScreenManagerRemoteControl()
				->loadLevelInPlayMode("level1");
		}
		else if (WorldState::LIVES<=0) {
			SoundEngine::playPlayerExplode();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num5))
	{
		SoundEngine::playShoot();
		WorldState::CREDITS++;
	}
}

void GameOverInputHandler::handleLeftClick(
	std::string& buttonInteractedWith, RenderWindow& window)
{
	if (buttonInteractedWith == "Play") {
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->
			loadLevelInPlayMode("level1");
	}

	else if (buttonInteractedWith == "Home") {
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->
			SwitchScreens("Select");
	}
}