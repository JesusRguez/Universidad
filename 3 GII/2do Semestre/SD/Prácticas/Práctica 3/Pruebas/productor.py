!/usr/bin/env python
import               pika
#               Crea
conexión
con_params               =               pika.ConnectionParameters(localhost)
connection               =               pika.BlockingConnection(con_params)
#               Crea               Canal
channel               =               connection.channel()
#               Crea               cola
channel.queue_declare(queue=hello)
#Envía               mensaje
channel.basic_publish(exchange="",
routing_key=hello,
body=Hello               World!)
print(" [x] Sent Hello               World!")
connection.close()
