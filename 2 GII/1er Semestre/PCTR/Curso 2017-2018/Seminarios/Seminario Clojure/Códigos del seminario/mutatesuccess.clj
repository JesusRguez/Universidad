(def saldo (ref 0))

(println "El saldo es" @saldo)

(dosync 
  (ref-set saldo 100))

(println "El saldo ahora es" @saldo)
