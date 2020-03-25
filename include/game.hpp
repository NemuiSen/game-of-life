#pragma once
#include <drawcel.hpp>
#include <c_cursor.hpp>

struct Game
{
	Game();
	~Game();
	int run();
private:
	void _events();
	void _update();
	void _render();

	uint32_t size;

	sf::RenderWindow *_window;
	DrawCel *_dc;
	C_Cursor *_cursor;
};
