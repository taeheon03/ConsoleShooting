#include "include.h"
Effect effects[D_EFFECT_MAX];

char effectShape[3][3][3] =
{
	{
		{' ',' ',' '},
		{' ','*',' '},
		{' ',' ',' '}
	},
{
		{' ','*',' '},
		{'*','*','*'},
		{' ','*',' '}
	},
{
		{'*',' ','*'},
		{' ','*',' '},
		{'*',' ','*'}
	}
};

void EffectInit()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		effects[i].index = 0;
		effects[i].indexUpdateTime = 0;
		effects[i].isAlive = false;
		effects[i].x = 0;
		effects[i].y = 0;
	}
}

void EffectDraw()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isAlive)
		{
			DrawChar(effects[i].x - 1, effects[i].y - 1, effectShape[effects[i].index][0][0], BLUE);
			DrawChar(effects[i].x, effects[i].y - 1, effectShape[effects[i].index][0][1], BLUE);
			DrawChar(effects[i].x + 1, effects[i].y - 1, effectShape[effects[i].index][0][2], BLUE);

			DrawChar(effects[i].x - 1, effects[i].y, effectShape[effects[i].index][1][0], BLUE);
			DrawChar(effects[i].x, effects[i].y, effectShape[effects[i].index][1][1], BLUE);
			DrawChar(effects[i].x + 1, effects[i].y, effectShape[effects[i].index][1][2], BLUE);

			DrawChar(effects[i].x - 1, effects[i].y + 1, effectShape[effects[i].index][2][0], BLUE);
			DrawChar(effects[i].x, effects[i].y + 1, effectShape[effects[i].index][2][1], BLUE);
			DrawChar(effects[i].x + 1, effects[i].y + 1, effectShape[effects[i].index][2][2], BLUE);
		}
	}
}

void EffectUpdate()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isAlive &&
			effects[i].indexUpdateTime < GetTickCount())
		{
			effects[i].indexUpdateTime = GetTickCount() + 300;
			effects[i].index++;

			if (effects[i].index >= 3)
				effects[i].isAlive = false;
		}
	}
}


void CreateEffect(int x, int y)
{
	{
		for (int i = 0; i < D_EFFECT_MAX; i++)
		{
			if (effects[i].isAlive == false)
			{
				effects[i].isAlive = true;
				effects[i].x = x;
				effects[i].y = y;

				effects[i].index = 0;
				effects[i].indexUpdateTime = GetTickCount() + 300;
				break;
			}
		}
	}
}
