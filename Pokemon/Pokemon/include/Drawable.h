#pragma once

class Drawable {
public:
	virtual void Draw(int xPos, int yPos) = 0;
	virtual void ChangeTexture(const char* path) = 0;
};