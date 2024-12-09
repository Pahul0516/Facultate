namespace ConsoleApp1.model;

public class StackContainer : AbstractContainer
{
    public override Task Remove()
    {
        if (tasks.Count != 0)
        {
            var ret = tasks[tasks.Count - 1];
            tasks.RemoveAt(tasks.Count - 1);
            return ret;
        }
        else {
            return null;
        }
    }
}