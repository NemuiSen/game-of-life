#include <drawcel.hpp>

DrawCel::~DrawCel()
{
	delete _texture;
	_texture = nullptr;

	delete _sprite;
	_sprite = nullptr;

	delete _cellog;
	_cellog = nullptr;
}

DrawCel::DrawCel(uint32_t w, uint32_t h)
:	play(false)
{
	_cellog = new CelLog(w, h);
	_texture = new sf::Texture;
	_texture->create(w, h);
	_sprite = new sf::Sprite(*_texture);
}

void DrawCel::update()
{
	if (play && clock.getElapsedTime() > sf::seconds(1.0/15.0))
	{
		_cellog->update();
		clock.restart();
	}
}

void DrawCel::render()
{
	size_t size = _cellog->get_celList().size();
	sf::Uint8 *pixels = new sf::Uint8[size*4];

	for (uint32_t i = 0; i < size*4; i+=4)
	{
		sf::Uint8 tp = _cellog->get_celList()[i/4] == false ? 0 : 255;

		pixels[ i ] = tp;  //r
		pixels[i+1] = tp;  //g
		pixels[i+2] = tp;  //b
		pixels[i+3] = 255; //a
	}

	if (_texture->copyToImage().getPixelsPtr() != pixels)
	{
		_texture->update(pixels);
	}

	delete[] pixels;
	pixels = nullptr;
}

void DrawCel::click(uint32_t x, uint32_t y)
{
	_cellog->click(x, y);
}

void DrawCel::clear()
{
	_cellog->clear();
}

void DrawCel::tick()
{
	play = !play;
}

void DrawCel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*_sprite, states);
}