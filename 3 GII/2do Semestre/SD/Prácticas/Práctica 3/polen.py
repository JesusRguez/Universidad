from celery.schedules import crontab, timedelta
from celery, import Celery, task
import time
import tweepy
import dropbox
import tempfile
import requests

# [ ]
# { }
# \

# Para twitter
consumer_key="..."
consumer_secret="..."
access_token="..."
access_token_secret="..."
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_acces_token(access_token, access_token_secret)
api = tweepy.API(auth)

# Para dropbox
token="hKm7e_zTPsoAAAAAAAAR0AcyVIFNaj9kzasWqp2KTAWU7R62ajApg3PEh6icZ0RW"
dbx=dropbox.Dropbox(token)

def Calcula_Pares(sourceKey, sourceValue, translateKey, translateValue):
    ciudades=list();
    values=sourceValue

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

app = Celery("tasks", backend="rpc://", broker="pyamqp://guest@localhost//")
@app.task(name=Busca_polen)
def Busca_polen():
    req=requests.get("https://www.eltiempo.es/polen")
    source = req.content
    source.split("mapConf.dataMap={")[1]
    source,translate=source.split("mapConf.dataMapUrl={")

    source=source.replace("};","")
    translate=translate.split("}")[0]

    source=source.replace("\"","")
    translate=translate.replace("\"","")

    source=source.strip()
    translate=translate.strip()

    source=source.replace(",",":")
    translate=translate.replace(",",":")

    source=source.split(":")
    translate=translate.split(":")

    sourceKey=list();
    translateKey=list();
    sourceValue=list();
    translateValue=list();

    for i in range(0,len(source)):
        if(i%2==0):
            sourceKey.append(source[i])
            translateKey.append(translate[i])
        else:
            sourceValue.append(source[i])
            translateValue.append(translate[i])

    user=dbx.users_get_current_account()
    datos=Calcula_Pares(sourceKey, sourceValue, translateKey, translateValue)
    polenFecha="Polen "+ time.strftime("%c")
    dbx.files_upload(datos(datos, polenFecha, mute=True)




app = Celery("tasks", backend="rpc://", broker="pyamqp://guest@localhost//")
@app.task(name=Publica_twitter)
def Publica_twitter():
    update_status(texto que quieras poner juanpe)
