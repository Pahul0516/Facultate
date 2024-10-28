package Repository;

import Domain.Entity;
import Domain.User;
import org.jgrapht.Graph;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.graph.SimpleGraph;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public abstract class AbstractRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {

    protected Graph<E, DefaultEdge> friendshipGraph = new SimpleGraph<>(DefaultEdge.class);

    @Override
    public abstract Optional<E> create(E user);

    @Override
    public abstract void read();

    @Override
    public abstract Optional<E> delete(E user);

    @Override
    public Optional<E> findOne(ID id) {
        return friendshipGraph.vertexSet()
                .stream()
                .filter(user -> user.getId().equals(id))
                .map(user -> (E) user)
                .findFirst();
    }

    @Override
    public Iterable<E> findAll() {
        return friendshipGraph.vertexSet();
    }

    public List<E> getVertexList() {
        return new ArrayList<>(friendshipGraph.vertexSet());
    }

    public Graph<E, DefaultEdge> getGraph() {
        return friendshipGraph;
    }

}
