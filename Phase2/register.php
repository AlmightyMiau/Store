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
        <h2>Create New User</h2>
        <form method="POST">
            Username: <input name="username"><br>
            Password: <input name="password" type="password"><br>
            <button type="submit">Register</button>
        </form>
        <p style="color:red;"><?php echo $message; ?></p>
        <p><a href="login.php">Back to Login</a></p>
    </body>
</html>
