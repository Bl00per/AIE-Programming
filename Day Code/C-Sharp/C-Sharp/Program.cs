using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_Sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter your name:");
            string name = Console.ReadLine();
            var vowels = Console.ReadLine().ToLower().Intersect("AEIOUaeiou");
            int vowelCount = 0;

            if (!vowels.Any())
            {
                Console.WriteLine("No vowels found");
            }
            else
            {
                foreach (var vowel in vowels)
                {
                    vowelCount += 1;
                }

                Console.WriteLine("Number of vowels: " + vowelCount);
            }



            Console.ReadKey();
        }
    }
}
