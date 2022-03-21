#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	// 회사마다 다를수있겠지만
	// Actor를 만들어야죠?

	CreateActor<TitleBackGround>("TitleLogo", 0);

	CreateActor<TitleLogo>("TitleLogo", 1);

}

void TitleLevel::Update()
{
	// GameEngine::GlobalEngine().ChangeLevel("Play");
}