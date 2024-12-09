module org.example.lab7 {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.management;
    requires java.desktop;

    opens org.example.lab7 to javafx.fxml;
    exports org.example.lab7;
    exports org.example.lab7.Controller;
    exports org.example.lab7.Repository;
    exports org.example.lab7.Domain;
}