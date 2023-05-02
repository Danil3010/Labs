using System;

interface ICalculatingFigureProperties
{
    double BasePerimeter { get; }
    double CalculateLateralArea();
    double CalculateVolume();
}

class RightPyramid : ICalculatingFigureProperties
{
    private double height;
    private double baseSide;

    public RightPyramid(double height, double baseSide)
    {
        this.height = height;
        this.baseSide = baseSide;
    }

    public double BasePerimeter
    {
        get { return 4 * baseSide; }
    }

    public double CalculateLateralArea()
    {
        return baseSide * Math.Sqrt(Math.Pow(height, 2) + Math.Pow(baseSide / 2, 2)) * 2;
    }

    public double CalculateVolume()
    {
        return (Math.Pow(baseSide, 2) * height) / 3;
    }
}

class Cone : ICalculatingFigureProperties
{
    private double height;
    private double radius;

    public Cone(double height, double radius)
    {
        this.height = height;
        this.radius = radius;
    }

    public double BasePerimeter
    {
        get { return 2 * Math.PI * radius; }
    }

    public double CalculateLateralArea()
    {
        return Math.PI * radius * Math.Sqrt(Math.Pow(height, 2) + Math.Pow(radius, 2));
    }

    public double CalculateVolume()
    {
        return (Math.PI * Math.Pow(radius, 2) * height) / 3;
    }
}

class Program
{
    static void Main(string[] args)
    {
        double x1, y1, x2, y2, x3, y3;
        double pyramidHeight, pyramidBaseSide, coneHeight, coneRadius;

        bool isValidInput = false;
        while (!isValidInput)
        {
            Console.WriteLine("Enter coordinates of three points in the plane separated by spaces:");
            string[] coordinates = Console.ReadLine().Split(' ');
            if (coordinates.Length == 6 &&
                double.TryParse(coordinates[0], out x1) &&
                double.TryParse(coordinates[1], out y1) &&
                double.TryParse(coordinates[2], out x2) &&
                double.TryParse(coordinates[3], out y2) &&
                double.TryParse(coordinates[4], out x3) &&
                double.TryParse(coordinates[5], out y3))
            {
                double a = Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
                double b = Math.Sqrt(Math.Pow(x3 - x2, 2) + Math.Pow(y3 - y2, 2));
                double c = Math.Sqrt(Math.Pow(x1 - x3, 2) + Math.Pow(y1 - y3, 2));
                if (a + b > c && a + c > b && b + c > a)
                {
                    isValidInput = true;

                    Console.WriteLine("Enter height of the pyramid:");
                    double.TryParse(Console.ReadLine(), out pyramidHeight);
                    Console.WriteLine("Enter base side length of the pyramid:");
                    double.TryParse(Console.ReadLine(), out pyramidBaseSide);
                    RightPyramid pyramid = new RightPyramid(pyramidHeight, pyramidBaseSide);
                    Console.WriteLine("Perimeter of the base of pyramid: " + pyramid.BasePerimeter);
                    Console.WriteLine("Lateral area of pyramid: " + pyramid.CalculateLateralArea());
                    Console.WriteLine("Volume of pyramid: " + pyramid.CalculateVolume());

                    Console.WriteLine("Enter height of the cone:");
                    double.TryParse(Console.ReadLine(), out coneHeight);
                    Console.WriteLine("Enter radius of the cone:");
                    double.TryParse(Console.ReadLine(), out coneRadius);
                    Cone cone = new Cone(coneHeight, coneRadius);
                    Console.WriteLine("Perimeter of the base of cone: " + cone.BasePerimeter);
                    Console.WriteLine("Lateral area of cone: " + cone.CalculateLateralArea());
                    Console.WriteLine("Volume of cone: " + cone.CalculateVolume());
                }
                else
                {
                    Console.WriteLine("Invalid input. The entered coordinates do not form a valid triangle.");
                }
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter three pairs of coordinates separated by spaces.");
            }
        }

        Console.ReadKey();
    }

}

