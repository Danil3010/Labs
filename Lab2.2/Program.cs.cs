using System;
using MyStringNamespace;

namespace ProgramNamespace{
    class Program{
        static void Main(string[] args){
            bool runAgain = true;

            while (runAgain){
                Console.Write("Enter a string of numeric values: ");
                string input = Console.ReadLine();

                MyString s1 = new MyString();
                MyString s2 = new MyString(input);
                MyString s3 = new MyString(s2);
                MyString s6 = new MyString(s3);

                int[] arr = new int[4];

                if (!s3.Check()){
                    Console.WriteLine("Error: string contains non-digit characters.\n");
                    continue;
                }

                Console.Write("Original string: ");
                s6.Print();
                Console.WriteLine("Length of string: " + s3.Length());
                s3.RemoveFive();
                Console.Write("String after removing 5: ");
                s3.Print();
                Console.WriteLine("Length of string after removing 5: " + s3.Length());
                s3.Length2();
                Console.WriteLine();

                arr[0] = input[0] - '0';
                arr[1] = input[1] - '0';
                for (int i = 0; i < 2; i++){
                    arr[3 - i] = arr[i];
                }

                Console.Write("Array:");
                foreach (int i in arr){
                    Console.Write(" " + i);
                }
                Console.WriteLine();

                Console.Write("Do you want to add a character to a string? (Yes / No): ");
                string answer1 = Console.ReadLine();

                if (answer1 == "Yes"){
                    Console.WriteLine("Enter an additional character:");
                    string add = Console.ReadLine();
                    s3.Add(add);
                    s3.Print();
                }
                else if (answer1 == "No"){
                    goto contin;
                }

            contin:; // мітка продовження циклу

                Console.WriteLine("Continue? (Yes/No): ");
                string answer2 = Console.ReadLine();
                Console.WriteLine("");
                if (answer2 == "No"){
                    runAgain = false;
                }
            }
        }
    }
}