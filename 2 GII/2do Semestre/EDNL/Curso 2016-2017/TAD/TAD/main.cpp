#include <iostream>

class A{
    public:

    A();
    explicit A(int b, int relleno = 0);
    int operator[](int pos) const {return v_[pos];}
    int& operator[](int pos) {return v_[pos];}
    size_t tam() const;

    friend std::ostream& operator<<(std::ostream& os, const A& a);
    ~A(){delete[] v_;}

    private:

    int *v_;
    size_t tam_;
};

inline size_t A::tam() const {return tam_;}

inline A::A(): v_(nullptr),tam_(0) {}

A::A(int b,int relleno): v_(new int[b]),tam_(b) {

    for(size_t i=0; i<tam_; ++i)
        v_[i] = relleno;
}

A operator -(const A& a1, const A& a2){

    A res(a1.tam());

    for(size_t i=0; i<a1.tam(); ++i)
        res[i] = a1[i] - a2[i];

    return res;
}

std::ostream& operator <<(std::ostream& os,const A& a){

    for(size_t i=0;i<a.tam();++i)
        os << a.v_[i] << " ";

    return os;
}

int main(){

    A r(5,10);
    A f(5,6);
    std::cout << r - f;
}
