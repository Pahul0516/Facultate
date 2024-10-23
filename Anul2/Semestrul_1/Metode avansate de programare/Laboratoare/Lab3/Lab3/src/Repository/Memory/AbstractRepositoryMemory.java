package Repository.Memory;

import Domain.User;
import Repository.AbstractRepository;

public abstract class AbstractRepositoryMemory extends AbstractRepository {

    @Override
    public abstract void create(User user);

    @Override
    public void read() {
        // de implementat
    }

    @Override
    public abstract void delete(User user);

}
