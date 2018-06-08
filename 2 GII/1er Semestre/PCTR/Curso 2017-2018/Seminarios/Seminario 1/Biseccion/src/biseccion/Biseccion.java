package biseccion;

/**
 * @author Jesus
 */
public class Biseccion {

    static float f2(float x) {
        return (x * x) - 5;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        float a = 2, b = 3;
        //Float x; si pongo la mayúscula, estoy transformando la x en un objeto de la clase Float a las que se le puede asignar métodos
        //Puede servir para pasar parámetros por referencia.
        int iteraciones = 0;
        if (args.length != 1) {
            System.out.println("Debe introducir un parámetro.");
        } else {
            try {
                iteraciones = Integer.parseInt(args[0]);
                for (int i = 0; i < iteraciones; i++) {
                    float c = (a + b) / 2;
                    if (f2(c) == 0) {
                        System.out.println("La raíz es " + c);
                    } else {
                        if (f2(c) * f2(a) > 0) {
                            a = c;
                        } else {
                            b = c;
                        }
                    }
                    System.out.println("a = " + a + ", b = " + b);
                }
                System.out.println("La raíz es aproximadamente " + (a + b) / 2);
            } catch (NumberFormatException ex) { //Al poner NumberFormatException solo vamos a coger las excepciones de ese tipo.
                //Si le ponemos Exception solamente, cogeríamos todas las excepciones que se generasen.
                //También podemos poner varios bloques catch para pillar varias excepciones de distinto tipo.
                System.out.println("El parámetro debe ser un número entero");
                ex.printStackTrace();//Muestra el mensaje feo que sale ya que siempre recurre a este método.
            } catch (Exception ex) {
                System.out.println("Error desconocido.");
                //Como en este ejercicio, podemos meter todo el código del programa entre un bloque try-catch para que, cuando
                //se detecte una excepción, se salte todas las líneas de código y que vaya directamente al catch correspondiente.
            }
        }
    }
}
