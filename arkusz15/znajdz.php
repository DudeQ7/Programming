<?php
$ip = "localhost";
$user ="root";
$passwd = " ";
$db_name = "db26";
$conn = mysqli_connect($ip,$user,$passwd,$db_name);
//Alter USER 'root'@'localhost'Identified by " " ; 

?>

<!DOCTYPE html 5>
<html lang="PL-pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kwiaty</title>
    <link rel="stylesheet" href="styl3.css">
</head>
<body>
    <section class="baner">
        <h1>Grupa Polskich Kwiaciarni</h1>
    </section>
    <section class="lewy">
        <h2>Menu</h2>
        <ol>
            <li><a href="index.html">Strona głowna</a></li>
            <li><a href="https://www.kwiaty.pl/" target="_blank"></a></li>
            <li> <a href="znajdz.php"></a>
                <ul>
                    <li>w Warszawie</li>
                    <li>w Malborku</li>
                    <li>w Poznaniu</li>
                </ul>
            </li>
        </ol>
    </section>
    <section class="prawy">
        <h2>Znajdź kwiaciarnię</h2>
    <form method="post">
       Znajdź kwiaciarnię<input type="text" name="input">
       <input type="submit" value="SPRAWDŹ">
    </form>
    <?php
    $zmienna = $_POST['input'];
    echo $zmienna ; 
    ?>
    </section>
    <footer>
        <p>Strone opracowal: VW GOLF GTI </p>
    </footer>
</body>
</html>