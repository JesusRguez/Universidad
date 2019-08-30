package ibex5;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface iIBEX5 extends Remote{
    /*
     * Método para consultar las cotizaciones generales
     * @return Devuelve todas las cotizaciones de las empresas en ese momento
     */
    public String consultarCotizaciones() throws RemoteException;

    /*
     * Método para consultar las cotizaciones de una empresa
     * @param  empresa         Empresa de la cual queremos saber las cotizaciones en ese momento
     * @return                 Devuelve las cotizaciones de la empresa señalada
     */
    public String consultarCotizacion(String empresa) throws RemoteException;
}
