#include "Brick.h"

void CBrick::Render() {
	animations[8]->Render(x, y);
}

void CBrick::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x;
	t = y;
	r = x + BRICK_BBOX_WIDTH;
	b = y + BRICK_BBOX_HEIGHT;
}