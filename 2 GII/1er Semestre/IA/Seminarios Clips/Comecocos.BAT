(deftemplate comecocos
	(slot posX (type INTEGER))
	(slot posY (type INTEGER))
	(slot contador (type INTEGER))
	(slot vida (type INTEGER))
)
(deftemplate fantasma
	(slot posX (type INTEGER))
	(slot posY (type INTEGER))
)
(deftemplate fruta
	(slot posX (type INTEGER))
	(slot posY (type INTEGER))
)
(defrule GANAR
	(comecocos (contador 10))
	=>(printout t cvff "Has ganado." cvff)
)
(defrule GAMEOVER
	(comecocos (vida 0))
	=>(printout t cvff "¡GAME OVER!" cvff)
)
(defrule COMER
	?comecocos<-(comecocos (posX ?x)(posY ?y)(contador ?c)(vida ?v))
	?fruta<-(fruta (posX ?x)(posY ?y))
	=>(modify ?comecocos (contador (+ ?c 1)))
	  (retract ?fruta)
)
(defrule MORIR
	?comecocos<-(comecocos (posX ?x)(posY ?y)(contador ?c)(vida ?v))
	?fantasma<-(fantasma (posX ?x)(posY ?y))
	=>(modify ?comecocos (posX 1)(posY 1)(vida (- ?v 1)))
)
)deffacts iniciales
	(fruta (posX 1)(posY 3))
	(fruta (posX 3)(posY 2))
	(fantasma (posX 4)(posY 3))
)