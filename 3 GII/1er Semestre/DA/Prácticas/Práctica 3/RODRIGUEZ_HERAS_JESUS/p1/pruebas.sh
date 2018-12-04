#!/bin/bash
niveles=(1324 1625 1854 2356 2856 3456 3552 3728 4356 4592 5432 5842 6248 6561 6842 7435 7854 8543 8999)
for j in "${niveles[@]}"
do
    echo "Nivel $j: "
    ../simulador/simulador -level $j
done
