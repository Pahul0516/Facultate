package UserInterface;

import java.sql.SQLException;
import java.util.Collections;


import Controller.Controller;
import Domain.Validator.ValidationException;

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
        System.out.println("1.Adauga utilizator");
        System.out.println("2.Sterge utilizator");
        System.out.println("3.Adauga prietenie");
        System.out.println("4.Sterge prietenie");
        System.out.println("5.Afisare numar de comunitati");
        System.out.println("6.Afisare cea mai sociabila comunitate");
        System.out.println("7.Exit");
    }

    public void run() throws IOException, ValidationException, SQLException {

        contr.read();

        boolean ok = true;

        while (true)
        {
            show_entities();
            show_options();
            System.out.println("Te rog sa introduci o optiune: ");
            var option = Integer.parseInt(reader.readLine());
            switch (option)
            {
                case 1:
                    System.out.println("Te rog sa intorduci numele: ");
                    String name = reader.readLine();
                    try {
                        contr.add_user(name);
                    }
                    catch (ValidationException e){
                        e.printStackTrace();
                    }
                    break;
                case 2:
                    System.out.println("Te rog sa intorduci id-ul persoanei pe care vrei sa o stergi: ");
                    int id = Integer.parseInt(reader.readLine());
                    try {
                        contr.delete_user(id);
                    }
                    catch (ValidationException e){
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    System.out.println("Te rog sa introduci id-urile persoanelor intre care vrei sa faci o prietenie: ");
                    int id1 = Integer.parseInt(reader.readLine());
                    int id2 = Integer.parseInt(reader.readLine());
                    String ids = id1 + "," + id2;
                    try {
                        contr.add_friendship(id1, id2);
                    }
                    catch (ValidationException e){
                        e.printStackTrace();
                    }
                    break;
                case 4:
                    System.out.println("Te rog sa introduci id-urile persoanelor care vrei sa nu mai fie prieteni: ");
                    int id3 = Integer.parseInt(reader.readLine());
                    int id4 = Integer.parseInt(reader.readLine());
                    try {
                        contr.delete_friendship(id3, id4);
                    }
                    catch (ValidationException e){
                        e.printStackTrace();
                    }
                    break;
                case 5:
                    System.out.println("Numarul de comunitati este " + contr.numbers_of_communities());
                    break;
                case 6:
                    System.out.println("Cea mai sociabila comunitate este " + contr.longestCommunity());
                    break;
                case 7:
                    contr.close_DB();
                    ok = false;
                    break;
                default:
                    break;
            }
            if (ok == false)
                break;
        }
    }
}
