package org.example;

import Domain.Validator.ValidationException;
import UserInterface.UI;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, ValidationException {
        UI ui = new UI();
        ui.run();
    }
}
