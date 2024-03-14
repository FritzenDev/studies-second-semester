<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ex2</title>
</head>
<body>
<!-- Efetue um algorítmo PHP que receba um valor digitado pelo usuário e imprima o texto
"o valor é maior ou igual a 10" caso isso seja verdade, senão imprima "o valor não é maior
ou igual a 10" -->

<form action="./Ex2.php" method="POST">
    <label for="valor">Digite um valor: </label>
    <input type="text" id="value" name="value">
    <button type="submit">Enviar</button>
</form>

<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") { //Puxando o método de requisição post no servidor
        $valor = 0;
        $valor = $_POST['value'];
        if($valor != 0) {
            if ($valor >= 10) {
                echo "O valor é maior ou igual a 10";
            }else {
                echo "O valor não é maior ou igual a 10";
            }
        }
    } 
?>
    
</body>
</html>