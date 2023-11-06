<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db_name = 'db17';
$conn = mysqli_connect($ip, $user, $password, $db_name);
?>

<!DOCTYPE html 5 >
<html lang="pl-PL">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sekretariat</title>
    <link rel="stylesheet" href="styl.css">
</head>
<body>
    <section class="lewy">
        <h1>Akta pracownicze</h1>
        <?php
        //zapytanie 1 - SELECT  imie,nazwisko,adres,miasto,czyRODO,czyBadania FROM pracownicy WHERE id = 2 ;
        $query = "SELECT  imie,nazwisko,adres,miasto,czyRODO,czyBadania FROM pracownicy WHERE id = 2 ;";
        $SQL = mysqli_query($conn, $query);
        while($row = mysqli_fetch_array($SQL)){
            echo "<h3>dane</h3>   
                  <p>$row[0] $row[1]</p>
                  <hr>
                  <h3>adres</h3>
                  <p>$row[2]</p>
                  <p>$row[3]</p>
                  <hr>
                  <p>Rodo:";
                  if($row[4]== "1") echo "Rodo: podpisano " ;
                  else echo "Rodo: niepodpisano " ;
            
          
        }
        mysqli_close($conn);
        

        ?>
        <hr> </hr>
        <h3>Dokumenty pracownika</h3>
        <a href="cv.txt"download >Pobierz </a>
        <h1>Liczba zatrudnionych pracownikow</h1>
        <p><?php 
            $query_2 = "SELECT count(*) FROM pracownicy";  
            $conn_2 = mysqli_connect($ip, $user, $password, $db_name);
            $SQL_2 = mysqli_query($conn_2, $query_2);
            while($row_2 = mysqli_fetch_array($SQL_2)){
                echo $row_2[0];
            }
            mysqli_close($conn_2);
?>   </p>
    </section>
    <section class="prawy">
      <?php 
      $query_3 = "SELECT id, imie, nazwisko FROM pracownicy WHERE id = 2;";
      $conn_3 = mysqli_connect($ip, $user, $password, $db_name);
      $SQL_3 = mysqli_query($conn_3, $query_3);
      
      while ($row_3 = mysqli_fetch_array($SQL_3)) {
          $obraz = $row_3[0] . '.jpg';
          echo "<img src='$obraz' alt='pracownik'>";
          echo "<h2>" . $row_3[1] . " " . $row_3[2] . "</h2>";
      }
      
      ?> 
    </section>
    <footer>
        Autorem aplikacji jest: Pawel Dutkiewicz 5TiP (GolfGTI :P)
        <ul>
            <li>skontaktuj sie</li>
            <li>Pozaj nasza firme </li>
        </ul>
    </footer>
</body>
</html>