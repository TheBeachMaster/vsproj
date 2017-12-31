using System;
using MQTTnet;
using MQTTnet.Client;

namespace MQTT_net
{
    class Program
    {
        static async System.Threading.Tasks.Task MainAsync(string[] args)
        {
            Console.WriteLine("Hello World!");
            var clientFatory = new MqttFactory();
            var mqttClient = clientFatory.CreateMqttClient();

            var opts = new MqttClientOptionsBuilder()
                .WithClientId("DotNet")
                .WithTcpServer("sungura1-angani-ke-host.africastalking.com", 1882)
                .WithCredentials("akka", "devicemanager")
                .WithCleanSession()
                .Build();
                    await mqttClient.ConnectAsync(opts);
                
        }
    }
}
