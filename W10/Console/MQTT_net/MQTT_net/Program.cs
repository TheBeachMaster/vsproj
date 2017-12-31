using System;
using System.Text;
using System.Threading.Tasks;
using MQTTnet;
using MQTTnet.Client;

namespace MQTT_net
{
    class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            var clientFactory = new MqttFactory();
            var mqttClient = clientFactory.CreateMqttClient();

            var opts = new MqttClientOptionsBuilder()
                .WithClientId("DotNet")
                .WithTcpServer("sungura1-angani-ke-host.africastalking.com", 1882)
                .WithCredentials("akka", "devicemanager")
                .WithCleanSession()
                .Build();
                    await mqttClient.ConnectAsync(opts);
            mqttClient.Disconnected += async (s, e) =>
            {
                Console.WriteLine("Woops We're disconnected");
                await Task.Delay(TimeSpan.FromSeconds(5));

                try
                {
                    await mqttClient.ConnectAsync(opts);
                }
                catch (Exception exception)
                {
                    Console.WriteLine("Could not conect: " + exception);

                }
            };

            mqttClient.Connected += async (s, e) =>
            {
                Console.WriteLine("We're connected");
                await mqttClient.SubscribeAsync(new TopicFilterBuilder().WithTopic("akka/dotnet/get").Build());
                Console.WriteLine("Subscribed");
            };

            mqttClient.ApplicationMessageReceived += (s, e) =>
            {
                Console.WriteLine("Got Stuff");
                Console.WriteLine($"+ Payload = {Encoding.UTF8.GetString(e.ApplicationMessage.Payload)}");
            };

            Console.ReadLine(); 
        }
    }
}
