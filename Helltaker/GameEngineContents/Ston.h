#pragma once
class Ston
{
public:
	Ston();
	~Ston();


	Ston(const Ston& _Other) = delete;
	Ston(Ston&& _Other) noexcept = delete;
	Ston& operator=(const Ston& _Other) = delete;
	Ston& operator=(Ston&& _Other) noexcept = delete;
protected:

private:

};