#include "stdafx.h"
#include "Base.h"
#include "Utils.h"
#include "Entity.h"
#include "EntRainDrop.h"

EntRainDrop::EntRainDrop()
{
	m_life = Randomize(MIN_LIFE_WATER, MAX_LIFE_WATER);
}

EntRainDrop::~EntRainDrop()
{
}

void EntRainDrop::Update()
{
	if (IsActive())
	{
		if (m_life > 0)
			m_life--;
		else
			Desactive();
	}
	else
	{
		int pos = Randomize(XMAP_INI, XMAP_FIN);
		Active(pos);
		m_life = Randomize(MIN_LIFE_WATER, MAX_LIFE_WATER);
	}
}

int EntRainDrop::GetLife() const
{
	return m_life;
}
