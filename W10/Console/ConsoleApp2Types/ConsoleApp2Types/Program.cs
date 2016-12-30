using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2Types
{
    class Program
    {
        static void Main(string[] args)
        {
            int myInteger;
            string myString;

            myInteger =  17;
            myString = "\"myInteger\" is";
            Console.WriteLine($"{myString} {myInteger}"); //Outputs "myInteger is 17"
            Console.ReadKey();        
        }
    }
}
