#pragma once
class MenuBotUI
{
private:
	// constrcuter destructer
	MenuBotUI();
	~MenuBotUI();

	// delete Function
	MenuBotUI(const MenuBotUI& _Other) = delete;
	MenuBotUI(MenuBotUI&& _Other) noexcept = delete;
	MenuBotUI& operator=(const MenuBotUI& _Other) = delete;
	MenuBotUI& operator=(MenuBotUI&& _Other) noexcept = delete;
};