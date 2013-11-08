#include "stdafx.h"
#include "Base.h"
#include "Utils.h"
#include "Entity.h"
#include "EntBullet.h"
#include "EntEnemy.h"
#include "EntHero.h"
#include "EntRainDrop.h"
#include "World.h"

World::World()
{
	StartPlay();
	srand(time(NULL));
	m_hero = new EntHero();
	m_entities = new Entity*[NUM_ENTITIES];
	StarEntities();
	StartRain();
	m_numMurders = 0;
}

World::~World()
{
	delete m_hero;
	for(int i = 0; i < NUM_ENTITIES; i++)
		delete m_entities[i];
	delete[] m_entities;
}

bool World::IsPlaying() const
{
	return m_playing;
}

void World::StartPlay()
{
	m_playing = true;
}

void World::StopPlay()
{
	m_playing = false;
}

void World::UpdateWorld()
{
	Sleep(TIME_SLEEP);
	UpdateEnemies();
	UpdateEntities();
	UpdateRain();
	UpdateHero();
	if (LookingCollisions())
		StopPlay();
}

void World::UpdateEnemies()
{
	if (!m_entities[ENEMY_LEFT]->IsActive())
		m_entities[ENEMY_LEFT]->Active(XMAP_INI);
	if (!m_entities[ENEMY_RIGHT]->IsActive())
		m_entities[ENEMY_RIGHT]->Active(XMAP_FIN);
}

void World::UpdateEntities()
{
	for (int i = 0; i < NUM_ENTITIES; i++)
		if (m_entities[i]->IsActive())
			m_entities[i]->Update();
}

void World::UpdateRain()
{
	for (int i = 0; i < MAX_NUM_RAINDROP; i++)
		m_rain[i].Update();
}

void World::UpdateHero()
{
	m_hero->Update();
}

void World::MoveHero(TACTION action)
{
	if (XMAP_INI < m_hero->GetPos() && action == MOVE_LEFT)
		m_hero->SetMov(ToLeft);
	else if (m_hero->GetPos() < XMAP_FIN && action == MOVE_RIGHT)
		m_hero->SetMov(ToRight);
	else
		m_hero->SetMov(NoMove);
}

void World::Shoot(TACTION action)
{
	if (XMAP_INI < m_hero->GetPos() && action == SHOT_LEFT)
	{
		if (!m_entities[BULLET_LEFT]->IsActive())
			m_entities[BULLET_LEFT]->Active(m_hero->GetPos());
	}
	else if (m_hero->GetPos() < XMAP_FIN && action == SHOT_RIGHT)
	{
		if (!m_entities[BULLET_RIGHT]->IsActive())
			m_entities[BULLET_RIGHT]->Active(m_hero->GetPos());
	}
}

bool World::LookingCollisions()
{
	bool HeroDead = false;
	BulletCollisions();
	return EnemyCollisions();
}

void World::Render() const
{
	DrawFrame();
	DrawBase();
	DrawRain();
	DrawEntities();
	DrawHero();
	DrawInfo();
}

void World::StarEntities()
{
	m_entities[ENEMY_LEFT] = new EntEnemy(ToLeft);
	m_entities[ENEMY_RIGHT] = new EntEnemy(ToRight);
	m_entities[BULLET_LEFT] = new EntBullet(ToLeft);
	m_entities[BULLET_RIGHT] = new EntBullet(ToRight);
}

void World::StartRain()
{
	int pos = 0;
	auto it = m_rain.begin();
	for (int i = 0; i < MAX_NUM_RAINDROP; i++)
	{
		pos = Randomize(WIDTH) + XMAP_INI;
		EntRainDrop* water = new EntRainDrop();
		water->SetPos(pos);
		m_rain.push_back(*water);
		delete water;
	}
}

void World::BulletCollisions()
{
	if (m_entities[ENEMY_LEFT]->IsActive() && m_entities[BULLET_LEFT]->IsActive())
	{
		if (m_entities[BULLET_LEFT]->GetPos() <= m_entities[ENEMY_LEFT]->GetPos())
		{
			m_entities[BULLET_LEFT]->Desactive();
			m_entities[ENEMY_LEFT]->Desactive();
			m_numMurders++;
		}
	}
	if (m_entities[ENEMY_RIGHT]->IsActive() && m_entities[BULLET_RIGHT]->IsActive())
	{
		if (m_entities[ENEMY_RIGHT]->GetPos() <= m_entities[BULLET_RIGHT]->GetPos())
		{
			m_entities[ENEMY_RIGHT]->Desactive();
			m_entities[BULLET_RIGHT]->Desactive();
			m_numMurders++;
		}
	}
}

bool World::EnemyCollisions()
{
	bool HeroDead = false;
	if (m_entities[ENEMY_LEFT]->IsActive())
	{
		if (m_hero->GetPos() <= m_entities[ENEMY_LEFT]->GetPos())
			HeroDead = true;
	}
	if (m_entities[ENEMY_RIGHT]->IsActive())
	{
		if (m_entities[ENEMY_RIGHT]->GetPos() <= m_hero->GetPos())
			HeroDead = true;
	}
	return HeroDead;
}

void World::DrawFrame() const
{
	gotoxy(0, 0);
	for(int i = 0; i <= X_MAX; i++)
		printf("%c", C_FRAME);
	gotoxy(0, Y_MAX);
	for(int i = 0; i <= X_MAX; i++)
		printf("%c", C_FRAME);
	for(int i = 0; i <= Y_MAX; i++)
	{
		gotoxy(0, i);
		printf("%c", C_FRAME);
		gotoxy(X_MAX, i);
		printf("%c", C_FRAME);
	}
}

void World::DrawBase() const
{
	SetColorText(COLOR_MAP);
	gotoxy(XMAP_INI, YMAP_INI);
	for(int i = 0; i < WIDTH; i++)
		printf("%c", C_MAP);
	SetColorText(COLOR_RESET);
}

void World::DrawRain() const
{
	SetColorText(COLOR_RAINDROP);
	for (int i = 0; i < MAX_NUM_RAINDROP; i++)
	{
		if (m_rain[i].IsActive())
		{
			gotoxy(m_rain[i].GetPos(), YMAP_INI);
			if (FLOOR_LIFE_WATER <= m_rain[i].GetLife())
				printf("%c", C_FALLING_RAINDROP);
			else
				printf("%c", C_RAINDROP);
		}
	}
	SetColorText(COLOR_RESET);
}

void World::DrawEntities() const
{
	for (int i = 0; i < NUM_ENTITIES; i++)
	{
		if (m_entities[i]->IsActive())
		{
			gotoxy(m_entities[i]->GetPos(), YMAP_INI);
			DrawChar(i);
		}
	}
}

void World::DrawHero() const
{
	SetColorText(COLOR_HERO);
	gotoxy(m_hero->GetPos(), YMAP_INI);
	printf("%c", C_HERO);
	SetColorText(COLOR_RESET);
}

void World::DrawChar(int i) const
{
	if (i == 0 || i == 1)
	{
		SetColorText(COLOR_ENEMY);
		printf("%c", C_ENEMY);
		SetColorText(COLOR_RESET);
	}
	else if (i == 2)
	{
		SetColorText(COLOR_BULLET);
		printf("%c", C_BULLET_LEFT);
		SetColorText(COLOR_RESET);
	}
	else if (i == 3)
	{
		SetColorText(COLOR_BULLET);
		printf("%c", C_BULLET_RIGHT);
		SetColorText(COLOR_RESET);
	}
}

void World::DrawInfo() const
{
	gotoxy(XMAP_INI, YINFO_INI);
	printf("ENEMIGOS MUERTOS: %d", m_numMurders);
}
