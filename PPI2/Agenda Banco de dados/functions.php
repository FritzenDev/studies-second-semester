<?php
// Configurações do banco de dados
$host = 'localhost'; // Endereço do servidor MySQL
$dbname = 'tb_agenda_usuarios'; // Nome do banco de dados
$user = 'root'; // Usuário do banco de dados
$pass = ''; // Senha do banco de dados

// Conexão com o banco de dados
function get_db_connection() {
    global $host, $dbname, $user, $pass;
    try {
        $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $pass);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        return $pdo;
    } catch (PDOException $e) {
        die("Erro ao conectar com o banco de dados: " . $e->getMessage());
    }
}

// Função auxiliar para hash de senha
function hash_password($password) {
    return password_hash($password, PASSWORD_DEFAULT);
}

// Função auxiliar para verificar senha
function verify_password($password, $hash) {
    return password_verify($password, $hash);
}

// Verificar se o usuário existe e retorna o ID
function get_user_by_email($email) {
    $pdo = get_db_connection();
    $stmt = $pdo->prepare("SELECT id, password FROM users WHERE email = :email");
    $stmt->execute(['email' => $email]);
    return $stmt->fetch(PDO::FETCH_ASSOC);
}

// Cadastrar novo usuário
function register_user($name, $email, $password) {
    $pdo = get_db_connection();
    $stmt = $pdo->prepare("INSERT INTO users (name, email, password) VALUES (:name, :email, :password)");
    $stmt->execute([
        'name' => $name,
        'email' => $email,
        'password' => hash_password($password)
    ]);
}

// Adicionar compromisso
function add_appointment($user_id, $appointment, $date, $time) {
    $pdo = get_db_connection();
    $stmt = $pdo->prepare("INSERT INTO appointments (user_id, appointment, date, time) VALUES (:user_id, :appointment, :date, :time)");
    $stmt->execute([
        'user_id' => $user_id,
        'appointment' => $appointment,
        'date' => $date,
        'time' => $time
    ]);
}

// Obter compromissos do usuário
function get_appointments($user_id) {
    $pdo = get_db_connection();
    $stmt = $pdo->prepare("SELECT appointment, date, time FROM appointments WHERE user_id = :user_id");
    $stmt->execute(['user_id' => $user_id]);
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}
?>
