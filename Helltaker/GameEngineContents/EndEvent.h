#pragma once
class EndEvent
{
private:
	// constrcuter destructer
	EndEvent();
	~EndEvent();

	// delete Function
	EndEvent(const EndEvent& _Other) = delete;
	EndEvent(EndEvent&& _Other) noexcept = delete;
	EndEvent& operator=(const EndEvent& _Other) = delete;
	EndEvent& operator=(EndEvent&& _Other) noexcept = delete;
};