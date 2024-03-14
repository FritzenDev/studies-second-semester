<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ex3</title>
</head>
<body>
<!-- Efetue um algoritmo PHP que receba um valor digitado pelo usuário e verifique se esse
valor é positivo, negativo ou igual a zero. Imprima na tela: "Valor Positivo", "Valor
negativo", "Igual a Zero" -->
<form action="./Ex3.php" method="POST">
    <label for="valor">Digite um valor: </label>
    <input type="text" id="value" name="value">
    <button type="submit">Enviar</button>
</form>

<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") { //Puxando o método de requisição post no servidor
        $valor = 0;
        $valor = $_POST['value'];
        if($valor != 0) {
            if ($valor > 0) {
                echo "O valor é positivo";
            }else if ($valor == 0) {
                echo "O valor é igual a 0";
            }else {
                echo "O valor é negativo";
            }
        }
    } 
?>
    
</body>
</html>