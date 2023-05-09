#pragma once
class Lock
{
public:
	Lock();
	~Lock();


	Lock(const Lock& _Other) = delete;
	Lock(Lock&& _Other) noexcept = delete;
	Lock& operator=(const Lock& _Other) = delete;
	Lock& operator=(Lock&& _Other) noexcept = delete;
protected:

private:

};