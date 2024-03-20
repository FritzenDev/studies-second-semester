<?php
/*Crie um algoritmo que exiba a tabuada de 0 a 10 de acordo com o valor de
uma variável */

$var = 3;

for ($i = 1; $i <= 10; $i++) {
    $calc = $var * $i; 
    echo "$i x 10 = $calc\n";
}
