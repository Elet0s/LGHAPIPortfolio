#pragma once
#include<GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>

class MenuLevel : public  GameEngineLevel
{
public:
	MenuLevel();
	~MenuLevel();

	GameEngineSoundPlayer BgmPlayer;
	MenuLevel(const MenuLevel& _Other) = delete;
	MenuLevel(MenuLevel&& _Other) noexcept = delete;
	MenuLevel& operator=(const MenuLevel& _Other) = delete;
	MenuLevel& operator=(MenuLevel&& _Other) noexcept = delete;
protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _NextLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;
private:

};