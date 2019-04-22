//Crear/Modificar enlace doble alumnos<=>asignatura con grupo
void Alumno_Asignatura::matriculado_en(Alumno& a, Asignatura& as, Grupo& g){
	directa[&a][&as] = inversa[&as][&a];
}

void Alumno_Asignatura::matriculado_en(Asignatura&as, Alumno& a, Grupo& g){
	matriculado_en(a, as, g);
}
