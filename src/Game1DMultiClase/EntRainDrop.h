#ifndef _ENTRAINDROP_H_
#define _ENTRAINDROP_H_

#include "Entity.h"

class EntRainDrop : public Entity
{
public:
	EntRainDrop();
	~EntRainDrop();

	//Devuelve la vida restante.
	int GetLife() const;

	//Actualiza el estado de EntRainDrop.
	void Update();
private:
	int m_life;
};

#endif
