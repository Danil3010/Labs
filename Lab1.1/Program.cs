using System;

namespace MyStringNamespace{
    class Program{
        static void Main(string[] args){

            bool runAgain = true;
            while (runAgain){

                Console.Write("Enter a string of numeric values: ");
                string a = Console.ReadLine();
                MyString s = new MyString(a);

                if (!s.Check()){
                    Console.WriteLine("Error: string contains non-digit characters.");
                    Console.WriteLine();
                    continue;
                }

                Console.Write("Original string: ");
                s.Print();

                Console.WriteLine("Length of string: " + s.Length());

                s.RemoveFive();

                Console.Write("String after removing 5: ");
                s.Print();

                Console.WriteLine("Length of string after removing 5: " + s.Length2());
                Console.WriteLine();

                Console.Write("Continue? (Yes/No): ");
                string answer = Console.ReadLine();
                Console.WriteLine();

                if (answer.ToLower() == "no"){
                    runAgain = false;
                }
            }
        }
    }
}
