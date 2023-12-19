<?php
$ip = 'localhost';
$user='root';
$passwd ='';
$dbname = 'db17';
$conn = mysqli_connect($ip,$user,$passwd,$dbname);
?>


<!DOCTYPE html>
<html lang="Pl-pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Odżywianie zwierząt</title>
    <link rel="stylesheet" href="style4.css">
</head>
<body>
    <section class="baner">
        <h2>DRAPIEŻNIKI I INNE </h2>
    </section>
    <section class="formularz">
        <h3>Wybierz styl życia:</h3>
        <form method="post">
        <select class="lista" name="opcja">
                <option value="1">Drapieżniki</option>
				<option value="2">Roślinożerne</option>
				<option value="3">Padlinożerne</option>
				<option value="4">Wszystkożerne</option>
        </select>
        <input type="submit" value="Zobacz">
    </form>
    </section>
    <section class="glowny_lewy">
        <h3>Lista zwierząt</h3>
        <ul>
        <?php
        $query = 'SELECT zwierzeta.gatunek,odzywianie.rodzaj 
        FROM zwierzeta INNER JOIN odzywianie 
        ON zwierzeta.Odzywianie_id = odzywianie.id;';
        $hogwart = mysqli_query($conn,$query);
        while ($result = mysqli_fetch_array($hogwart))
        {
            echo "<li>".$result[0]."  ".$result[1]."</li>";
        }
        mysqli_close($conn);
        ?>
        <ul>
    </section>
    <section class="glowny_srodek">
     <?php
     //skrypt 2 
     $conn_2 = mysqli_connect($ip,$user,$passwd,$dbname);
     $opcja_1 =$_POST["opcja_1"];
     if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $wartosc = $_POST['opcja'];
        if($wartosc == $opcja_1){
            echo "test";
        }
    }
    ?>
    

    </section>
    <section class="glowny_prawy">
        <img src="drapieznik.jpg" alt="Wilki">
    </section>
    <footer>
        <a href="pl.wikipedia.org" target="_blank">Poczytaj o zwierzętach na Wikipedii </a>
        autor strony: Golf VII GTI
    </footer>
</body>
</html>