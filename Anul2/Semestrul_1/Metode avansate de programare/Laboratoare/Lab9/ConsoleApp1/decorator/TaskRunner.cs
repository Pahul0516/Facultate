namespace ConsoleApp1.decorator;
using Task = ConsoleApp1.model.Task;

public interface ITaskRunner
{
    void  ExecuteOneTask();

    void ExecuteAll();

    void AddTask(Task t);

    bool HasTask();
}