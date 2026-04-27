<?php
$ip = 'localhost';
$user = 'root';
$password ='';
$db = 'db12';
$conn = mysqli_connect($ip,$user,$password,$db);
$query = ' SELECT * from pogoda WHERE miasta_id = 1 ORDER BY data_prognozy ASC ; ';
//$query ="select * from pogoda";
$potega = mysqli_query($conn,$query);
//db12
?>

<html>
    <body>
    <meta charset="utf-8" >
    <meta lang="pl">
    <title>Prognoza pogody Wrocław</title>
    <link rel="stylesheet" href="styl2.css">
    <section class="baner_l">
        <img src="logo.png" alt="meteo">
    </section>
    <section class="baner_sr">
        <h1>Prognoza dla Wroclawia</h1>
    </section>
    <section class="baner_p">
        <p>maj, 2019 r.</p>
    </section>
    <section class="glowny">
        <table>
            <tr>
                <th>DATA</th>
                <th>TEMPERATURA W NOCY</th>
                <th>TEMPERATURA W DZIEN</th>
                <th>OPADY[mm/h]</th>
                <th>CIŚNIENIE[hPa]</th>
            </tr>
            <?php
            while ($power = mysqli_fetch_assoc($potega)){
                echo "<tr>";
                echo "<td>" . $power['data_prognozy'] . "</td>";
                echo "<td>" . $power['temperatura_noc'] . "</td>";
                echo "<td>" . $power['temperatura_dzien'] . "</td>";
                echo "<td>" . $power['opady'] . "</td>";
                echo "<td>" . $power['cisnienie'] . "</td>";
                echo "</tr>";
            }
            ?>
        </table>
    </section>
    <section class="lewy">
        <img src="obraz.jpg" alt="Polska, Wrocław">
    </section>
    <section class="prawy">
        <a href="kwerendy.txt" download> Pobierz kwerendy </a>
    </section>
    <section class="stopka">
        <p>Stronę wykonał: Maciej H :)</p>
    </section>
    </body>
</html>
