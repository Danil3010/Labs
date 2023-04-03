using System;

class StudentsTable
{
    private string[] names;
    private string[] surnames;
    private string[] patronymics;
    private int count;

    public StudentsTable(int size)
    {
        names = new string[size];
        surnames = new string[size];
        patronymics = new string[size];
        count = 0;
    }

    public string this[int index]
    {
        get { return $"{surnames[index]} {names[index]} {patronymics[index]}"; }
        set
        {
            string[] parts = value.Split(' ');
            surnames[index] = parts[0];
            names[index] = parts[1];
            patronymics[index] = parts[2];
        }
    }

    public int Count
    {
        get { return count; }
    }

    public void Add()
    {
        Console.Write("Enter student's name: ");
        string name = Console.ReadLine();
        Console.Write("Enter student's surname: ");
        string surname = Console.ReadLine();
        Console.Write("Enter student's patronymic: ");
        string patronymic = Console.ReadLine();

        // Перевірка на наявність цифр в рядку
        if (ContainsDigits(name) || ContainsDigits(surname) || ContainsDigits(patronymic))
        {
            Console.WriteLine("Invalid input: name, surname or patronymic contains digits.");
            Console.WriteLine("Please enter the correct data for this student.");

            // Переписуємо дані для цього студента
            Add();
            return;
        }

        names[count] = name;
        surnames[count] = surname;
        patronymics[count] = patronymic;
        count++;
    }

    private bool ContainsDigits(string str)
    {
        foreach (char c in str)
        {
            if (Char.IsDigit(c))
            {
                return true;
            }
        }
        return false;
    }
}

class Program
{
    static void Main(string[] args)
    {
        StudentsTable table = new StudentsTable(10);

        while (true)
        {
            Console.WriteLine("Do you want to add a new student? (Yes/No)");
            string answer = Console.ReadLine();

            if (answer.Equals("Yes", StringComparison.OrdinalIgnoreCase))
            {
                table.Add();
            }
            else if (answer.Equals("No", StringComparison.OrdinalIgnoreCase))
            {
                break;
            }
            else
            {
                Console.WriteLine("Invalid answer.");
            }
        }

        table[1] = "Number of student:";
        Console.WriteLine(table[1]);
        Console.WriteLine(table.Count);
    }
}
