#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"

enum class ORDER
{
	TitleBackGround,
	TitleLogo,
};
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

	CreateActor<TitleBackGround>("TitleLogo", (int)ORDER::TitleBackGround);

	CreateActor<TitleLogo>("TitleLogo", (int)ORDER::TitleLogo);

}

void TitleLevel::Update()
{
	// GameEngine::GlobalEngine().ChangeLevel("Play");
}