#pragma once
#include<crtdbg.h>//릭체크
#include<string>//자료구조를 위한 참조
#include<assert.h>//터트리는 것
#include<Windows.h>// 윈도우명령어 쓸 것


class GameEngineDebug
{
public:
	static void LeekCheakOn(); //객체를 안만들고 전역으로 만들어버릴 것이다. 객체없이 쓸거니까.
	//static void MsgBoxAssert(const std::string&); 매크로랑 중복구현x
	//자료구조 string 문자열 말하는게 아님, vector와 흡사한 구조 시퀸스배열구조 오로지 글자를 위한 자료구조 문자열을위한 연산자 정의가 있음 , const& 주소를 써서 메모리 아끼고 내용을 바꾸지 않을 것이기 때문에
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