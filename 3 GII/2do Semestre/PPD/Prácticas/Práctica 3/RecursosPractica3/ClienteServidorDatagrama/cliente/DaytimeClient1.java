
import java.io.*;

/**
 * This module contains the presentaton logic of a DaytimeClient.
 *
 * @author M. L. Liu
 */
public class DaytimeClient1 {

    public static void main(String[] args) {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        try {
            System.out.println("Welcome to the Daytime client.\n");
            String hostName = "localhost";  //   use the default host name
            String portNum = "13";          // default port number
            System.out.println("Here is the timestamp received from the server"
                    + DaytimeClientHelper1.getTimestamp(hostName, portNum));
        } // end try  
        catch (Exception ex) {
            ex.printStackTrace();
        } // end catch
    } //end main
} // end class
