<?php
// Find items in cart
// subtract cart items from inventory
// Send user to index.html (or a confirmation page)
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
?>

<DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Checkout</title>
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
        <p>
            <?php
                checkoutCart();
                displayItemsInCartShort();
            ?>
        </p>
        <p>
            <form id="cardInput" method="POST">
                Card number (put any 16 digit number): <input name="card"></input><br>
                Expiration date (mm/yy): <input name="expiration"></input><br>
                Funny 3 numbers on the back: <input name="security"></input><br>
                <button id="submitBtn" type="submit">Confirm checkout</button>
            </form>
        </p>
    </body>
    <script>
        const form = document.getElementById('cardInput');
        const regexCard = "^\\d{16}$";
        const regexExpiration = "^(0?[1-9]|1[012])/(\\d\\d)";
        const regexSecurity = "^(\\d{3})";
        
        const card = form.elements['card'];
        const expiration = form.elements['expiration'];
        const security = form.elements['security'];

        function getRegExp(i){
            return new RegExp(i);
        }
        
        form.addEventListener("submit", function(e) {
            if ( getRegExp(regexCard).test(card.value)
              && getRegExp(regexExpiration).test(expiration.value)
              && getRegExp(regexSecurity).test(security.value)
            ) {
                // Passes regEx tests, submit to server
                return true; 
            } else {
                // Fails regEx tests, alert user and don't submit to server
                if (e.preventDefault) e.preventDefault(); // Stop the submit maybe
                form.append("Failed input validation");
                return false; 
            }
        });
    </script>
</html>