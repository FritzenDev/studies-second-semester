<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ex5</title>
</head>
<body>
<!-- Efetue um algoritmo PHP que receba quatro notas de um aluno, calcule e imprima a média
aritmética das notas e a mensagem de aprovado para média superior ou igual OU superior
a 7.0. -->
<form action="./Ex6.php" method="POST">
    <label for="valor">Digite 4 valores: </label><br>
    <input type="number" name="A" id="A">
    <br></br>
    <input type="number" name="B" id="B">
    <br></br>
    <input type="number" name="C" id="C">
    <br></br>
    <input type="number" name="D" id="D">
    <br></br>
    <button type="submit">Enviar</button>
</form>
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $A = $_POST['A'];
        $B = $_POST['B'];
        $C = $_POST['C'];
        $D = $_POST['D'];
        
        $med = ($A + $B + $C + $D) / 4;

        if ($med >= 7) {
            echo "</br>";
            echo "Aprovado";
        } else {
            echo "</br>";
            echo "Reprovado";
        }
    }
?>
</body>
</html>