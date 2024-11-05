package org.example;

import Domain.Validator.ValidationException;
import UserInterface.UI;

import java.io.IOException;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws IOException, ValidationException, SQLException {
        UI ui = new UI();
        ui.run();
    }
}
