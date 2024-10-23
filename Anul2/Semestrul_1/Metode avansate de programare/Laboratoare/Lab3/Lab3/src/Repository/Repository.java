package Repository;

import Domain.User;

public interface Repository {
    public void create(User user);
    public void read();
    public void update(User user1,User user2);
    public void delete(User user);

}
