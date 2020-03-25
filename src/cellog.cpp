#include <cellog.hpp>

CelLog::~CelLog() {}

CelLog::CelLog(uint32_t w, uint32_t h)
:	canvas(sf::Vector2u(w, h))
{
	celList.resize(w*h, false);
}

void CelLog::update()
{
	std::vector<bool> tempList = celList;

	for (uint32_t i = 0; i < tempList.size(); i++)
	{
		uint32_t count = 0;

		for (int v_x = -1; v_x < 2; v_x++)
		for (int v_y = -1; v_y < 2; v_y++)
		{
			sf::Vector2u c_p = index2_pos(i);

			int new_x = v_x + c_p.x;
			int new_y = v_y + c_p.y;

			if (new_x < 0) new_x = canvas.x-1;
			else if (new_x >= canvas.x) new_x = 0;

			if (new_y < 0) new_y = canvas.y-1;
			else if (new_y >= canvas.y) new_y = 0;

			if (celList[pos2_index(new_x, new_y)]) count++;
		}

		bool act_cel = celList[i];

		if (act_cel) count--;

		if (act_cel && (count < 2 || count > 3))
			tempList[i] = false;
		else if (!act_cel && count == 3)
			tempList[i] = true;
	}

	celList = tempList;
}

void CelLog::clear() { std::fill(celList.begin(), celList.end(), false); }

void CelLog::click(uint32_t x, uint32_t y) { celList[pos2_index(x, y)] = !celList[pos2_index(x, y)]; }

std::vector<bool> CelLog::get_celList() const { return celList; }

uint32_t CelLog::pos2_index(uint32_t x, uint32_t y) { return x + y * canvas.x; }

sf::Vector2u CelLog::index2_pos(uint32_t index)
{
	uint32_t x = index % canvas.x;
	uint32_t y = (index - x) / canvas.x;

	return sf::Vector2u(x, y);
}
