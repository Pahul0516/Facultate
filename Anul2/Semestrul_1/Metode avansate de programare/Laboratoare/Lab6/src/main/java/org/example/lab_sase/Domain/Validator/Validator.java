package org.example.lab_sase.Domain.Validator;


import org.example.lab_sase.Repository.AbstractRepository;

import java.sql.SQLException;

public class Validator {
    private ValidatorStrategy strategy;

    public void setStrategy(ValidatorStrategy strategy) {
        this.strategy = strategy;
    }

    public void validate(String input) throws ValidationException{
        if (strategy == null) {
            throw new IllegalStateException("Nu ai setat un tip de validare");
        }
        strategy.validate(input);
    }
}