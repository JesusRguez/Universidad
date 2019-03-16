#!/bin/bash

cd ~/importante/

fecha=$(date +%Y%m%d)

for i in */; do
    tar -cvzf /media/backup/"${i%/}_$fecha.tgz" "$i";
done
