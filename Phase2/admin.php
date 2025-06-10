<?php
    session_start();
    require_once 'User.php';
    require_once 'products.php';
    require_once 'UserManagement.php';

    $logged = false;
    if (isset($_SESSION['user'])) {
        $logged = true;
        $user = User::fromArray($_SESSION['user']);
    }

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        if (isset($_POST['createProductName'])) { // Create product
            $name = trim($_POST['createProductName'] ?? '');
            $desc = trim($_POST['desc'] ?? '');
            $price = trim($_POST['price'] ?? '');
            $quantity = trim($_POST['quantity'] ?? '');

            addProduct($name, $desc, $price, $quantity);
        } else if (isset($_POST['DeleteItem'])) {
            deleteProduct($_POST['DeleteItem']);
        } else if (isset($_POST["createUsername"])) {
            $manager = new UserManagement();
            $username = trim($_POST['createUsername'] ?? '');
            $password = trim($_POST['createPassword'] ?? '');

            if ($username && $password) {
                $newUser = new User($username, $password);
                $manager->saveUser($newUser);
            } else {
                $message = "Please fill in all fields.";
            }
        } else if (isset($_POST['DeleteUser'])) {
            $manager = new UserManagement();
            $manager->deleteUser($_POST['DeleteUser']);
        }
    }
?>
<!DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Menu</title>
        <script src="admin.js"></script>
    </head>
    <body>
        <!-- Top bar header -->
        <header>
            <div id="logo"><a href="index.php">Store</a></div>
            <div id="nav">
                <?php 
                    if ($user->admin) {
                        echo '<a href="admin.php">Admin</a>';
                    }
                    echo '<a href="viewCart.php">Cart</a>';
                    if (!$logged) {
                        echo '<a href="login.php">Login</a>';
                        echo '<a href="register.php">Sign Up</a>';
                    } else {
                        echo '<a href="logout.php">Logout</a>';
                    }
                ?>
            </div>
            <?php if ($logged) {echo "<h3> Welcome, " . htmlspecialchars($user->username) . '! </h3>';} ?> 
        </header>
        <div class="adminMenu">
            <span id="Products">
                <button id="viewProducts" onclick="ViewProducts()">Products</button>
                <ul id="productOptions" style="display: none;">
                    <li id="createProduct"><button onclick="CreateProducts()">Create</button>
                        <form id="createProductForm" method="POST" style="padding: 5px; width: 30%; display: none;">
                            Name: <input name="createProductName"><br>
                            Description: <input name="desc"><br>
                            Price: <input name="price"><br>
                            Quantity: <input name="quantity"><br>
                            <button id="submitProductBtn" type="submit">Submit</button>
                        </form>
                    </li>
                    <!-- <li id="editProduct"><button onclick="EditProducts()">Edit</button></li> -->
                    <li id="deleteProduct"><button onclick="DeleteProducts()">Delete</button></li>
                    <div id="deleteProductHelper" style="display: none;"></div>
                </ul>
                <?php displayProductsFull() ?>
            </span>
            <span id="Users">
                <button id="viewUsers" onclick="ViewUsers()">Users</button>
                <ul id="userOptions" style="display: none;">
                    <li id="createUser">
                        <button onclick="CreateUser()">Create</button>
                        <form id="createUserForm" method="POST" style="display: none;">
                            Username: <input name="createUsername"><br>
                            Password: <input name="createPassword"><br>
                            <button id="submitUserBtn" type="submit">Register</button>
                        </form>
                    </li>
                    <!-- <li><button id="editUser" onclick="EditUser()">Edit</button></li> -->
                    <li id="deleteUser"><button onclick="DeleteUser()">Delete</button></li>
                    <div id="deleteUserHelper" style="display: none;"></div>
                </ul>
                <?php 
                    $manage = new UserManagement;
                    $manage->displayUsers();
                ?>
            </span>
        </div>
    </body>
</html>
