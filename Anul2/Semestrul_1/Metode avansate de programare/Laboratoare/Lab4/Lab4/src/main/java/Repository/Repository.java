package Repository;

import Domain.Entity;
import Domain.User;

import java.util.Optional;

public interface Repository<ID, E extends Entity<ID>> {
    Optional<E> create(E entity);
    void read();
    Optional<E> delete(E entity);


    Optional<E> findOne(ID id);
    Iterable<E> findAll();

}
