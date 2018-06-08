package cliente;

import java.io.*;

public class ClienteDaytime {

    public static void main(String[] args) {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        try {
            System.out.println("Bienvenido al cliente Daytime.\n");
            String nombreMaquina = "localhost"; // usa el nombre de maquina por defecto
            String numPuerto = "13"; // numero de puerto por defecto
            System.out.println("Aqui esta la marca de tiempo recibida del servidor"
                    + ClienteDaytimeAuxiliar.obtenerMarcaTiempo(nombreMaquina, numPuerto));
        } // fin de try
        catch (Exception ex) {
            ex.printStackTrace();
        } // fin de catch
    } // fin de main
} // fin de class

