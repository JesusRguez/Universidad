/*****************************************************************************
Juan Boubeta Puig <juan.boubeta@uca.es>
Antonio Balderas Alberico <antonio.balderas@uca.es>
Universidad de Cádiz (Spain)
*****************************************************************************/

package eventos;

public class EventoHogar {	
	
	private String hogar; 
	private String sensor;
	private String localizacion; 
	private float latitud; 
	private float longitud;
	private String tiempoRegistro;
	private float consumoEnergetico; 
	private float luz; // lux
	private float temperaturaExt; // temperatura exterior
	
	public EventoHogar(String ho, String s, String l, float la, float lo, String t, 
			float e, float ti, float te) {
		hogar = ho; 
		sensor = s; 
		localizacion = l; 
		latitud = la; 
		longitud = lo; 
		tiempoRegistro = t; 
		consumoEnergetico = e; 
		luz = ti; 
		temperaturaExt = te; 
	}
		
	public EventoHogar() {
		
	}

	public String getHogar() {
		return hogar;
	}
	
	public String getSensor() {
		return sensor;
	}

	public String getLocalizacion() {
		return localizacion;
	}

	public float getLatitud() {
		return latitud;
	}

	public float getLongitud() {
		return longitud;
	}

	public String getTiempoRegistro() {
		return tiempoRegistro;
	}

	public float getConsumoEnergetico() {
		return consumoEnergetico;
	}

	public float getLuz() {
		return luz;
	}

	public float getTemperaturaExt() {
		return temperaturaExt;
	}
	
	public void setHogar(String ho) {
		hogar = ho;
	}
	
	public void setSensor(String s) {
		sensor = s; 
	}

	public void setLocalizacion(String l) {
		localizacion = l; 
	}

	public void setLatitud(float la) {
		latitud = la; 
	}

	public void setLongitud(float lo) {
		longitud = lo; 
	}

	public void setTiempoRegistro(String t) {
		tiempoRegistro = t; 
	}

	public void setConsumoEnergetico(float e) {
		consumoEnergetico = e; 
	}

	public void setLuz(float ti) {
		luz = ti; 
	}

	public void setTemperaturaExt(float te) {
		temperaturaExt = te; 
	}

	@Override
	public String toString() {
		return "Lugar:  " + hogar + "\n - sensor=" + sensor
				+ "\n - latitud=" + latitud 
				+ "\n - longitud=" + longitud + "\n - tiempoRegistro=" + tiempoRegistro
				+ "\n - luz=" + luz
				+ "\n - temperaturaExt=" + temperaturaExt
				+ "\n";
	}
}