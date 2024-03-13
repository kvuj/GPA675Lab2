#pragma once
#include "SnakeGameState.h"

class ConfigurationState : public SnakeGameState
{
public:
	ConfigurationState(PressedKeys const& registeredKeys);
	~ConfigurationState() = default;
	void tic(float elapsedTime) override;
	void handleKeyPress() override;
	void handleKeyRelease() override;
	void exiting() override;
	void draw(QPainter& painter) override;
	void changeArenaSize(int x, int y);
};

