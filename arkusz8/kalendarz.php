<?php
$user = 'root';
$passwd = '';
$ip = 'localhost';
$db_name = 'db16';
$golf5 = mysqli_connect($ip,$user,$passwd,$db_name); 
?>
<html>
    <head>
        <meta charset="UTF-8" />
        <meta lang="pl">
        <title>Mój kalendarz </title>
        <link rel="stylesheet" href="styl5.css" type="text/css" >
    </head>
    <body>
        <section class="baner_1">
            <img src="logo1.png" alt="Mój kalendarz" />
        </section>
        <section class="baner_2">
            <h1>Kalendarz</h1>
            <?php 
           $query_1 =  "SELECT miesiac,rok FROM zadania WHERE dataZadania = '2020-07-01';";
           $golf_mk7_GTI = mysqli_query($golf5, $query_1);
           while ($golfGTI = mysqli_fetch_array($golf_mk7_GTI)){
            echo "<h3>"."miesiąc: ".$golfGTI['miesiac']." "."rok:".$golfGTI['rok']."</h3>";
            
        }
        mysqli_close($golf5);
            ?>
            
        </section>
        <section class="main">
        <?php
        //skrypt 2 
        $golf5_2 =mysqli_connect($ip,$user,$passwd,$db_name); 
        $query_2 = "SELECT dataZadania,wpis FROM zadania WHERE miesiac = 'lipiec';";
        $porsche_GT3_RS = mysqli_query($golf5_2, $query_2);
        $lolik = 'dni';
        //  echo "<section class='$zmienna_testowa'>";
        echo "<section class='$lolik'>"; 
        while ($BMWM5 = mysqli_fetch_array($porsche_GT3_RS)){
            echo "<h5>".$BMWM5['dataZadania']."</h5>";
            echo "<p>".$BMWM5['wpis']."</p>";
        }
        echo "</section>";
        mysqli_close($golf5_2);
        ?>    
        
      
        </section>
       
     
        <section class="stopka">
            <form method="post">
               Dodaj wpis: <input type="text" name="wpis">
               Dodaj<input type="submit" name="DODAJ">
                <p> Stronę wykonał: GOLF mk7 GTI </p>
            </form>
    </section>
    </body>