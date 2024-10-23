package sem1_2.model;


import sem1_2.decorator.AbstractSorter;


import java.util.Arrays;



public class SortingTask extends Task{

    private final int[] array;
    private AbstractSorter sorter;

    public SortingTask(String id, String description, int[]array, SortingStrategy sortingStrategy) {
        super(id,description);
        this.array = array;

        switch (sortingStrategy) {
            case BUBBLE_SORTING -> this.sorter = new BubbleSort();
            case QUICK_SORTING ->  this.sorter = new QuickSort();
        }
    }

    @Override
    public void execute() {
        this.sorter.sort(this.array);
        System.out.println(Arrays.toString(array));
    }
}
