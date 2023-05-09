#pragma once
class Monster
{
public:
	Monster();
	~Monster();


	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;
protected:

private:

};