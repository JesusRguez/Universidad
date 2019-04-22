class Formulario{};

class Opcion{
public:
	Opcion(Formulario&); //Una opción se construye enlazada a un formulario
	void asocia(Formulario&);
	Formulario& asociado() const;
private:
	Formulario* formulario;
};

class Menu{
public:
	void asocia(Opcion&);
	void desasocia(Opcion&);
	std::set<Opcion>& asociados() const;
private:
	std::set<Opcion> opciones;
};
