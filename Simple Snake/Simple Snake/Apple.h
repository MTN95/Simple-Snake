#pragma once
#include "common.h"

class Apple {
public:
	unsigned x;
	unsigned y;

	Apple() {
		this->respawn();
	}

	void respawn() {
		this->x = 1 + rand() % (CELL_WIDTH - 2);
		this->y = 1 + rand() % (CELL_HEIGHT - 2);
	}
};