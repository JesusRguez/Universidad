
/**
 * @author Jesus
 */
import java.util.Scanner;
public class Coche extends Vehiculo//Clase coche. Si se usa una interfeaz se escribe implements y si se usa otra clase extends.
{

    int ruedas = 4;
    boolean roto;
    String matricula = "";

    public Coche(String matricula) { //Constructor de la clase coche
        this.matricula = matricula; //Al usar el this, son variables diferentes y ocupan posiciones de memoria diferentes
    }
    
    //Si tenemos dos clases con el mismo método, dicha clase usará el méotdo más cercano a sí misma, es decir,
    //de la que menos tenga que heredar.
    public void arranca() //Método de la clase
    {   //En caso de que haya una variable local con el mismo nombre del de una variable de clase, usar el "this"
        //que es un puntero al de la clase y no a la variable local que tiene el mismo nombre y es al que haría
        //referencia en primera instacia
        if (roto) {
            System.out.println("El coche con matrícula " + matricula + " no puede arrancar porque está roto.");
        } else {
            System.out.println("El coche con matrícula " + matricula + " arranca porque no está roto.");
        }
    }
    
    
    public void detente()
    {
        System.out.println("Parate.");
    }

    //El String[] args es para recoger todos los datos que el usuario mete en el programa después de que se ejecute
    //con java "nombredelprograma" en la línea de comandos.
    public static void main(String[] args) //Método principal
    {
        Coche C = new Coche("8290GXT");
        Coche D = new Coche("1168HGB");
        C.roto = true;
        D.roto = false;

        C.arranca();
        D.arranca();
        
        int a=0;
        System.out.print("Introduce un número entero: ");
        Scanner teclado = new Scanner(System.in);
        try {
        a = teclado.nextInt();
        } catch (Exception ex){
            System.out.println("Se ha producido un error.");
        }
        System.out.println("Su número ha sido: " + a);
        
        //Ahora imprimiremos los argumentos:
        //Para introducir los argumentos directamente sin entrar en el CMD, nos vamos al proyecto>boton derecho>
        //>propiedades>run y en argumentos, escribimos los argumentos iniciales que queremos que se le pasen al programa.
        for(int i=0; i<args.length; i++)
        {
            System.out.println("El argumento " + i + " es: " + args[i]);
        }
    }
}
