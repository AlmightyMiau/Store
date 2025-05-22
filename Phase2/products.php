<?php
// Create the database
function initProducts() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    // Database
    $conn->query('CREATE DATABASE IF NOT EXISTS `store`');
    
    // Table
    $conn->query(
        'CREATE TABLE IF NOT EXISTS `store`.`products` (
            `ID` INT UNSIGNED NOT NULL AUTO_INCREMENT , 
            `Name` TEXT NOT NULL , 
            `Description` TEXT NOT NULL , 
            `Price` DECIMAL(5,2) NOT NULL DEFAULT "0.00" , 
            `Quantity` INT NOT NULL DEFAULT "0" ,
            PRIMARY KEY (`ID`) ,
            UNIQUE (Name)
        )'
    );

}

// Create a product
function addProduct($name, $desc, $price, $quantity) {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    // Add a product into the table
    $statement = $conn->prepare('INSERT INTO store.products (Name, Description, Price, Quantity) VALUES (?, ?, ?, ?)'); // prepare statement
    $statement->bind_param("ssdi", $name, $desc, $price, $quantity); // bind parameters to values
    $statement->execute(); // Execute statement
}

// Display all of the records in the products database
function displayProducts() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT id, name, description, price, quantity FROM Store.products";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
      // output data of each row
      while($row = $result->fetch_assoc()) {
        echo '<div class="product">
                <p> ID: ' . $row["id"] . '</p>
                <p> Name: ' . $row["name"] . '</p>
                <p> Description: ' . $row["description"] . '</p>
                <p> Price: ' . $row["price"] . '</p>
                <p> Quantity: ' . $row["quantity"] . '</p>
              </div>';
      }
      
    } else {
      echo "0 products in inventory :(";
    }
}

?>