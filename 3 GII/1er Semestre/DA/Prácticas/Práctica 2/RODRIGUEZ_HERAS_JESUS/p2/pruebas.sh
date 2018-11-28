#!/bin/bash
niveles=(3124 3125 3054 3056 3056 3056 3052 3028 4056 4092)
pases=(0.5 0.6 0.4 0.5 0.7 1 0.5 0.6 0.3 0.5)
defenses=(30 40 40 50 40 50 40 60 70 80)
defensetypes=(30 40 30 40 20 50 40 50 70 70)
defenserandomness=(0.5 0.6 0.4 0.5 0.7 0.5 0.5 0.6 0.3 0.5)
for j in {0..9}
do
    echo "Nivel ${niveles[j]}: "
    ../simulador/simulador -level ${niveles[j]} -pases ${pases[j]} -defenses ${defenses[j]} -defensetypes ${defensetypes[j]} -defenserandomness ${defenserandomness[j]} -time 1000
done
