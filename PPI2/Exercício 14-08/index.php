<?php
require 'config.php';
require 'login.php'; // Processamento do login
require 'register.php'; // Processamento do registro
require 'appointments.php'; // Processamento de compromissos

// Começa a sessão se não estiver ativa
if (session_status() === PHP_SESSION_NONE) {
    session_start();
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
        <div class="message <?php echo isset($_SESSION['message']) ? (strpos($_SESSION['message'], 'sucesso') !== false ? 'success' : '') : ''; ?>">
            <?php 
            if (isset($_SESSION['message'])) {
                echo $_SESSION['message'];
                unset($_SESSION['message']);
            }
            ?>
        </div>
        
        <?php if (!isset($_SESSION['user_username'])): ?>
            <!-- Formulário de Cadastro -->
            <h1>Cadastro de Novo Usuário</h1>
            <form method="POST" action="register.php">
                <label for="username">Nome de Usuário:</label>
                <input type="text" id="username" name="username" required>
                <label for="email">E-mail:</label>
                <input type="email" id="email" name="email" required>
                <label for="password">Senha:</label>
                <input type="password" id="password" name="password" required>
                <button type="submit" name="register">Cadastrar</button>
            </form>

            <!-- Formulário de Login -->
            <h1>Login</h1>
            <form method="POST" action="login.php">
                <label for="login_username">Nome de Usuário:</label>
                <input type="text" id="login_username" name="username" required>
                <label for="login_password">Senha:</label>
                <input type="password" id="login_password" name="password" required>
                <button type="submit" name="login">Entrar</button>
            </form>
        <?php else: ?>
            <!-- Área da Agenda -->
            <h1>Minha Agenda</h1>
            <a href="logout.php?logout" class="logout-button">Sair</a>

            <!-- Formulário de Adicionar Compromisso -->
            <h2>Adicionar Compromisso</h2>
            <form method="POST" action="appointments.php">
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
            <?php
            $hasAppointments = false;
            if (!empty($_SESSION['appointments'])): ?>
                <ul>
                    <?php foreach ($_SESSION['appointments'] as $appointment): ?>
                        <?php if ($appointment['user_username'] === $_SESSION['user_username']): ?>
                            <?php $hasAppointments = true; ?>
                            <li><?php echo "Compromisso: {$appointment['appointment']}, Data: {$appointment['date']}, Hora: {$appointment['time']}"; ?></li>
                        <?php endif; ?>
                    <?php endforeach; ?>
                </ul>
            <?php endif; ?>
            <?php if (!$hasAppointments): ?>
                <p>Você não tem compromissos agendados.</p>
            <?php endif; ?>
        <?php endif; ?>
    </div>
</body>
</html>
