bool factibilidad(float x, float y, Defense* defensa, std::list<Object*> obstaculos, float mapWidth, float mapHeight, std::list<Defense*> defensas, float cellWidth, float cellHeight){
	bool entra = true;

	if (x-defensa->radio < 0 || x+defensa->radio > mapWidth || y-defensa->radio < 0 || y+defensa->radio > mapHeight) {
		entra = false; //No cabe porque se sale de los limites del mapa
	}

	std::list<Object*>::const_iterator iterObst = obstaculos.begin();
	std::list<Defense*>::const_iterator iterDef = defensas.begin();
	Vector3 posicionDefensa(x, y, 0);
	while (iterObst!=obstaculos.end()) {
		if ((defensa->radio + (*iterObst)->radio) > (_distance(posicionDefensa, (*iterObst)->position))) {
			entra = false; //Se choca con un obsaculo
		}else{
			while ((*iterDef)!=defensa) {
				if ((defensa->radio + (*iterDef)->radio) > (_distance(posicionDefensa, (*iterDef)->position))) {
					entra = false; //Se choca con una defensa
				}
				++iterDef;
			}
		}
		++iterObst;
	}

	return entra;
}
