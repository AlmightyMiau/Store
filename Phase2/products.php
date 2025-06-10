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

// Delete a product
function deleteProduct($id) {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    // Add a product into the table
    $statement = $conn->prepare('DELETE FROM store.products WHERE ID=?'); // delete product
    $statement->bind_param("i", $id); // bind parameters to values
    $statement->execute(); // Execute statement
}

// change the quantity of the product with name $name to $quantity
function setQuantity($id, $quantity) {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    // Add a product into the table
    $statement = $conn->prepare('UPDATE store.products SET quantity = ? WHERE id = ?'); // prepare statement
    $statement->bind_param("ii", $quantity, $id); // bind parameters to values
    $statement->execute(); // Execute statement
}

function getProducts() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    $sql = "SELECT id, name, description, price, quantity FROM Store.products";
    return $conn->query($sql);
}

// Display records in the products database with quantity > 1
function displayProducts() {
    $result = getProducts();

    if ($result->num_rows > 0) {
        // output data of each row
        echo '<div id="product-window">';
        while($row = $result->fetch_assoc()) {
            if ($row["quantity"] != 0) {
                echo '<div class="product">
                        <p> Name: ' . $row["name"] . '</p>
                        <p> Description: ' . $row["description"] . '</p>
                        <p> Price: $' . $row["price"] . '</p>
                        <p> Quantity: ' . $row["quantity"] . '</p>
                        <button onclick="addItemToCart(`' . $row["name"] . '`)">Add To Cart</button>
                    </div>';
            }
        }
        echo '</div>';
      
    } else {
      echo "0 products in inventory :(";
    }
}

// Display all of the records in the products database, including id, with hidden delete button
function displayProductsFull() {
    $result = getProducts();

    if ($result->num_rows > 0) {
        // output data of each row
        echo '<div id="product-window" style="display: none;">';
        while($row = $result->fetch_assoc()) {
            echo '<div class="product">
                    <p> ID: ' . $row["id"] . '
                    <p> Name: ' . $row["name"] . '</p>
                    <p> Description: ' . $row["description"] . '</p>
                    <p> Price: $' . $row["price"] . '</p>
                    <p> Quantity: ' . $row["quantity"] . '</p>
                    <form method="POST"><button class="productDeleteBtn" name="DeleteItem" value="' . $row["id"] . '" type="submit" style="display: none;">Delete</button></form>
                </div>';
        }
        echo '</div>';
      
    } else {
      echo "0 products in inventory :(";
    }
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
            if (isset($_COOKIE[escape($row["name"])])) {
                $total += $_COOKIE[escape($row["name"])] * $row["price"];
                echo '<div class="product">
                    <p> Name: ' . $row["name"] . '</p>
                    <p> Description: ' . $row["description"] . '</p>
                    <p> Price: $' . $row["price"] . '</p>
                    <p> Amount in Cart: ' . $_COOKIE[escape($row["name"])] . '</p>
                    <p> Total: $' . $_COOKIE[escape($row["name"])] * $row["price"] . '</p>
                    <button onclick="addItemToCart(`' . $row["name"] . '`)">+1</button>
                    <button onclick="removeItemFromCart(`' . $row["name"] . '`)">-1</button>
                </div>';
            }
        }
        echo '<p> Total: $' . $total . '</p>
          </div>
          <a href="checkout.php"> Checkout </a>
          ';
    }
}

function displayItemsInCartShort() {
    $servername = "localhost";
    $username = "root";

    // Create connection
    $conn = new mysqli($servername, $username);

    $cart = getItemsInCart();
    if (!$cart) return false;
    $total = 0;
    foreach ($cart as $x => $y) {
        $sql = "SELECT name, price, quantity FROM Store.products WHERE id = $x";
        $result = $conn->query($sql); // Execute statement
        $row = $result->fetch_assoc();
        $total += $y * $row['price'];
        echo $row['name'] . " --> " . $y . " in cart totalling $" . $y * $row['price'] . "<br>";
    }
    echo "total: $" . $total . "<br>";
}

function getItemsInCart() {
    $result = getProducts();
    $valid = false;

    // check all products to see if any are in cart
    // for any that are, get the id's and quantities
    if ($result->num_rows > 0) {
        // Parse each row
        $cart; // product id, quantity
        while($row = $result->fetch_assoc()) {
            if (isset($_COOKIE[escape($row["name"])])) {
                // binds the id of a product to its quantity
                $cart[$row["id"]] = $_COOKIE[escape($row["name"])];
                $valid = true;
            }
        }
        if ($valid)
            return $cart;
    }
    return false;
}

function checkoutCart() {
    if (isset($_POST["card"])) {
        // find what items are in cart (cookie stuff) (getItemsInCart())
        $inventory = getProducts();
        $items = $inventory->fetch_all();
        $cart = getItemsInCart();
        // for each item in cart
        foreach ($cart as $x => $y) {
            // find corresponding item in inventory
            for ($j = 0; $j < sizeof($items); $j++) {
                if ($items[$j][0] == $x) { // $items[$j][0] is the id at this row
                    // calculate new amount of item in inventory
                    $newQuantity = $items[$j][4] - $y;

                    // set quantity of item using setQuantity($name, $quantity)
                    setQuantity($x, $newQuantity);

                    // delete cookies
                    setcookie(escape($items[$j][1]), 0, time() - 3600);
                }
            }
        }
    }
    // check if there are no items in cart
    if (!getItemsInCart()) {
        header("Location: index.php");
    }
}

function escape($string) {
    for ($i = 0; $i < strlen($string); $i++) {
        if ($string[$i] == ' ') {
            $string[$i] = '_';
        }
    }
    return '"' . $string . '"';
}
?>