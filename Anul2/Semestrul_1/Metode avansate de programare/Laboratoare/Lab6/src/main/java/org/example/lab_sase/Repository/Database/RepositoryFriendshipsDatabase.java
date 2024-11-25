package org.example.lab_sase.Repository.Database;

import org.example.lab_sase.Domain.Friendship;
import org.example.lab_sase.Repository.AbstractRepository;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

public class RepositoryFriendshipsDatabase extends AbstractRepository<Integer, Friendship> {

    private final List<Friendship> friendships = new ArrayList<>();
    private Connection connection;
    private Statement statement;

    public RepositoryFriendshipsDatabase(Connection connection){
        try {
            this.connection = connection;
            this.statement = connection.createStatement();
            this.read();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public Optional<Friendship> create(Friendship friendship) throws SQLException {
        friendships.add(friendship);
        this.write(friendship,"add");
        return Optional.of(friendship);
    }

    @Override
    public Optional<Friendship> update(Friendship friendship) throws SQLException {
        Friendship oldFriendship = friendships.get(friendship.getId());
        oldFriendship.setUser_id1(friendship.getUser_id1());
        oldFriendship.setUser_id2(friendship.getUser_id2());
        oldFriendship.setFriendsFrom(friendship.getFriendsFrom());
        this.write(friendship, "update");
        return Optional.of(oldFriendship);
    }

    @Override
    public Optional<Friendship> delete(Friendship friendship) throws SQLException {
        friendships.remove(friendship);
        this.write(friendship,"delete");
        return Optional.empty();
    }

    @Override
    public Optional<Friendship> findOne(Integer id) {
        return friendships.stream()
                .filter(friendship -> Objects.equals(friendship.getId(), id))
                .findFirst();
    }

    @Override
    public Iterable<Friendship> findAll() {
        return friendships;
    }

    public Iterable<Friendship> findAllById1(Integer id1) {
        List<Friendship> f = new ArrayList<>();
        for (Friendship friendship : friendships) {
            if (friendship.getUser_id1() == id1) {
                f.add(friendship);
            }
        }
        return f;
    }

    public Iterable<Friendship> findAllById2(Integer id1) {
        List<Friendship> f = new ArrayList<>();
        for (Friendship friendship : friendships) {
            if (friendship.getUser_id2() == id1) {
                f.add(friendship);
            }
        }
        return f;
    }

    public String getStatus(Integer id){
        try {
            String querry = "SELECT status FROM friendship_status where id_status = " + id.toString();
            ResultSet resultSet = statement.executeQuery(querry);
            if (resultSet.next()) {
                return resultSet.getString("status");
            }
            return null;
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    public void setStatus(Integer id_status, String status){
        try {
            String querry = "UPDATE friendship_status SET status = ? WHERE id_status = ?";
            PreparedStatement preparedStatement = connection.prepareStatement(querry);
            preparedStatement.setString(1, status);
            preparedStatement.setInt(2, id_status);
            preparedStatement.executeUpdate();
            preparedStatement.close();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }

    }

    @Override
    public void read() throws SQLException {
        String query = "SELECT * FROM friendships";
        ResultSet resultSet = statement.executeQuery(query);
        while (resultSet.next()) {
            int id = resultSet.getInt("id_friendship");
            int idUser1 = resultSet.getInt("id_user1");
            int idUser2 = resultSet.getInt("id_user2");
            int idStatus = resultSet.getInt("id_status");
            LocalDateTime friendsFrom = resultSet.getTimestamp("friendship_date").toLocalDateTime();
            Friendship friendship = new Friendship(idUser1, idUser2, idStatus, friendsFrom);
            friendship.setId(id);
            friendships.add(friendship);
        }
    }

    @Override
    public void write(Friendship friendship, String operationType) throws SQLException {
        switch (operationType) {
            case "add":
                add_database(friendship);
                break;
            case "delete":
                delete_database(friendship);
                break;
            case "update":
                update_database(friendship);
                break;
        }
    }

    private void add_database(Friendship friendship) throws SQLException {
        String query = "INSERT INTO friendships (id_user1, id_user2, id_status, friendship_date) VALUES (?, ?, ?, ?)";
        PreparedStatement preparedStatement = connection.prepareStatement(query);
        preparedStatement.setInt(1, friendship.getUser_id1());
        preparedStatement.setInt(2, friendship.getUser_id2());
        preparedStatement.setInt(3, friendship.getId_staus());
        preparedStatement.setTimestamp(4, Timestamp.valueOf(friendship.getFriendsFrom()));
        preparedStatement.execute();
        preparedStatement.close();
    }

    private void delete_database(Friendship friendship) throws SQLException {
        String querry = "DELETE FROM friendship_status WHERE id_status = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(querry);
        preparedStatement.setInt(1, friendship.getId_staus());
        preparedStatement.execute();
        preparedStatement.close();
    }

    private void update_database(Friendship friendship) throws SQLException {
        String query = "UPDATE prietenie SET iduser1 = ?, iduser2 = ?, dataprieteniei = ? WHERE id = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(query);
        preparedStatement.setInt(1, friendship.getUser_id1());
        preparedStatement.setInt(2, friendship.getUser_id2());
        preparedStatement.setTimestamp(3, Timestamp.valueOf(friendship.getFriendsFrom()));
        preparedStatement.setInt(4, friendship.getId());
        preparedStatement.execute();
        preparedStatement.close();
    }

    public Integer create_friendshipStatus(Integer idUserRequest, Integer idUserReceive, String message) {
        try {
            String queryInsert = "INSERT INTO friendship_status (id_user_request, id_user_receive, status)  VALUES (?, ?, ?)";
            PreparedStatement preparedStatement1 = connection.prepareStatement(queryInsert);
            preparedStatement1.setInt(1, idUserRequest);
            preparedStatement1.setInt(2, idUserReceive);
            preparedStatement1.setString(3, message);
            preparedStatement1.executeUpdate();
            preparedStatement1.close();

            String qeurySelect = "Select id_status from friendship_status where id_user_request = ? and id_user_receive = ?";
            PreparedStatement preparedStatement2 = connection.prepareStatement(qeurySelect);
            preparedStatement2.setInt(1, idUserRequest);
            preparedStatement2.setInt(2, idUserReceive);
            ResultSet resultSet = preparedStatement2.executeQuery();
            if (resultSet.next()) {
                return resultSet.getInt("id_status");
            }
            preparedStatement2.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        return -1;
    }
    public void deleteFriendship(Integer idStatus) {
        try {
            String query = "DELETE FROM friendship_status where id_status = ?";
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            preparedStatement.setInt(1, idStatus);
            preparedStatement.executeUpdate();
            preparedStatement.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
