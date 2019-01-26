/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

import java.util.concurrent.*;
import java.util.concurrent.Callable;
import java.util.ArrayList;

public class perfectNumbers implements Callable<ArrayList<Integer>>{

    public int rango;
    public int id;
    public int n;

    /**
     * Constructor de perfectNumbers
     * @param id Identificador del hilo
     * @param r  Rango de actuación del hilo
     */
    public perfectNumbers(int id, int r){
        this.id = id;
        this.rango = r;
    }

    /**
     * Método obtenerDivisores
     * @param  n Número del que queremos obtener sus divisores
     * @return   Retorna la lista de divisores del número n
     */
    public ArrayList<Integer> obtenerDivisores(int n){
        ArrayList<Integer> r = new ArrayList<Integer>();
        for (int i=0; i<n; ++i) {
            if (n % i == 0) {
                r.add(i);
            }
        }
        return r;
    }

    /**
     * Método esPerfecto
     * @param  d Lista de divisores
     * @param  n Número que queremos saber si es o no perfecto
     * @return   Retorna true en caso de que el número n sea perfecto y false en caso contrario
     */
    public boolean esPerfecto(ArrayList<Integer> d, int n){
        boolean perfecto = false;
        int suma = 0;
        for (int i=0; i<d.size(); ++i) {
            suma += d.get(i);
        }
        if (suma == n) {
            perfecto = true;
        }
        return perfecto;
    }

    public ArrayList<Integer> call(){
        ArrayList<Integer> solucion = new ArrayList<Integer>();
        for (int i=id*rango; i<id*rango+rango; ++i) {
            System.out.println("Comprobando el número "+i);
            ArrayList<Integer> divisores = new ArrayList<Integer>();
            divisores = obtenerDivisores(i);//aquí estarán los divisores de CADA numerito
            if (esPerfecto(divisores, i)) {
                solucion.add(i);//aquí estarán los números perfectos encontrados por cada hilo (una lista por hilo)
            }
        }
        return solucion; //cada hilo devuelve esta lista
    }

    public static void main(String[] args) throws InterruptedException {
        if (args.length != 2) {
            System.out.println("Por favor, introduzca dos números");
        }

        int n = Integer.parseInt(args[0]);
        int tareas = Integer.parseInt(args[1]);

        ExecutorService ejecutor = Executors.newFixedThreadPool(tareas);
        ArrayList<Future<ArrayList<Integer>>> numeros = new ArrayList<Future<ArrayList<Integer>>>();

        long time_start = System.currentTimeMillis();
        for (int i=0; i<tareas; ++i) {
            numeros.add(ejecutor.submit(new perfectNumbers(i, n/tareas)));//numeros será una lista de listas de números perfectos que se encuentran entre 0 y n
        }
        ejecutor.shutdown();
        ejecutor.awaitTermination(1, TimeUnit.HOURS);
        long time_end = System.currentTimeMillis();

        ArrayList<ArrayList<Integer>> div = new ArrayList<ArrayList<Integer>>();

        for (Future<ArrayList<Integer>> iterador:numeros) {
            try{
                div.add(iterador.get());
            }catch (Exception e) {
                System.out.println("Error en el Future");
            }
        }

        System.out.println("Los números perfectos encontrados son:");
        for (int i=0; i<div.size(); ++i) {
            for (int j=0; j<div.get(i).size(); ++j) {
                System.out.println(div.get(i).get(j));
            }
        }

        System.out.println("Tarda "+(time_end-time_start)+" milisegundos.");
    }
}
