package Repository.File;

import Domain.User;
import Repository.AbstractRepository;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class RepositoryUsersFile extends AbstractRepository<Integer, User> {

    @Override
    public Optional<User> create(User user) {
        if (!friendshipGraph.containsVertex(user))
            friendshipGraph.addVertex(user);

        var friends = user.getFriendship_list();
        friends.forEach(friendID-> {
            var person = findOne(friendID);
            if (!friendshipGraph.containsEdge(user, person.get()))
                friendshipGraph.addEdge(user, person.get());
        });

        return Optional.of(user);
    }

    @Override
    public Optional<User> delete(User user) {
        friendshipGraph.removeVertex(user);
        return Optional.of(user);
    }

    public void read() {
        String filePath = "C:\\Users\\berin\\IdeaProjects\\Lab4\\src\\main\\java\\Repository\\File\\Data.csv";


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
                    friendshipGraph.addVertex(user);
                }
            }

            var persons = findAll();
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
        String filePath = "C:\\Users\\berin\\IdeaProjects\\Lab4\\src\\main\\java\\Repository\\File\\Data.csv";


        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            for (User user : findAll()) {
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

}
