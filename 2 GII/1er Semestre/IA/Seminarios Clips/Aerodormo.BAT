(deftemplate aeronave
	(slot identificador_aeronave)
	(slot compania)
	(slot aerodromo_origen)
	(slot aerodromo_destino)
	(slot velocidad)
	(slot peticion (allowed-values Ninguna Despegue Aterrizaje Emergencia Rumbo)(default Ninguna))
	(slot estado (allowed-values enTierra Ascenso Crucero Descenso)(default enTierra))
)
(deftemplate aerodromo
	(slot identificador_aerodromo)
	(slot ciudad)
	(slot estado_radar (allowed-values ON OFF)(default OFF))
	(slot condiciones_atmosfericas (allowed-values Visibilidad velocidad_viento))
)
(deftemplate piloto
	(slot identificador_piloto)
	(slot identificador_aeronave)
	(slot estado (allowed-values OK SOS Ejecutando Stand_by)(default Stand_by))
)
(deftemplate vuelo
	(slot identificador_origen)
	(slot identificador_destino)
	(slot distancia)
	(slot velocidad_despegue (default 240))
	(slot velocidad_crucero (default 700))
)

(defrule Despegar
	?f1<-(aeronave (identificador_aeronave ?idaeronave)(compania ?co)(aerodromo_origen ?origen)(aerodromo_destino ?destino)(estado enTierra)(peticion Despegue))
	?f2<-(aerodromo (identificador_aerodromo ?origen)(ciudad ?corigen)(radioVisibilidad ?rV)(viento ?v)(estado_radar ON))
	?f3<-(piloto (identificador_piloto ?ip)(identificador_aeronave ?iaeronave)(estado OK))
	(test (> ?rV 5))
	(test (< ?v 75))
	(vuelo (origen ?aorigen)(destino ?adestino)(velocidad_despegue ?vd))
	(aerodromo (identificador_aerodromo ?adestino)(ciudad ?cdestino))
=>(printout t "La aeronave " ?iaeronave " de la compania " ?co " va a realizar la accion " despegue " desde el aerodromo " ?aorigen " de " ?corigen " con destino " ?cdestino crlf)
	(modify f1(estado Ascenso)(velocidad_actual ?vd)(peticion Ninguna)))
	(modify f3(estado Ejecutando))
)

(defrule Excepcion
	(aeronave (identificador_aeronave ?iaeronave)(compania ?co)(origen ?aorigen)(destino ?adestino)(peticion Despegue))
	(piloto (identificador_piloto ?ip)(identificaador_aeronave ?iaeronave)(estado ?estado ~OK))

=>
	(modify ?aeronave(peticion Emergencia))
	(printout t "El piloto no se encuentra disponible)
)

(deffacts iniciales
	(aeronave (identificador_aeronave FX111)(compania IBERIA)(aerodromo_origen XRY_Jerez)(aerodromo_destino Madrid)
)

