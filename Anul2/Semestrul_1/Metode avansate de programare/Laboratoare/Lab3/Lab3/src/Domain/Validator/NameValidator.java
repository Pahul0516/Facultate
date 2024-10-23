package Domain.Validator;

import Controller.Controller;

public class NameValidator implements ValidatorStrategy{

    Controller contr;
    public NameValidator(Controller contr) {
        this.contr = contr;
    }

    @Override
    public boolean validate(String data) {
        if (data == null || data.trim().isEmpty()) {
            return false;
        }
        String regex = "^[\\p{L} .'-]+$";
        return data.matches(regex);
    }
}
