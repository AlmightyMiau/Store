<?php
class User {
    public string $username;
    public string $password;
    public bool $admin;

    public function __construct($username, $password, $admin = false) {
        $this->username = $username;
        $this->password = $password;
        $this->admin = $admin;
    }

    public function toArray(): array {
        return get_object_vars($this);
    }

    public static function fromArray(array $data): User {
        return new User(
            $data['username'],
            $data['password'],
            $data['admin']
        );
    }
}
?>
