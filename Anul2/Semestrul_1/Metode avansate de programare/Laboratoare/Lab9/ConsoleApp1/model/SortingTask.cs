using ConsoleApp1.decorator;
namespace ConsoleApp1.model;


public class SortingTask : Task
{
    private int[] array;
    private AbstractSorter sorter ;

    public SortingTask(string id, string description, int[] array, SortingStrategy sortingStrategy) 
        : base(id, description)
    {
        this.array = array;
        this.sorter = sorter;
        switch (sortingStrategy)
        {  
          case SortingStrategy.BubbleSorting:
              this.sorter = new BubbleSort();
              break;
          case SortingStrategy.QuickSorting:
              this.sorter = new QuickSort();
              break;
        }
    }
    

    public override void Execute()
    {
        this.sorter.Sort(array);
        System.Console.WriteLine(string.Join(" ", array));
    }
}