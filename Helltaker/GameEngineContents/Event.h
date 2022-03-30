#pragma once
class Event
{
private:
	// constrcuter destructer
	Event();
	~Event();

	// delete Function
	Event(const Event& _Other) = delete;
	Event(Event&& _Other) noexcept = delete;
	Event& operator=(const Event& _Other) = delete;
	Event& operator=(Event&& _Other) noexcept = delete;
};