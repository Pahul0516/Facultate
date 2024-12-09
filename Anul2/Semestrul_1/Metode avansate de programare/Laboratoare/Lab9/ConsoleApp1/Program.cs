using ConsoleApp1.decorator;
using ConsoleApp1.Factory;
using ConsoleApp1.model;

MessageTask[] CreateMessages() {
    var msg1 = new MessageTask("1", "feedback lab 2", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
    var msg2 = new MessageTask("2", "feedback lab 3", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
    var msg3 = new MessageTask("3", "feedback lab 4", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
    var msg4 = new MessageTask("4", "feedback lab 5", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
    var msg5 = new MessageTask("5", "feedback lab 6", "Te-ai descurcat bine", "teacher", "student", DateTime.Now);
    return [msg1, msg2, msg3, msg4, msg5];
}


// Problema 4
var messageTasks = CreateMessages();
foreach (var messageTask in messageTasks)
{
    System.Console.WriteLine(messageTask);
}
// aici

// AbstractContainer q = new StackContainer();
// q.Add(messageTasks[0]);
// q.Add(messageTasks[1]);
// q.Add(messageTasks[2]);
// q.Add(messageTasks[3]);
// q.Add(messageTasks[4]);
// while (!q.IsEmpty())
//     System.Console.WriteLine(q.Remove());

//Problema 10
ITaskRunner strategyTaskRunner;
if (args[0]=="Fifo")
   strategyTaskRunner = new StrategyTaskRunner(Strategy.Fifo);
else 
    strategyTaskRunner = new StrategyTaskRunner(Strategy.Lifo);

foreach (var m in messageTasks) {
    strategyTaskRunner.AddTask(m);
}

strategyTaskRunner.ExecuteAll();
// aici

int []array = [3,5,1,1,523,123651,12,4,514,1235];
SortingTask t = new SortingTask("1","ceva", array, SortingStrategy.BubbleSorting);
t.Execute();

//Problema 14

StrategyTaskRunner p14_strategy;
if (args[0] == "Fifo")
{
    p14_strategy = new StrategyTaskRunner(Strategy.Fifo);
}
else
{
    p14_strategy = new StrategyTaskRunner(Strategy.Lifo);

}
//        for (MessageTask m : messageTasks) {
//            p14_strategy.addTask(m);
//        }
//        p14_strategy.executeAll();

ITaskRunner p14Delay = new DelayTaskRunner(p14_strategy);
foreach (var m in messageTasks) {
    p14_strategy.AddTask(m);
}
p14Delay.ExecuteAll();

ITaskRunner p14Printer = new PrinterTaskRunner(p14_strategy);
foreach (var m in messageTasks) {
    p14_strategy.AddTask(m); 
}
p14Printer.ExecuteAll();






