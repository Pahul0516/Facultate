package org.example.lab_sase.Controller;

import javafx.beans.Observable;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;
import org.example.lab_sase.Domain.Friendship;
import org.example.lab_sase.Domain.FriendshipsDTO;
import org.example.lab_sase.Domain.RequestDTO;
import org.example.lab_sase.Domain.UserDTO;
import org.example.lab_sase.Observer.Observer;
import org.example.lab_sase.Repository.Database.RepositoryFriendshipsDatabase;
import org.example.lab_sase.Repository.Database.RepositoryUsersDatabase;

import java.io.IOException;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Controller_main_page extends Service implements Observer {

    private Stage stage;
    private Integer id_user;

    @FXML
    private Label Label_name;

    @FXML
    public TableView<FriendshipsDTO> tableViewFriendships;
    @FXML
    public TableView<RequestDTO> tableViewRequests;
    @FXML
    public TableColumn<FriendshipsDTO,Void> friendsTableColumn;
    @FXML
    public TableColumn<RequestDTO,Void> requestTableColumn;

    @FXML
    private Button btn_options;
    @FXML
    private ContextMenu contextMenu;

    @FXML
    public ListView<UserDTO> listViewSearch;
    @FXML
    private TextField search_textField;
    @FXML
    public ContextMenu contextMenuSearch;
    @FXML
    public CustomMenuItem customMenuItem;

    ObservableList<FriendshipsDTO> friendsList = FXCollections.observableArrayList();
    ObservableList<RequestDTO> requestsList = FXCollections.observableArrayList();
    ObservableList<UserDTO> names = FXCollections.observableArrayList();


    @FXML
    public void initialize(RepositoryUsersDatabase repositoryUsers, RepositoryFriendshipsDatabase repositoryFriendships) throws SQLException {

        this.repo_users = repositoryUsers;
        this.repo_friendships = repositoryFriendships;

        search_textField.textProperty().addListener((observable, oldValue, newValue) -> {

            FilteredList<UserDTO> filteredNames = new FilteredList<>(names, s -> true);
            listViewSearch.setItems(filteredNames);

            filteredNames.setPredicate(user -> user.getName().toLowerCase().startsWith(newValue.toLowerCase()));
            boolean hasMatches = !filteredNames.isEmpty();

            if (!newValue.isEmpty() && hasMatches) {
                // Update ListView items
                listViewSearch.setItems(filteredNames);

                // Calculate position of the TextField
                double textFieldY = search_textField.localToScene(0, 0).getY();
                double textFieldHeight = search_textField.getHeight();

                // Adjust ListView position dynamically
                listViewSearch.relocate(search_textField.getLayoutX(), textFieldY + textFieldHeight);
                listViewSearch.setVisible(true);
            } else {
                listViewSearch.setVisible(false);
            }
        });

        listViewSearch.setCellFactory(lv -> new ListCell<>() {
            @Override
            protected void updateItem(UserDTO item, boolean empty) {
                super.updateItem(item, empty);

                if (empty || item == null) {
                    setGraphic(null);
                }
                else {
                    // Create a Label for the name
                    Label nameLabel = new Label(item.getName());

                    // Create a Button for the action
                    Button addButton = new Button();

                    Image trashIcon = new Image(getClass().getResourceAsStream("/org/example/lab_sase/Add.png")); // Ensure the path is correct
                    ImageView trashImageView = new ImageView(trashIcon);
                    trashImageView.setFitWidth(15);
                    trashImageView.setFitHeight(15);

                    addButton.setGraphic(trashImageView);
                    addButton.setStyle("-fx-background-color: transparent;");


                    addButton.setOnAction(event -> {
                        search_textField.clear(); // Update the search bar with the selected name
                        listViewSearch.setVisible(false); // Hide the dropdown
                        Integer id_status = repositoryFriendships.create_friendshipStatus(id_user,item.getId_user(),"pending");
                        Friendship friendship = new Friendship(id_user,item.getId_user(),id_status, LocalDateTime.now());
                        try {
                            add_friendship(friendship);
                        } catch (SQLException e) {
                            throw new RuntimeException(e);
                        }
                        notifyObservers();
                        //loadData();
                    });
                    addButton.setOnMouseEntered(event -> {
                        addButton.setStyle("-fx-background-color: rgba(169, 169, 169, 0.3); -fx-border-color: transparent;");
                    });
                    addButton.setOnMouseExited(event -> {
                        addButton.setStyle("-fx-background-color: transparent; -fx-border-color: transparent;");
                    });



                    // Combine the Label and Button in an HBox
                    HBox cellBox = new HBox(10, nameLabel, addButton);
                    cellBox.setAlignment(Pos.CENTER);
                    cellBox.setSpacing(5);
                    setGraphic(cellBox);
                }
            }
        });

        friendsTableColumn.setCellFactory(cell -> new TableCell<FriendshipsDTO, Void>() {
            private final HBox container = new HBox();
            private final Label nameText = new Label();
            private final Label dateText = new Label();
            private final Button deleteButton = new Button();
            {
                container.setSpacing(10);
                container.setAlignment(Pos.CENTER);

                Image trashIcon = new Image(getClass().getResourceAsStream("/org/example/lab_sase/Trash.png")); // Ensure the path is correct
                ImageView trashImageView = new ImageView(trashIcon);
                trashImageView.setFitWidth(15);
                trashImageView.setFitHeight(15);

                deleteButton.setGraphic(trashImageView);
                deleteButton.setStyle("-fx-background-color: transparent;");

                deleteButton.setOnAction(event -> {
                    FriendshipsDTO friendshipDTO = getTableView().getItems().get(getIndex());
                    getTableView().getItems().remove(friendshipDTO);

                    try {
                        delete_friendship(repositoryFriendships.findOne(friendshipDTO.getId_friendship()).get());
                    } catch (SQLException e) {
                        throw new RuntimeException(e);
                    }
                    notifyObservers();
                    //loadData();

                    handleClickOutside();
                });
                deleteButton.setOnMouseEntered(event -> {
                    deleteButton.setStyle("-fx-background-color: rgba(169, 169, 169, 0.3); -fx-border-color: transparent;");
                });
                deleteButton.setOnMouseExited(event -> {
                    deleteButton.setStyle("-fx-background-color: transparent; -fx-border-color: transparent;");
                });

                container.getChildren().addAll(nameText, dateText, deleteButton);
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);
                if (empty) {
                    setGraphic(null);
                } else {
                    FriendshipsDTO friendship = getTableView().getItems().get(getIndex());
                    String fullName = repo_users.findOne(friendship.getId_friend()).get().getFirstName() + " " + repo_users.findOne(friendship.getId_friend()).get().getLastName();
                    nameText.setText(fullName);
                    dateText.setText(friendship.getCreated_at().toString());
                    setGraphic(container);
                }
            }
        });
        requestTableColumn.setCellFactory(cell->new TableCell<RequestDTO, Void>(){
            private final HBox container = new HBox();
            private final Label nameText = new Label();
            private final Button acceptButton = new Button();
            private final Button rejectButton = new Button();
            {
                container.setSpacing(10);
                container.setAlignment(Pos.CENTER);

                Image acceptIcon = new Image(getClass().getResourceAsStream("/org/example/lab_sase/Accepted.png")); // Ensure the path is correct
                ImageView acceptImageView = new ImageView(acceptIcon);
                acceptImageView.setFitWidth(15);
                acceptImageView.setFitHeight(15);

                Image rejectIcon = new Image(getClass().getResourceAsStream("/org/example/lab_sase/Rejected.png")); // Ensure the path is correct
                ImageView rejectImageView = new ImageView(rejectIcon);
                rejectImageView.setFitWidth(15);
                rejectImageView.setFitHeight(15);

                acceptButton.setGraphic(acceptImageView);
                acceptButton.setStyle("-fx-background-color: transparent;");
                rejectButton.setGraphic(rejectImageView);
                rejectButton.setStyle("-fx-background-color: transparent;");

                acceptButton.setOnAction(event -> {
                    RequestDTO requestDTO = getTableView().getItems().get(getIndex());
                    getTableView().getItems().remove(requestDTO);
                    repo_friendships.setStatus(requestDTO.getId_status(), "accepted");
                    //loadData();
                    notifyObservers();
                    handleClickOutside();
                });
                rejectButton.setOnAction(event -> {
                    RequestDTO requestDTO = getTableView().getItems().get(getIndex());
                    getTableView().getItems().remove(requestDTO);
                    repo_friendships.deleteFriendship(requestDTO.getId_status());
                    //loadData();
                    notifyObservers();
                    handleClickOutside();
                });

                acceptButton.setOnMouseEntered(event -> {
                    acceptButton.setStyle("-fx-background-color: rgba(169, 169, 169, 0.3); -fx-border-color: transparent;");
                });
                acceptButton.setOnMouseExited(event -> {
                    acceptButton.setStyle("-fx-background-color: transparent; -fx-border-color: transparent;");
                });

                rejectButton.setOnMouseEntered(event -> {
                    rejectButton.setStyle("-fx-background-color: rgba(169, 169, 169, 0.3); -fx-border-color: transparent;");
                });
                rejectButton.setOnMouseExited(event -> {
                    rejectButton.setStyle("-fx-background-color: transparent; -fx-border-color: transparent;");
                });

                container.getChildren().addAll(nameText, acceptButton, rejectButton);
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);
                if (empty) {
                    setGraphic(null); // No content in the cell if empty
                } else {
                    RequestDTO requestDTO = getTableView().getItems().get(getIndex());
                    String fullName = repo_users.findOne(requestDTO.getId_user()).get().getFirstName() + " " + repo_users.findOne(requestDTO.getId_user()).get().getLastName();
                    nameText.setText(fullName);
                    setGraphic(container); // Set the HBox as the cell content
                }
            }
        });


        loadData();
    }

    void loadData(){

        List<Friendship> list = new ArrayList<>();

        friendsList.clear();
        requestsList.clear();
        names.clear();

        names = FXCollections.observableArrayList(repo_users.findAlLNames(id_user));

        for (Friendship friendship : repo_friendships.findAllById1(id_user))
            list.add(friendship);
        for (Friendship friendship : repo_friendships.findAllById2(id_user))
            list.add(friendship);


        for (Friendship friendship:list) {
            if (Objects.equals(repo_friendships.getStatus(friendship.getId_staus()), "accepted")) {
                if (Objects.equals(friendship.getUser_id1(), id_user) && !Objects.equals(friendship.getUser_id2(), id_user)) {
                    FriendshipsDTO friendshipDTO = new FriendshipsDTO(friendship.getId(),id_user, friendship.getUser_id2(), friendship.getFriendsFrom());
                    friendsList.add(friendshipDTO);
                }
                else {
                    if (!Objects.equals(friendship.getUser_id1(), id_user) && Objects.equals(friendship.getUser_id2(), id_user)) {
                        FriendshipsDTO friendshipDTO = new FriendshipsDTO(friendship.getId(), id_user, friendship.getUser_id1(), friendship.getFriendsFrom());
                        friendsList.add(friendshipDTO);
                    }
                }
            }
            else
            {
                if (Objects.equals(repo_friendships.getStatus(friendship.getId_staus()), "pending")) {
                    if (!Objects.equals(friendship.getUser_id1(), id_user) && Objects.equals(friendship.getUser_id2(), id_user)) {
                        RequestDTO requestDTO = new RequestDTO(friendship.getUser_id1(),friendship.getId_staus(), repo_users.findOne(friendship.getUser_id1()).get().getFirstName() + " " + repo_users.findOne(friendship.getUser_id1()).get().getFirstName());
                        requestsList.add(requestDTO);
                    }
                }
            }
        }

        tableViewFriendships.setItems(friendsList);
        tableViewRequests.setItems(requestsList);
    }

    public void setStage(Stage stage) {
        this.stage = stage;
        Label_name.setText("Welcome " + repo_users.findOne(id_user).get().getFirstName() + " " + repo_users.findOne(id_user).get().getLastName() + " ");
    }

    public void setId_user(Integer id_user) {
        this.id_user = id_user;
    }

    public void btn_click(ActionEvent actionEvent) {
        double screenX = btn_options.localToScreen(btn_options.getBoundsInLocal()).getMinX();
        double screenY = btn_options.localToScreen(btn_options.getBoundsInLocal()).getMaxY();

        // Show the context menu below the button
        contextMenu.show(btn_options, screenX, screenY);
    }

    public void open_modify_account(ActionEvent actionEvent) throws Exception {
        showPopup();
        notifyObservers();
    }

    private void showPopup() throws Exception {
        // Load the FXML file
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/lab_sase/Modify_account.fxml"));
        Parent root = loader.load();

        // Create a new stage for the popup
        Stage popupStage = new Stage();
        popupStage.initModality(Modality.APPLICATION_MODAL); // Make it modal
        popupStage.setTitle("Popup Window");

        Scene popupScene = new Scene(root);
        popupStage.setScene(popupScene);
        popupStage.setResizable(false);
        popupScene.getRoot().requestFocus();

        Controller_modifiy controller = loader.getController();
        controller.setRepo_friendships(repo_friendships);
        controller.setRepo_users(repo_users);
        controller.setId_user(id_user);
        controller.setStage(popupStage);
        controller.set_text_fields();
        popupStage.showAndWait(); // Block interaction with the main window
        Label_name.setText("Welcome " + repo_users.findOne(id_user).get().getFirstName() + " " + repo_users.findOne(id_user).get().getLastName()+ " ");
    }

    public void handle_logout(ActionEvent actionEvent) throws IOException {
        stage.close();
//        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/lab_sase/welcome.fxml"));
//        Parent root = loader.load();
//        Scene loginScene = new Scene(root);
//        stage.setScene(loginScene);
//
//        Controller_welcome controller = loader.getController();
//        controller.setRepo_friendships(repo_friendships);
//        controller.setRepo_users(repo_users);
//
//        controller.setStage(stage);
//
//        stage.setWidth(loginScene.getWidth());
//        stage.setHeight(loginScene.getHeight());
//        stage.show();
//        root.requestFocus();
    }

    public void action_delete(ActionEvent actionEvent) throws SQLException, IOException {
        delete_user(repo_users.findOne(id_user).get());
        stage.close();
        notifyObservers();
    }

    public void  handleClickOutside(){
        search_textField.getParent().requestFocus();
    }

    public void clicked_textField(MouseEvent mouseEvent) {
        listViewSearch.setVisible(false);
        // Calculate the screen position of the button
        double screenX = search_textField.localToScreen(search_textField.getBoundsInLocal()).getMinX();
        double screenY = search_textField.localToScreen(search_textField.getBoundsInLocal()).getMaxY();

        // Show the context menu below the button
        contextMenuSearch.show(search_textField, screenX, screenY);
    }

    @Override
    public void update() {
        loadData();
    }
}