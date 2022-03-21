#pragma once
#include<Windows.h>
#include<string>
#include"GameEngineMath.h"


class GameEngineWindow
{
private://�������� �̱��� ������� �̱��� - ��ü�� �ν��Ͻ��� ���ϳ��� �����ϴ� ���� private ����ϴ� ������ ����ȭ���� �� �ϳ��� ���� ���̱� ������ ������������ �ϳ����� ���������� ��� ���������� ȥ�ڸ� �˰� ���� ��
	static GameEngineWindow* Inst_;	

public:
	inline static GameEngineWindow& GetInst()//������ ������ �Լ��̱� ������ ȣ���ϴ� �ð��� �Ʊ���� inline
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
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title); //������ ����� �Լ�
	void ShowGameWindow();//������ �׷��ִ� �Լ�
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
	HWND hWnd_; // ���ʿ��� ���ڰ��� ��� �ִ� ���� ���� �߰��� ���� ������� ����� ������� �����ϱ�?
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