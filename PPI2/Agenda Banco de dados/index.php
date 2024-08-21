<?php
session_start();
require 'functions.php';

// Processar o cadastro de novos usuários
if (isset($_POST['register'])) {
    $name = htmlspecialchars($_POST['name']);
    $email = htmlspecialchars($_POST['email']);
    $password = $_POST['password'];

    register_user($name, $email, $password);
    $message = "Usuário cadastrado com sucesso!";
}

// Processar o login de usuários
if (isset($_POST['login'])) {
    $email = htmlspecialchars($_POST['email']);
    $password = htmlspecialchars($_POST['password']);

    $user = get_user_by_email($email);
    if ($user && verify_password($password, $user['password'])) {
        $_SESSION['user_email'] = $email;
        $_SESSION['user_id'] = $user['id'];
        header('Location: ' . $_SERVER['PHP_SELF']);
        exit();
    }
    $message = "Email ou senha incorretos.";
}

// Processar o logout
if (isset($_GET['logout'])) {
    session_unset();
    session_destroy();
    header('Location: ' . $_SERVER['PHP_SELF']);
    exit();
}

// Processar o cadastro de compromissos
if (isset($_POST['add_appointment'])) {
    if (isset($_SESSION['user_id'])) {
        $appointment = htmlspecialchars($_POST['appointment']);
        $date = htmlspecialchars($_POST['date']);
        $time = htmlspecialchars($_POST['time']);
        $user_id = $_SESSION['user_id'];

        add_appointment($user_id, $appointment, $date, $time);
        $message = "Compromisso adicionado com sucesso!";
    } else {
        $message = "Você precisa estar logado para adicionar compromissos.";
    }
}

// Exibir compromissos
$appointments = [];
if (isset($_SESSION['user_id'])) {
    $appointments = get_appointments($_SESSION['user_id']);
}
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Agenda de Compromissos</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <div class="message <?php echo isset($message) ? (strpos($message, 'sucesso') !== false ? 'success' : '') : ''; ?>">
            <?php if (isset($message)) echo $message; ?>
        </div>
        
        <?php if (!isset($_SESSION['user_email'])): ?>
            <!-- Formulário de Cadastro -->
            <h1>Cadastro de Novo Usuário</h1>
            <form method="POST">
                <label for="name">Nome:</label>
                <input type="text" id="name" name="name" required>
                <label for="email">Email:</label>
                <input type="email" id="email" name="email" required>
                <label for="password">Senha:</label>
                <input type="password" id="password" name="password" required>
                <button type="submit" name="register">Cadastrar</button>
            </form>

            <!-- Formulário de Login -->
            <h1>Login</h1>
            <form method="POST">
                <label for="login_email">Email:</label>
                <input type="email" id="login_email" name="email" required>
                <label for="login_password">Senha:</label>
                <input type="password" id="login_password" name="password" required>
                <button type="submit" name="login">Entrar</button>
            </form>
        <?php else: ?>
            <!-- Área da Agenda -->
            <h1>Minha Agenda</h1>
            <a href="?logout" class="logout-button">Sair</a>

            <!-- Formulário de Adicionar Compromisso -->
            <h2>Adicionar Compromisso</h2>
            <form method="POST">
                <label for="appointment">Compromisso:</label>
                <input type="text" id="appointment" name="appointment" required>
                <label for="date">Data:</label>
                <input type="date" id="date" name="date" required>
                <label for="time">Hora:</label>
                <input type="time" id="time" name="time" required>
                <button type="submit" name="add_appointment">Adicionar</button>
            </form>

            <!-- Lista de Compromissos -->
            <h2>Compromissos</h2>
            <?php if (!empty($appointments)): ?>
                <ul>
                    <?php foreach ($appointments as $appointment): ?>
                        <li><?php echo "Compromisso: {$appointment['appointment']}, Data: {$appointment['date']}, Hora: {$appointment['time']}"; ?></li>
                    <?php endforeach; ?>
                </ul>
            <?php else: ?>
                <p>Você não tem compromissos agendados.</p>
            <?php endif; ?>
        <?php endif; ?>
    </div>
</body>
</html>
