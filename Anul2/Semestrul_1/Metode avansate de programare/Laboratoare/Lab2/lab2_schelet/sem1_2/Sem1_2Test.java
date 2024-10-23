package sem1_2;

import sem1_2.decorator.DelayTaskRunner;
import sem1_2.decorator.PrinterTaskRunner;
import sem1_2.decorator.StrategyTaskRunner;
import sem1_2.decorator.TaskRunner;
import sem1_2.factory.Strategy;
import sem1_2.model.*;

import java.time.LocalDateTime;

public class Sem1_2Test {
    public static MessageTask[] createMessages() {
        MessageTask msg1 = new MessageTask("1", "feedback lab 2", "Te-ai descurcat bine", "teacher", "student", LocalDateTime.now());
        MessageTask msg2 = new MessageTask("2", "feedback lab 3", "Te-ai descurcat bine", "teacher", "student", LocalDateTime.now());
        MessageTask msg3 = new MessageTask("3", "feedback lab 4", "Te-ai descurcat bine", "teacher", "student", LocalDateTime.now());
        MessageTask msg4 = new MessageTask("4", "feedback lab 5", "Te-ai descurcat bine", "teacher", "student", LocalDateTime.now());
        MessageTask msg5 = new MessageTask("5", "feedback lab 6", "Te-ai descurcat bine", "teacher", "student", LocalDateTime.now());

        return new MessageTask[]{msg1, msg2, msg3, msg4, msg5};
    }


    public static void main(String[] args) {
          MessageTask[] messageTasks = createMessages();
//        for (MessageTask messageTask : messageTasks) {
//            System.out.println(messageTask);
//        }
//
//        AbstractContainer q = new QueueContainer();
//        q.add(messageTasks[0]);
//        q.add(messageTasks[1]);
//        q.add(messageTasks[2]);
//        q.add(messageTasks[3]);
//        q.add(messageTasks[4]);
//        while (!q.isEmpty())
//            System.out.println(q.remove());

        TaskRunner strategyTaskRunner = new StrategyTaskRunner(Strategy.valueOf(args[0]));
        for (MessageTask m : messageTasks) {
            strategyTaskRunner.addTask(m);
        }

        // t.executeAll();

//        TaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
//        printerTaskRunner.executeAll();
//
//        TaskRunner delayTaskRunner = new DelayTaskRunner(strategyTaskRunner);
//        delayTaskRunner.executeAll();


        int []array = {3,5,1,1,523,123651,12,4,514,1235};
        SortingTask t = new SortingTask("1","ceva", array, SortingStrategy.BUBBLE_SORTING);
        t.execute();



        StrategyTaskRunner p14_strategy = new StrategyTaskRunner(Strategy.valueOf(args[0]));
//        for (MessageTask m : messageTasks) {
//            p14_strategy.addTask(m);
//        }
//        p14_strategy.executeAll();

        TaskRunner p14_delay = new DelayTaskRunner(p14_strategy);
        for (MessageTask m : messageTasks) {
            p14_strategy.addTask(m);
        }
        p14_delay.executeAll();

        TaskRunner p14_printer = new PrinterTaskRunner(p14_strategy);
        for (MessageTask m : messageTasks) {
            p14_strategy.addTask(m);
        }
        p14_printer.executeAll();

    }
}
