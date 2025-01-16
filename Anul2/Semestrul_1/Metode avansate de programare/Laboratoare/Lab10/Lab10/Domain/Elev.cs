namespace Lab10.Domain;

public class Elev : Entity<int>
{
    public string Name { get; set; }
    public string School { get; set; }

    public Elev(int id, string name, string school) : base(id)
    {
        Name = name;
        School = school;
    }

    public override string ToString()
    {
        return $"{base.Id}.{Name}";
    }
}