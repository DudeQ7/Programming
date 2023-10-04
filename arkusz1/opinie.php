<?php
$user = "root";
$password = "";
$db = "db7";
$ip = "localhost";
$conn = mysqli_connect($ip, $user, $password, $db);
$query = "SELECT zdjecie, imie, opinia FROM klienci INNER JOIN opinie ON klienci.id = opinie.Klienci_id WHERE Typy_id = 2 or Typy_id = 3;";
$data = mysqli_query($conn, $query);
?>

<!DOCTYPE html5>
<html lang="pl">
<head>
    <meta charset="utf-8">
    <title>Opinie klientów</title>
    <link rel="stylesheet" href="styl3.css">
</head>
<body>
    <section class="baner_1">
        <h1>Hurtownia spożywcza</h1>
    </section>
    <section class="glowny_2">
        <h2>Opinie naszych klientów</h2>
        <?php
        while ($build = mysqli_fetch_array($data)) {
            echo '<img src="' . $build["zdjecie"] . '" alt="klient">';
            echo $build["opinia"];
        }
        ?>

    </section>
    <section class="stopka_3">
        <h3>Współpracują z nami</h3>
        <a href="http://sklep.pl">Sklep 1</a>
    </section>
    <section class="stopka_4">
        <h3>Nasi top klienci </h3>
        <ul>
            <li>SKRYPT 2 </li>
        </ul>
    </section>
    <section class="stopka_5">
        <h3>Skontaktuj się</h3>
        <p>telefon: 111222333</p>
    </section>
    <section class="stopka_6">
        <h3>Autor: Ja muhahah</h3>
    </section>
</body>
</html>
