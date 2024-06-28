<?php
$ip = 'localhost';
$user='root';
$passwd ='';
$dbname = 'db19';
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
          if(!empty($_POST['opcja'])) {
             $nr = $_POST['opcja'];
             $wybor = "";
             if ($nr == 1) $wybor = "Drapieżniki";
             if ($nr == 2) $wybor = "Roślinożerne";
             if ($nr == 3) $wybor = "Padlinożerne";
             if ($nr == 4) $wybor = "Wszystkożerne";
             $query = "SELECT zwierzeta.id, zwierzeta.gatunek, zwierzeta.wystepowanie FROM zwierzeta, odzywianie WHERE zwierzeta.Odzywianie_id = odzywianie.id AND odzywianie.id = $nr;";
             echo "<h3>$wybor</h3>";
             $res2 = mysqli_query($conn, $query);
             while($tab = mysqli_fetch_array($res2)) {
                 echo "$tab[0]. $tab[1], $tab[2]<br/>";
             }
         }
         mysqli_close($conn);
      
        ?>
        <ul>
    </section>
    <section class="glowny_srodek">
   
    

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