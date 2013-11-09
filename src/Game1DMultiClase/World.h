#ifndef _WORLD_H_
#define _WORLD_H_

#include "Base.h"
#include "Utils.h"
#include "Entity.h"
#include "EntHero.h"
#include "EntRainDrop.h"

class World
{
public:
	World();
	~World();

	//Devuelve el estado del mundo.
	bool IsPlaying() const;

	//Activa el mundo.
	void StartPlay();

	//Desactiva el mundo.
	void StopPlay();

	//Actualiza el mundo y sus entidades.
	void UpdateWorld();
	
	//Actualiza a los enemigos.
	void UpdateEnemies();

	//Actualiza las balas.
	void UpdateEntities();

	//Actualiza la lluvia.
	void UpdateRain();

	//Actualiza al heroe.
	void UpdateHero();

	//Mueve al heroe.
	void MoveHero(TACTION action);

	//Dispara una bala.
	void Shoot(TACTION action);

	//Verifica colisiones.
	bool LookingCollisions();

	//Muestra el mundo por pantalla.
	void Render() const;
private:
	bool m_playing;
	EntHero* m_hero;
	Entity** m_entities;
	std::vector<EntRainDrop> m_rain;
	int m_numMurders;

	//Inicializa las entidades.
	void StarEntities();

	//Inicializa la lluvia.
	void StartRain();

	//Trata colisiones por balas.
	void BulletCollisions();

	//Trata colisiones por enemigo.
	bool EnemyCollisions();

	//Muestra un marco por pantalla.
	void DrawFrame() const;

	//Muestra el marco interior por pantalla.
	void DrawIntFrame() const;

	//Muestra la base del por pantalla.
	void DrawBase() const;

	//Limpia el fondo del mapeado.
	void DrawBackGround() const;

	//Muestra la lluvia por pantalla.
	void DrawRain() const;

	//Muestra las entidades por pantalla.
	void DrawEntities() const;

	//Muestra al heroe por pantalla.
	void DrawHero() const;

	//Muestra un caracter entidad por pantalla.
	void DrawChar(int pos, int i) const;

	//Muestra informacion extra de la partida.
	void DrawInfo() const;
};

#endif
