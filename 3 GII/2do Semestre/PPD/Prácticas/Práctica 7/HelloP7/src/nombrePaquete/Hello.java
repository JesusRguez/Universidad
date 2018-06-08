package nombrePaquete;

import java.util.HashMap;
import java.util.Map;

import javax.ws.rs.*;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.core.MediaType;

@Path("/gondor")
public class Hello {
@GET
@Produces(MediaType.TEXT_PLAIN)
public String sayPlainTextHello(){return "Hola Gondor";}

@GET
@Path("/rohan")
@Produces(MediaType.TEXT_PLAIN)
public String sayPlainTextHello2(){return "Hola Rohan";}

@GET
@Path("/hayId/{oid}")
@Produces(MediaType.TEXT_PLAIN)
public String sayHelloWithId(@PathParam("oid")int id)
{return "Hay "+id+" reinos de los hombres en la Tercera Edad del Sol";}

@GET
@Path("/holaQuery")
@Produces(MediaType.TEXT_PLAIN)
public String sayHelloWithQuery(@QueryParam("name")String
name,@QueryParam("surname")String surname )
{return "Hola " + name + " "+ surname;}

@GET
@Path("/dateJSON")
@Produces({"application/json"})
public MyDate getDate_JSON() {
MyDate oneDate = new MyDate();
oneDate.setDay(19);
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
@Path("/myDate2015")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public MyDate dateToString(MyDate myDate){
myDate.setYear(2015);
return myDate;}

@POST
@Path("/myDateForm")
@Consumes(MediaType.APPLICATION_FORM_URLENCODED)
@Produces(MediaType.APPLICATION_JSON)
public MyDate dateToText(@FormParam("day") int myDay,
@FormParam("month") int myMonth, @FormParam("year") int myYear){
MyDate myDate = new MyDate();
myDate.setDay(myDay);
myDate.setMonth(myMonth);
myDate.setYear(myYear);
return myDate;
}

private static Map<String, MyDate> myMap = new HashMap<>();
static{
MyDate myDate = new MyDate();
myDate.setDay(25);
myDate.setMonth(12);
myDate.setYear(2014);
myMap.put("Navidad", myDate);
myMap.put("Nochebuena", myDate);
myMap.put("AnioNuevo", myDate);
myMap.put("Reyes", myDate);
}

@PUT
@Path("/modifyDate/{date}")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.TEXT_PLAIN)
public String modifyImportantDate(@PathParam("date") String key, MyDate myDate) {
myMap.put(key, myDate);
return "Fecha modificada"; }

@PUT
@Path("/deleteDate/{date}")
@Consumes(MediaType.APPLICATION_JSON)
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
return "Mi ip es " +t;
}
}

