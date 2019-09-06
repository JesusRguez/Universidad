package oficina;

import java.util.*;

public class pruebaOficina{

    public static Oficina monitor = new Oficina();

    public static void main(String[] args) {
        Thread empleados[] = new Thread[10];
        Thread limpiador[] = new Thread[10];

        for (int i=0; i<10; ++i) {
            empleados[i] = new Thread(new Empleado(monitor));
            empleados[i].start();
            limpiador[i] = new Thread(new Limpiador(monitor));
            limpiador[i].start();
        }
    }

}
