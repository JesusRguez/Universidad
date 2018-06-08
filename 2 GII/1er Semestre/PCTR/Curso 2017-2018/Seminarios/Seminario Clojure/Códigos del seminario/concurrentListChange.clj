(defn insertarelemento [listadeseos elemento]
  (dosync (alter listadeseos conj elemento)))

(def listadeseosFamilia (ref '("iPad")))
(def listadeseosOriginal @listadeseosFamilia)

(println "La lista de los deseos original es" listadeseosOriginal)

(future (insertarelemento listadeseosFamilia "MBP"))
(future (insertarelemento listadeseosFamilia "Bike"))

(. Thread sleep 1000)

(println "La lista de los deseos original es" listadeseosOriginal)
(println "La lista de los deseos actualizada es" @listadeseosFamilia)
