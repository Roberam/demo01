#ifndef _ENTENEMY_H_
#define _ENTENEMY_H_

#include "Base.h"
#include "Entity.h"

class EntEnemy : public Entity
{
public:
	EntEnemy(TMOV type);
	~EntEnemy();

	//Devuelve el tipo.
	TMOV GetType() const;

	//Actualiza la posicion de EntEnemy.
	void Update();
private:
	int m_mov;
	TMOV m_type;
};

#endif
