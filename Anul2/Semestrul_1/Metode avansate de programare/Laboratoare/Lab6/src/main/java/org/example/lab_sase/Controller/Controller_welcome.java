package org.example.lab_sase.Controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Rectangle2D;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Hyperlink;
import javafx.stage.Screen;
import javafx.stage.Stage;

import java.io.IOException;

public class Controller_welcome extends Service {

    private Stage stage;

    @FXML
    public Button btn_register;
    @FXML
    public Button btn_login;

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    public void open_login(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/lab_sase/Login.fxml"));
        Parent root = loader.load();
        Scene loginScene = new Scene(root);
        stage.setScene(loginScene);

        Controller_login controller = loader.getController();
        controller.setRepo_friendships(repo_friendships);
        controller.setRepo_users(repo_users);
        controller.setStage(stage);

        stage.show();
        root.requestFocus();
    }

    public void open_register(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/lab_sase/Register.fxml"));
        Parent root = loader.load();
        Scene loginScene = new Scene(root);
        stage.setScene(loginScene);

        Controller_register controller = loader.getController();
        controller.setRepo_friendships(repo_friendships);
        controller.setRepo_users(repo_users);
        controller.setStage(stage);

        stage.show();
        root.requestFocus();
    }
}
