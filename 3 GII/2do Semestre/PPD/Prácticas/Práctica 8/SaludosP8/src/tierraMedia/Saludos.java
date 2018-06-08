package tierraMedia;

import java.util.HashMap;
import java.util.Map;

import javax.ws.rs.*;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.core.MediaType;

@Path("/saludos")
public class Saludos {
@GET
@Path("/gondor")
@Produces(MediaType.TEXT_PLAIN)
public String sayPlainTextHello(){return "Aragorn: Salve rey Théoden";}

@GET
@Path("/rohan")
@Produces(MediaType.TEXT_PLAIN)
public String sayPlainTextHello2(){return "Théoden: Bienvenido Aragorn, hijo de Arathorn, heredero al trono de Isildur";}

@GET
@Path("/hayId/{oid}")
@Produces(MediaType.TEXT_PLAIN)
public String sayHelloWithId(@PathParam("oid")int id)
{return "Hay "+id+" reinos de los hombres en la Tercera Edad del Sol, Gondor y Rohan";}

@GET
@Path("/heroeQuery")
@Produces(MediaType.TEXT_PLAIN)
public String sayHelloWithQuery(@QueryParam("name")String
name,@QueryParam("surname")String surname )
{return "Y aquí está nuestro pequeño héroe, " + name + " " + surname + " un hobbit de la comarca";}

@GET
@Path("/dateJSON")
@Produces({"application/json"})
public Fechas getDate_JSON() {
Fechas oneDate = new Fechas();
oneDate.setDay(20);
oneDate.setMonth(04);
oneDate.setYear (2018);
return oneDate;}

@POST
@Path("/name")
@Consumes(MediaType.TEXT_PLAIN)
@Produces(MediaType.TEXT_PLAIN)
public String HelloName(String myName){
return "Hola "+myName;}

@POST
@Path("/myDateForm")
@Consumes(MediaType.APPLICATION_FORM_URLENCODED)
@Produces(MediaType.APPLICATION_JSON)
public Fechas dateToText(@FormParam("day") int myDay,
@FormParam("month") int myMonth, @FormParam("year") int myYear){
Fechas myDate = new Fechas();
myDate.setDay(myDay);
myDate.setMonth(myMonth);
myDate.setYear(myYear);
return myDate;
}

private static Map<String, Fechas> myMap = new HashMap<>();
static{
Fechas myDate = new Fechas();
myDate.setDay(25);
myDate.setMonth(12);
myDate.setYear(2014);
myMap.put("ConcilioElrond", myDate);
myMap.put("ConcilioBlanco", myDate);
myMap.put("DerrotaSauron", myDate);
}

@PUT
@Path("/modifyDate/{date}")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.TEXT_PLAIN)
public String modifyImportantDate(@PathParam("date") String key, Fechas myDate) {
myMap.put(key, myDate);
return "Fecha modificada"; }

@PUT
@Path("/deleteDate/{date}")
@Produces(MediaType.TEXT_PLAIN)
public String deleteImportantDate(@PathParam("date") String key) {
myMap.remove(key);
return "Fecha eliminada"; }

@GET
@Path("/ip")
@Produces(MediaType.TEXT_PLAIN)
public String IpObtain(){
Client cliente = ClientBuilder.newClient();
String t = cliente.target("https://api.ipify.org")
.request(MediaType.TEXT_PLAIN).get(String.class);
cliente.close();
return "La IP de la comarca es: " + t;
}
}

