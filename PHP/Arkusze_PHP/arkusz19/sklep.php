<?php
$ip  = 'localhost';
$user ='root';
$password = '';
$db = 'db22';
$conn = mysqli_connect($ip,$user,$password,$db);

?>
<!DOCTYPE html>
<html lang="pl-PL">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hurtownia</title>
    <link rel="stylesheet" href="styl1.css">
</head>
<body>
    <section class="logo">
        <img src="komputer.png" alt="hurtownia komputerowa">
    </section>
    <section class="listy">
        <ul>
            <li>Sprzęt
            <ol>
                <li>Procesory</li>
                <li>Pamięci RAM</li>
                <li>Monitory</li>
                <li>Obudowy</li>
                <li>Karty graficzne</li>
                <li>Dyski twarde</li>
            </ol></li>
            <li>Oprogramowanie</li>
        </ul>
    </section>
    <section class="formularz">
        <h2>Hurtownia komputerowa</h2>
        <form method="post" action="sklep.php">
                Wybierz kategorię sprzętu<input type="number" name="kategoria" id="kategoria" placeholder="0"> <br>
                <input type="submit" value="SPRAWDŹ">
        </form>
    </section>
    <section class="glowny">
        <h1>Podzespoły we wskazanej kategorii</h1>
        <?php
        $kategoria = $_POST['kategoria'];
        if(empty($kategoria)){
    echo "Wybierz poprawną kategorię sprzętu"."<br>";
}
else{      
        $query = "SELECT nazwa,opis,cena FROM podzespoly WHERE typy_id = '$kategoria'";
        $hogwart = mysqli_query($conn,$query);
        while($row = mysqli_fetch_array($hogwart)){
            echo $row[0]." ".$row[1]." CENA: ".$row[2]."<br>"."<br>";
        }}  
        ?>
    </section>
    <footer>
        <h3>Hurtownia działa od poniedziałku do soboty w godzinach 7<sup>00</sup>-16<sup>00</sup></h3>
        <a href="mailto:bok@hurtownia.pl">Napisz do nas</a>
        <text>Partnerzy</text>
        <a href="http://intel.pl" target="_blank">Intel</a>
        <a href="http://amd.pl" target="_blank">AMD</a>
        <p>Stronę wykonał:GOLF VII GTI</a>
    </footer>
</body>
</html>