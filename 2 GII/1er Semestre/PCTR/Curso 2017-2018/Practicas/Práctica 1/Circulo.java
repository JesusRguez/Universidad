
/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */
public class Circulo {

    static final double PI = 3.141592;

    /**
     * @param diametroBase = Diámetro de la base
     * @param altura = Altura del cono
     */
    public static void volumen(double diametroBase, double altura) {
        double v = (altura * PI * Math.pow(diametroBase / 2, 2)) / 3;
        System.out.println("El volumen del cono es: " + v);
        //El resultado estará en centímetros cuadrados
    }

    public static void main(String[] args) {
        double diametroBase = 14.2;
        double altura = 20;
        //Ambas medidas en centímetros
        volumen(diametroBase, altura);
    }
}
