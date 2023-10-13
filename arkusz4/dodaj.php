<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db = 'db13';
$conn = mysqli_connect($ip, $user, $password,$db);
$zapytanie1 ="INSERT INTO filmy(id, tytul, rok, ocena) VALUES (NULL,'Suburbicon',2017,5)";
$potega = mysqli_query($conn,$zapytanie1);
if(!empty($_POST['tytul']) && !empty($_POST['gatunek']) && !empty($_POST['rok']) && !empty($_POST['ocena'])) {
    $tytul = $_POST['tytul']; //G
    $gatunek = $_POST['gatunek'];
    $rok = $_POST['rok']; //pobiera dane :)
    $ocena = $_POST['ocena'];
    $sql = "INSERT INTO filmy(gatunki_id, tytul, rok, ocena) VALUES ($gatunek,'$tytul','$rok',$ocena);";
    mysqli_query($conn, $sql);
    echo "Film $tytul zostal dodany do bazy :) ";
}
mysqli_close($conn);
?>