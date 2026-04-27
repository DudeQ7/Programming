<?php 
$ip = 'localhost';
$user = 'root';
$password = '';
//$database  = 'db20'; //laptop ;)
$database = 'db16'; //pc
$conn = mysqli_connect($ip, $user, $password, $database);
$imie = $_POST['imie'];
$nazwisko = $_POST['nazwisko'];
$adres = $_POST['adres'];
//zapytanie1 
$query = "INSERT INTO karty_wedkarskie 
(id, imie, nazwisko, adres, data_zezwolenia, punkty)
VALUES
(null, '$imie', '$nazwisko', '$adres', null, null);";
mysqli_query($conn, $query);
echo "dane zapisane: ". $imie." " .$nazwisko." ". $adres. " ";
mysqli_close($conn);
?>
