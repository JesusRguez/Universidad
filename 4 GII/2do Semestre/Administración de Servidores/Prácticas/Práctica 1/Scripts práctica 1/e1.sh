#!/bin/bash
archivos=$(ls "$1")
n=0
for i in ${archivos[@]}
do
    mv -f "$i" "${n}"
    let n=n+1
done
