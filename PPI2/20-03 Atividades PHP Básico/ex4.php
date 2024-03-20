<?php
// Crie um algoritmo para calcular a média final de um aluno, para isso, insira os
// valores de três notas em um array, por fim, calcule a média geral. Caso a
// média seja maior ou igual a seis, exiba aprovado, caso contrário, exiba
// reprovado. Exiba também a média final calculada

$var = [8, 7, 9];

$media = ($var[0] + $var[1] + $var[2]) / 3;

if ($media >= 6) {
    echo "Aprovado";
} else {
    echo "Reprovado";
}