#pragma once
class KeyEx
{
public:
	KeyEx();
	~KeyEx();


	KeyEx(const KeyEx& _Other) = delete;
	KeyEx(KeyEx&& _Other) noexcept = delete;
	KeyEx& operator=(const KeyEx& _Other) = delete;
	KeyEx& operator=(KeyEx&& _Other) noexcept = delete;
protected:

private:

};