using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2MathOperators
{
    class Program
    {
        static void Main(string[] args)
        {
            double firstNumber, secondNumber;
            string userName;
           


            Console.WriteLine("Enter your Username followed by Enter Key");

            userName = Console.ReadLine();

            Console.WriteLine($"Welcome {userName}");

            Console.WriteLine("Enter the first number to manipulate");

            firstNumber = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Good , enter a second digit");

            secondNumber = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine($"Well, {userName} ,...");

            double sum = firstNumber + secondNumber;
            double product = firstNumber * secondNumber;
            double divide = firstNumber / secondNumber;
            double subtract = firstNumber - secondNumber;
            double modulo = firstNumber % secondNumber;

            

            Console.WriteLine($"the sum is : {sum} \n" +
                              $"the product is : {product} \n" +
                              $"the division is : {divide} \n" +
                              $"the difference is : {subtract} \n" + 
                              $"the remainder is : {modulo} \n");
            Console.WriteLine("Please press any key to continue");

            Console.ReadKey();




        }
    }
}
