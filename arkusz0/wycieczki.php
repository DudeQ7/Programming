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
</section>
<section class="srodkowy">
    <h2>Galeria</h2>
  <h2>LOL SKRYPT HOGWARTU</h2>
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
<section class="dane"></section>
<section class="stopka">
    <p>Strone wykonal: 01010 </p>
</section>

</body>
<?php
$user = 'root';
$ip = 'localhost';
$password = '';
$dbname = 'db4';
$query = "Select nazwaPliku,podpis from zdjecia order by(podpis) ASC";
$conn= mysqli_connect($ip,$user,$password,$dbname);
$result = mysqli_query($conn,$query);
//Select nazwaPliku,podpis from zdjecia order by(podpis) ASC;

while($row = mysqli_fetch_assoc($result)) {
    $zmienna_potegi = 0;
    echo "<img src=" .$row['nazwaPliku'] .". alt=" . $row['podpis']. "";

}
mysqli_close($conn);


?>