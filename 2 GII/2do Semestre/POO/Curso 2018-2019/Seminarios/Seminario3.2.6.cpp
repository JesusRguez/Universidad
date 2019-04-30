//Grupos impartidos por el profesor p
const Profesor_Grupo::Grupo& Profesor_Grupo::impartidos(Profesor& p) const{
	std::map<Profesor*, Grupo>::iterator it = directa.find(p);
	if(it != directa.end()){
		return directa[&p];
	}else{
		return NULL;
	}
}

//Profesor que imparte el grupo g
Profesor& Profesor_Grupo::impartido(Grupo& g) const{
	std::map<Grupo*, Profesor>::iterator it = inversa.find(g);
	if(it != inversa.end()){
		return inversa[&g];
	}else{
		return NULL;
	}
}
