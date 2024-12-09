namespace ConsoleApp1.decorator;

public class PrinterTaskRunner : AbstractTaskRunner 
{
    public PrinterTaskRunner(ITaskRunner taskRunner) : base(taskRunner){}
    public override void ExecuteOneTask() {
        base.ExecuteOneTask();
        System.Console.WriteLine("Task executed at: " + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
    }
}