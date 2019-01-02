class posicionConValor{
public:
    int i, j;
    float valor;
    posicionConValor(){i=j=0;valor=0.0;};

    bool operator <(posicionConValor p){
        return this->valor < p.valor;
    }

    bool operator >(posicionConValor p){
        return this->valor > p.valor;
    }

    bool operator ==(posicionConValor p){
        return this->valor == p.valor;
    }

    bool operator <=(posicionConValor p){
        return this->valor <= p.valor;
    }
};
