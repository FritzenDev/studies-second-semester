<?php
// Inclui o config.php para garantir que a sessão está iniciada
require 'config.php';

// Processa o logout
if (isset($_GET['logout'])) {
    // Remove todos os dados da sessão
    session_unset();
    session_destroy();

    // Redireciona para a página de login e cadastro
    header('Location: index.php');
    exit();
}
?>
