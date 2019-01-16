#!/bin/bash
niveles=(1224 2225 2054 2056 2556 2452 2428 3256 3292)
for j in "${niveles[@]}"
do
    echo "Nivel $j: "
    ../simulador/simulador -level $j
done
