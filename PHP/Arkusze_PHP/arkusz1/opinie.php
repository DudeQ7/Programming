<?php
$user = "root";
$password = "";
$db = "db7";
$ip = "localhost";
$conn = mysqli_connect($ip, $user, $password, $db);
$query = "SELECT klienci.zdjecie, klienci.imie, opinie.opinia FROM klienci, opinie WHERE klienci.id=opinie.Klienci_id AND klienci.Typy_id in(2,3) LIMIT 2";
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
        while ($build = mysqli_fetch_row($data)) {
            echo "<section class='opinie'>";
            echo '<img src="' . $build[0] . '" alt="klient">';
              echo "<blockquota>" . $build[2] ."</blockquota>" ;
              echo "<h4>".$build[1]."</h4>" ;
              echo "</section>";
            }
        mysqli_close($conn);
        ?>

    </section>
    <section class="stopka_3">
        <h3>Współpracują z nami</h3>
        <a href="http://sklep.pl">Sklep 1</a>
    </section>
    <section class="stopka_4">
        <h3>Nasi top klienci </h3>
        <?php 
$conn2 = mysqli_connect($ip, $user, $password, $db);
$query_2 = 'SELECT imie,nazwisko,punkty from klienci order by (punkty) DESC LIMIT 3;';
$data2 = mysqli_query($conn2,$query_2);
echo "<ol>";
while ($dziala = mysqli_fetch_array($data2)) {
  //  echo "MACIEJ to  ". $dziala['imie'];
echo  "<li>". "Imie: ". $dziala['imie']. " ".  $dziala['nazwisko'] . ",  " . $dziala['punkty'] . " pkt." .  "</li>"   ;
}
echo "</ol>";

mysqli_close($conn2);

?>
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
