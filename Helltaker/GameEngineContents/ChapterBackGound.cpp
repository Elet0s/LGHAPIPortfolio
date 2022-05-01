#include"ChapterBackGound.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>


ChapterBackGound::ChapterBackGound()
	:ChapterBackGoundRender_(nullptr)
	, ChapterBackGoundTileMap_(this)// 1.타일맵 만들 때 actor가 필요한데 백그라운드에서 생성하는 것이니까 백그라운드에서 엑터를 가지고 있어야한다. 그렇기에 부모class인 actordml 생성자를 받아서 호출 해주려고 this호출  2.보이진 않지만 여기서 부모클래스자료형 하나가 만들어져있음
{
	// 내가 가지고 있으니 is a <-actor
	// 내가 줘야할 곳은 has a <-TileMap
}
ChapterBackGound::~ChapterBackGound()
{

}

void ChapterBackGound::Start()
{
	ChapterBackGoundRender_ = CreateRenderer();
}

void ChapterBackGound::Render()
{
}
