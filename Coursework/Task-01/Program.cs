using System;

namespace Ohm.Coursework.Task01
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // Test Point
            Point.MaxX = 100;
            Point.MaxY = 100;
            var myPoint1 = new Point(2, 2);
            var myPoint2 = new Point(-4, -4);
            myPoint2 = -myPoint2;
            myPoint1 *= 2;
            if (myPoint2 == myPoint1)
            {
                Console.WriteLine("identical points");
            }

            // Test Polygon
            var myLine = new Polygon(new Point(2, 1), new Point(2, 2), new Point(3, 3));
            myLine[0] = new Point(1, 1);
            Console.WriteLine("polygon points: ");
            for (var i = 0; i < myLine.NumberPoints; i++)
            {
                Console.WriteLine(myLine[i]);
            }

            Console.WriteLine($"Length Polygon: {(double) myLine}");
            // Test constructor Point: throws ArgumentOutOfException
            var myPoint3 = new Point(200, 200);
        }
    }

    public static class Assert
    {
        public static int CheckRange(int value, int min, int max)
        {
            if (value < min || value > max) throw new ArgumentOutOfRangeException();
            return value;
        }
    }

    public class Point
    {
        public static int MaxX, MaxY;

        // The x,y coordinates should only be set once
        private readonly int x, y;

        public Point(int xv, int yv)
        {
            x = Assert.CheckRange(xv, -MaxX, MaxX);
            y = Assert.CheckRange(yv, -MaxY, MaxY);
        }

        /// <summary>
        /// Calculates the distance from the current point to the point which is given as argument.
        /// The distance is calculated euclidean norm.
        /// </summary>
        /// <param name="point">The second point</param>
        /// <returns>The calculated distance</returns>
        public double Distance(Point point)
        {
            var dx = point.x - x;
            var dy = point.y - y;
            return Math.Sqrt(dx * dx + dy * dy);
        }

        /// <summary>
        /// Override to get the correct console output.
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return $"x: {x} y: {y}";
        }

        public static Point operator -(Point point)
        {
            // use our * operator
            return point * -1;
        }

        public static Point operator *(Point point, int factor)
        {
            return new Point(point.x * factor, point.y * factor);
        }

        public static bool operator ==(Point ap, Point bp)
        {
            return ap.x == bp.x && ap.y == bp.y;
        }

        public static bool operator !=(Point ap, Point bp)
        {
            return !(ap == bp);
        }
    }

    public class Polygon
    {
        // points are readonly because array length should not be modified after init 
        private readonly Point[] points;

        /// <summary>
        /// Simple constructor which requires at least two point parameters.
        /// After this the amount of points am variate.
        /// </summary>
        /// <param name="one">The first required point</param>
        /// <param name="two">The second required point</param>
        /// <param name="others">The various amount of points</param>
        public Polygon(Point one, Point two, params Point[] others)
        {
            points = new Point[2 + others.Length];
            points[0] = one;
            points[1] = two;
            for (var i = 0; i < others.Length; i++)
            {
                points[i + 2] = others[i];
            }
        }

        /// <summary>
        /// Indexer for manipulating the sored point in the polygon.
        /// </summary>
        /// <param name="idx">The index of the point starting with zero, has at least two entries</param>
        public Point this[int idx]
        {
            get => points[Assert.CheckRange(idx, 0, points.Length - 1)];
            set => points[Assert.CheckRange(idx, 0, points.Length - 1)] = value;
        }

        public int NumberPoints => points.Length;

        /// <summary>
        ///  Calculates the surrounding line length of the polygon when explicitly converted to an double.
        ///  NOTE: The example has a mistake an in the calculation one side length is missing,
        ///  so my result variates from the example.
        /// </summary>
        /// <param name="polygon">The Polygon to get the surrounding length</param>
        /// <returns>The surrounding length as double</returns>
        public static explicit operator double(Polygon polygon)
        {
            double result = 0;
            for (var i = 0; i < polygon.points.Length - 1; i++)
            {
                result += polygon.points[i].Distance(polygon.points[i + 1]);
            }

            result += polygon.points[polygon.points.Length - 1].Distance(polygon.points[0]);
            return result;
        }
    }
}