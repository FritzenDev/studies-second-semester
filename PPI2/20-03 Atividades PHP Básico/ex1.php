<?php
//Crie um algoritmo que verifica se o valor de uma variável é positivo, negativo
//ou igual a zero. A saída deve ser: "Valor Positivo", "Valor Negativo" ou "Igual a
//Zero"

$var = rand(-10,10);
echo "\nNúmero gerado: $var\n\n";

if ($var > 0) {
    echo "Valor Positivo";
} else if ($var == 0) {
    echo "Igual a Zero";
} else {
    echo "Valor Negativo";
}
