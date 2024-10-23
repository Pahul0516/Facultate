package sem1_2.decorator;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DelayTaskRunner extends AbstractTaskRunner{

    private static final DateTimeFormatter TIME_FORMATTER = DateTimeFormatter.ofPattern("HH:mm");

    public DelayTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeOneTask() {
        try {
            super.executeOneTask();
            System.out.println("Task executed at: " + LocalDateTime.now().format(TIME_FORMATTER));
            Thread.sleep(3000);

        } catch (InterruptedException e) {
            e.printStackTrace();
        }


    }
}
