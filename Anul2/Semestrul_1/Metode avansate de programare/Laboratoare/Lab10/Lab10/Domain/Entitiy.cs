namespace Lab10.Domain;

public class Entity<T>(T id)
{
    public T Id { get; set; } = id;
}