#pragma once
#include<GameEngine/GameEngineLevel.h>

class MenuLevel : public  GameEngineLevel
{
public:
	MenuLevel();
	~MenuLevel();


	MenuLevel(const MenuLevel& _Other) = delete;
	MenuLevel(MenuLevel&& _Other) noexcept = delete;
	MenuLevel& operator=(const MenuLevel& _Other) = delete;
	MenuLevel& operator=(MenuLevel&& _Other) noexcept = delete;
protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
private:

};