using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace RegexString
{
    class Program
    {
        static void Main(string[] args)
        {
            bool status = false;
            bool stat = true;
            //string phoneNumberList = "+4654";
            string phoneNumberList = "+25472487654,+25473487654,+25471587654,+4654";
            string[] nums = phoneNumberList.Split(',');
            foreach (string num in nums)
            {
                Console.WriteLine(num);
                status =  IsPhoneNumber(num);
                Console.WriteLine(status);
                stat = stat & status;
            }
            Console.WriteLine("Overall: " +stat);
            Console.ReadLine();
        }

        private static bool IsPhoneNumber(string number)
        {
                      return Regex.Match(number, @"^\+?(\d[\d-. ]+)?(\([\d-. ]+\))?[\d-. ]+\d{5,}$").Success;
        }
    }
}
