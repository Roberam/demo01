#ifndef _ENTBULLET_H_
#define _ENTBULLET_H_

#include "Base.h"
#include "Entity.h"

class EntBullet : public Entity
{
public:
	EntBullet(TMOV mov);
	~EntBullet();

	//Devuelve el tipo.
	TMOV GetType() const;

	//Actualiza la posicion de EntBullet.
	void Update();
private:
	int m_mov;
	TMOV m_type;
};

#endif
