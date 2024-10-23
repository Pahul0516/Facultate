package Repository;
import Domain.User;
import org.jgrapht.Graph;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.graph.SimpleGraph;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractRepository implements Repository {

    protected Graph<User, DefaultEdge> friendshipGraph = new SimpleGraph<>(DefaultEdge.class);

    @Override
    public abstract void create(User user);

    @Override
    public abstract void read();

    @Override
    public void update(User oldUser,User newUser) {
        delete(oldUser);
        create(newUser);
    }

    @Override
    public abstract void delete(User user);

    public List<User> getVertexList () {
        return new ArrayList<>(friendshipGraph.vertexSet());
    }

    public Graph<User, DefaultEdge> getGraph() {
        return friendshipGraph;
    }


}
