import pika

con_params=pika.ConnectionParameters("localhost")
connection=pika.BlockingConnection(con_params)

channel=connection.channel()
channel.queue_declare(queue="colaTweets")

def callback(ch, method, poroperties, body):
    print (" [X] %r" % body)
    inputFile = open("/home/jesus/input.txt","w")
    inputFile.write(body)
    inputFile.close()

channel.basic_consume(callback, queue="colaTweets", no_ack=True)

channel.start_consuming()
