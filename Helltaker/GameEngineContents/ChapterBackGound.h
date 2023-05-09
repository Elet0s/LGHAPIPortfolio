#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>

class GameEngineRenderer;
class ChapterBackGound : public GameEngineActor
{
public:
	ChapterBackGound();
	~ChapterBackGound();


	ChapterBackGound(const ChapterBackGound& _Other) = delete;
	ChapterBackGound(ChapterBackGound&& _Other) noexcept = delete;
	ChapterBackGound& operator=(const ChapterBackGound& _Other) = delete;
	ChapterBackGound& operator=(ChapterBackGound&& _Other) noexcept = delete;

	void Start() override;
protected:
	void Update() override;
	void SetChaterLevel(int _CurChapterLevel);

private: 
	int CurChapterLevel_;
	float4 ChapterBackGoundScale_;
	GameEngineRenderer* BackGoundRender_;
	
public:
	GameEngineRendererTileMap ChapterBackGoundTileMap_;
};