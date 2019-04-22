class Alumno_Asignatura{
public:
	typedef std::map<Asignatura*, Grupo*> Asignaturas;
	typedef std::map<Alumno*, Grupo*> Alumnos;
	void matriculado_en(Alumno&, Asignatura&, Grupo&);
	void matriculado_en(Asignatura&, Alumno&, Grupo&);
	const Asignaturas& matriculados(Alumno&) const;
	const Alumnos& matriculados(Asignaturas&) const;
private:
	std::map<Alumno*, Asignaturas> directa;
	std::map<Asigantura*, Alumno> inversa;
}
