<?php
session_start();
require_once 'User.php';
require_once 'UserManagement.php';

$manager = new UserManagement();
$message = "";

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (
        preg_match("/^[A-Za-z0-9_-]{3,15}$/", $_POST['username']) &&
        preg_match("/((?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[!*@#$%]).{6,20})/", $_POST['password'])
    ) {
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
}
?>
<!DOCTYPE html>
<html>
    <head>
        <link href="styles.css" rel="stylesheet">
        <title>Login</title>
    </head>
    <body>
        <!-- Top bar header -->
        <header>
            <div id="logo"><a href="index.php">Store</a></div>
            <div id="nav">
                <?php 
                    echo '<a href="login.php">Login</a>';
                    echo '<a href="register.php">Sign Up</a>';
                ?>
            </div>
        </header>
        <h2>Login</h2>
        <form id="userInput" method="POST">
            Username: <input name="username"><br>
            Password: <input name="password"><br>
            <button id="submitBtn" type="submit">Login</button>
        </form>
        <p style="color:red;"><?php echo $message; ?></p>
        <p><a href="register.php">Create New User</a></p>
    </body>
</html>
