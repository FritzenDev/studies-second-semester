<?php
// Inclui o config.php para garantir que a sessão está iniciada
require 'config.php';

// Processa o cadastro de compromissos
if (isset($_POST['add_appointment'])) {
    if (isset($_SESSION['user_username'])) {
        $appointment = htmlspecialchars($_POST['appointment']);
        $date = htmlspecialchars($_POST['date']);
        $time = htmlspecialchars($_POST['time']);
        $user_username = $_SESSION['user_username'];

        $_SESSION['appointments'][] = [
            'user_username' => $user_username,
            'appointment' => $appointment,
            'date' => $date,
            'time' => $time
        ];

        $_SESSION['message'] = "Compromisso adicionado com sucesso!";
    } else {
        $_SESSION['message'] = "Você precisa estar logado para adicionar compromissos.";
    }
    header('Location: index.php'); // Redireciona para a página principal
    exit();
}
?>
