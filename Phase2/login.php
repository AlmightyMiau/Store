<?php
session_start();
require_once 'User.php';
require_once 'UserManagement.php';

$manager = new UserManagement();
$message = "";

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username'] ?? '');
    $password = trim($_POST['password'] ?? '');

    $user = $manager->loadUser($username);
    if ($user && $user->password === $password) {
        $_SESSION['user'] = $user->toArray();
        header("Location: index.php");
        exit;
    } else {
        $message = "Invalid username or password.";
    }
}
?>
<!DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Login</title>
    </head>
    <body>
        <h2>Login</h2>
        <form id="userInput" method="POST">
            Username: <input name="username"><br>
            Password: <input name="password"><br>
            <button id="submitBtn" type="submit">Login</button>
        </form>
        <p style="color:red;"><?php echo $message; ?></p>
        <p><a href="register.php">Create New User</a></p>
        <p><a href="blackjack.html">Play Blackjack</a></p>
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
