#pragma once
#include <GameEngine/GameEngine.h>

class Helltaker : public GameEngine
{
public:

	Helltaker();
	~Helltaker();

	Helltaker(const Helltaker& _Other) = delete;
	Helltaker(Helltaker&& _Other) noexcept = delete;
	Helltaker& operator=(const Helltaker& _Other) = delete;
	Helltaker& operator=(Helltaker&& _Other) noexcept = delete;

	void GameInit() override;
	void GameLoop() override;
	void GameEnd() override;

protected:

private:
	float Chapter_;
};

