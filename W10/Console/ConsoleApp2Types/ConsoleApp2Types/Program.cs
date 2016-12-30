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

            string myVerbatim = @"This is a verbatim string:
                                   1.It can span several lines
                                   2.This is anoter line spanned by
                                     the verbatim string";
            Console.WriteLine($"{myVerbatim}");
            Console.ReadKey();        
        }
    }
}
