//Asignaturas del alumno a
const Alumno_Asignatura::Asignaturas& Alumno_Asignatura::matriculados(Alumno& a) const{
	return directa[&a];
}

//Alumnos matriculados en la asignatura as
const Alumno_Asignatura::Alumnos& Alumno_Asignatura::matriculados(Asignatura& as) const{
	return inversa[&as];
}
