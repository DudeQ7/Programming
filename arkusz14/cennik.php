<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db = 'db25';
$conn = mysqli_connect($ip, $user, $password,$db); 
?>
<!DOCTYPE html 5>
<html lang="Pl-pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wynajem pokoi</title>
    <link rel="stylesheet" href="styl2.css">
</head>
<body>
    <section class="baner"> 
        <h1>Pensjonat pod dobrym humorem</h1>
    </section>
    <section class="lewy"> 
        <a href="index.html">Głowna</a>
        <img src="1.jpg" alt="pokoje">
    </section>
    <section class="srodkowy"> 
        <a href="cennik.php">CENNIK</a>
        <table>
            <?php
            $query = "select * from pokoje" ;
            $hogwart = mysqli_query($conn,$query);
         while($result = mysqli_fetch_array($conn)){
            echo "<tr> '$result[0]'</tr> ";
         }
            ?>
            </table>
    </section>
    <section class="prawy">
        <a href="kalkulator.html">Kalkulator</a>
        <img src="3.jpg" alt="pokoje">
    </section>
    <footer>
        <p>Stronę opracował: VW Golf 7 GTI</p>
    </footer>
</body>
</html>