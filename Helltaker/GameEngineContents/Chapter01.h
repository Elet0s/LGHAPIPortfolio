#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include "ChapterBackGound.h"

class GameEngineSound;
class BotUi;
class TopUi;
class LodingManager;
class ClearEvent;
class LifeCounter;
class ChapterCounter;

class Chapter01 : public GameEngineLevel
{
private:
	 int  ChapterCount_; // 카운터
	ChapterBackGound* ChapterBackGound_; // 배경화면, 타일맵관리
	GameEngineSoundPlayer ChapterBgm_; // BGM사운드
	LifeCounter* LifeCounter_;
	BotUi* BotUi_; // 움직일수있는 카운터 체크
	TopUi* TopUi_;
	LodingManager* LodingManager_; 
	ClearEvent* ClearEvent_; // 목표달성시 대화창
	ChapterCounter* ChapterCounter_;
	float ReloadTimer_;
	bool ReloadCheaker_;

public:

	Chapter01();
	~Chapter01();

	Chapter01(const Chapter01& _Other) = delete;
	Chapter01(Chapter01&& _Other) noexcept = delete;
	Chapter01& operator=(const Chapter01& _Other) = delete;
	Chapter01& operator=(Chapter01&& _Other) noexcept = delete;

	bool ChapterClear();
protected:
	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _NextLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;


};