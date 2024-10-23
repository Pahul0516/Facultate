package UserInterface;

import java.util.Collections;


import Controller.Controller;
import Domain.Validator.ListValidator;
import Domain.Validator.NameValidator;
import Domain.Validator.ValidationException;
import Domain.Validator.Validator;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UI {

    private Controller contr = new Controller();
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));


    public void show_entities()
    {
        var users = contr.getUsers();
        Collections.sort(users, (person1, person2) -> Integer.compare(person1.getId(), person2.getId()));
         for (var user : users)
         {
             System.out.println(user);
         }
    }

    public void show_options()
    {
        System.out.println("1.Citeste din memorie");
        System.out.println("2.Adauga utilizator");
        System.out.println("3.Sterge utilizator");
        System.out.println("4.Adauga prietenie");
        System.out.println("5.Sterge prietenie");
        System.out.println("6.Afisare numar de comunitati");
        System.out.println("7.Afisare cea mai sociabila comunitate");
    }

    public void run() throws IOException {
        Validator validator1 = new Validator();
        Validator validator2 = new Validator();
        
        validator1.setStrategy(new NameValidator(contr));
        validator2.setStrategy(new ListValidator(contr));
        
        while (true)
        {
            show_entities();
            show_options();
            System.out.println("Te rog sa introduci o optiune: ");
            var option = Integer.parseInt(reader.readLine());
            switch (option)
            {
                case 1:
                    contr.read();
                    break;
                case 2:
                    System.out.println("Te rog sa intorduci numele: ");
                    String name = reader.readLine();
                    try {
                        if (validator1.validate(name))
                            contr.add_user(name);
                        else {
                            throw new ValidationException("Numele nu e bun!");
                        }
                    }
                    catch (ValidationException e){
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    System.out.println("Te rog sa intorduci id-ul persoanei pe care vrei sa o stergi: ");
                    int id = Integer.parseInt(reader.readLine());
                    contr.delete_user(id);
                    break;
                case 4:
                    System.out.println("Te rog sa introduci id-urile persoanelor intre care vrei sa faci o prietenie: ");
                    int id1 = Integer.parseInt(reader.readLine());
                    int id2 = Integer.parseInt(reader.readLine());
                    String ids = id1 + "," + id2;
                    if (validator2.validate(ids))
                        contr.add_friendship(id1, id2);
                    else
                        System.out.println("Unul dintre id-uri nu exista");
                    break;
                case 5:
                    System.out.println("Te rog sa introduci id-urile persoanelor care vrei sa nu mai fie prieteni: ");
                    int id3 = Integer.parseInt(reader.readLine());
                    int id4 = Integer.parseInt(reader.readLine());
                    contr.delete_friendship(id3, id4);
                    break;
                case 6:
                    System.out.println("Numarul de comunitati este " + contr.numbers_of_comunities());
                    break;
                case 7:
                    System.out.println("Cea mai sociabila comunitate este " + contr.longestCommunity());
                    break;
                default:
                    break;
            }
        }
    }
}
