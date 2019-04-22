//Grupos impartidos por el profesor p
const Profesor_Grupo::Grupo& Profesor_Grupo::impartidos(Profesor& p) const{
	return directa[&p];
}

//Profesor que imparte el grupo g
Profesor& Profesor_Grupo::impartido(Grupo& g) const{
	return inversa[&g];
}
