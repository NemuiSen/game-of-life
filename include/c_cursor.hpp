#pragma once
#include <stdafx.h>

struct C_Cursor: public sf::Drawable
{
	C_Cursor(float c_size, float o_size);
	~C_Cursor();
	void tick();
	void setPos(int x, int y);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::RectangleShape *m_cursor;
};