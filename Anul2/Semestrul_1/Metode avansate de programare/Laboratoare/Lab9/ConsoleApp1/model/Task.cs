namespace ConsoleApp1.model;

public abstract class Task(string id, string description)
{
    private string Id { get; set; } = id;
    private string Description { get; set; } = description;
    public abstract void Execute();
    protected bool Equals(Task other) {
        return Id == other.Id && Description == other.Description;
    }
    public override int GetHashCode()
    {
        return HashCode.Combine(Id, Description);
    }
    public override string ToString()
    {
        return $"{nameof(Id)}: {Id}, {nameof(Description)}: {Description}";
    }
}