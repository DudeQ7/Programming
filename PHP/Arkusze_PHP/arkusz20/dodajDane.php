<?php
$imie = $_POST['imie'];
$nazwisko = $_POST['nazwisko'];
$telefon = $_POST['telefon'];
$email = $_POST['email'];
$ip = 'localhost';
$user = 'root';
$password = '';
$db_name = 'db23';
$conn = mysqli_connect($ip,$user,$password,$db_name);
$query = "INSERT INTO uzytkownik (id,imie,nazwisko,telefon,email)VALUES(null,'$imie','$nazwisko','$telefon','$email');";
$potega = mysqli_query($conn,$query);
if($potega){
    echo "Dane zostaly dodane :) ";
    mysqli_close($conn);
}
else{
    echo "Coś poszło nie tak :( ";
}
?>