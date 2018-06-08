!/usr/bin/env python
import               pika
#               Crea conexión
con_params               =               pika.ConnectionParameters(localhost)
connection               =               pika.BlockingConnection(con_params)
#               Crea               Canal
channel               =               connection.channel()
#               Crea               cola
channel.queue_declare(queue=hello)
#               Mensaje               de recepción
def               callback(ch,               method,               properties,               body):
print(" [x] Received %r"               %               body)
#               Consume               mensaje
channel.basic_consume(callback, queue=hello, no_ack=True)
connection.close()
