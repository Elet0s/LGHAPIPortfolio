#pragma once
#include<Windows.h>
#include<string>
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

protected:

private:
	HWND hWnd_; // ���ʿ��� ���ڰ��� ��� �ִ� ���� ���� �߰��� ���� ������� ����� ������� �����ϱ�?
	HINSTANCE hInst_;
	std::string Title_;

	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

};