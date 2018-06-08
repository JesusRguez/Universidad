import shutil, os, sys

archivo = "/etc/passwd"
usuario = sys.argv[1]
encontrado = False

if(len(sys.argv)!=2):
	print("Introduce un usuario")
else:
	if os.path.exists(archivo):
		with open(archivo, 'rb') as fich:
			linea=fich.readline()
			while(linea!="" and not encontrado):
				L = linea.split(":")
				if(L[0] == usuario):
					encontrado=True
					print(L[len(L)-1])
				linea=fich.readline()
			if (not encontrado):
				print("No se ha encontrado el usuario")
