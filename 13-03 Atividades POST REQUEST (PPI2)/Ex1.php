<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ex1</title>
</head>
<body>
<form action="./Ex1.php" method="post">
<!-- Efetue um algorítmo PHP que receba um valor digitado pelo usuário e imprima o texto
"o valor é maior que 10" caso isso seja verdade, senão imprima "o valor é menor que 10". -->
        <label for="valor">Digite um valor:</label>
        <input type="number" id="valor" name="valor">
        <input type="submit" value="Verificar">
    </form>
<?php
        $valor = 0;
    if ($_SERVER["REQUEST_METHOD"] == "POST") { // Puxando o método de requisição post no servidor
        $valor = $_POST["valor"];
        if ($valor > 10) {
            echo "<p>O valor é maior que 10.</p>";
        }else {
            echo "<p>O valor é menor que 10.</p>";
        }
    }
?>
</body>
</html>