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
    addProduct("name:3", "desc:3", 5.00, 5); // This adds a product to the table (only adds one bc name has to be unique)

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
    </head>
    <body>
        <header>
            <div id="logo"><a href="index.php">Store</a></div>
            <?php if ($logged) {echo "<h2> Welcome," . htmlspecialchars($user->username) . '! </h2>';} ?> 
            <div id="nav">
                <?php 
                    if (!$logged) {
                        echo '<a href="login.php">Login</a>';
                        echo '<a href="register.php">Sign Up</a>';
                    } else {
                        echo '<a href="viewCart.php">Cart</a>';
                    }
                ?>
            </div>
        </header>
        <!-- PUT ALL OF THE PRODUCTS HERE, WITH "ADD TO CART BUTTONS" -->
        <div class="product">This is the first product</div>
        <?php displayProducts(); ?>
    </body>
</html>
