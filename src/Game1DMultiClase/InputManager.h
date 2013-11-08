#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include "Base.h"
#include "World.h"

class InputManager
{
public:
	InputManager(World*);
	~InputManager();

	//Recoge la entrada el usuario.
	void CatchUser();

	//Trata la entrada del usuario.
	void InputUse();

	//Devuelve la accion correspondiente.
	TACTION GetAction() const;
private:
	TACTION m_action;
	World* m_world;
};

#endif
