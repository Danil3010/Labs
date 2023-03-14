using System;

class Program
{
    static void Main()
    {
        // Створення об'єкту ромба з відомими координатами центра та довжинами діагоналей
        Rhombus rhombus = new Rhombus(0, 0, 4, 6);

        // Виведення координат вершин ромба
        Console.WriteLine("Rhombus coordinates:");
        rhombus.PrintCoordinates();
        Console.WriteLine();

        // Обчислення та виведення периметру ромба
        Console.WriteLine($"Rhombus perimeter: {rhombus.Perimeter()}");
        Console.WriteLine();

        // Обчислення та виведення площі ромба
        Console.WriteLine($"Rhombus area: {rhombus.Area()}");

        Console.WriteLine();

        Rhombus r = new Rhombus(0, 0, 4, 6);
        r = r + 2.5; // Пересування ромба вправо на 2.5

        r.PrintCoordinates();

        Console.WriteLine();

        Rhombus rhombus1 = new Rhombus(0, 0, 4, 4);
        Rhombus rhombus2 = new Rhombus(3, 3, 4, 4);

        // Виведення координат вершин ромбів
        Console.WriteLine("Rhombus 1:");
        rhombus1.PrintCoordinates();
        Console.WriteLine("Rhombus 2:");
        rhombus2.PrintCoordinates();

        // Об'єднання двох ромбів
        Rhombus result = rhombus1 + rhombus2;

        // Виведення координат вершин нового ромба
        Console.WriteLine("Resulting Rhombus:");
        result.PrintCoordinates();

        Console.WriteLine();

        Rhombus r1 = new Rhombus(0, 0, 4, 6);
        Rhombus r2 = new Rhombus(0, 0, 4, 7);

        int result1 = Rhombus.Compare(r1, r2);

        if (result1 == -1)
        {
            Console.WriteLine("Площа першого ромба менша за площу другого.");
        }
        else if (result1 == 1)
        {
            Console.WriteLine("Площа першого ромба більша за площу другого.");
        }
        else
        {
            Console.WriteLine("Площі ромбів рівні.");
        }

        Console.WriteLine();

        Rhombus r1_1 = new Rhombus(3, 4, 4, 6, true);

        r1_1.PrintCoordinates();

        Rhombus rhombus6 = new Rhombus(1, 1, 4, 6);
        Rhombus rhombus7 = new Rhombus(3, 3, 5, 8);

        // Перевірка, чи дорівнюють нулю всі закриті змінні двох ромбів
        bool allVariablesAreNotZero = rhombus6 & rhombus7;

        // Виведення результату перевірки в консоль
        Console.WriteLine($"All variables of rhombus1 and rhombus2 are not zero: {allVariablesAreNotZero}");
    }
}
