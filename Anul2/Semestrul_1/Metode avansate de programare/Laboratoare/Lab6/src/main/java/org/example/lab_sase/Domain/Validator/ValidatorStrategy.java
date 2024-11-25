package org.example.lab_sase.Domain.Validator;

import java.sql.SQLException;

public interface ValidatorStrategy {
    public void validate(String data) throws ValidationException;
}
