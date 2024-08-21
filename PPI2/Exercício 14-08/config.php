<?php
// Começa a sessão se não estiver ativa
if (session_status() === PHP_SESSION_NONE) {
    session_start();
}

// Inicializa os usuários fixos
$fixed_users = [
    'teste' => [
        'email' => 'teste@example.com',
        'password' => password_hash('123', PASSWORD_DEFAULT)
    ]
];

// Inicializa compromissos na sessão
if (!isset($_SESSION['appointments'])) {
    $_SESSION['appointments'] = [];
}
