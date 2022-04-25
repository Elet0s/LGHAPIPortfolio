#pragma once
#include <GameEngine/GameEngineActor.h>

class BeelFly : public GameEngineActor
{
public:
	BeelFly();
	~BeelFly();

	BeelFly(const BeelFly& _Other) = delete;
	BeelFly(BeelFly&& _Other) noexcept = delete;
	BeelFly& operator=(const BeelFly& _Other) = delete;
	BeelFly& operator=(BeelFly&& _Other) noexcept = delete;

protected:
	void Start();
	void Render();
private:
	float Width_;
	float Hight_;
	GameEngineRenderer* BeelFlyRender_;

};