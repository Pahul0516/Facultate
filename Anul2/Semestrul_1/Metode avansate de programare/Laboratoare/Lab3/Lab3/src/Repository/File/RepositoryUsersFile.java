package Repository.File;

import Domain.User;

public class RepositoryUsersFile extends AbstractRepositoryFile {

    @Override
    public void create(User user) {
        if (!friendshipGraph.containsVertex(user))
            friendshipGraph.addVertex(user);
        var friends = user.getFriendship_list();
        var persons = getVertexList();
        for (var friendID : friends) {
            for (var person : persons) {
                if (person.getId() == friendID) {
                    if (!friendshipGraph.containsEdge(user, person))
                        friendshipGraph.addEdge(user, person);
                }
            }
        }
        write();
    }

    @Override
    public void delete(User user) {
        friendshipGraph.removeVertex(user);

    }
}
