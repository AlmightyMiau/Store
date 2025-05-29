<!-- 
  pages needed are:
    -> menu, showing all products, make the products look good
    cart, showing items in cart with options including checkout, remove an item
    login, with fields for username/password
    signup, with fields for username/password
    checkout, with confirmation of cart total and whatnot
  
  Completed: 
    First page builds the database and table
      menu, showing all products
-->
<?php
    session_start();
    require_once 'User.php';
    require_once 'products.php';
    initProducts(); // Make sure the database and table is set up
    addProduct("name :3", "desc :3", 42.06, 2); // This adds a product to the table (only adds one bc name has to be unique)

    $logged = false;
    if (isset($_SESSION['user'])) {
        $logged = true;
        $user = User::fromArray($_SESSION['user']);
    }

?>
<!DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Menu</title>
        <script src="cart.js"></script>
    </head>
    <body>
        <!-- Top bar header -->
        <header>
            <div id="logo"><a href="index.php">Store</a></div>
            <div id="nav">
                <?php 
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
        <!-- PUT ALL OF THE PRODUCTS HERE, WITH "ADD TO CART BUTTONS" -->
        <?php displayProducts(); ?>
    </body>
</html>
