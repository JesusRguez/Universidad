(defglobal ?*ANNO=2015)

;;Funciones
(deffunction Decrementar(?a)
	(- ?a 1)
)	

(deffunction Diferencia(?a ?b)
	(- ?a ?b)
)

;;Definicion de plantillas
(deftemplate Usuario
	(slot DNI)
	(slot Pin)
	(slot Dinero)
)

(deftemplate Tarjeta
	(slot DNI)
	(slot Pin)
	(slot Intentos (default 3))
	(slot Limite (default 500))
	(slot Anno (default 2010))
	(slot Valida (allowed-values Si No)(default No))
)

(deftemplate Cuenta
	(slot DNI)
	(slot Saldo)
	(slot Estado (allowed-values enPantalla dineroEntregado Inicial SuperaLimite SinSaldo)(default Inicial))
)

;;Hechos iniciales
(deffacts Iniciales
	(Tarjeta (DNI 123456)(Pin 1212)(Intentos 3)(Limite 500)(Anno 2015))
	(Tarjeta (DNI 456456)(Pin 4545)(Intentos 3)(Limite 500)(Anno 2015))
	(Tarjeta (DNI 000111)(Pin 0011)(Intentos 0)(Limite 500)(Anno 2015))
	(Cuenta (DNI 123456)(Saldo 5000))
	(Cuenta (DNI 456456)(Saldo 33))
	(Cuenta (DNI 000111)(Saldo 30000))
)

;;Reglas
(defrule Supera_Intentos
	(Usuario (DNI ?x))
	(Tarjeta (DNI ?x)(Intentos 0))
=>
	(printout t "No quedan intentos." crlf)
)

(defrule Pin_Invalido
	(Usuario (DNI ?x)(Pin ?p1))
	?tarjeta <- (Tarjeta (DNI ?x)(Pin ?p2)(Intentos ?z))
	(test (neq ?p1 ?p2))
=>
	(modify ?tarjeta (Intentos Decrementar ?z))
	(printout t "Pin incorrecto. Intentos restantes: "?z crlf)
)

(defrule Valida_Tarjeta
	(Tarjeta (DNI ?x)(Pin ?y)(Intentos ?z)(Anno ?a))
	(Usuario (DNI ?x)(Pin ?y))
	(test (> ?z 0))
	(test (<= ?a ANNO))
=>
	(modify (Tarjeta (DNI ?x)(Valida Si))
)
