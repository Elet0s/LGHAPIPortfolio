#pragma once
class MBotUi
{
public:
	MBotUi();
	~MBotUi();


	MBotUi(const MBotUi& _Other) = delete;
	MBotUi(MBotUi&& _Other) noexcept = delete;
	MBotUi& operator=(const MBotUi& _Other) = delete;
	MBotUi& operator=(MBotUi&& _Other) noexcept = delete;
protected:

private:

};