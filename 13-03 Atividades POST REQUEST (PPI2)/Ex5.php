<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ex5</title>
</head>
<body>
<!-- Efetue um algoritmo PHP que receba os valores A, B e imprima-os em ordem crescente
em relação aos seus valores. Exemplo, para A=5, B=4. Você deve imprimir na tela: "4
5". -->
<form action="./Ex5.php" method="POST">
    <label for="valor">Digite 2 valores: </label><br>
    <input type="number" name="A" id="A">
    <br></br>
    <input type="number" name="B" id="B">
    <br></br>
    <button type="submit">Enviar</button>
</form>
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $A = $_POST['A'];
        $B = $_POST['B'];
        if ($A > $B) {
            echo "<br/>";
            echo "$B";
            echo "<br/>";
            echo "$A";
        } else if ($B > $A) {
            echo "<br/>";
            echo "$A";
            echo "<br/>";
            echo "$B";
        }
    }
?>
</body>
</html>