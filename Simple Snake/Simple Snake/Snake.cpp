#include "Snake.h"


Snake::Snake(SDL_Color* headColor, SDL_Color* segmentColor, SDL_Color* coinColor) {
	this->headColor = headColor;
	this->segmentColor = segmentColor;
	this->coinColor = coinColor;

	this->restart();
}

Snake::~Snake() {
	this->segments.clear();
	headColor = nullptr;
	segmentColor = nullptr;
	coinColor = nullptr;
}

void Snake::restart() {
	this->segments.clear();

	for (unsigned i = 0; i < START_LENGTH; i += 1) {
		this->addSegment(START_X - i, START_Y);
	}

	this->direction = GO_RIGHT;
	this->time = 0;
	this->timeout = 5;
	this->dead = false;

	this->coin.respawn();
}

void Snake::addSegment(unsigned x, unsigned y) {
	SnakeSegment segment(x, y);

	this->segments.push_back(segment);
}

void Snake::update() {
	if (this->dead) {
		return;
	}

	this->updateInputControls();

	this->time += 1;

	if (this->time < this->timeout) {
		return;
	}

	this->time = 0;

	if (this->checkForWallCollision() || this->checkForSelfCollision()) {
		this->dead = true;
		return;
	}

	if (this->checkForCoinCollision()) {
		this->coin.respawn();
	}
	else {
		this->segments.pop_back();
	}

	this->moveSnake();
}

void Snake::updateInputControls() {
	const Uint8* keys = SDL_GetKeyboardState(nullptr);

	if (keys[SDL_SCANCODE_UP] && this->direction != GO_DOWN) {
		this->direction = GO_UP;
	}
	else if (keys[SDL_SCANCODE_DOWN] && this->direction != GO_UP) {
		this->direction = GO_DOWN;
	}
	else if (keys[SDL_SCANCODE_LEFT] && this->direction != GO_RIGHT) {
		this->direction = GO_LEFT;
	}
	else if (keys[SDL_SCANCODE_RIGHT] && this->direction != GO_LEFT) {
		this->direction = GO_RIGHT;
	}
}

bool Snake::checkForWallCollision() {
	unsigned headX = this->segments[0].x;
	unsigned headY = this->segments[0].y;

	return (
		headX == 0 ||
		headY == 0 ||
		headX == CELL_WIDTH - 1 ||
		headY == CELL_HEIGHT - 1
		);
}

bool Snake::checkForSelfCollision() {
	unsigned headX = this->segments[0].x;
	unsigned headY = this->segments[0].y;

	for (unsigned i = 1; i < this->segments.size(); i += 1) {
		if (this->segments[i].x == headX && this->segments[i].y == headY) {
			return true;
		}
	}

	return false;
}

bool Snake::checkForCoinCollision() {
	unsigned headX = this->segments[0].x;
	unsigned headY = this->segments[0].y;

	return this->coin.x == headX && this->coin.y == headY;
}

void Snake::moveSnake() {
	static const int moveX[] = { 0, 0, -1, 1 };
	static const int moveY[] = { -1, 1, 0, 0 };

	unsigned currentX = this->segments[0].x;
	unsigned currentY = this->segments[0].y;
	std::cout << "X, Y: " << this->segments[0].x * CELL_SIZE << ", " 
		<< this->segments[0].y * CELL_SIZE << '\n';

	unsigned newHeadX = currentX + moveX[this->direction];
	unsigned newHeadY = currentY + moveY[this->direction];

	SnakeSegment newHead(newHeadX, newHeadY);

	this->segments.push_front(newHead);
}

void Snake::render(SDL_Renderer* renderer) {
	if (this->dead) {
		return;
	}

	SDL_Rect renderRect;
	renderRect.w = CELL_SIZE;
	renderRect.h = CELL_SIZE;

	this->RenderGrid(renderer);
	this->renderCoin(renderer);
	this->renderSnake(renderer);
}

void Snake::renderCoin(SDL_Renderer* renderer) {
	SDL_Rect renderRect;
	renderRect.x = this->coin.x * CELL_SIZE;
	renderRect.y = this->coin.y * CELL_SIZE;
	renderRect.w = CELL_SIZE;
	renderRect.h = CELL_SIZE;

	SDL_SetRenderDrawColor(renderer, coinColor->r,coinColor->g,coinColor->b,coinColor->a);
	SDL_RenderFillRect(renderer, &renderRect);
}

void Snake::renderSnake(SDL_Renderer* renderer) {
	SDL_Rect renderRect;

	renderRect.w = CELL_SIZE;
	renderRect.h = CELL_SIZE;

	renderRect.x = this->segments[0].x * CELL_SIZE;
	renderRect.y = this->segments[0].y * CELL_SIZE;

	SDL_SetRenderDrawColor(renderer, headColor->r, headColor->g, headColor->b, headColor->a);
	SDL_RenderFillRect(renderer, &renderRect);

	for (unsigned i = 1; i < this->segments.size(); i += 1) {
		renderRect.x = this->segments[i].x * CELL_SIZE;
		renderRect.y = this->segments[i].y * CELL_SIZE;

		SDL_SetRenderDrawColor(renderer, segmentColor->r, segmentColor->g, segmentColor->b, segmentColor->a);
		SDL_RenderFillRect(renderer, &renderRect);
	}
}

void Snake::RenderGrid(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
	for (int i = 0; i <= SCREEN_WIDTH; i += CELL_SIZE) {
		for (int j = 0; j <= SCREEN_HEIGHT; j += CELL_SIZE) {
			SDL_RenderDrawLine(renderer, i, 0, i, SCREEN_HEIGHT);
			SDL_RenderDrawLine(renderer, 0, j, SCREEN_WIDTH, j);
		}
	}
}
