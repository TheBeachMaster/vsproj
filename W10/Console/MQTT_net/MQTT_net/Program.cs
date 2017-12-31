using System;
using MQTTnet;
using MQTTnet.Client;

namespace MQTT_net
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            var clientFatory = new MqttFactory();
            var mqttClient = clientFatory.CreateMqttClient();
        }
    }
}
