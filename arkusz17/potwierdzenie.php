<!DOCTYPE html>
<html lang="pl-PL">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kwiaciarnia</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<h1>Kwiaciarnia orchidea</h1>
    <section class="baner">
    <img src="logo.jpg" alt="biały kwiat">
    <h1>Kwiaciarnia orchidea</h1>
    </section>
    <section class="panel_boczny">
        <img src="rose.png"alt="róża">
    </section>
    <section class="panel_glowny">
        <h2>dziękujemy za złożenie zamówienia</h2>
        <p>szczegóły są dostępne <a href="kwerendy.txt"target="_blank">tutaj</a> </p>
        <p><a href="index.php">powrót do strony głównej </a></p>
    </section>
    <footer>
        <p>Przygotowal:Golf VII GTI </p>
      
    </footer>
    <section>
    <?php
            $ip = 'localhost';
            $user = 'root';
            $password = '';
            $db_name = 'db20';
            $ilosc = $_POST['ilosc'];
            $adres = $_POST['adres'];
            $telefon = $_POST['telefon'];
            $nr = $_POST['select'];
            $query_3 = "INSERT INTO orders(flower_id,count,cost,address,phone)VALUES('$nr','$ilosc',null,'$adres','$telefon');";
            $conn_3 = mysqli_connect($ip,$user,$password,$db_name);
            $hogwart = mysqli_query($conn_3,$query_3) ;
            echo $nr ; 
            
            echo "Zamowienie zostala dodane z tymi danymi: "."typ_kwiatu:".$nr."\n"."ilosc kwiatow: ".$ilosc."\n"."adres:".$adres."\n"."telefon:".$telefon;
            
        
            ?>
    </section>
   
</body>
</html>