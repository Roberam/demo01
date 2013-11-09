#include "stdafx.h"
#include "Base.h"
#include "Utils.h"
#include "World.h"
#include "InputManager.h"

InputManager::InputManager(World* newWorld)
{
	m_world = newWorld;
	m_action = NOTHING;
}

InputManager::~InputManager()
{
}

void InputManager::CatchUser()
{
	char keyPressed = NULL;
	if (m_world->IsHeroDead())
	{
		system("color 0A");
		while (keyPressed != ESC)
		{
			Sleep(TIME_SLEEP);
			m_world->DrawGameOver();
			if (_kbhit())
			{
				keyPressed = _getch();
			}
		}
		system("color 07");
	}
	else
	{
		if (_kbhit())
		{
			keyPressed = _getch();
			if ('a' <= keyPressed && keyPressed <= 'z')
				keyPressed = toupper(keyPressed);
			if (keyPressed == ESC)
				m_action = ESCAPE;
			else if (keyPressed == LEFT_KEY)
				m_action = MOVE_LEFT;
			else if (keyPressed == RIGHT_KEY)
				m_action = MOVE_RIGHT;
			else if (keyPressed == LEFT_SHOT)
				m_action = SHOT_LEFT;
			else if (keyPressed == RIGHT_SHOT)
				m_action = SHOT_RIGHT;
			else
				m_action = NOTHING;
		}
		else
			m_action = NOTHING;
	}
}

void InputManager::InputUse()
{
	if (m_action == ESCAPE)
		m_world->StopPlay();
	else if (m_action == MOVE_LEFT || m_action == MOVE_RIGHT || m_action == NOTHING)
		m_world->MoveHero(m_action);
	else if (m_action == SHOT_LEFT || m_action == SHOT_RIGHT)
		m_world->Shoot(m_action);
}

TACTION InputManager::GetAction() const
{
	return m_action;
}
