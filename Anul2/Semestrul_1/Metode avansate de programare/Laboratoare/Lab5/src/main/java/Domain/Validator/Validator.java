package Domain.Validator;


public class Validator {
    private ValidatorStrategy strategy;

    public void setStrategy(ValidatorStrategy strategy) {
        this.strategy = strategy;
    }

    public void validate(String input) throws ValidationException {
        if (strategy == null) {
            throw new IllegalStateException("Nu ai setat un timp de validare");
        }
        strategy.validate(input);
    }
}
