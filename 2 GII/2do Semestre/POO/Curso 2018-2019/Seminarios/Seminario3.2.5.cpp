//Crear/modificar enlace doble profesor <=> Grupo
void Profesor_Grupo::imparte(Profeosr& p, Grupo& g){
	std::pair<std::map<Grupo*, Profesor*>::iterator, bool> ins;
	std::pair = inversa.insert(std::make_pair(&g, &p)); //enlace grupo-profesor
	if(!ins.second){
		//El grupo g ya tiene otro profesor.
		//Quitar el grupo g al profeosr que lo tenga
		directa[ins.first->second].erase(&g);
		inversa[&g] = &p; //Enlace grupo-profesor
	}
	directa[&p].insert(&g); //Enlace profesor-grupo
}

void Profesor_Grupo::imparte(Grupo& g, Profesor& p){
	imparte(p, g);
}
