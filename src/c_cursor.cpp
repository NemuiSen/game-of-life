#include <c_cursor.hpp>

C_Cursor::~C_Cursor() { delete m_cursor; m_cursor = nullptr; }

C_Cursor::C_Cursor(float c_size, float o_size)
{
	m_cursor = new sf::RectangleShape({c_size, c_size});
	m_cursor->setFillColor(sf::Color::Transparent);
	m_cursor->setOutlineThickness(o_size);
	m_cursor->setOutlineColor(sf::Color::Red);
}

void C_Cursor::setPos(int x, int y)
{
	m_cursor->setPosition(x, y);
}

void C_Cursor::tick()
{
	if (m_cursor->getOutlineColor() == sf::Color::Red)
		m_cursor->setOutlineColor(sf::Color::Yellow);
	else
		m_cursor->setOutlineColor(sf::Color::Red);
}

void C_Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*m_cursor, states);
}
