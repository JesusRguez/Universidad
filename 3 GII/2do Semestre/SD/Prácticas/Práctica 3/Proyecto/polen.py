import requests
import plotly
import plotly.graph_objs as go
from celery.schedules import crontab, timedelta
from celery import Celery, task
import time
import tweepy
import dropbox
import tempfile
import requests

# [ ]
# { }
# \

# Para twitter
consumer_key="qbLkLNSMeimtgX2KjAnFESpcL"
consumer_secret="07a34Bq5zmeDD1dDVvwV4XldC9r6ZJPFxzljci6JCiYqPDDOVc"
access_token=" 986600430422675457-40mznk6K4fMCYrTBR5i4pZAMWM0MdXz"
access_token_secret="QT3AtSFpCaBKw8F2q8RtVx8vuMhociEaUz0kDTBQDRFOu"
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_acces_token(access_token, access_token_secret)
api = tweepy.API(auth)

# Para dropbox
token="hKm7e_zTPsoAAAAAAAAR0AcyVIFNaj9kzasWqp2KTAWU7R62ajApg3PEh6icZ0RW"
dbx=dropbox.Dropbox(token)

def Calcula_Pares(sourceKey, sourceValue, translateKey, translateValue):
    ciudades=list();
    values=sourceValue;

    for i in range(0,len(sourceValue)):
        ciudades[i]=sourceValue[sourceKey.index(translateKey[i])]
        print(values[i],ciudades[i])


app.conf.beat_schedule = {
    "cada_dos_horas":{
        "task":"Busca_polen",
        "schedule":timedelta(hours=2) # Poner minutes=1 para hacer pruebas
    }
}
app.conf.timezone = "Europe/Madrid"

app = Celery("polen", backend="rpc://", broker="pyamqp://guest@localhost//")
@app.task(name=Busca_polen)
def Busca_Polen():
    req = requests.get("https://www.eltiempo.es/polen/")
    source = req.content
    source = source.split("mapConf.dataMap = {")[1]
    source,translate = source.split("mapConf.dataMapUrl= {")

    source = source.replace("};","")
    translate = translate.split("}")[0]

    source = source.replace("\"","")
    translate = translate.replace("\"","")

    source = source.strip()
    translate = translate.strip()

    source = source.replace(",",":")
    translate = translate.replace(",",":")

    source = source.split(':')
    translate = translate.split(':')

    #source = source.split(":")
    #translate = translate.split(":")
    sourceKey = list();
    translateKey = list();
    sourceValue = list();
    translateValue = list();

    for i in range(0,len(source)):
        if(i%2==0):
            sourceKey.append(source[i])
            translateKey.append(translate[i])
        else:
            sourceValue.append(source[i])
            translateValue.append(translate[i])
    #Calcula_Pares(sourceKey,sourceValue,translateKey,translateValue)

    #print(sourceKey)
    #print
    #print(sourceValue)
    #print
    #print
    #print(translateKey)
    #print
    #print(translateValue)

    finalKey = list();
    finalValue = list();

    for i in range(0,len(sourceKey)):
        for j in range (0,len(sourceKey)):
            if (sourceKey[i] == translateKey[j]):
                finalValue.append(sourceValue[i])
                finalKey.append(translateValue[j])

    print
    print
    print
    print
    print (finalKey)
    print
    print
    print (finalValue)
    print
    print

    f=open("prueba.csv",'w')
    for i in range(0,len(finalKey)):
        f.write(finalKey[i]+","+finalValue[i]+"\n")
    f.close()

    finalTranslatedValue = list();
    color = list();

    for i in range(0,len(finalValue)):
    	if(finalValue[i] == 'low'):
    		finalTranslatedValue.append(0.5)
    		color.append("rgb(0,128,0)")
    	if(finalValue[i] == 'medium'):
    		finalTranslatedValue.append(1.0)
    		color.append("rgb(255,211,0)")
    	if(finalValue[i] == 'high'):
    		finalTranslatedValue.append(1.5)
    		color.append("rgb(128,0,0)")

    data = [go.Bar(
        x=finalKey,
        y=finalTranslatedValue,
        marker=dict(
        color=color)
    )]
    plotly.offline.plot(data, filename = 'basic-bar')



    user=dbx.users_get_current_account()
    datos=Calcula_Pares(sourceKey, sourceValue, translateKey, translateValue)
    polenFecha="Polen "+ time.strftime("%c")
    dbx.files_upload(datos(datos, polenFecha, mute=True)

# app = Celery("tasks", backend="rpc://",broker="pyamqp://guest@localhost//")


#app = Celery("polen", backend="rpc://", broker="pyamqp://guest@localhost//")
app = Celery("publica", backend="rpc://", broker="pyamqp://guest@localhost//")
@app.task(name=Publica_twitter)
def Publica_twitter():
    update_status(texto que quieras poner juanpe)


Busca_Polen()
