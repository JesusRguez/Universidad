#!/bin/bash

tarjetas=(192.168.1.2 192.168.1.3)
for t in "${tarjetas[@]}"
do
	echo Haciendo ping a $t
	ping -c 3 $t
done
