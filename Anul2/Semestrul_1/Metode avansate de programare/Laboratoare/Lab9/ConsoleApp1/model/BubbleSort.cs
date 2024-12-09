using ConsoleApp1.decorator;

namespace ConsoleApp1.model;

public class BubbleSort : AbstractSorter
{
    public override void Sort(int[] array)
    {
        var n = array.Length;
        for (var i = 0; i < n - 1; i++) {
            for (var j = 0; j < n - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    (array[j], array[j + 1]) = (array[j + 1], array[j]);
                }
            }
        }
    }
}