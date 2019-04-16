namespace Ohm.Coursework.Task02
{
    public class Employees
    {
        private BasicPiece head = new BasicPiece();

        public Employees()
        {
        }

        private int Count => head.Counter;

        private class ValuePiece : BasicPiece
        {
            private readonly Employee value;
            private BasicPiece other;

            public ValuePiece(BasicPiece other, Employee value)
            {
                this.other = other;
                this.value = value;
            }

            public int Counter => other.Counter + 1;

            public BasicPiece Delete(Employee search)
            {
                if (search == value) return other.Delete(search);
                other = other.Delete(search);
                return this;
            }
            
            public bool Equals(Employee search)
            {
                return value == search || other.Equals(search);
            }
            
        }

        private class BasicPiece
        {
            public BasicPiece Insert(Employee search)
            {
                return new ValuePiece(this, search);
            }

            public int Counter => 0;

            public BasicPiece Delete(Employee search)
            {
                return this;
            }

            public bool Equals(Employee search)
            {
                return false;
            }
            
        }

        public static Employees operator +(Employees list, Employee employee)
        {
            list.head = list.head.Insert(employee);
            return list;
        }

        public static Employees operator -(Employees list, Employee employee)
        {
            list.head = list.head.Delete(employee);
            return list;
        }

        public static bool operator >(Employees left, Employees right)
        {
            return left.Count > right.Count;
        }

        public static bool operator >=(Employees left, Employees right)
        {
            return left.Count >= right.Count;
        }

        public static bool operator <(Employees left, Employees right)
        {
            return left.Count < right.Count;
        }

        public static bool operator <=(Employees left, Employees right)
        {
            return left.Count <= right.Count;
        }
    }
}