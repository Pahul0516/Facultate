package Repository.File;
import Domain.User;
import Repository.AbstractRepository;

import java.io.*;
import java.util.ArrayList;
import java.util.List;


public abstract class AbstractRepositoryFile extends AbstractRepository {

    @Override
    public abstract void create(User user);

    @Override
    public void read() {
        String filePath = "C:\\Users\\berin\\IdeaProjects\\Lab3\\src\\Repository\\File\\Data.csv";

        try (BufferedReader br = new BufferedReader(new FileReader(filePath)))
        {
            String line;
            while ((line = br.readLine()) != null) {
                if (line!="") {
                    String[] values = line.split(",");
                    User user = new User(Integer.parseInt(values[0]), values[1]);
                    List<Integer> list = new ArrayList<>();

                    if (values.length > 2 && values[2] != null && !values[2].isEmpty()) {
                        String[] ids = values[2].split(" ");
                        for (String id : ids) {
                            list.add(Integer.parseInt(id));
                        }
                    }
                    user.setFriendship_list(list);
//
                    friendshipGraph.addVertex(user);
                }
            }

            var persons = getVertexList();
            for (var person : persons) {
                var friends = person.getFriendship_list();
                for (var friendID : friends) {
                    for (var person2 : persons) {
                        if (person2.getId() == friendID) {
                            if (!friendshipGraph.containsEdge(person, person2))
                                friendshipGraph.addEdge(person, person2);
                        }
                    }
                }
            }
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }


    public void write() {
        String filePath = "C:\\Users\\berin\\IdeaProjects\\Lab3\\src\\Repository\\File\\Data.csv";

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            for (User user : getVertexList()) {
                StringBuilder line = new StringBuilder();
                line.append(user.getId()).append(",")
                        .append(user.getName()).append(",");

                List<Integer> friends = user.getFriendship_list();
                for (int i = 0; i < friends.size(); i++) {
                    line.append(friends.get(i));
                    if (i < friends.size() - 1) {
                        line.append(" ");
                    }
                }

                bw.write(line.toString());
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    @Override
    public abstract void delete(User user);
}
