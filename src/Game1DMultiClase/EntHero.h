#ifndef _ENTHERO_H_
#define _ENTHERO_H_

#include "Base.h"
#include "Entity.h"

class EntHero : public Entity
{
public:
	EntHero();
	~EntHero();

	//Actualiza la direccion de EntHero.
	void SetMov(TMOV mov);

	//Actualiza la posicion de EntHero.
	void Update();
private:
	TMOV m_dir;
};

#endif
