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

    $sql = "SELECT id, name, description, price, quantity FROM Store.products";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        // output data of each row
        echo '<div id="product-window">';
        while($row = $result->fetch_assoc()) {
            echo '<div class="product">
                    <p> Name: ' . $row["name"] . '</p>
                    <p> Description: ' . $row["description"] . '</p>
                    <p> Price: $' . $row["price"] . '</p>
                    <p> Quantity: ' . $row["quantity"] . '</p>
                    <form method="post"> <input type="submit" name="' . $row["id"] . '" value="Add to Cart"></input> </form>
                </div>';
        }
        echo '</div>';
      
    } else {
      echo "0 products in inventory :(";
    }
}

// Add any new items to cart (reset POST values)
function addItemsToCart() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    $sql = "SELECT id, name FROM Store.products";
    $result = $conn->query($sql);

    // check if any items are in post (look through post for all products)
    if ($result->num_rows > 0) {
        // Parse each row
        while($row = $result->fetch_assoc()) {
            if (isset($_POST[$row["id"]])) {
                if (isset($_SESSION["cart"][$row["name"]])) {
                    $_SESSION["cart"][$row["name"]]++;
                } else {
                    $_SESSION["cart"][$row["name"]] = 1;
                }
            }
        }
    }
    // for any in post, add them to session['cart'] and remove them from post
}

function displayItemsInCart() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    $sql = "SELECT id, name, description, price, quantity FROM Store.products";
    $result = $conn->query($sql);

    // check all products to see if any are in cart
    // for any that are, display them
    if ($result->num_rows > 0) {
        // Parse each row
        $total = 0;
        echo '<div id="product-window">';
        while($row = $result->fetch_assoc()) {
            if (isset($_SESSION["cart"][$row["name"]])) {
                $total += $_SESSION["cart"][$row["name"]] * $row["price"];
                echo '<div class="product">
                    <p> Name: ' . $row["name"] . '</p>
                    <p> Description: ' . $row["description"] . '</p>
                    <p> Price: $' . $row["price"] . '</p>
                    <p> Amount in Cart: ' . $_SESSION["cart"][$row["name"]] . '</p>
                    <p> Total: $' . $_SESSION["cart"][$row["name"]] * $row["price"] . '</p>
                    <form method="post"> <input type="submit" name="' . $row["id"] . '" value="Remove item (-1)"></input> </form>
                </div>';
            }
        }
        echo '<p> Total: $' . $total . '</p>
          </div>
          <a href="checkout.php"> Checkout </a>
          ';
    }
}

// Add any new items to cart (reset POST values)
function removeItemsToCart() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    $sql = "SELECT id, name FROM Store.products";
    $result = $conn->query($sql);

    // check if any items are in post (look through post for all products)
    if ($result->num_rows > 0) {
        // Parse each row
        while($row = $result->fetch_assoc()) {
            if (isset($_POST[$row["id"]])) {
                if ($_SESSION["cart"][$row["name"]] == 1) {
                    unset($_SESSION["cart"][$row["name"]]);
                } else {
                    $_SESSION["cart"][$row["name"]]--;
                }
            }
        }
    }
}
?>