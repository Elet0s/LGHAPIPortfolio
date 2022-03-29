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
	// ȸ�縶�� �ٸ����ְ�����
	// Actor�� ��������?

	CreateActor<TitleBackGround>(0);

	CreateActor<TitleLogo>(1);

}

void TitleLevel::Update()
{
	// GameEngine::GlobalEngine().ChangeLevel("Play");
}