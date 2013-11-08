#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	m_position = 0;
	m_active = false;
}

Entity::~Entity()
{
}

int Entity::GetPos() const
{
	return m_position;
}

void Entity::SetPos(int pos)
{
	m_position = pos;
}

bool Entity::IsActive() const
{
	return m_active;
}

void Entity::UpdateState(int pos)
{
	if (m_active)
		Desactive();
	else
		Active(pos);
}

void Entity::Active(int pos)
{
	m_active = true;
	m_position = pos;
}

void Entity::Desactive()
{
	m_active = false;
}
