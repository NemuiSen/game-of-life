#pragma once
#include <stdafx.h>
#include <cellog.hpp>

struct DrawCel: public sf::Drawable
{
	DrawCel(uint32_t w, uint32_t h);
	~DrawCel();
	void update();
	void render();
	void click(uint32_t x, uint32_t y);
	void clear();
	void tick();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool play;
	sf::Texture *_texture;
	sf::Sprite *_sprite;
	sf::Clock clock;

	CelLog *_cellog;
};
