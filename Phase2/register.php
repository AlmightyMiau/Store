<?php
require_once 'User.php';
require_once 'UserManagement.php';

$manager = new UserManagement();
$message = "";

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username'] ?? '');
    $password = trim($_POST['password'] ?? '');

    if ($username && $password) {
        $user = new User($username, $password);
        $manager->saveUser($user);
        header("Location: index.php");
        exit;
    } else {
        $message = "Please fill in all fields.";
    }
}
?>
<!DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Register</title>
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
        <h2>Create New User</h2>
        <form id="userInput" method="POST">
            Username: <input name="username"><br>
            Password: <input name="password"><br>
            <button id="submitBtn" type="submit">Register</button>
        </form>
        <p style="color:red;"><?php echo $message; ?></p>
        <p><a href="login.php">Back to Login</a></p>
    </body>
    <script>
        const form = document.getElementById('userInput');
        const regexUsername = "^[A-Za-z0-9_-]{3,15}$";
        const regexPassword = "((?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[!*@#$%]).{6,20})";
        
        const username = form.elements['username'];
        const password = form.elements['password'];

        function getRegExp(i){
            return new RegExp(i);
        }
        
        form.addEventListener("submit", function(e) {
            if ( getRegExp(regexUsername).test(username.value)
              && getRegExp(regexPassword).test(password.value)
            ) {
                return true; // Passes regEx tests, submit to server
            } else {
                // Fails regEx tests, alert user and don't submit to server
                if (e.preventDefault) e.preventDefault(); // Stop the submit maybe
                form.append("Failed input validation");
                return false; 
            }
        });
    </script>
</html>
