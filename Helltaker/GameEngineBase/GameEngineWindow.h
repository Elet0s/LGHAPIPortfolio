#pragma once
#include<Windows.h>
#include<string>
#include"GameEngineMath.h"


class GameEngineWindow
{
private://포인터형 싱글톤 만들것임 싱글톤 - 객체의 인스턴스가 단하나만 생성하는 구조 private 사용하는 이유는 게임화면은 단 하나만 만들 것이기 때문임 전역설정으로 하나만들어서 끝날때까지 계속 쓸것이지만 혼자만 알고 있을 것
	static GameEngineWindow* Inst_;	

public:
	inline static GameEngineWindow& GetInst()//실행이 간단한 함수이기 때문에 호출하는 시간이 아까워서 inline
	{
		return *Inst_;
	}

	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
public:
	void RegClass(HINSTANCE _hIsnt);
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title); //윈도우 만드는 함수
	void ShowGameWindow();//윈도우 그려주는 함수
	void MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)());
	void SetWindowScaleAndPosition(float4 _Pos, float4 _Scale);
	void Off();

	static inline HDC GetHDC()
	{
		return Inst_->HDC_;
	}

	static inline float4 GetScale()
	{
		return Inst_->Scale_;
	}

protected:

private:
	HWND hWnd_; // 안쪽에서 인자값을 들고 있는 것이 좋음 중간에 설정 변경등의 기능을 만들수도 있으니까?
	HINSTANCE hInst_;
	std::string Title_;
	bool WindowOn_;
	HDC HDC_;
	float4 Scale_;

	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

};