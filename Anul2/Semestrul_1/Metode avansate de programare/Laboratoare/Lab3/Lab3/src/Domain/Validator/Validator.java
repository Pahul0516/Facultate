package Domain.Validator;


public class Validator {
    private ValidatorStrategy strategy;

    public void setStrategy(ValidatorStrategy strategy) {
        this.strategy = strategy;
    }

    public boolean validate(String input) {
        if (strategy == null) {
            throw new IllegalStateException("Validation strategy not set");
        }
        return strategy.validate(input);
    }
}
