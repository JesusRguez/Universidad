import filecmp, shutil, os

origen = "/etc/network/interfaces"
destino = "/etc/network/interfaces_bck"

if os.path.exists(origen):
	with open(origen, 'rb') as forigen:
		with open(destino, 'rb') as fdestino:
			dato1=forigen.readline()
			dato2=fdestino.readline()
			iguales = True
			while (dato1 !="" and dato2 !="" and iguales):
				if(dato1 != dato2):
					iguales=False
				dato1=forigen.readline()
				dato2=fdestino.readline()
			if (iguales):
				print("Ficheros iguales")
			else:
				print("Ficheros distintos")
