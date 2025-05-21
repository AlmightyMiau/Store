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
        <form method="POST">
            Username: <input name="username"><br>
            Password: <input name="password" type="password"><br>
            <button type="submit">Login</button>
        </form>
        <p style="color:red;"><?php echo $message; ?></p>
        <p><a href="register.php">Create New User</a></p>
        <p><a href="blackjack.html">Play Blackjack</a></p>
    </body>
</html>
