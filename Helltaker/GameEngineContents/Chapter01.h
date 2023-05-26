#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include "ChapterBackGound.h"

class GameEngineSound;
class BotUi;
class TopUi;

class LodingManager;
class ClearEvent;

class Chapter01 : public GameEngineLevel
{
private:
	 int  ChapterCount_; // ī����
	ChapterBackGound* ChapterBackGound_; // ���ȭ��, Ÿ�ϸʰ���
	GameEngineSoundPlayer ChapterBgm_; // BGM����
	BotUi* BotUi_; // �����ϼ��ִ� ī���� üũ
	TopUi* TopUi_;
	LodingManager* LodingManager_; 
	ClearEvent* ClearEvent_; // ��ǥ�޼��� ��ȭâ
	bool ChapterClear();

public:

	Chapter01();
	~Chapter01();

	Chapter01(const Chapter01& _Other) = delete;
	Chapter01(Chapter01&& _Other) noexcept = delete;
	Chapter01& operator=(const Chapter01& _Other) = delete;
	Chapter01& operator=(Chapter01&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _NextLevel) override;
	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;


};