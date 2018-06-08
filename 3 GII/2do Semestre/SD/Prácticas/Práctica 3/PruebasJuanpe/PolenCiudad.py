import tweepy
import dropbox
import time

# Para twitter
consumer_key="qbLkLNSMeimtgX2KjAnFESpcL"
consumer_secret="07a34Bq5zmeDD1dDVvwV4XldC9r6ZJPFxzljci6JCiYqPDDOVc"
access_token="986600430422675457-40mznk6K4fMCYrTBR5i4pZAMWM0MdXz"
access_token_secret="QT3AtSFpCaBKw8F2q8RtVx8vuMhociEaUz0kDTBQDRFOu"
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

# Para dropbox
token="hKm7e_zTPsoAAAAAAAAR0AcyVIFNaj9kzasWqp2KTAWU7R62ajApg3PEh6icZ0RW"
dbx=dropbox.Dropbox(token)


def Publica_twitter():
    update_status("texto que quieras poner juanpe")


def ObtenerFichero():
    nombreFicheros = list()
    nombresModificados = list()
    fechas = list()
    response = dbx.files_list_folder("")
    for file in response.entries:
        nombreFicheros.append(file.name)
    #dbx.files_download_to_file("ruta/nombre.txt", '/nombre.txt')
    for i in range(0,len(nombreFicheros)):
        nombresModificados.append(nombreFicheros[i].replace("Polen ",""))
        nombresModificados[i] = nombresModificados[i].replace(".csv","")
        print nombresModificados[i]
        fechas.append(time.strptime(nombresModificados[i],'%c'))
        #print fechas[i]

    maxFechaIndex = fechas.index(max(fechas))
    #filename = "Polen "+time.strftime("%c",maxFecha)+".csv"
    print nombreFicheros[maxFechaIndex]
    dbx.files_download_to_file('consulta.csv',"/"+nombreFicheros[maxFechaIndex])


def translateValue(mensaje):

        mensaje = mensaje.replace('high','alto')
        mensaje = mensaje.replace('medium','medio')
        mensaje = mensaje.replace('low','bajo')

        return mensaje


def BuscarCiudad():
    ciudad = raw_input("Introduzca la ciudad donde quiere ver el nivel de polen: ")


    f=open("consulta.csv",'r')
    linea=f.readline()
    while linea!="":
        if (ciudad in linea):
            mensaje=linea.split(",")[1]
        linea=f.readline()

    f.close()

    respuesta="El nivel de polen en "+ciudad+" es "+str(translateValue(str(mensaje)))
    print respuesta
    try:
        api.update_status(respuesta)
    except tweepy.error.TweepError:
        pass

ObtenerFichero()
BuscarCiudad()
