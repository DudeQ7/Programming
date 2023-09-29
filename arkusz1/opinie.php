<!DOCTYPE html5>
<html lang="pl">
<head>
<meta charset="utf-8">
<title>Opinie klientów</title>
<link rel="stylesheet"href="styl3.css">
</head>
<body>
<section class="baner_1">
    <h1>Hurtownia spożywcza</h1>
</section>
<section class="glowny_2">
    <h2>Opinie naszych klientów</h2>
    SKRYPT 1 
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
    <h3>Skontaktuj sie</h3>
    <p>telefon:111222333</p>
</section>
<section class="stopka_6">
    <h3>Autor: Ja muhahah </h3>
</section>

</body>
<?php
$user = "root";
$password = "";
$db = "db7";
$ip = "localhost";
$conn = mysqli_connect($ip,$user,$password,$db,$ip);
$query = "";
mysqli_close($conn);
?>