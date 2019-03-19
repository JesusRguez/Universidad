#!/bin/bash
archivos=$(ls "$1")
n=0
for i in ${archivos[@]}
do
    ext=$(echo $i | cut -d . -f 2)
    nombre="${n}.$ext"
    mv "${1}/$i" "${1}/$nombre"
    let n=n+1
done
