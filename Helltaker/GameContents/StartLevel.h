#pragma once
class StartLevel
{
private:
	// constrcuter destructer
	StartLevel();
	~StartLevel();

	// delete Function
	StartLevel(const StartLevel& _Other) = delete;
	StartLevel(StartLevel&& _Other) noexcept = delete;
	StartLevel& operator=(const StartLevel& _Other) = delete;
	StartLevel& operator=(StartLevel&& _Other) noexcept = delete;
};