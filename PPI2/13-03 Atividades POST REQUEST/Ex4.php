<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ex4</title>
</head>
<body>
<!-- Efetue um algoritmo PHP que receba os valores A, B, C e D. Efetue a soma entre A e C,
a multiplicação entre B e D e verifique se o resultado da soma é maior, menor ou igual
ao da multiplicação. Imprima: "A+C é maior que B+D", "A+C é menor que B+D", "A+C
é igual a B+D". -->
<form action="./Ex4.php" method="POST">
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
        $somaA_C = $A + $C;
        $prodB_D = $B * $D;
        if ($somaA_C > $prodB_D) {
            echo "A + C é maior que B * D";
        } else if ($somaA_C < $prodB_D) {
            echo "A + C é menor que B * D";
        } else {
            echo "A + C é igual a B * D";
        }
    }
?>
</body>
</html>