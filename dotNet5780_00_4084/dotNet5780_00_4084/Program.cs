using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dotNet5780_00_4084
{
    class Program
    {
        static void Main(string[] args)
        {
            WelcomeMethod();
            Console.ReadKey();
        }

        private static void WelcomeMethod()
        {
            Console.WriteLine("Enter your name: ");
            string userName = Console.ReadLine();
            Console.WriteLine(userName + " Welcome to my first console application");
        }
    }
}
