#pragma once
#include<crtdbg.h>//��üũ
#include<string>//�ڷᱸ���� ���� ����
#include<assert.h>//��Ʈ���� ��
#include<Windows.h>// �������ɾ� �� ��


class GameEngineDebug
{
public:
	static void LeekCheakOn(); //��ü�� �ȸ���� �������� �������� ���̴�. ��ü���� ���Ŵϱ�.
	//static void MsgBoxAssert(const std::string&); ��ũ�ζ� �ߺ�����x
	//�ڷᱸ�� string ���ڿ� ���ϴ°� �ƴ�, vector�� ����� ���� �������迭���� ������ ���ڸ� ���� �ڷᱸ�� ���ڿ������� ������ ���ǰ� ���� , const& �ּҸ� �Ἥ �޸� �Ƴ��� ������ �ٲ��� ���� ���̱� ������
protected:

private:
	// constrcuter destructer
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;
};

#define MsgBoxAssert(Text) MessageBeep(0);\
MessageBoxA(nullptr, Text, "Error", MB_OK);\
assert(false);