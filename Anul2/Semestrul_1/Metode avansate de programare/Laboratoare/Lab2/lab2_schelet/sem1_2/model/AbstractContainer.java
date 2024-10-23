package sem1_2.model;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractContainer implements Container {
    List<Task> tasks = new ArrayList<Task>();

    public abstract Task remove();

    public void add(Task task) {
        tasks.add(task);
    }

    public int size() {
        return tasks.size();
    }

    public boolean isEmpty() {
        return tasks.isEmpty();
    }
}
