(deffacts iniciales
	(ubicacion oeste G H)
	(ubicacion oeste H I)
	(ubicacion oeste D E)
	(ubicacion oeste E F)
	(ubicacion oeste A B)
	(ubicacion oeste B C)
	(ubicacion norte D G)
	(ubicacion norte A D)
	(ubicacion norte E H)
	(ubicacion norte B E)
	(ubicacion norte F I)
	(ubicacion norte C F)
)
(defrule este_de
	(ubicacion oeste ?x ?y)
	=>(assert (ubicacion este ?y ?x))
)
(defrule sur_de
	(ubicacion norte ?x ?y)
	=>(assert (ubicacion sur ?y ?x))
)

(defrule transitiva
	(ubicacion ?u ?x ?y)
	(ubicacion ?u ?y ?z)
	=>(assert (ubicacion ?u ?x ?z))
)


(defrule noroeste
	(ubicacion norte ?x ?y)
	(ubicacion oeste ?y ?z)
	=>(assert (ubicacion noroeste ?x ?z))
)
(defrule noreste
	(ubicacion norte ?x ?y)
	(ubicacion este ?y ?z)
	=>(assert (ubicacion noreste ?x ?z))
)
(defrule suroeste
	(ubicacion sur ?x ?y)
	(ubicacion oeste ?y ?z)
	=>(assert (ubicacion suroeste ?x ?z))
)
(defrule sureste
	(ubicacion sur ?x ?y)
	(ubicacion este ?y ?z)
	=>(assert (ubicacion sureste ?x ?z))
)
(defrule situacion
	(ubicacion ?u ?x ?y)
	(situacion ?x ?y)
	=>(printout t ?u)
)