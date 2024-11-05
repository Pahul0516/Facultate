package Domain;
import java.util.ArrayList;
import java.util.List;

public class User extends Entity<Integer> {

    private int id;
    private String name;
    private List<Integer> friendship_list = new ArrayList<>();

    public User(int id, String name) {
        super(id);
        this.id = id;
        this.name = name;
    }

    public Integer getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Integer> getFriendship_list() {
        return friendship_list;
    }

    public void setFriendship_list(List<Integer> friendship_list) {
        this.friendship_list = friendship_list;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", friendship_list=" + friendship_list +
                '}';
    }
}
