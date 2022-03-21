#pragma once
class Lock
{
private:
	// constrcuter destructer
	Lock();
	~Lock();

	// delete Function
	Lock(const Lock& _Other) = delete;
	Lock(Lock&& _Other) noexcept = delete;
	Lock& operator=(const Lock& _Other) = delete;
	Lock& operator=(Lock&& _Other) noexcept = delete;
};