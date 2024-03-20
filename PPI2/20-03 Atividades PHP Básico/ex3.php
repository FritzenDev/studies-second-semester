<?php

/*Crie um algoritmo que faça o cálculo fatorial do valor de uma variável, exiba o
resultado na tela
*/

$var = rand(1,10);
$calc = 1;

for ($i = 1; $i <= $var; $i++) {
    $calc = $i * $calc;
}

echo "\nNúmero gerado: $var\n";
echo "\n$var! = $calc";