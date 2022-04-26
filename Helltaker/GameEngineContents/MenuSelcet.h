#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuSelcet : public GameEngineActor
{
public:
	MenuSelcet();
	~MenuSelcet();

	MenuSelcet(const MenuSelcet& _Other) = delete;
	MenuSelcet(MenuSelcet&& _Other) noexcept = delete;
	MenuSelcet& operator=(const MenuSelcet& _Other) = delete;
	MenuSelcet& operator=(MenuSelcet&& _Other) noexcept = delete;

protected:
	void Start();
	void Update();
private:
	GameEngineRenderer* MenuSelcetRenderer01_;
	GameEngineRenderer* MenuSelcetRenderer02_;
	GameEngineRenderer* MenuSelcetRenderer03_;
	float MenuSelcetCount_;

public:
	inline float GetMenuSelcetCount()
	{
		return MenuSelcetCount_;
	}
};