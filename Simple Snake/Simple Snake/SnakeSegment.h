#pragma once


class SnakeSegment {
public:
	unsigned x;
	unsigned y;

	SnakeSegment(unsigned x, unsigned y) {
		this->x = x;
		this->y = y;
	}
};