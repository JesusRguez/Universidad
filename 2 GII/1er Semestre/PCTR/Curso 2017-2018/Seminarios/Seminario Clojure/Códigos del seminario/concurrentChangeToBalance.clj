(defn deposito [saldo cantidad]
  (dosync
    (println "Preparado para depositar..." cantidad)
    (let [saldoactual @saldo]
      (println "Simulando retraso en deposito...")
      (. Thread sleep 2000)
      (alter saldo + cantidad)
      (println "Hecho deposito de" cantidad))))

(defn reintegro [saldo cantidad]
  (dosync
    (println "Preparado para reintegro..." cantidad)
    (let [saldoactual @saldo]
      (println "Simulando retraso en reintegro...")
      (. Thread sleep 2000)
      (alter saldo - cantidad)
      (println "Hecho reintegro de" cantidad))))

(def saldo1 (ref 100))

(println "El saldo1 es" @saldo1)

(future (deposito saldo1 20))
(future (reintegro saldo1 10))

(. Thread sleep 10000)

(println "El saldo1 ahora es" @saldo1)
