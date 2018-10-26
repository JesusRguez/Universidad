/**
 * @author Jesús Rodríguez Heras
 * @version 1.0
 */

package hospital;

public class Paciente{
    String dni, nombre, direccion, aseguradora, diagnostico, sexo;
    int telefono, edad, nss;

    public Paciente(){};

    /**
     * Constructor de Paciente
     * @param dni         DNI del paciente
     * @param nombre      Nombre del paciente
     * @param direccion   Dirección del paciente
     * @param telefono    Teléfono del paciente
     * @param aseguradora Aseguradora del paciente
     * @param diagnostico Diagnóstico del paciente
     * @param sexo        Sexo del paciente
     * @param edad        Edad del paciente
     * @param nss         Número de la seguridad social del paciente
     */
    public Paciente(String dni, String nombre, String direccion, int telefono, String aseguradora, String diagnostico, String sexo, int edad, int nss){
        this.dni = dni;
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.aseguradora = aseguradora;
        this.diagnostico = diagnostico;
        this.sexo = sexo;
        this.edad = edad;
        this.nss = nss;
    }

    /**
     * Método para obtener el DNI de un paciente
     * @return Retorna el DNI del paciente
     */
    public String getDNI(){
        return this.dni;
    }

    /**
     * Método para establecer el DNI de un paciente
     * @param d DNI del paciente
     */
    public void setDNI(String d){
        this.dni = d;
    }

    /**
     * Método para obtener el nombre de un paciente
     * @return Retorna el nombre del paciente
     */
    public String getNombre(){
        return this.nombre;
    }

    /**
     * Método para establecer el nombre de un paciente
     * @param n Nombre del paciente
     */
    public void setNombre(String n){
        this.nombre = n;
    }

    /**
     * Método para obtener la dirección de un paciente
     * @return Retorna la dirección del paciente
     */
    public String getDireccion(){
        return this.direccion;
    }

    /**
     * Método para establecer la dirección de un paciente
     * @param d Dirección del paciente
     */
    public void setDireccion(String d){
        this.direccion = d;
    }

    /**
     * Método para obtener el teléfono de un paciente
     * @return Retorna el teléfono del paciente
     */
    public int getTelefono(){
        return this.telefono;
    }

    /**
     * Método para establecer el teléfono de un paciente
     * @param t Teléfono del paciente
     */
    public void setTelefono(int t){
        this.telefono = t;
    }

    /**
     * Método para obtener la aseguradora de un paciente
     * @return Retorna la aseguradora del paciente
     */
    public String getAseguradora(){
        return this.aseguradora;
    }

    /**
     * Método para establecer la aseguradora de un paciente
     * @param a Aseguradora del paciente
     */
    public void setAseguradora(String a){
        this.aseguradora = a;
    }

    /**
     * Método para obtener el diagnóstico de un paciente
     * @return Retorna el diagnóstico del paciente
     */
    public String getDiagnostico(){
        return this.diagnostico;
    }

    /**
     * Método para establecer el diagnóstico de un paciente
     * @param d Diagnóstico del paciente
     */
    public void setDiagnostico(String d){
        this.diagnostico = d;
    }

    /**
     * Método para obtener el sexo de un paciente
     * @return Retorna el sexo del paciente
     */
    public String getSexo(){
        return this.sexo;
    }

    /**
     * Método para establecer el sexo de un paciente
     * @param s Sexo del paciente
     */
    public void setSexo(String s){
        this.sexo = s;
    }

    /**
     * Método para obtener la edad de un paciente
     * @return Retorna la dedad del paciente
     */
    public int getEdad(){
        return this.edad;
    }

    /**
     * Método para establecer la edad de un paciente
     * @param e Edad del paciente
     */
    public void setEdad(int e){
        this.edad = e;
    }

    /**
     * Método para obtener el número de la seguridad social de un paciente
     * @return Retorna el número de la seguridad social del paciente
     */
    public int getNSS(){
        return this.nss;
    }

    /**
     * Método para establecer el número de la seguridad social de un paciente
     * @param n Número de la seguridad social del paciente
     */
    public void setNSS(int n){
        this.nss = n;
    }
}
