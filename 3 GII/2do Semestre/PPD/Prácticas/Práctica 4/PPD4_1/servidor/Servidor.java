package servidor;

import java.io.*;
import java.net.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Servidor implements Runnable {

    MiSocketStream socketFlujo;
    static AtomicInteger clientes = new AtomicInteger(0);

    public Servidor(MiSocketStream miSocketDatos) {
        this.socketFlujo = miSocketDatos;
    }

    public void run() {
        clientes.incrementAndGet();
        String bienvenida = "Bienvenido. Eres el cliente número " + clientes;
        try {
            socketFlujo.enviaMensaje(bienvenida);
        } catch (Exception e) {
            System.out.println("No he podido enviar la bienvenida.");
        }

        String operacion = "";
        char[] cuenta;
        try {
            operacion = socketFlujo.recibeMensaje();

        } catch (Exception e) {
            System.out.println("No he recibido nada por el socket.");
        }
        
        double a=0, b=0;
        boolean entrado, primeroNegativo=false; //Bandera para ver si el primer número es negativo
        char OP='+';
        String[] ooPP; //array de Strings para meter los operandos
		do{
			entrado=false;
			if(operacion.contains("*") && entrado==false){
				//System.out.println("Multiplica"); //Test
			    ooPP=operacion.split("\\*");
			    a=Double.parseDouble(ooPP[0]);
			    b=Double.parseDouble(ooPP[1]);
			    OP='*';
			    entrado=true;
			}
			
			if(operacion.contains("/") && entrado==false){
				//System.out.println("Divide"); //Test
			    ooPP=operacion.split("\\/");
			    a=Double.parseDouble(ooPP[0]);
			    b=Double.parseDouble(ooPP[1]);
			    OP='/';
			    entrado=true;
			}
			
			if(operacion.contains("+") && entrado==false){
				//System.out.println("Suma"); //Test
			    ooPP=operacion.split("\\+");
			    a=Double.parseDouble(ooPP[0]);
			    b=Double.parseDouble(ooPP[1]);
			    OP='+';
			    entrado=true;
			}
			
			if(operacion.contains("-") && entrado==false){
				//System.out.println("Resta"); //Test
			    ooPP=operacion.split("\\-");
			    if(ooPP[0]==null){
			    	operacion=ooPP[1];
			    	primeroNegativo=true; //Como el primer numero es negativo, la bandera se establece a true
			    }else{
					a=Double.parseDouble(ooPP[0]);
					b=Double.parseDouble(ooPP[1]);
					OP='-';
			    }
			    entrado=true;
			}
			
        }while(primeroNegativo==true); //Se reitera si el primer numero es negativo
        
        Double resultado=0.0;
        boolean infinito = false, indeterminacion = false;

        switch (OP) {
            case '+':
                resultado = a + b;
                break;
            case '-':
                resultado = a - b;
                break;
            case '*':
                resultado = a * b;
                break;
            case '/':
                if (b == 0) {
                    infinito = true;
                    if (a == 0) {
                        indeterminacion = true;
                    }
                } else {
                    resultado = a / b;
                }
                break;
        }

        if (indeterminacion == true) {
            String falloIndeterminacion = "Indeterminacion";
            try {
                socketFlujo.enviaMensaje(falloIndeterminacion);
            } catch (Exception e) {
                System.out.println("No he podido enviar el fallo por indeterminacion");
            }
        } else {
            if (infinito == true) {
                String falloInfinito = "Infinito";
                try {
                    socketFlujo.enviaMensaje(falloInfinito);
                } catch (Exception e) {
                    System.out.println("No he podido enviar el fallo por infinito");
                }
            } else {
                String solucion = resultado.toString();
                try {
                    socketFlujo.enviaMensaje(solucion);
                } catch (Exception e) {
                    System.out.println("No he podido enviar la solucion");
                }
            }
        }

        clientes.decrementAndGet();
    }

    public static void main(String[] args) {
        int puertoServidor = 13; // puerto por defecto
        try {
            // instancia un socket stream para aceptar las conexiones
            ServerSocket miSocketConexion = new ServerSocket(puertoServidor);
            System.out.println("El servidor de la calculadora esta listo.");
            while (true) { // bucle infinito // espera para aceptar una conexion 
                System.out.println("Espera una conexion.");
                MiSocketStream miSocketDatos = new MiSocketStream(miSocketConexion.accept());

                // Nota: no hay necesidad de leer una peticion - la peticion es implicita.
                System.out.println("Un cliente ha hecho una conexion.");

                ExecutorService executor = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

                executor.execute(new Servidor(miSocketDatos));

                executor.shutdown();

                // ahora manda la respuesta al solicitante
                miSocketDatos.close();
            } // fin de while
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        }
    } // fin de main
} // fin de class

