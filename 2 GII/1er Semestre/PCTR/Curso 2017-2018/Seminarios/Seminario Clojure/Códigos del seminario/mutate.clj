(def saldo (ref 0))

(println "El saldo es" @saldo)

(ref-set saldo 100)

(println "El saldo ahora es de" @saldo)
