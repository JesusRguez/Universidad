# Codificacion ISO Latin-1 y terminal EPS.

set encoding iso_8859_1
set terminal postscript eps

# Titulo de cada eje.

set xlabel "n (numero de celdas)"
set ylabel "t(n) (tiempo en segundos)"

# Estilo de presentacion (puntos interpolados linealmente).

#set data style linespoints

# Creacion de los ficheros EPS.

set output "graphic.eps"
plot 'data.txt' using 1:2 title "Sin pre-ordenacion" with lines, \
     '' using 1:3 title "Fusion" with lines, \
	 '' using 1:4 title "Rapida" with lines, \
	 '' using 1:5 title "Monticulo" with lines
