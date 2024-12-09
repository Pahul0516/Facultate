namespace ConsoleApp1.model;

public abstract class AbstractContainer : IContainer
{
    protected List<Task> tasks = new List<Task>();

    public abstract Task Remove();

    public void Add(Task task)
    {
        tasks.Add(task);
    }

    public int Size()
    {
        return tasks.Count;
    }

    public bool IsEmpty()
    {
        return Size() == 0;
    }
}