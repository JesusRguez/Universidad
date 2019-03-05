#!/bin/bash

direcciones=(192.168.1.39 192.168.1.40)
tarjetas=(zybo1 zybo2)
a=0
for d in "${direcciones[@]}"
do
	echo Comprobando la conexión con ${tarjetas[a]}.
	string=$(ping -c 3 $d)
	if [[ $string == *100%\ packet\ loss* ]]; then
		echo Tarjeta ${tarjetas[a]} desconectada. Compruebe la conexion.
	else
		echo Tarjeta ${tarjetas[a]} conectada.
	fi
	let a=a+1
done
