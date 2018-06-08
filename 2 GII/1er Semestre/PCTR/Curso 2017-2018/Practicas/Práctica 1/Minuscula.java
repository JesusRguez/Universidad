import java.io.*;
class Minuscula
{
    public static void main (String[] args) throws IOException
    {
        int i;
        int dato;
        //esto fuerza la recoleccion de basura
        System.gc();
        //muestra el tiempo actual en milisegundos
        System.out.println(System.currentTimeMillis());
        //muestra propiedades del sistema
        System.out.println(System.getProperties());
        System.out.println("Introduzca un caracter...");
        do
        {
            i = System.in.read();
            dato = Character.toLowerCase((char) i);
            System.out.write(dato);
        } while (true); //salir con CTRL-B, en JCreator o CTRL-C desde un shell
    }
}
