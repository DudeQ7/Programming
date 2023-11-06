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
        while ($wynik = mysqli_fetch_array($porsche_GT3_RS)) {
            echo "<section class='$lolik'><h5>$wynik[0]</h5><p>$wynik[1]</p></section>";
        }
        mysqli_close($golf5_2);
        ?>    
        </section>
       
     
        <section class="stopka">
            <form method="post">
               Dodaj wpis: <input type="text" name="wpis">
               Dodaj<input type="submit" name="wyslij">
                <p> Stronę wykonał: GOLF mk7 GTI </p>
            </form>
            <?php 
         
           if(isset($_POST["wyslij"])) {
            $wpis =  $_POST['wpis'];
            //zapytanie 4 = UPDATE zadania SET wpis = "Wycieczka:jezioro" WHERE dataZadania = '2020-07-13' ;
            $golf5_3 =mysqli_connect($ip,$user,$passwd,$db_name); 
            $query4 = "UPDATE zadania set wpis = '$wpis' WHERE dataZadania = '2020-07-13' ; ";
            $hogwart =  mysqli_query($golf5_3,$query4);
             echo "Nazwa zmieniona na:". $wpis ;
           
           }
            ?>

    </section>
    </body>