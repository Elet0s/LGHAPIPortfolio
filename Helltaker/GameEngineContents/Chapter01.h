#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include "ChapterBackGound.h"


class GameEngineSound;
class BotUi;
class TopUi;
class LodingNext;

class Chapter01 : public GameEngineLevel
{
private:
	 int  ChapterCount_;
	ChapterBackGound* ChapterBackGound_;
	GameEngineSoundPlayer ChapterBgm_;
	BotUi* BotUi_;
	TopUi* TopUi_;
	LodingNext* LodingNext_;

public:

	Chapter01();
	~Chapter01();

	Chapter01(const Chapter01& _Other) = delete;
	Chapter01(Chapter01&& _Other) noexcept = delete;
	Chapter01& operator=(const Chapter01& _Other) = delete;
	Chapter01& operator=(Chapter01&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _NextLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;


};