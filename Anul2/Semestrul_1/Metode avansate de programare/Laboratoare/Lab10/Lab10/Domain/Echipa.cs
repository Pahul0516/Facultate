namespace Lab10.Domain;

public class Echipa : Entity<int>
{
    public string Name { get; set; }
    public Echipa(int id, string name): base(id)
    {
        Name = name;
    }
    public override string ToString()
    {
        return $"{nameof(Name)}: {Name}";
    }
}