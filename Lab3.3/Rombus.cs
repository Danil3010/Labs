using System;

class Rhombus
{
    private double x1, y1, x2, y2, x3, y3, x4, y4;

    public Rhombus(double x, double y, double diagonal1, double diagonal2)
    {
        // Обчислення координат вершин ромба з відомими координатами центра та довжинами діагоналей
        x1 = x - diagonal1 / 2;
        y1 = y;
        x2 = x;
        y2 = y - diagonal2 / 2;
        x3 = x + diagonal1 / 2;
        y3 = y;
        x4 = x;
        y4 = y + diagonal2 / 2;
    }

    public double Perimeter()
    {
        // Обчислення периметру ромба
        double sideLength = Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
        return 4 * sideLength;
    }

    public double Area()
    {
        // Обчислення площі ромба
        double diagonal1Length = Math.Sqrt(Math.Pow(x3 - x1, 2) + Math.Pow(y3 - y1, 2));
        double diagonal2Length = Math.Sqrt(Math.Pow(x4 - x2, 2) + Math.Pow(y4 - y2, 2));
        return diagonal1Length * diagonal2Length / 2;
    }

    public void PrintCoordinates()
    {
        // Виведення координат вершин ромба в консоль
        Console.WriteLine($"Vertex 1: ({x1}, {y1})");
        Console.WriteLine($"Vertex 2: ({x2}, {y2})");
        Console.WriteLine($"Vertex 3: ({x3}, {y3})");
        Console.WriteLine($"Vertex 4: ({x4}, {y4})");
    }
    public double Diagonal1Length()
    {
        return Math.Sqrt(Math.Pow(x3 - x1, 2) + Math.Pow(y3 - y1, 2));
    }
    public double Diagonal2Length()
    {
        return Math.Sqrt(Math.Pow(x4 - x2, 2) + Math.Pow(y4 - y2, 2));
    }


    public static Rhombus operator +(Rhombus rhombus, double distance)
    {
        double newX = rhombus.x1 + distance;
        double newY = rhombus.y1;
        double diagonal1 = rhombus.Diagonal1Length();
        double diagonal2 = rhombus.Diagonal2Length();
        return new Rhombus(newX, newY, diagonal1, diagonal2);
    }

    public static Rhombus operator +(Rhombus rhombus1, Rhombus rhombus2)
    {
        // Обчислення мінімального значення серед усіх значень координат другого ромба
        double minX2 = Math.Min(Math.Min(rhombus2.x1, rhombus2.x2), Math.Min(rhombus2.x3, rhombus2.x4));
        double minY2 = Math.Min(Math.Min(rhombus2.y1, rhombus2.y2), Math.Min(rhombus2.y3, rhombus2.y4));
        double minCoordinate2 = Math.Min(minX2, minY2);

        // Додавання мінімального значення до координат вершин першого ромба
        Rhombus result = new Rhombus(rhombus1.x1 + minCoordinate2, rhombus1.y1 + minCoordinate2, rhombus1.Area(), rhombus1.Area());
        return result;
    }


    public static int Compare(Rhombus r1, Rhombus r2)
    {
        double area1 = r1.Area();
        double area2 = r2.Area();

        if (area1 < area2)
        {
            return -1;
        }
        else if (area1 > area2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    public Rhombus(double x, double y, double diagonal1, double diagonal2, bool decrementCoordinates = false)
    {
        if (decrementCoordinates)
        {
            x--;
            y--;
            diagonal1--;
            diagonal2--;
        }
        // Обчислення координат вершин ромба з відомими координатами центра та довжинами діагоналей
        x1 = x - diagonal1 / 2;
        y1 = y;
        x2 = x;
        y2 = y - diagonal2 / 2;
        x3 = x + diagonal1 / 2;
        y3 = y;
        x4 = x;
        y4 = y + diagonal2 / 2;
    }
    public static bool operator &(Rhombus rhombus1, Rhombus rhombus2)
    {
        return (rhombus1.x1 != 0 && rhombus1.y1 != 0 && rhombus1.x2 != 0 && rhombus1.y2 != 0 &&
                rhombus1.x3 != 0 && rhombus1.y3 != 0 && rhombus1.x4 != 0 && rhombus1.y4 != 0 &&
                rhombus2.x1 != 0 && rhombus2.y1 != 0 && rhombus2.x2 != 0 && rhombus2.y2 != 0 &&
                rhombus2.x3 != 0 && rhombus2.y3 != 0 && rhombus2.x4 != 0 && rhombus2.y4 != 0);
    }
}