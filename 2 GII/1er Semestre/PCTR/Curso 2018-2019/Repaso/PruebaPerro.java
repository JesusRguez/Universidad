class Animal{
public void move(){
System.out.println("Los animales se mueven");
}
}
class Perro extends Animal{
public void move(){
System.out.println("Los perros andan y corren");
}
}
public class PruebaPerro{
public static void main(String args[]){
Animal a = new Animal();
Animal b = new Perro();
a.move();
b.move();
}
}
