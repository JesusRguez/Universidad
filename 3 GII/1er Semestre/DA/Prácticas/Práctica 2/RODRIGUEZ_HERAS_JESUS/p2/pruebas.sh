#!/bin/bash
niveles=(3124 3125 3054 3056 3052 3028 4056 4092)
for j in "${niveles[@]}"
do
    echo "Nivel $j: "
    ../simulador/simulador -level $j
done
