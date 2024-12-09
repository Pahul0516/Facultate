using System.ComponentModel;
using ConsoleApp1.Factory;
using IContainer = ConsoleApp1.model.IContainer;
using Task = ConsoleApp1.model.Task;

namespace ConsoleApp1.decorator;

public class StrategyTaskRunner : ITaskRunner
{
    private IContainer container;
    private ITaskRunner _taskRunnerImplementation;

    public StrategyTaskRunner(Strategy strategy) {

        var con = TaskContainerFactory.GetInstance();
        container = con.CreateContainer(strategy);
    }
    
    public void ExecuteOneTask()
    {
        Task task = container.Remove();
        task.Execute();
    }

    public void ExecuteAll()
    {
        while (HasTask()) {
            ExecuteOneTask();
        }
    }

    public void AddTask(Task t)
    {
        container.Add(t);
    }

    public bool HasTask()
    {
        return !container.IsEmpty();
    }
}