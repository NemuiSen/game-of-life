#include <game.hpp>

Game::~Game()
{
	delete _window;
	_window = nullptr;

	delete _dc;
	_dc = nullptr;

	delete _cursor;
	_cursor = nullptr;
}

Game::Game()
{
	size = 16;
	uint32_t w = 1280 / size;
	uint32_t h = 720 / size;

	_window = new sf::RenderWindow({w*size, h*size}, "GameOfLife");
	sf::Vector2f wv = _window->getView().getSize() / (float)size;
	_window->setView({wv / 2.f, wv});
	_window->setMouseCursorVisible(false);

	_dc = new DrawCel(w, h);
	_cursor = new C_Cursor(1.f, 0.3f);
}

void Game::_events()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		{
			_window->close();
		}
		if (event.type == sf::Event::Resized)
		{
			sf::Vector2f wv = (sf::Vector2f)(_window->getSize() / size);
			_window->setView({wv / 2.f, wv});
			
		}
		if (event.type == sf::Event::MouseMoved)
		{
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(*_window);

			_cursor->setPos
			(
				ceil(mouse_pos.x / size),
				ceil(mouse_pos.y / size)
			);
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			_dc->click
			(
				ceil(event.mouseButton.x / size),
				ceil(event.mouseButton.y / size)
			);
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
		{
			_dc->tick();
			_cursor->tick();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
		{
			_dc->clear();
		}
	}
}

void Game::_update()
{
	_dc->update();
}

void Game::_render()
{
	_window->clear({200, 200, 200});

	_dc->render();
	_window->draw(*_dc);

	_window->draw(*_cursor);

	_window->display();
}

int Game::run()
{
	while (_window->isOpen())
	{
		_events();
		_update();
		_render();
	}

	return 0;
}
