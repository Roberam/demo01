#include "stdafx.h"
#include "Base.h"
#include "Entity.h"
#include "EntHero.h"

EntHero::EntHero()
{
	m_dir = NoMove;
	SetPos(WIDTH/2 + XMAP_INI);
}

EntHero::~EntHero()
{
}

void EntHero::SetMov(TMOV mov)
{
	m_dir = mov;
}

void EntHero::Update()
{
	if (m_dir == ToLeft)
		SetPos(GetPos() + MOV_HERO_LEFT);
	else if (m_dir == ToRight)
		SetPos(GetPos() + MOV_HERO_RIGHT);
}
