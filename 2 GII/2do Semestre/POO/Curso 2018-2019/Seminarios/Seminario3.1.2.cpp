class Alumno{
public:
	//Asiganturas con grupo (atributos de enlace)
	typedef std::map<Asignatura*, Grupo*> Asignaturas;

	//Asociación con Asignatura
	void matriculado_en(Asignatura&, Grupo&);
	Asignaturas& matricula() const;
private:
	Asignaturas asignaturas; //Asociación con Asignatura
};

class Asiugnatura{
public:
	typedef std::set<Grupo*> Grupos;

	//Alumnos con grupo (atirbutos de enlace)
	typedef std::map<Alumno*, Grupo*> Alumnos;

	//Asocia con alumno
	void matriculado(Alumno&, Grupo&);
	Alumnos& matricula() const;

	//Asociación con Grupo
	void grupo(Grupo&);
	Grupos& grupos() const;
private:
	Alumnos alumnos; //Asociación con Alumno
	Grupos grupos; //Asoscición con Grupo
};

//Clase de atributos de enlace Alumno-Asignatura
class Grupo{
public:
	//Asociación con Asignatura
	void pertenece(Asignatura&);
	Asignaturas& asignatura() const;

	//Asociación con Profesor
	void impartido(Profesor&);
	Profesor& profesor() const;
private:
	string autla; //Atributos de enlace
	int h_semana;
	Asignatura* asig; //Asociación con Asigantura
	Profesor* profe; //Asosciación con Profesor
};

class Profesor{
public:
	typedef std::set<Grupo*> Grupos;

	//Asosciación con Grupo
	void imparte(Grupo&);
	Grupos& impartidos() const;
private:
	Grupos grupos; //Asociación con Grupo
};
