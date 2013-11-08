#include "stdafx.h"
#include "Base.h"
#include "Entity.h"
#include "EntEnemy.h"

EntEnemy::EntEnemy(TMOV type)
{
	m_type = type;
	if (type == ToLeft)
		m_mov = MOV_ENEMY_LEFT;
	else
		m_mov = MOV_ENEMY_RIGHT;
}

EntEnemy::~EntEnemy()
{
}

TMOV EntEnemy::GetType() const
{
	return m_type;
}

void EntEnemy::Update()
{
	SetPos(GetPos() + m_mov);
}
