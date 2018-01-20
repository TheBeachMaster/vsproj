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
            string phoneNumberList = "+25472487654";
            //string phoneNumberList = "+25472487654,+254734587654,+25471587654";
            string[] nums = phoneNumberList.Split(',');
            foreach (string num in nums)
            {
                Console.WriteLine(num);
                Console.WriteLine(IsPhoneNumber(num));
            }
            
            Console.ReadLine();
        }

        private static bool IsPhoneNumber(string number)
        {
                      return Regex.Match(number, @"^\+?(\d[\d-. ]+)?(\([\d-. ]+\))?[\d-. ]+\d$").Success && number.Length > 5;
        }
    }
}
