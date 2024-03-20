<?php

// Crie um vetor com n posições e calcule o número de valores pares e ímpares

$n = 100; //Número de posições

$vetor = range(1, $n); // Cria um vetor com n posições

$pares = 0;
$impares = 0;

foreach ($vetor as $valor) {
    if ($valor % 2 == 0) {
        $pares++;
    } else {
        $impares++;
    }
}

echo "\nNúmero de valores pares: $pares\n";
echo "Número de valores ímpares: $impares\n";