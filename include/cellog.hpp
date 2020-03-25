#pragma once
#include <stdafx.h>

struct CelLog
{
	CelLog(uint32_t w, uint32_t h);
	~CelLog();
	void update();
	void clear();
	void click(uint32_t x, uint32_t y);
	std::vector<bool> get_celList() const;
private:
	inline uint32_t pos2_index(uint32_t x, uint32_t y);
	inline sf::Vector2u index2_pos(uint32_t index);

	std::vector<bool> celList;
	sf::Vector2u canvas;
};
