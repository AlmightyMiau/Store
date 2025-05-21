<?php
class User {
    public string $username;
    public string $password;
    public int $win;
    public int $loss;
    public bool $admin;

    public function __construct($username, $password, $win = 0, $loss = 0, $admin = false) {
        $this->username = $username;
        $this->password = $password;
        $this->win = $win;
        $this->loss = $loss;
        $this->admin = $admin;
    }

    public function toArray(): array {
        return get_object_vars($this);
    }

    public static function fromArray(array $data): User {
        return new User(
            $data['username'],
            $data['password'],
            $data['win'],
            $data['loss'],
            $data['admin']
        );
    }
}
?>
