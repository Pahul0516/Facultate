using Task = ConsoleApp1.model.Task;

namespace ConsoleApp1.decorator;

public abstract class AbstractTaskRunner : ITaskRunner
{
    private ITaskRunner taskRunner;
    
    public AbstractTaskRunner(ITaskRunner taskRunner) {
        this.taskRunner = taskRunner;
    }
    
    public virtual void ExecuteOneTask()
    {
        taskRunner.ExecuteOneTask();
    }

    public void ExecuteAll()
    {
        while (HasTask()) {
            ExecuteOneTask();
        }
    }

    public void AddTask(Task t)
    {
        taskRunner.AddTask(t);
    }

    public bool HasTask()
    {
        return taskRunner.HasTask();
    }
}