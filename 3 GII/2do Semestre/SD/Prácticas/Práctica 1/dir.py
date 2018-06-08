import shutil, os

archivo = "/etc/passwd"

if os.path.exists(archivo):
	with open(archivo, 'rb') as fich:
		linea=fich.readline()
		while(linea!=""):
			L = linea.split(":")
			print(L[len(L)-2])
			linea=fich.readline()
