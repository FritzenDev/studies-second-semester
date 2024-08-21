<?php
// Inclui o config.php para garantir que a sessão está iniciada
require 'config.php';

// Processa o cadastro de novos usuários
if (isset($_POST['register'])) {
    $username = htmlspecialchars($_POST['username']);
    $email = htmlspecialchars($_POST['email']);
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);

    // Adiciona o novo usuário aos usuários fixos
    $fixed_users[$username] = [
        'email' => $email,
        'password' => $password
    ];
    $_SESSION['message'] = "Usuário cadastrado com sucesso!";
    header('Location: index.php'); // Redireciona para a página principal
    exit();
}
?>
