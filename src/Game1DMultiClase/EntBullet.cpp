#include "stdafx.h"
#include "Base.h"
#include "Entity.h"
#include "EntBullet.h"

EntBullet::EntBullet(TMOV mov)
{
	m_type = mov;
	if (mov == ToLeft)
		m_mov = MOV_BULLET_LEFT;
	else
		m_mov = MOV_BULLET_RIGHT;
}

EntBullet::~EntBullet()
{
}

TMOV EntBullet::GetType() const
{
	return m_type;
}

void EntBullet::Update()
{
	SetPos(GetPos() + m_mov);
}
