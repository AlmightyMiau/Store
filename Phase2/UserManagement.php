<?php
require_once 'User.php';

class UserManagement {
    private string $folder = "users";

    public function __construct() {
        if (!is_dir($this->folder)) {
            mkdir($this->folder);
        }

        $adminPath = $this->folder . "/admin.json";
        if (!file_exists($adminPath)) {
            $admin = new User("admin", "Admin!1", true);
            $this->saveUser($admin);
        }
    }

    public function saveUser(User $user): void {
        $path = $this->folder . "/" . $user->username . ".json";
        file_put_contents($path, json_encode($user->toArray(), JSON_PRETTY_PRINT));
    }

    public function loadUser(string $username): ?User {
        $path = $this->folder . "/" . $username . ".json";
        if (!file_exists($path)) return null;

        $data = json_decode(file_get_contents($path), true);
        return User::fromArray($data);
    }

    public function displayUsers() {
        $users = scandir("users");
        if (!$users) {
            echo "No users found";
            return 0;
        }
        echo '<div id="user-window" style="display: none;">';
        foreach ($users as $i => $file) {
            if (!($file == '.' || $file == '..')) {
                $path = $this->folder . "/" . $file;

                $data = json_decode(file_get_contents($path), true);
                $user = User::fromArray($data);

                echo '<div class="user">
                    <p> Username: ' . $user->username . '</p>
                    <p> Password: ' . $user->password . '</p>
                    <p> Admin: ' . ($user->admin == true ? 'true' : 'false') . '</p>
                </div>';
            }
        }
        echo '</div>';
    }
}
?>
