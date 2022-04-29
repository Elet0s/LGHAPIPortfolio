#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>
class ChapterBackGound : public GameEngineActor
{
public:
	ChapterBackGound();
	~ChapterBackGound();


	ChapterBackGound(const ChapterBackGound& _Other) = delete;
	ChapterBackGound(ChapterBackGound&& _Other) noexcept = delete;
	ChapterBackGound& operator=(const ChapterBackGound& _Other) = delete;
	ChapterBackGound& operator=(ChapterBackGound&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Render() override;

private: 
	GameEngineRendererTileMap ChapterBackGoundTileMap_;
public:
	GameEngineRenderer* ChapterBackGoundRender_;
};