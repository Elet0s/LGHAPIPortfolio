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
	// ȸ�縶�� �ٸ����ְ�����
	// Actor�� ��������?

	CreateActor<TitleBackGround>("TitleLogo", 0);

	CreateActor<TitleLogo>("TitleLogo", 1);

}

void TitleLevel::Update()
{
	// GameEngine::GlobalEngine().ChangeLevel("Play");
}