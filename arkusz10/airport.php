<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db_name = 'db18';
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
                $query_1 = 'SELECT id,nr_rejsu,czas,kierunek,status_lotu FROM odloty ORDER BY czas DESC;';
                $hogwart = mysqli_query($conn,$query_1);
                    echo "<table";
                    while ($row = mysqli_fetch_array($hogwart))
                    {
                echo "
                    <td><th>lp.</th></td>
                    <td><th>NUMER REJSU</th></td>
                    <td><th>CZAS</th></td>
                    <td><th>KIERUNEK</th></td>
                    <td><th>STATUS</th></td>";
                }
           echo  "</table>";
            
            ?>
    </section>
    <section class="footer_1">
        <a href="kw1.jpg"Download target="_blank">Pobierz obraz </a>
    </section>
    <section class="footer_2">
        SKRYPT 2 
    </section>
    <section class="footer_3">
        Autor: Golf Mk7 GTI 
    </section>
</body>
</html>