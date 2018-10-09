/**
 * @author Jesús Rodríguez Heras
 */

class Circulo{
    static final double PI = 3.1416;
    public static void main(String[] args) {
        double diametro = 14.2;
        double altura = 20;
        double radio = diametro/2;
        double volumen = (PI*radio*radio*altura)/3;
        System.out.println("El volumen del cono es: "+volumen);
    }
}
