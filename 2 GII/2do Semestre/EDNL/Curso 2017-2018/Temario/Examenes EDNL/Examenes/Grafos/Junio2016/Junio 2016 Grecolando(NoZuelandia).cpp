struct Ciudad{
	double x,y;
}

struct Puente{
	Puente(Ciudad c1,Ciudad c2):c1(c1),c2(c2){}
	Ciudad c1,c2;
}

struct CosteyCiudad{
	vector<tCoste> costes;
	vector<Ciudad> ciudad;
}

CosteyCiudad CalculaCostesCostera(vector<ciudades> ciudades, vector<bool> costeras, const GrafoP<tCoste>& G){

	vector<tCoste> costes_costera,vector_dijkstra;
	vector<vertice> p,costeras_aux;
	vector<Ciudad> ciudades_costeras;
	vertice indice=0;
	
	for(vertice i=0;i<costeras.size();i++)
		if(costeras[i]){
			costeras_aux[indice]=i;
			ciudades_costeras[indice]=ciudades[i];
			indice++;
		}
	indice=0;

	for(vertice j=0;j<costeras_aux.size();j++){ ????????
		costes_costera=Dijkstra(G,costeras_aux[j],p);

		for(vertice x=0;x<costes_costera.size();x++)
			vector_dijkstra[indice]+=costes_costera[x];

		indice++;
	}	

return CosteyCiudad(vector_dijkstra,ciudades_costeras);

}

template <typename T>
Puente NoZuelandia(const Matriz& Fobos, const Matriz& Deimos,const vector<Ciudad> ciudades_fobos,const vector<Ciudad> ciudades_deimos
						   vector<bool> costeras_fobos, vector<bool> costeras_deimos){
	
	typedef typename GrafoP<tCoste>::vertice vertice;
	GrafoP<tCoste> fobos(Fobos.dimension(),INFINITO);
	GrafoP<tCoste> deimos(Deimos.dimension(),INFINITO);

	vector<tCoste> Fobos_costeras_costes, Deimos_costeras_costes;
	tCoste coste_min=INFINITO;

	CosteyCiudad cfobos,cdeimos;
	Ciudad cf,cd;

	//Fobos
	for(vertice i=0;i<fobos.numVert();i++){
		for(vertice j=0;j<fobos.numVert();j++){
			if(i==j)
				fobos[i][j]=0;
			if(Fobos[i][j])
				fobos[i][j]=DistanciaEuclidea(ciudades_fobos[i],ciudades_fobos[j]);
		}
	}

	//Deimos
	for(vertice i=0;i<deimos.numVert();i++){
		for(vertice j=0;j<deimos.numVert();j++){
			if(i==j)
				deimos[i][j]=0;
			if(Deimos[i][j])
				deimos[i][j]=DistanciaEuclidea(ciudades_deimos[i],ciudades_deimos[j]);
		}
	}

	cfobos=CalculaCostesCostera(ciudades_fobos,costeras_fobos,fobos);
	cdeimos=CalculaCostesCostera(ciudades_deimos,costeras_deimos,deimos);


	for(vertice i=0;i<Fobos_costeras_costes.size();i++){ ????????
		for(vertice j=0;j<Deimos_costeras_costes.size();j++){
			if(suma(cfobos.costes[i],cdeimos.costes[j])<coste_min){
				coste_min=suma(cfobos.costes[i],cdeimos.costes[j]);
				cf=cfobos.ciudad[i];
				cd=cdeimos.ciudad[j];
			}

		}
	}
	return Puente(cf,cd);
}