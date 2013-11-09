// Game1DMultiClase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Base.h"
#include "World.h"
#include "InputManager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//Inicializacion.
	World* world = new World();
	InputManager input(world);

	//Comienzo del juego.
	world->DrawStartPlay();

	//Bucle principal del juego.
	while (world->IsPlaying())
	{
		//Actualiza el mundo.
		world->UpdateWorld();
		//Dibuja por pantalla.
		world->Render();
		//Recoge la entrada el usuario.
		input.CatchUser();
		//Trata la entrada del usuario.
		input.InputUse();
	}

	//Salida.
	delete world;
	return 0;
}

