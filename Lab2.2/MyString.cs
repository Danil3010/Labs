using System;

namespace MyStringNamespace{
    class MyString{
        private string str; // Значення рядка
        public MyString(){ // Конструктор за замовчуванням              
            str = "";
        }
        public MyString(int[] s){ // Конструктор зі значенням C-style рядка
            str = string.Join("", Array.ConvertAll(s, i => i.ToString()));
        }
        public MyString(string s){ // Конструктор зі значенням рядка типу string
            str = s;
        }
        public MyString(MyString other){ // Конструктор копіювання
            str = other.str;
        }
        public bool Check()
        { // Перевірка елементів
            foreach (char c in str)
            {
                if (!Char.IsDigit(c))
                {
                    return false;
                }
            }
            return true;
        }
        public int Length(){ // Метод обчислення довжини рядка
            return str.Length;
        }
        public int Length2(){ // Метод обчислення довжини рядка після видалення
            return str.Length;
        }

        public void RemoveFive(){ // Метод видалення символу '5'
            str = str.Replace("5", "");
        }
        public void Print(){ // Метод виведення рядка на екран
            Console.WriteLine(str);
        }
        public void Add(string a){ // Метод додавання символу
            str += a;
        }
    }
}

