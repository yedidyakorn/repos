using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace part2
{
    class Program
    {
        static void Main(string[] args)
        {
            int choice=1;
            Boolean[][] arr = new Boolean[12][];
            for(int i=0;i<arr.Length;i++)
            {
                arr[i] = new Boolean[31];
                for (int j = 0; j < arr[i].Length; j++)
                    arr[i][j] = false;
            }
            while(choice!=0)
            {
                Console.WriteLine("Enter Choice: 1-enter new vication.\t 2-show whole list. \t 3-show taken dates.\t 0-exit");
                choice = Convert.ToInt32(Console.ReadLine());
                switch(choice)
                {
                    case 0:
                        break;
                    case 1:
                        newDate ( arr);
                        break;
                    case 2:
                        all( arr);
                        break;
                    case 3:
                        taken(arr);
                        break;
                    default:
                        Console.WriteLine("Error");
                        break;
                }
            }

        }

        private static void taken(Boolean[][] arr)
        {
            int month, date, days;
            Console.WriteLine("Enter month:");
            month = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter date:");
            date = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter how many days::");
            days = Convert.ToInt32(Console.ReadLine());
            if(arr[month-1][date-1])

            throw new NotImplementedException();
        }

        private static void all(Boolean[][] arr)
        {
            throw new NotImplementedException();
        }

        private static void newDate(Boolean[][] arr)
        {
            throw new NotImplementedException();
        }
    }
}
