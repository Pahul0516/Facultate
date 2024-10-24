package Domain.Validator;

import Controller.Controller;

public class NameValidator implements ValidatorStrategy{

    Controller contr;
    public NameValidator(Controller contr) {
        this.contr = contr;
    }

    @Override
    public void validate(String data) throws ValidationException {
        if (data == null || data.trim().isEmpty()) {
            throw new ValidationException("Trebuie sa existe un nume");
        }
        String regex = "^[\\p{L} .'-]+$";
        if (!data.matches(regex)) {
            throw new ValidationException("Numele nu e bun");
        }
    }
}
