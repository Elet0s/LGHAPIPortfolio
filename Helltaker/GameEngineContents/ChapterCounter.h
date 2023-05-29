#pragma once
#include <GameEngine/GameEngineActor.h>
#include<GameEngine/GameEngineFont.h>

class ChapterCounter : public GameEngineActor
{
public:
	GameEngineFont ChapterFont_;
	int ChapterPoint_;
	std::string ChapterPointStr_;
	bool SetEnter_;
public:
	ChapterCounter();
	~ChapterCounter();

	ChapterCounter(const ChapterCounter& _Other) = delete;
	ChapterCounter(ChapterCounter&& _Other) noexcept = delete;
	ChapterCounter& operator=(const ChapterCounter& _Other) = delete;
	ChapterCounter& operator=(ChapterCounter&& _Other) noexcept = delete;

	void SetChapterPoint(int _ChapterPoint);
	void Start() override;
protected:
	void Render() override;
private:

};