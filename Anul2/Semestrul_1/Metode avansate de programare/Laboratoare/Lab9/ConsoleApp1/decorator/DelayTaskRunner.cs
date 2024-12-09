namespace ConsoleApp1.decorator;

public class DelayTaskRunner : AbstractTaskRunner
{
    public DelayTaskRunner(ITaskRunner taskRunner) : base(taskRunner) {}
    public override void ExecuteOneTask() {
        try {
            base.ExecuteOneTask();
            System.Console.WriteLine("Task executed at: " + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
            Thread.Sleep(3000);

        } catch (Exception e)
        {
           System.Console.WriteLine(e);
        }
    }
}