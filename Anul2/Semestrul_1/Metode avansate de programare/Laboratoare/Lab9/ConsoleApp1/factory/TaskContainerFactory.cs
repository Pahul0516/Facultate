    using ConsoleApp1.model;

    namespace ConsoleApp1.Factory;

    public class TaskContainerFactory:IFactory
    {
        
        private static TaskContainerFactory Instance;
        private TaskContainerFactory() { }

        public static TaskContainerFactory GetInstance()
        {
            if (Instance == null)
            {
                return new TaskContainerFactory();
            }
            else
            {
                return Instance;
            }
        }


        public IContainer CreateContainer(Strategy strategy) {
            if (strategy == Strategy.Fifo) {
                return new QueueContainer();
            } else {
                return new StackContainer();
            }
        }
    }