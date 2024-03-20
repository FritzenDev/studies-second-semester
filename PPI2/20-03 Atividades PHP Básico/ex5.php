<?php

// Ler um número inteiro entre 1 e 12 e escrever o mês correspondente. Caso o
// número seja fora desse intervalo, informar que não existe mês com este
// número

$var = rand(1,12);

echo "\nNúmero gerado: $var\n\n";


$months = ["Inválido", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto",
"Setembro", "Outubro", "Novembro", "Dezembro"];

echo $months[$var];