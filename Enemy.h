#pragma once
struct Enemy
{
	int x;
	int y;
	bool isAlive;
};

void Enemylnit();
void EnemyUpdate();
void EnemyDraw();

void EnemyMove();
void EnemyClipping();
void CreateEnemy(int x, int y);


void BulletEnemyCllosion();