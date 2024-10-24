package Domain.Validator;

import Controller.Controller;

import java.util.HashSet;
import java.util.Set;


public class IdValidator implements ValidatorStrategy {

    Controller contr;

    public IdValidator(Controller contr) {
        this.contr = contr;
    }

    @Override
    public void validate(String data) throws ValidationException {

        String[] elements = data.split(",");
        Set<Integer> uniqueIds = new HashSet<>();

        for (String element : elements) {
            Integer id = Integer.parseInt(element.trim());

            if (!contr.isValidUserId(id)) {
                throw new ValidationException("Nu avem un user cu id-ul " + id);
            }

            if (!uniqueIds.add(id)) {
                throw new ValidationException("Nu putem adauga un user la un user");
            }
        }
    }
}
