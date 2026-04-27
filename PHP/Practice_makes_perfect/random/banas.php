<?php //OTWIERAMY PHP'a
$ip = 'localhost';
$user = 'root';
$passwd = '';
$bazadanych = 'db7';   
$conn = mysqli_connect($ip, $user, $passwd, $bazadanych); // linie 1 -6 connection 
$query = 'select * from klienci LIMIT 2 '; // kwerenda sql'owa
$potega = mysqli_query($conn,$query);  // mysqli query(POLACZENIE, KWERENEDA SQLOWA) POZWALA WYKONAC KWERENDE MYSQL W PHP 
echo "<ol>";  //  // POCZATEK LISTY NUMEROWANEJ
while ($result = mysqli_fetch_array($potega)){   // WHILE ( JAKAS ZMIIENNA = POZWALA SFETCHOWAC(WYSWIETLIC) WYNIKI KWERENDY POTEGA )
    echo "<li>". $result['imie'] . " " .$result['nazwisko']  . "</br>". "</li>" ; 
// ECHO TO PRINT <li> to jest poczateke elementu listy  .  $result to nasza zmienna ta z linii numer 10 [w nawiasie kwadrawtowym piszemy]
// nazwe kolumny z bazy danych  , potem zakanczymy element listy numerowanej piszac </li>
} // konczymy while'a 
echo "</ol>"; // konczymy nasza liste numerowana
mysqli_close($conn); // KONCZYMY POLACZENIE z MYSQLEM

//ZAMYKAMY PHP'a
?> 
