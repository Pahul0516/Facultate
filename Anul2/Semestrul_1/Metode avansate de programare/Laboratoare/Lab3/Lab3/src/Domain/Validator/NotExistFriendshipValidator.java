package Domain.Validator;

import Controller.Controller;

public class NotExistFriendshipValidator implements ValidatorStrategy{

    Controller contr;

    public NotExistFriendshipValidator(Controller contr) {
        this.contr = contr;
    }

    @Override
    public void validate(String data) throws ValidationException {

        String[] elements = data.split(",");
        int id1 = Integer.parseInt(elements[0].trim());
        int id2 = Integer.parseInt(elements[1].trim());
        var persons = contr.getUsers();

        boolean friendshipExists = false;

        for (var person : persons) {
            if (person.getId() == id1 && person.getFriendship_list().contains(id2)) {
                friendshipExists = true;
                break;
            }
        }

        if (!friendshipExists) {
            throw new ValidationException("Nu exista o prietenie intre " + String.valueOf(id1) + " si " + String.valueOf(id2));
        }

    }
}
