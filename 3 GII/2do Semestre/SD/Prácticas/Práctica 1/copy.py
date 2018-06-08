import shutil, os

origen = '/etc/network/interfaces'
destino = '/etc/network/interfaces_bck'

if os.path.exists(origen):
	with open(origen, 'rb') as forigen:
		with open(destino, 'wb') as fdestino:
			shutil.copyfileobj(forigen, fdestino)
			print("Archivo copiado")
