#pragma once
#include <iostream>

static const unsigned SCREEN_WIDTH = 800;
static const unsigned SCREEN_HEIGHT = 600;

static const unsigned GO_UP = 0;
static const unsigned GO_DOWN = 1;
static const unsigned GO_LEFT = 2;
static const unsigned GO_RIGHT = 3;

static const unsigned CELL_SIZE = 20;
static const unsigned CELL_WIDTH = SCREEN_WIDTH / CELL_SIZE;
static const unsigned CELL_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

static const unsigned START_X = CELL_WIDTH / 2;
static const unsigned START_Y = CELL_HEIGHT / 2;
static const unsigned START_LENGTH = 3;