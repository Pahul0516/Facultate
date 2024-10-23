package Repository.Memory;

import Domain.User;

public class RepositoryUsersMemory extends AbstractRepositoryMemory{
    @Override
    public void create(User user) {
        System.out.println("Creating users memory");
    }

    @Override
    public void delete(User user) {
        System.out.println("Deleting users memory");
    }
}
