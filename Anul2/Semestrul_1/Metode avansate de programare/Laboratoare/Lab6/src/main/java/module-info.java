module org.example.lab_sase{
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.management;
    requires java.desktop;

    opens org.example.lab_sase to javafx.fxml;
    exports org.example.lab_sase;
    exports org.example.lab_sase.Controller;
    exports org.example.lab_sase.Repository;
    exports org.example.lab_sase.Domain;
}