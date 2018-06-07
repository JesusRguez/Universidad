#ifndef MIPOLINOMIO_H_INCLUDED
#define MIPOLINOMIO_H_INCLUDED

class polinomio{
public:
    polinomio();
    polinomio(unsigned int gradoMax); //1ª función de la hoja de la práctica
    unsigned int grado() const; //2ª función de la hoja de la práctica
    double coeficiente (unsigned int n) const;  //3ª función de la hoja de la práctica
    void coeficiente(unsigned n, double c); //4ª función de la hoja de la práctica
    ~polinomio();
private:
    unsigned int Grado;
    float *coef;
};

#endif //MIPOLINOMIO_H:INCLUDED
