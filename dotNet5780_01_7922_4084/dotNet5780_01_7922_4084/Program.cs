using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dotNet5780_01_7922_4084
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random(DateTime.Now.Millisecond);
            int[] a = new int[20];
            int[] b = new int[20];
            int[] c = new int[20];
            fill(rnd, a);
            fill(rnd, b);
            for (int i = 0; i < 20; i++)
                c[i] = Math.Abs(a[i] - b[i]);
            print(a);
            print(b);
            print(c);
            Console.ReadKey();
        }

        private static void print(int[] a)
        {
            for (int i = 1; i < 20; i++)
                Console.Write("{0 ,-3} ", a[i]);
            Console.WriteLine();
            }

        private static void fill(Random rnd, int[] a)
        {
            for (int i = 0; i < 20; i++)
                a[i] = rnd.Next(18, 122);
        }
    }
}
