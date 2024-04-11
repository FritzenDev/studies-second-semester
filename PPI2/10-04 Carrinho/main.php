<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Carrinho de compras</title>
</head>
<body>
    <header>
        <div>
            <h1>Minha Loja Online</h1>
            <nav>
                <ul>
                    <li><a href="#">Home</a></li>
                    <li><a href="#">Produtos</a></li>
                    <li><a href="#">Sobre</a></li>
                    <li><a href="#">Contato</a></li>
                </ul>
            </nav>
        </div>
    </header>

    <section>
        <div>
            <h2>Bem-vindo à nossa loja online!</h2>
            <p>Carrinho</p>
        </div>
    </section>

    <section>
    <?php
    $car = array();


    if(isset($_POST["produto1"])) {
        array_push($car, $_POST["produto1"]);
    }

    if(isset($_POST["produto2"])) {
        array_push($car, $_POST["produto2"]);
    }
    $total = 0;
    for($i=0; $i<sizeof($car); $i++) {
        $total += $car[$i];
    }
    echo $total;
    ?>
    </section>

    <footer>
        <div class="container">
            <p>&copy; Minha Loja Online. Todos os direitos reservados.</p>
        </div>
    </footer>
</body>
</html>
