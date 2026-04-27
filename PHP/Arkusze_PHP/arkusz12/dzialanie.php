<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db_name = 'db16';
$imie = $_POST['imie'];
$nazwisko = $_POST['nazwisko'];
$adres = $_POST['adres'];
$polaczenie = mysqli_connect($ip,$user,$password,$db_name); //polaczenie bazo danowe
$query = "INSERT INTO karty_wedkarskie (id, nazwisko, imie, adres, data_zezwolenia, punkty) VALUES(null,'$nazwisko', '$imie', '$adres', null, null);";

mysqli_query($polaczenie,$query);
 echo "  imie  ". $imie. "   nazwisko   " . $nazwisko . "  adres  ". $adres;

 /* polaczenie 
 baza 
 danych */


?>
 