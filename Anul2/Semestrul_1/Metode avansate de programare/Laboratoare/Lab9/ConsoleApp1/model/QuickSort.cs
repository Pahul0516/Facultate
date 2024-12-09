using ConsoleApp1.decorator;

namespace ConsoleApp1.model;

public class QuickSort : AbstractSorter
{
    public override void Sort(int[] array)
    {
        QSort(array, 0, array.Length - 1);
    }
    private void QSort(int[] array, int low, int high) {
        if (low < high) {
            var pi = Partition(array, low, high);
            QSort(array, low, pi - 1);
            QSort(array, pi + 1, high);
        }
    }
    private static int Partition(int[] array, int low, int high)
    {
        int temp;
        var pivot = array[high];
        var i = (low - 1);
        for (var j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        return i + 1;
    }
}