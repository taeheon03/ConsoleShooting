#pragma once
struct Effect
{
	bool isAlive;
	int x;
	int y;
	
	int index;
	DWORD indexUpdateTime;
};

void EffectInit();
void EffectDraw();
void EffectUpdate();

void CreateEffect(int x, int y);