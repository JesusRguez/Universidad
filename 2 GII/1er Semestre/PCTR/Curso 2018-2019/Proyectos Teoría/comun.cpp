#include <thread>
#include <mutex>
#include <iostream>
struct Comun {
std::mutex clang;
int q;
Comun() : q(0) {}
void oper_A(int x){

std::lock_guard<std::mutex> cerrojo(clang);std::cout << "Echamos el cerrojo en A" << '\n';
q -= x;
}
void oper_B(int x){

std::lock_guard<std::mutex> cerrojo(clang);std::cout << "Echamos el cerrojo en B" << '\n';
q++;
}
void oper_C(int x, int y){

    std::lock_guard<std::mutex> cerrojo(clang);std::cout << "Echamos el cerrojo en C" << '\n';
oper_B(33);
oper_A(56);
}
};
int main(){
Comun ref;
ref.oper_B(5);
ref.oper_C(6, 6);
std::cout<<"Spock dice: Larga vida y prosperidad...";
return 0;
}
