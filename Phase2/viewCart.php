<?php
    session_start();
    require_once 'User.php';
    require_once 'products.php';

    $logged = false;
    if (isset($_SESSION['user'])) {
        $logged = true;
        $user = User::fromArray($_SESSION['user']);
    } else {
        header("Location: index.php");
    }

    removeItemsToCart();

?>
<!DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Menu</title>
    </head>
    <body>
        <!-- Top bar header -->
        <header>
            <div id="logo"><a href="index.php">Store</a></div>
            <div id="nav">
                <?php 
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
        <!-- Show items in cart with amounts of items -->
        <?php displayItemsInCart(); ?>
    </body>
</html>
