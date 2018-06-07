#ifndef MIPOLINOMIO_H_INCLUDED
#define MIPOLINOMIO_H_INCLUDED

class polinomio{
public:
    polinomio();
    polinomio(unsigned int gradoMax); //1� funci�n de la hoja de la pr�ctica
    unsigned int grado() const; //2� funci�n de la hoja de la pr�ctica
    double coeficiente (unsigned int n) const;  //3� funci�n de la hoja de la pr�ctica
    void coeficiente(unsigned n, double c); //4� funci�n de la hoja de la pr�ctica
    ~polinomio();
private:
    unsigned int Grado;
    float *coef;
};

#endif //MIPOLINOMIO_H:INCLUDED
