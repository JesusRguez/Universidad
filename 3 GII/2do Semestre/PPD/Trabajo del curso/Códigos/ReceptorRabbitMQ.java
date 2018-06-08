import com.rabbitmq.client.*;
import java.io.IOException;

public class ReceptorRabbitMQ {

    private static final String COLA = "colaTweets";
    private static final String URL = "localhost";

    public static void main(String[] args) {

       try {

           ConnectionFactory factory = new ConnectionFactory();
           factory.setHost(URL);

           Connection connection = factory.newConnection();

           Channel channel = connection.createChannel();

           channel.queueDeclare(COLA,false,false,false,null);

           System.out.println("Esperando mensajes...");

           Consumer consumer = new DefaultConsumer(channel){

               @Override
               public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties, byte[] body) throws IOException {

                   String mensaje = new String(body,"UTF-8");

                   System.out.println("recibido: " + mensaje);//AQUI HACER COSAS CON EL MENSAJE
               }
           };

           channel.basicConsume(COLA,true,consumer);

       } catch(Exception ex) {
           ex.getMessage();
           System.err.println("");
           ex.printStackTrace(System.err);
       }
    }
}
