package Controller;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.StreamSupport;

import Domain.User;
import Domain.Validator.*;
import Repository.File.RepositoryUsersFile;

import org.jgrapht.alg.connectivity.ConnectivityInspector;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.Graph;

public class Controller {

    RepositoryUsersFile repoFile = new RepositoryUsersFile();
    Validator validator = new Validator();

    public Controller() {
    }

    private int generatorUserId() {
        AtomicInteger id = new AtomicInteger(1);
        var persons = repoFile.getVertexList();

        persons.sort((person1, person2) -> Integer.compare(person1.getId(), person2.getId()));

        persons.stream()
                .filter(person -> person.getId() == id.get())
                .forEach(person -> id.getAndIncrement());

        return id.get();
    }

    public void add_user(String name) throws ValidationException {

        validator.setStrategy(new NameValidator(this));
        validator.validate(name);

        int id = generatorUserId();
        repoFile.create(new User(id, name));
        repoFile.write();
    }

    public void delete_user(int id) throws ValidationException {

        validator.setStrategy(new IdValidator(this));
        validator.validate(String.valueOf(id));

        var persons = repoFile.findAll();

        persons.forEach(
                person -> person
                        .getFriendship_list()
                        .remove(Integer.valueOf(id))
        );
        var user = repoFile.findOne(id);
        repoFile.delete(user.get());
        repoFile.write();
    }

    public void add_friendship(int id1, int id2) throws ValidationException {

        validator.setStrategy(new IdValidator(this));
        validator.validate(String.valueOf(id1) + ',' + String.valueOf(id2));//ma asigur ca exista 2 utilizatori cu id-ul dat
        validator.setStrategy(new ExistFriendshipValidator(this));
        validator.validate(String.valueOf(id1) + ',' + String.valueOf(id2));//ma asigur ca nu exista deja o prietenie intre ei

        var persons = repoFile.findAll();

        persons.forEach(
                person -> {
                    if (person.getId() == id1) {
                        person.getFriendship_list().add(id2);
                    }
                }
        );

//        persons.forEach(
//                person -> {
//                    if (person.getId() == id2) {
//                        person.getFriendship_list().add(id1);
//                    }
//                }
//        );

        // codul de mai sus e echivalent cu cel de jos
        StreamSupport.stream(persons.spliterator(), false) // Creates a stream from persons
                .filter(person -> person.getId() == id2)       // Filter persons with id equal to id2
                .forEach(person -> person.getFriendship_list().add(id1));

        repoFile.write();
    }

    public void delete_friendship(int id1, int id2) throws ValidationException {

        validator.setStrategy(new IdValidator(this));
        validator.validate(String.valueOf(id1) + ',' + String.valueOf(id2));//ma asigur ca exista 2 utilizatori cu id-ul dat
        validator.setStrategy(new NotExistFriendshipValidator(this));
        validator.validate(String.valueOf(id1) + ',' + String.valueOf(id2));//ma asigur ca nu exista deja o prietenie intre ei


        var persons = repoFile.findAll();

        persons.forEach(
                person -> {
                    if (person.getId() == id1) {
                        person.getFriendship_list().remove(Integer.valueOf(id2));
                    }
                }
        );


//        persons.forEach(
//                person -> {
//                    if (person.getId() == id2) {
//                        person.getFriendship_list().remove(Integer.valueOf(id1));
//                    }
//                }
//        );

        // codul de mai sus e echivalent cu cel de jos
        StreamSupport.stream(persons.spliterator(), false)
                .filter(person -> person.getId() == id2)
                .forEach(person -> person.getFriendship_list().remove(Integer.valueOf(id1)));

        repoFile.write();
    }

    public int numbers_of_communities() {
        Graph<User, DefaultEdge> graph = repoFile.getGraph();
        ConnectivityInspector<User, DefaultEdge> connectivityInspector = new ConnectivityInspector<>(graph);
        return connectivityInspector.connectedSets().size();
    }

    public Set<User> longestCommunity() {
        Graph<User, DefaultEdge> graph = repoFile.getGraph();
        ConnectivityInspector<User, DefaultEdge> connectivityInspector = new ConnectivityInspector<>(graph); //determin toate componentele conexe
        Set<User> communityWithLongestPath = null; // la inceput lungimea celei mai mari comunitati este null
        int maxPathLength = 0;

        // parcurg fiecare componenta conexa in parte
        for (Set<User> community : connectivityInspector.connectedSets()) {

            Set<User> visited = new HashSet<>();
            int longestPathInCommunity = dfs(graph, community.iterator().next(), visited); // determin lungime drumului componenteo conexe

            if (longestPathInCommunity > maxPathLength) { // actualizez convnabil cea mai lung drum a comunitatii
                maxPathLength = longestPathInCommunity;
                communityWithLongestPath = community;
            }
        }
        return communityWithLongestPath; // Return the community with the longest path
    }

    private int dfs(Graph<User, DefaultEdge> graph, User current, Set<User> visited) {
        visited.add(current); //vizitez prima persoana din graf
        int maxLength = 0;

        for (DefaultEdge edge : graph.edgesOf(current)) {
            User neighbor = graph.getEdgeTarget(edge); // parcurg vecinii persoanei curente
            if (neighbor.equals(current)) {
                neighbor = graph.getEdgeSource(edge);
            }

            if (!visited.contains(neighbor)) {
                maxLength = Math.max(maxLength, 1 + dfs(graph, neighbor, visited));
            }
        }

        visited.remove(current);
        return maxLength;
    }

    public void read() {
        repoFile.read();
    }

    public List<User> getUsers() {
        return new ArrayList<>(repoFile.getVertexList());
    }

    public boolean isValidUserId(int userId) {
        var persons = repoFile.findAll();
        for (var person : persons) {
            if (person.getId() == userId) {
                return true;
            }
        }
        return false;
    }
}