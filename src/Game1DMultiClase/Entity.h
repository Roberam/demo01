#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
public:
	Entity();

	virtual ~Entity();

	//Devuelve la posicion de la entidad.
	int GetPos() const;

	//Actualiza la posicion de la entidad.
	void SetPos(int pos);

	//Devuelve true si la entidad esta activa.
	bool IsActive() const;

	//Actualiza el estado de la entidad.
	void UpdateState(int pos);

	//Activa la entidad.
	void Active(int pos);

	//Desactiva la entidad.
	void Desactive();

	//Actualiza la posicion de Entity.
	virtual void Update() = 0;

private:
	int m_position;
	bool m_active;
};

#endif
