<?php 
$ip = 'localhost';
$user = 'root';
$password = '';
$database  = 'db20'; //laptop ;)
$imie = $_GET['imie'];
$nazwisko = $_GET['nazwisko'];
$adres = $_GET['adres'];
//zapytanie1 
$query = 'INSERT INTO karty_wedkarskie 
(id,imie,nazwisko,adres,data_zezwolenia,punkty)
VALUES
(null,$imie,$nazwisko,$adres,null,null);';
mysqli_query($conn,$query)
?>
