<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Tabela</title>
</head>
<body>
	<table border="1">
		<tr>
		<th colspan="2">Lista de nomes</th>
		</tr>
		<tr>
			<th>Nomes</th>
			<th>E-mail</th>
		</tr>
		<?php
		$nomes = ["Bruno Scarpari", "Kauã Fritzen", "Alyson Marques", "Lucas Franke", "Matheus Toreto"];
		$emails = ["bscarpari@gmail.com", "kfritzen@gmail.com", "amarques@gmail.com", "lfranke@gmail.com", "mtoreto@gmail.com"];
		for ($i = 0; $i < 5; $i++) {
			printf("
			<tr>
				<td>%s</td>
				<td>%s</td:
			</tr>\n", $nomes[$i], $emails[$i]
			);
		}
		?>
	</table>
</body>
</html>