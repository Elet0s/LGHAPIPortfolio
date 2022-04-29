#pragma once
#include <GameEngine/GameEngineLevel.h>
class Player;
class ChapterBackGound;
class BotUI;
class Loding;
class LodingNext;
class Chapter01 : public GameEngineLevel
{
private:
	Player* Player_;
	ChapterBackGound* ChapterBackGound_;
	BotUI* BotUI_;
	Loding* Loding_;
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