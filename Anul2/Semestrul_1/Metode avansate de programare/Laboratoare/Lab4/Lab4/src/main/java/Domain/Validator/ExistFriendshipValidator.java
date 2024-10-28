package Domain.Validator;

import Controller.Controller;

public class ExistFriendshipValidator implements ValidatorStrategy{

    Controller contr;

    public ExistFriendshipValidator(Controller contr) {
        this.contr = contr;
    }

    @Override
    public void validate(String data) throws ValidationException {

        String[] elements = data.split(",");
        int id1 = Integer.parseInt(elements[0].trim());
        int id2 = Integer.parseInt(elements[1].trim());
        var persons = contr.getUsers();

        for (var person : persons) {
            if (person.getId() == id1 && person.getFriendship_list().contains(id2)) {
                throw new ValidationException("Exista deja prietenie intre "+ String.valueOf(id1) + " si " + String.valueOf(id2));
            }
        }


    }
}
