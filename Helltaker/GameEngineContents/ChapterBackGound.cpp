#include"ChapterBackGound.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>


ChapterBackGound::ChapterBackGound()
	:ChapterBackGoundRender_(nullptr)
	, ChapterBackGoundTileMap_(this)// 1.Ÿ�ϸ� ���� �� actor�� �ʿ��ѵ� ��׶��忡�� �����ϴ� ���̴ϱ� ��׶��忡�� ���͸� ������ �־���Ѵ�. �׷��⿡ �θ�class�� actordml �����ڸ� �޾Ƽ� ȣ�� ���ַ��� thisȣ��  2.������ ������ ���⼭ �θ�Ŭ�����ڷ��� �ϳ��� �����������
{
	// ���� ������ ������ is a <-actor
	// ���� ����� ���� has a <-TileMap
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
