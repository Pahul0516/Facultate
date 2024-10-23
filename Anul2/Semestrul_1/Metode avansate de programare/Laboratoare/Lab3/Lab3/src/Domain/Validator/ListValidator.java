package Domain.Validator;

import Controller.Controller;

import java.util.HashSet;
import java.util.Set;

public class ListValidator implements ValidatorStrategy{

    Controller contr;

    public ListValidator(Controller contr) {
        this.contr = contr;
    }

    @Override
    public boolean validate(String data) {
        
        try {
            String[] elements = data.split(",");
            for (String element : elements) {
               
                int id = Integer.parseInt(element.trim());
                
                if (!contr.isValidUserId(id)) {
                    return false;
                }

                if (!contr.isValidUserId(id)) {
                    return false;
                }
            }
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    
}

