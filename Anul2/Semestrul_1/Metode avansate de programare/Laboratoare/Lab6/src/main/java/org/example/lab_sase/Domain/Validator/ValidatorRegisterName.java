package org.example.lab_sase.Domain.Validator;

import org.example.lab_sase.Repository.Database.RepositoryUsersDatabase;


public class ValidatorRegisterName implements ValidatorStrategy{

    RepositoryUsersDatabase repositoryUsers;

    public ValidatorRegisterName(RepositoryUsersDatabase repositoryUsers) {
        this.repositoryUsers = repositoryUsers;
    }

    @Override
    public void validate(String data) throws ValidationException {
        if (data.isEmpty())
            throw new ValidationException("Empty data");
    }
}
