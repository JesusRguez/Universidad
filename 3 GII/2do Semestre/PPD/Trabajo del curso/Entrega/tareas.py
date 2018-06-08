import requests
import tweepy
import tempfile
import requests
import pika
import re

# Para twitter []
consumer_key="qbLkLNSMeimtgX2KjAnFESpcL"
consumer_secret="07a34Bq5zmeDD1dDVvwV4XldC9r6ZJPFxzljci6JCiYqPDDOVc"
access_token="986600430422675457-40mznk6K4fMCYrTBR5i4pZAMWM0MdXz"
access_token_secret="QT3AtSFpCaBKw8F2q8RtVx8vuMhociEaUz0kDTBQDRFOu"
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)
trends = api.trends_place(23424950)
data = trends[0]
trends = data['trends']
trendsName = list()

names = [trend['name'] for trend in trends]
#trendsName.append(names)
#trendsName = ' '.join(names)
#print trendsName
tweets = ""
search_results = api.search(q=names[0],count=100)
for i in search_results:
    tweets = tweets + i.text


conexion = pika.BlockingConnection(pika.ConnectionParameters(host="localhost"))
canal = conexion.channel()
canal.queue_declare(queue="colaTweets")
tweets2 = ' '.join([w for w in tweets.split() if len(w)>3])
tweets2 = canal.basic_publish(exchange="",routing_key="colaTweets",body=tweets2)
conexion.close()
