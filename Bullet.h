#pragma once
struct Bullet
{
	bool isAlive;
	int x;
	int y;
};

void BulletInit();
void BulletUpdate();
void BulletDraw();

void BulletMove();
void BulletClipping();
void CreateBullet(int x, int y);