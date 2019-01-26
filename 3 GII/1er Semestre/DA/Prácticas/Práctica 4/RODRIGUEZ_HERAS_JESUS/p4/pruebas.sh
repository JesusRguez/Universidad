#!/bin/bash
niveles=(1224 2225 2054 2056 2556 2452 2428 3256 3292 1225 1690 1890 2356 2500 3556 3652 3828 4556 4802)
for j in "${niveles[@]}"
do
    echo "Nivel $j: "
    ../simulador/simulador -level $j
done
