using System;

namespace Ohm.Coursework.Task02
{
    public class Employee
    {
        private readonly string name;
        private readonly DateTime dateOfBirth;
        private readonly DateTime dateOfHire;

        private string skills = "";

        public Employee(string name, DateTime dateOfBirth, DateTime dateOfHire)
        {
            this.name = name;
            this.dateOfBirth = dateOfBirth;
            this.dateOfHire = dateOfHire;
        }

        public string Name => name;
        public DateTime DateOfBirth => dateOfBirth;
        public DateTime DateOfHire => dateOfHire;

        public string[] Address { get; set; }
        public uint Salary { get; set; }

        public void AddSkill(string skill)
        {
            skills += $"{skill}; ";
        }

        public string GetSkills()
        {
            return skills;
        }

        private bool Equals(Employee other)
        {
            return name.Equals(other.name) &&
                   dateOfBirth.Equals(other.dateOfBirth) &&
                   dateOfHire.Equals(other.dateOfHire);
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj)) return false;
            if (ReferenceEquals(this, obj)) return true;
            return obj is Employee other && Equals(other);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                var hash = StringComparer.OrdinalIgnoreCase.GetHashCode(name);
                hash = (hash * 397) ^ dateOfBirth.GetHashCode();
                hash = (hash * 397) ^ dateOfHire.GetHashCode();
                return hash;
            }
        }

        public static bool operator ==(Employee left, Employee right)
        {
            return Equals(left, right);
        }

        public static bool operator !=(Employee left, Employee right)
        {
            return !Equals(left, right);
        }
    }
}