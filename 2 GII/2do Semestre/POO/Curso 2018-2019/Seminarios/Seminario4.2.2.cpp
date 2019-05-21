struct V{
    virtual void fv() = 0;
    virtual void f() = 0;
    virtual ~V(){}
};

struct X: V{
    void fv(){}
    void f(){
        std::cout << "Procesando objeto X..." << '\n';
    }
};

struct Y: V{
    void fv(){}
    void f(){
        std::cout << "Procesando objeto Y..." << '\n';
    }
};

struct Z: V{
    void fv(){}
    void f(){
        std::cout << "Procesando objeto Z..." << '\n';
    }
};
