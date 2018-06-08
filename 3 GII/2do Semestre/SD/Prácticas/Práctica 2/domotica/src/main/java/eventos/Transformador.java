/*****************************************************************************
Juan Boubeta Puig <juan.boubeta@uca.es>
Antonio Balderas Alberico <antonio.balderas@uca.es>
Universidad de C�diz (Spain)
*****************************************************************************/

package eventos;

import org.mule.api.annotations.ContainsTransformerMethods;
import org.mule.api.annotations.Transformer;
import org.mule.module.json.JsonData;

import eventos.EventoHogar;

// ver http://www.mulesoft.org/docs/site/current3/apidocs/org/mule/module/json/JsonData.html


@ContainsTransformerMethods
public class Transformador
{
	@Transformer  
	public EventoHogar JSONToEventoHogar(JsonData obj) throws Exception 
	{	  	  
		EventoHogar evento = new EventoHogar();
		String nombreHogar = obj.getAsString("channel/name");
		/*
		evento.setHogar(nombreHogar);
		evento.setSensor(obj.getAsString("feed")); 
		evento.setLocalizacion(obj.getAsString("location/name"));
		evento.setLatitud(Float.parseFloat(obj.getAsString("location/lat")));
		evento.setLongitud(Float.parseFloat(obj.getAsString("location/lon")));
		evento.setTiempoRegistro(obj.getAsString("updated"));
		
		if(nombreHogar.equalsIgnoreCase("Residential information")) {
			evento.setConsumoEnergetico(Float.parseFloat(obj.getAsString("datastreams[1]/current_value")));
			evento.setTemperaturaInt(Float.parseFloat(obj.getAsString("datastreams[14]/current_value")));	
		}
		else if(nombreHogar.equalsIgnoreCase("HAC Center")) {
			evento.setTemperaturaInt(Float.parseFloat(obj.getAsString("datastreams[1]/current_value")));
			evento.setTemperaturaExt(Float.parseFloat(obj.getAsString("datastreams[3]/current_value")));
			evento.setConsumoEnergetico(Float.parseFloat(obj.getAsString("datastreams[11]/current_value")));
		}
		else {
			System.out.println("No es posible realizar la conversi�n");
		}
		*/
		
		if(nombreHogar.equalsIgnoreCase("my_house")) {
			evento.setHogar(nombreHogar); 
			evento.setSensor(obj.getAsString("channel/description"));
			evento.setLatitud(Float.parseFloat(obj.getAsString("channel/latitude")));
			evento.setLongitud(Float.parseFloat(obj.getAsString("channel/longitude")));
			evento.setTemperaturaExt(Float.parseFloat(obj.getAsString("feeds[1]/field1")));
			evento.setLuz(Float.parseFloat(obj.getAsString("feeds[1]/field2")));
			System.out.println("Evento transformado: " + evento);
		}
		else {
			System.out.println("No es posible realizar la conversi�n");
		}
		
		return evento; 
	}
}