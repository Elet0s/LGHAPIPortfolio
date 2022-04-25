#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuText001 : public GameEngineActor
{
public:
	MenuText001();
	~MenuText001();

	MenuText001(const MenuText001& _Other) = delete;
	MenuText001(MenuText001&& _Other) noexcept = delete;
	MenuText001& operator=(const MenuText001& _Other) = delete;
	MenuText001& operator=(MenuText001&& _Other) noexcept = delete;

protected:
	void Start();
	void Render();
private:
	float Width_;
	float Hight_;
	GameEngineRenderer* MenuTextRenderer001_;

};