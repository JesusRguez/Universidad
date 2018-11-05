/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package poligono;

import java.util.*;

public class usaTodo{
    public static Scanner teclado = new Scanner(System.in);
    public static ArrayList<Punto> entrada;

    /**
     * Método que gestiona las operaciones del triángulo
     */
    public static void controlaTriangulo(){
        int opcion;
        System.out.println("Introduzca los puntos del triángulo:");
        double x, y;
        entrada = new ArrayList<Punto>();
        for (int i=0; i<3; ++i) {
            System.out.println("Introduzca la coordenada X del "+(i+1)+" punto:");
            x = teclado.nextDouble();
            System.out.println("Introduzca la coordenada Y del "+(i+1)+" punto:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }

        Triangulo T = new Triangulo(entrada);

        do {
            System.out.println("Seleccione la operación a realizar:\n1. Calcular perímetro\n2. Calcular área\n3. Número de lados\n4. Desplazar figura\n5. Hacer zoom\n6. Salir");
            opcion = teclado.nextInt();
            switch(opcion){
                case 1:
                    System.out.println("El perímetro del triángulo introducido es "+Math.abs(T.perimetroTriangulo())+" cm");
                    break;
                case 2:
                    System.out.println("El área del triángulo introducido es "+Math.abs(T.areaTriangulo())+" cm²");
                    break;
                case 3:
                    System.out.println("El número de la dos de la figura es: "+T.nLados());
                    break;
                case 4:
                    T.desplazarFigura();
                    break;
                case 5:
                    T.zoom();
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay 3 opciones, por favor, selecione 1, 2, 3, 4, 5 ó 6.");
            }
        } while (opcion != 6);
    }

    /**
     * Método que gestiona las operaciones del cuadrado
     */
    public static void controlaCuadrado(){
        int opcion;
        System.out.println("Introduzca los puntos del cuadrado:");
        double x, y;
        entrada = new ArrayList<Punto>();
        for (int i=0; i<4; ++i) {
            System.out.println("Introduzca la coordenada X del "+(i+1)+" punto:");
            x = teclado.nextDouble();
            System.out.println("Introduzca la coordenada Y del "+(i+1)+" punto:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }

        Cuadrado C = new Cuadrado(entrada);

        do {
            System.out.println("Seleccione la operación a realizar:\n1. Calcular perímetro\n2. Calcular área\n3. Número de lados\n4. Desplazar figura\n5. Hacer zoom\n6. Salir");
            opcion = teclado.nextInt();
            switch(opcion){
                case 1:
                    System.out.println("El perímetro del cuadrado introducido es "+Math.abs(C.perimetroCuadrado())+" cm");
                    break;
                case 2:
                    System.out.println("El área del cuadrado introducido es "+Math.abs(C.areaCuadrado())+" cm²");
                    break;
                case 3:
                    System.out.println("El número de la dos de la figura es: "+C.nLados());
                    break;
                case 4:
                    C.desplazarFigura();
                    break;
                case 5:
                    C.zoom();
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay 3 opciones, por favor, selecione 1, 2, 3, 4, 5 ó 6.");
            }
        } while (opcion != 6);
    }

    /**
     * Método que gestiona las operaciones del pentágono
     */
    public static void controlaPentagono(){
        int opcion;
        System.out.println("Introduzca los puntos del pentágono:");
        double x, y;
        entrada = new ArrayList<Punto>();
        for (int i=0; i<5; ++i) {
            System.out.println("Introduzca la coordenada X del "+(i+1)+" punto:");
            x = teclado.nextDouble();
            System.out.println("Introduzca la coordenada Y del "+(i+1)+" punto:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }

        Pentagono P = new Pentagono(entrada);

        do {
            System.out.println("Seleccione la operación a realizar:\n1. Calcular perímetro\n2. Calcular área\n3. Número de lados\n4. Desplazar figura\n5. Hacer zoom\n6. Salir");
            opcion = teclado.nextInt();
            switch(opcion){
                case 1:
                    System.out.println("El perímetro del pentágono introducido es "+Math.abs(P.perimetroPentagono())+" cm");
                    break;
                case 2:
                    System.out.println("El área del pentágono introducido es "+Math.abs(P.areaPentagono())+" cm²");
                    break;
                case 3:
                    System.out.println("El número de la dos de la figura es: "+P.nLados());
                    break;
                case 4:
                    P.desplazarFigura();
                    break;
                case 5:
                    P.zoom();
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay 3 opciones, por favor, selecione 1, 2, 3, 4, 5 ó 6.");
            }
        } while (opcion != 6);
    }

    /**
     * Método que gestiona las operaciones del hexágono
     */
    public static void controlaHexagono(){
        int opcion;
        System.out.println("Introduzca los puntos del hexágono:");
        double x, y;
        entrada = new ArrayList<Punto>();
        for (int i=0; i<6; ++i) {
            System.out.println("Introduzca la coordenada X del "+(i+1)+" punto:");
            x = teclado.nextDouble();
            System.out.println("Introduzca la coordenada Y del "+(i+1)+" punto:");
            y = teclado.nextDouble();
            entrada.add(new Punto(x, y));
        }

        Hexagono H = new Hexagono(entrada);

        do {
            System.out.println("Seleccione la operación a realizar:\n1. Calcular perímetro\n2. Calcular área\n3. Número de lados\n4. Desplazar figura\n5. Hacer zoom\n6. Salir");
            opcion = teclado.nextInt();
            switch(opcion){
                case 1:
                    System.out.println("El perímetro del hexágono introducido es "+Math.abs(H.perimetroHexagono())+" cm");
                    break;
                case 2:
                    System.out.println("El área del hexágono introducido es "+Math.abs(H.areaHexagono())+" cm²");
                    break;
                case 3:
                    System.out.println("El número de la dos de la figura es: "+H.nLados());
                    break;
                case 4:
                    H.desplazarFigura();
                    break;
                case 5:
                    H.zoom();
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay 3 opciones, por favor, selecione 1, 2, 3, 4, 5 ó 6.");
            }
        } while (opcion != 6);
    }

    public static void main(String[] args) {
        int opcion;
        do {
            System.out.println("Seleccione el polígono con el que desea trabajar:\n1. Triángulo\n2. Cuadrado\n3. Pentágono\n4. Hexágono\n5. Salir");
            opcion = teclado.nextInt();

            switch(opcion){
                case 1:
                    controlaTriangulo();
                    break;
                case 2:
                    controlaCuadrado();
                    break;
                case 3:
                    controlaPentagono();
                    break;
                case 4:
                    controlaHexagono();
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Solo hay cinco opciones, por favor, seleccione 1, 2, 3, 4 ó 5.");
            }
        } while (opcion != 5);
    }
}
