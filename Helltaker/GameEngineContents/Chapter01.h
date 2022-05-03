#pragma once
#include <GameEngine/GameEngineLevel.h>
#include<vector>
#include <GameEngineBase/GameEngineSound.h>

class Player;
class ChapterBackGound;
class BotUi;
class TopUi;
class Loding;
class LodingNext;
class Monster;
class Helper;
class Chapter01 : public GameEngineLevel
{
private:
	 int  ChapterCount_;
	Player* Player_;
	ChapterBackGound* ChapterBackGound_;
	BotUi* BotUi_;
	TopUi* TopUi_;
	Loding* Loding_;
	LodingNext* LodingNext_;
	GameEngineSoundPlayer ChpterBgmPlayer_;
	
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