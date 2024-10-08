#include "include.h"
Bullet bullets[D_BULLET_MAX];
void BulletInit()
{
	for (int i = 0;i < D_BULLET_MAX; i++)
	{
		bullets[i].x = 0;
		bullets[i].y = 0;
		bullets[i].isAlive = false;
	}
}
void BulletUpdate()
{
	BulletMove();
	BulletClipping();
}
void BulletDraw()
{
	for (int i = 0;i < D_BULLET_MAX;i++)
		if (bullets[i].isAlive)
			DrawChar(bullets[i].x, bullets[i].y, 'I', GREEN);
}

void BulletMove()
{
	for (int i = 0;i < D_BULLET_MAX;i++)
		if (bullets[i].isAlive)
			bullets[i].y--;
}

void BulletClipping()
{
	for (int i = 0;i < D_BULLET_MAX;i++)
		if (bullets[i].isAlive && bullets[i].y < 0)
			bullets[i].isAlive = false;
}

void CreateBullet(int x, int y)
{
	for (int i = 0;i < D_BULLET_MAX;i++)
	{
		if (bullets[i].isAlive == false)
		{
			bullets[i].x = x;
			bullets[i].y = y;
			bullets[i].isAlive = true;
			break;
		}
	}
}
