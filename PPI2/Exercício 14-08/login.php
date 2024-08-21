<?php
// Inclui o config.php para garantir que a sessão está iniciada
require 'config.php';

// Processa o login de usuários
if (isset($_POST['login'])) {
    $username = htmlspecialchars($_POST['username']);
    $password = htmlspecialchars($_POST['password']);

    // Verifica se o usuário está na lista de usuários fixos
    if (isset($fixed_users[$username]) && password_verify($password, $fixed_users[$username]['password'])) {
        $_SESSION['user_username'] = $username;
        $_SESSION['message'] = "Login realizado com sucesso!";
        header('Location: index.php'); // Redireciona para a página principal
        exit();
    } else {
        $_SESSION['message'] = "Usuário ou senha incorretos.";
        header('Location: index.php'); // Redireciona para a página principal
        exit();
    }
}
?>
