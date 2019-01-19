(def cuentaCorriente (ref 500))
(def cuentaAhorros (ref 600))

(defn retirarcuenta [saldoExtraer saldoRestringir cantidad]
  (dosync
    (let [saldoTotal (+ @saldoExtraer (ensure saldoRestringir))]
      (. Thread sleep 1000)
      (if (>= (- saldoTotal cantidad) 1000)
        (alter saldoExtraer - cantidad)
        (println "Lo sentimos, no se puede realizar el reintegro, produce error")))))

(println "La cuenta corriente tiene" @cuentaCorriente)
(println "La cuenta de ahorros tiene" @cuentaAhorros)
(println "El saldo total es de" (+ @cuentaCorriente @cuentaAhorros))

(future (retirarcuenta cuentaCorriente cuentaAhorros 100))
(future (retirarcuenta cuentaAhorros cuentaCorriente 100))

(. Thread sleep 2000)

(println "La cuenta corriente tiene" @cuentaCorriente)
(println "La cuenta de ahorros tiene" @cuentaAhorros)
(println "El saldo total es de" (+ @cuentaCorriente @cuentaAhorros))
