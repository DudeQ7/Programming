<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db_name = 'db20';
$data = date("Y/m/d");
$conn = mysqli_connect($ip,$user,$password,$db_name);
$query = "SELECT f.name, f.price,d.percent_off,MAX(d.percent_off) AS 'maksymalna znizka' FROM flowers AS f INNER JOIN discounts AS d ON f.id = d.flower_id WHERE DATE(d.date_start) <= '$data' AND DATE(d.date_end) >= '$data'GROUP BY f.name, f.price;";
$hogwart = mysqli_query($conn,$query);
?>
<!DOCTYPE html>
<html lang="pl-PL">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kwiaciarnia</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section class="baner">
    <img src="logo.jpg" alt="biały kwiat">
    <h1>Kwiaciarnia orchidea</h1>
    </section>
    <section class="panel_boczny">
        <h3>dzisiejsze promocje</h3>
        <table>
        <tr>
        <th>gatunek</th>
        <th>obniżka</th>
        <th>nowa cena</th>
        </tr>
        <?php
        while($lego = mysqli_fetch_array($hogwart)){
        $nowa_cena = $lego['price'] * (100 - $lego['maksymalna znizka']) / 10000;
        echo "<tr>";
        echo "<td>".$lego["name"]."</td>"; 
        echo "<td>"."-".$lego[2]." %"."</td>";
        echo "<td>".round($nowa_cena,2)." zł"."</td>";
        echo "</tr>";
        }
        mysqli_close($conn);
        ?>
        </table>
       <a href="cennik.php" target="_blank">cennik </a>
    </section>
    <section class="panel_glowny">
        <h2>zamów kwiaty</h2>
        <form action="potwierdzenie.php" method="post">
            gatunek kwiatów
            <select name="select" id="select">
             <?php
             $ip = 'localhost';
             $user = 'root';
             $password = '';
             $db_name = 'db20';
             $conn_2 = mysqli_connect($ip,$user,$password,$db_name);
             $query_2 = 'SELECT id , name from flowers';
             $rzyg  = mysqli_query($conn_2,$query_2);
        while($potega = mysqli_fetch_array($rzyg)){
            echo "<option value='$potega[0]'>$potega[1]</option>";
        }
        mysqli_close($conn_2);
             ?>       
            </select> <br>
            
            ilość: <input type="number" id="ilosc" name="ilosc"> <br>
            adres dostawy <input type="text" id="adres" name="adres"> <br>
            telefon kontaktowy <input type="text" id="telefon" name="telefon"> <br>
            <input type="submit" value="zamów"> 
            <input type="reset" value="wyczyść"> 
            
        </form>
    </section>
    <footer>
        <p>Przygotowal:Golf VII GTI </p>
    </footer>
</body>
</html>