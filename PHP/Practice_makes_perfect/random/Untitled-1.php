<?php 
$ip = 'localhost';
$user = 'root';
$passwd = '';
$bazadanych = 'db7';
$conn = mysqli_connect($ip, $user, $passwd, $bazadanych);
$query = 'select * from tabela';
$potega = mysqli_query($conn,$query);
while ($banas = mysqli_fetch_array($potega)){
    echo $banas['klienci.id'];
}
mysqli_close($conn);
?>
