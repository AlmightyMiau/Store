<?php

function displayProducts () {
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