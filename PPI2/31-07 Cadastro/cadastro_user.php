<?php
    if(isset($_POST["envia"])) {
        $nome=$_POST["nome"];
        $email=$_POST["email"];
        if (confirmaSenha($_POST["senha"],$_POST["rsenha"])) {
            if (validaSenha($_POST["senha"])) {
                global $senha; 
                $senha = $_POST["senha"];
            }
        }
    }

    function confirmaSenha($senha, $confSenha) {
        if($senha == $confSenha) {
            echo "<script>alert('Senhas iguais');</script>";
            return true;
        } else {
            header("location:cadastro.html");
        }
    }
    
    function validaSenha($senha) {
        $tamanho = strlen($senha);
        if (is_numeric($senha)) {
            if ($tamanho >= 6 && $tamanho <= 8) {
                echo "<script>alert('Senha válida');</script>";
                return true;
            } else {
                header("location:cadastro.html");
            }
        } else {
            header("location:cadastro.html");
        }
    }
?>