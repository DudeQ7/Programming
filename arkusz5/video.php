<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db = 'db12';
$conn = mysqli_connect($ip, $user, $password, $db);
$query = "SELECT id,nazwa,opis,zdjecie FROM produkty WHERE id in (18,22,23,25);";
$potega = mysqli_query($conn, $query);
?>
<html>
<head>
<meta charset="utf-8" />
<html lang="pl"></html>
<title>Video On Demand</title>
<link rel="stylesheet" href="styl3.css" type="text/css"  >
</head>    
<body>
<section class="baner_lewy">
<h1>Internetowa wypowżyczalnia filmów</h1>
</section>
<section class="baner_prawy">
    <table>
        <tr>
            <td>Kryminał</td>
            <td>Horror</td>
            <td>Przygodowy</td>

        </tr>
        <tr>
            <td>20</td>
            <td>30</td>
            <td>20</td>
        </tr>
    </table>
</section>
<section class="lista_polecamy">
<h3>Polecamy</h3>
<?php
$zmienna_testowa = "film";
echo "<section class=$zmienna_testowa>";
while($hogwart = mysqli_fetch_array($potega)){
echo "<h4>".$hogwart['id'].$hogwart['nazwa']."</h4>";

}
echo "</section>";
mysqli_close($conn); 
?>
</section> </br>
<section class="Filmy_fantastyczne">
<h3>Filmy fantastyczne</h3>
SKRYPT2 TUTAJ :)
</section>
<section class="stopka">
<form method="post">
    Usuń film nr:<input type="number" name="usun">
    Usuń film<input type="submit" name="wyslij">
</form>
Strone wykonal :<a href="mailto:wow@gmail.com"> GOLF :) 
</section>
</body>
    
</html>