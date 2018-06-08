(clear)
(reset)
(deftemplate persona
(multislot nombre) ;para almacenar nombre y apellidos
(slot dni (type INTEGER))
(slot profesion (default estudiante))
(slot nacionalidad (allowed-values Es Fr Po Al In It))
)