#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuTopUi : public GameEngineActor
{
public:
	MenuTopUi();
	~MenuTopUi();

	MenuTopUi(const MenuTopUi& _Other) = delete;
	MenuTopUi(MenuTopUi&& _Other) noexcept = delete;
	MenuTopUi& operator=(const MenuTopUi& _Other) = delete;
	MenuTopUi& operator=(MenuTopUi&& _Other) noexcept = delete;

protected:
	void Start();
	void Render();
	void Update();
private:
	float Width_;
	float Hight_;
	float Speed_;
	GameEngineRenderer* MenuTopUiRender_;

};