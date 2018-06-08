(clear)
(reset)
(deftemplate persona
(multislot nombre) ;para almacenar nombre y apellidos
(slot dni (type INTEGER))
(slot profesion (default estudiante))
(slot nacionalidad (allowed-values Es Fr Po Al In It))
)
(deftemplate intelectual_europeo
(multislot nombre)
(slot dni)
(slot idioma)
(slot nacionalidad)
)
(list-deftemplates) ;; para mostrar las plantillas definidas

(deffacts iniciales
;; con hechos estructurados
(persona (nombre Mario Cantero Cansino)
(dni 122333)
(profesion escritor)
(nacionalidad Es))
(persona (nombre Juana Bodega Gallego) (dni 3334444))
;; con hechos no estructurados
(ciudad Gertrudis Cadiz)
(ciudad Filoberto Sevilla)
);;deffacts
(facts) ;; visualizar los hechos actuales
;; no verás nada porque para añadir los hechos iniciales hay que usar la orden (reset) que restaura las condiciones iniciales:
(reset)
(facts)
(assert (ciudad Juana Cadiz))
(assert (persona (nombre Alicia Mata Rueda) (dni 1234)))
(assert (intelectual_europeo (nombre Victor Hugo) (idioma francés)))
(assert (persona (nombre Mateo Duran Barbera)
(dni 333221)))
(facts)
(retract 1)
(facts) ;; comprueba que se ha eliminado el hecho 1
(retract 3 5)
(facts) ;; comprueba que se han eliminado los hechos 3 y 5
(retract *)
(facts) ;; comprueba que se ha eliminado todo
(reset)
(reset)
(modify 1 (nombre Maria Cantero Cansino)))
(facts)
(duplicate 2 (nombre Maria Bodega Gallego) (dni 11))
(facts)
;;Los gaditanos y los sevillanos son andaluces
(defrule R1_gaditanos
(ciudad ?x Cadiz)
=>(assert(comunidad ?x Andalucia))
);;R1
(agenda) ;; lista de reglas del sistema
(defrule R2_sevillanos
(ciudad ?x Sevilla)
=>(assert (comunidad ?x Andalucia))
);;R2
(reset)
(agenda) ;; lista de reglas del sistema
(run 1) ;; ejecuta el sistema para disparar la primera regla de la agenda
(facts) ;; comprueba si se han añadido nuevos hechos al sistema
(run 1) ;; siguiente regla de la agenda
(facts)
(defrule R3_intelectuales
(persona (nombre ?x ?y ?z) (profesion escritor) (nacionalidad Es))
=> (assert (intelectual_europeo (nombre ?x ?y ?z) (nacionalidad española)))
);;R3
(agenda)
(refresh R1_gaditanos)
(agenda)