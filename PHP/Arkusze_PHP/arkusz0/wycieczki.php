<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wycieczki i urlopy</title>
    <link rel="stylesheet" href="styl3.css">
</head>
<body>
<section class="baner">
    <h1>Biuro Podróży</h1>
</section>
<section class="lewy">
    <h2>Kontakt</h2>
    <a href="mailto:kontakt@gmail.com" > Napisz do nas</a>
    <p>telefon 555666777</p>
</section>
<section class="srodkowy">
    <h2>Galeria</h2>
  <h2><?php
$user = 'root';
$ip = 'localhost';
$password = '';
$dbname = 'db5';
$query = "Select nazwaPliku,podpis from zdjecia order by(podpis) ASC";
$conn= mysqli_connect($ip,$user,$password,$dbname);
$result = mysqli_query($conn,$query);
//Select nazwaPliku,podpis from zdjecia order by(podpis) ASC;
while($row = mysqli_fetch_array($result)) {
    echo  "<img src='$row[0]' alt='$row[1]' />" ;

}
mysqli_close($conn);
?></h2>
</section>
<section class="prawy">
    <h2>PROMOCJE</h2>
    <table>
    <tr>
        <td>Jesień</td>
        <td>Grupa 4+</td>
        <td>Grupa 10+</td>
    </tr>
    <tr>
        <td>5%</td>
        <td>10%</td>
        <td>15%</td>
    </tr>
</table>

</section>
<section class="dane">
<h2>LISTA WYCIECZEK</h2>
<?php
$conn1 = mysqli_connect($ip,$user,$password,$dbname);
$query1 = "SELECT id,dataWyjazdu,cel,cena from wycieczki WHERE dostepna = 1 ";
$result1 = mysqli_query($conn1,$query1);
while ($row1 = mysqli_fetch_array($result1)){
 echo $row1['id'] . "  " .$row1['dataWyjazdu']. "  " . $row1['cel'] . "  ". "cena: " . $row1['cena'] . "</br>" ;
}
mysqli_close($conn1);

?>
</section>
<section class="stopka">
    <p>Strone wykonal: 01010 </p>
</section>

</body>
