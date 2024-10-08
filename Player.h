#pragma once

struct Player
{
	int x;
	int y;
	char body;
};

void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void PlayerMove();
void PlayerClipping();