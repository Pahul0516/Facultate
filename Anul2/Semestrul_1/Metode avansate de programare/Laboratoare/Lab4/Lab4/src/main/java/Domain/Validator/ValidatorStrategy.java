package Domain.Validator;

public interface ValidatorStrategy {
    public void validate(String data) throws ValidationException;
}
