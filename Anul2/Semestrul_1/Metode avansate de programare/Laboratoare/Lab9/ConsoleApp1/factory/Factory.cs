using ConsoleApp1.model;

namespace ConsoleApp1.Factory;

public interface IFactory
{
    IContainer CreateContainer(Strategy strategy);
}