class Profesor_Grupo{
public:
	typedef std::set<Grupo*> Grupos;
	void imparte(Grupo&, Profesor&);
	void imparte(Profesor&, Grupo&);
	const Grupo& impartidos(Profesor&);
	Profesor& impartido(Grupo&) const;
private:
	std::map<Profesor*, Grupos> directa;
	std::map<Grupos*, Profesor> inversa;
}
