package Repository.Database;

import Domain.User;
import Repository.AbstractRepository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import java.util.Arrays;

public class RepositoryUsersDatabase extends AbstractRepository<Integer, User> {

    private Statement statement;
    private Connection connection;

    // in constructor se face conectarea la baza de date
    public RepositoryUsersDatabase() {
        try{
            String url = "jdbc:postgresql://localhost:5432/Baza_de_date";
            String username = "postgres";
            String password = "Qwertyuiop12!";
            this.connection = DriverManager.getConnection(url, username, password);
            this.statement = connection.createStatement();
            System.out.println("Connected to database");
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    // aici se inchide conexiunea la baza de date
    public void close() {
        try {
            if(statement != null) statement.close();
            if (connection != null) connection.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }


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
    public void read() throws SQLException {

        String query = "SELECT * FROM utilizator";
        ResultSet result = statement.executeQuery(query);
        while (result.next()) {
            int id = result.getInt("id_user");
            String name = result.getString("name");
            Integer[] lista_prietenii  = (Integer[]) result.getArray("friendship_list").getArray();
            List<Integer> lista = new ArrayList<>(Arrays.asList(lista_prietenii));
            User user = new User(id,name);
            user.setFriendship_list(lista);
            friendshipGraph.addVertex(user);
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

    @Override
    public void write() throws SQLException {

        String del_querry = "DELETE from utilizator";
        statement.executeUpdate(del_querry);

        String add_query = "INSERT INTO utilizator VALUES (?, ?, ?)";

        PreparedStatement preparedStatement = connection.prepareStatement(add_query);
        for (User user : findAll()) {

            preparedStatement.setInt(1, user.getId());
            preparedStatement.setString(2, user.getName());
            preparedStatement.setArray(3, connection.createArrayOf("INTEGER", user.getFriendship_list().toArray()));

            preparedStatement.addBatch();
        }
        preparedStatement.executeBatch();
    }

    @Override
    public Optional<User> delete(User user) {
        friendshipGraph.removeVertex(user);
        return Optional.of(user);
    }
}
