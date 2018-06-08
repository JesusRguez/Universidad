(deffunction fpresion (?v2 ?ti ?p)
	(while(> ?ti 35)
		(modify ?v2(temperatura_interna(- ?ti 5)(presion(+ ?p 1)))
	)
)

(deffunction decrementar (?ti ?te)
	(if(> ?te ?ti) then
		?te<-(- ?te ?ti)
	)
)

(deftemplate valvula
	(slot nombre)
	(slot estado (allowed-values Abierta Cerrada)(default Cerrada))
	(slot presion (default 0))
	(slot temperatura_interna (default 0))
	(slot temperatura_externa (default 0))
)

(deffacts iniciales
	(valvula (nombre Entrada) (temperatura_interna 101) (temperatura_externa 35) (presion 1))
	(valvula (nombre Salida) (temperatura_interna 101) (temperatura_externa 155) (presion 5))
	(valvula (nombre Pasillo1) (temperatura_interna 99) (temperatura_externa 37) (estado Cerrada))
)

(defrule R1
	?v1<-(valvula (estado Abierta)(presion ?p))
=>
	(if(= ?p 5) then
		(modify ?v1(estado Cerrada)(presion 0))
	)
)

(defrule R2
	?v2<-(valvula(estado Cerrada)(presion ?p)(temperatura_interna ?ti))
	(test(< ?p 10))
	(test(> ?ti 35))
=>	
	(modify ?v2(estado Abierta)(presion (fpresion ?v2 ?ti ?p)))
)

(defrule R3
	?v1<-(valvula(nombre ?n1)(temperatura_interna ?ti)(temperatura_externa ?te))
	?v2<-(valvula(nombre ?n2)(temperatura_interna ?ti)(temperatura_externa ?te))
=>
	(if(< ?ti ?te)&(~ ?n1 ?n2) then
		(modify ?v2 (decrementar ?ti ?te))
		(modify ?v1 (estado Abierta))
		(modify ?v2 (estado Abierta))
	)
)