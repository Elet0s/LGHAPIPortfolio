#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class TitleBackGround : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleBackGround();
	~TitleBackGround();

	// delete Function
	TitleBackGround(const TitleBackGround& _Other) = delete;
	TitleBackGround(TitleBackGround&& _Other) noexcept = delete;
	TitleBackGround& operator=(const TitleBackGround& _Other) = delete;
	TitleBackGround& operator=(TitleBackGround&& _Other) noexcept = delete;

protected:
	void Start();
	void Render();
	void Update();
private:
	float Width_;
	float Hight_;
	GameEngineRenderer* TitleBackGroundRender_;
};

