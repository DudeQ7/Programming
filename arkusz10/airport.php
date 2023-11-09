<?php
$ip = 'localhost';
$user = 'root';
$password = '';
// $db_name = 'db18'; nazwa bazy na lapku
$db_name = 'db15'; // nazwa bazy na stacjonarce 
$conn = mysqli_connect($ip, $user, $password, $db_name);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Odloty samolotów</title>
    <link rel="stylesheet" href="styl6.css">
</head>
<body>
    <section class="baner_1">
        <h2>Odloty z lotniska</h2>
    </section>
    <section class="baner_2">
        <img src="zad6.png" alt="logotyp">
    </section>
    <section class="main">
        <h4> Tabela odlotów </h4>
            <table>
                <?php
                echo "
                        <th>lp</th>
                        <th>numer rejsu</th>
                        <th>czas</th>
                        <th>kierunek</th>
                        <th>status</th>
                    ";
                $query_1 = 'SELECT id,nr_rejsu,czas,kierunek,status_lotu FROM odloty ORDER BY czas DESC;';
                $hogwart = mysqli_query($conn,$query_1);
                while ($row = mysqli_fetch_array($hogwart)) {
                    echo "<tr>";
                    for($lego = 0; $lego < 5; $lego++) {
                        echo "
                                <td>$row[$lego] </td> 
                        "; //pokazuje elementy wyświetla 5 elementów z bazy danych ;) 
                    }
                    echo "</tr>";
                }
                mysqli_close($conn);
            ?>
    </section>
    <section class="footer_1">
        <a href="kw1.jpg"Download target="_blank">Pobierz obraz </a>
    </section>
    <section class="footer_2">
    <?php
$conn_2 = mysqli_connect($ip, $user, $password, $db_name);
if (isset($_COOKIE["ciasteczko"])) {
    echo "<p><i>Dzień dobry! Sprawdź regulamin naszej strony</i></p>";
} else {
    $cookie_name = "cookie";
    $cookie_value = "";
    $cookie_time = time() + 60*60*2;
    $cookie_path = "";
    $cookie_domain = "";
    $cookie_secure  = false;
    $cookie_httponly = false;
    echo "<p><b>Miło nam, że nas znowu odwiedziłeś</b></p>";
}

?>


    </section>
    <section class="footer_3">
        Autor: Golf Mk7 GTI 
    </section>
</body>
</html>