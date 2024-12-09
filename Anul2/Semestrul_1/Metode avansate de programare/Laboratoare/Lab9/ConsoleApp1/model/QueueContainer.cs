namespace ConsoleApp1.model;

public class QueueContainer : AbstractContainer
{
    public override Task Remove()
    {
        if (tasks.Count!=0)
        { 
            var ret = tasks[0];
            tasks.RemoveAt(0);
            return ret;
        }
        else
        {
            return null;
        }
    }
}