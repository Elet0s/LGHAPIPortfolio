#pragma once
class StartEvent
{
private:
	// constrcuter destructer
	StartEvent();
	~StartEvent();

	// delete Function
	StartEvent(const StartEvent& _Other) = delete;
	StartEvent(StartEvent&& _Other) noexcept = delete;
	StartEvent& operator=(const StartEvent& _Other) = delete;
	StartEvent& operator=(StartEvent&& _Other) noexcept = delete;
};