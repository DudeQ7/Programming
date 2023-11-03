<?php
$db_name = 'db15';
$user = 'root';
$password = '';
$ip = 'localhost';
$conn = mysqli_connect($ip,$user,$password,$db_name);
$query = 'SELECT zwierzeta.id,zwierzeta.Gromady_id,zwierzeta.gatunek,zwierzeta.wystepowanie,gromady.nazwa FROM zwierzeta INNER JOIN gromady ON zwierzeta.Gromady_id=gromady.id WHERE gromady.id = 4 OR gromady.id = 5 ;';
$hogwarton = mysqli_query($conn,$query);
?>
<html>
    <head>
    <meta charset="utf-8" />
    <title>Gromady kręgowców</title>
    <link rel="stylesheet" href="style12.css" />
    </head>
    <body>
        <section class="menu">
        <a href="gromada-ryby.html" target="_blank">gromady ryb</a>
        <a href="gromada-ptaki.html" target="_blank">gromady ptaki</a>
        <a href="gromada-ssaki.html" target="_blank">gromady ssaki</a>
        </section>
        <section class="logo">
            <h2>GROMADY KRĘGOWCÓW</h2>
        </section>
        <section class="lewy">
            <?php  // skrypt_1 :) 
          while ($hogwart = mysqli_fetch_array($hogwarton)) {
            echo "<hr>";
            echo "<p>" . $hogwart['id'] . " " . $hogwart['gatunek'] . "</p>";
            echo "<p>Występowanie: " . $hogwart['wystepowanie'] . ", gromada: " . $hogwart['nazwa'] . "</p>";
            echo "<hr>";
        }
        
            mysqli_close($conn);
            ?>
        </section>
        <section class="prawy">
            <h1>PTAKI</h1>
                <?php
                $conn_2 = mysqli_connect($ip,$user,$password,$db_name);
                $query_2 = 'SELECT zwierzeta.gatunek, zwierzeta.obraz FROM zwierzeta INNER JOIN gromady ON zwierzeta.Gromady_id=gromady.id WHERE gromady.nazwa = "ptaki";';
                $golf_ON = mysqli_query($conn_2,$query_2);
                echo "<ol>";
                while($golf_mk7_GTI = mysqli_fetch_array($golf_ON)){
                    echo '<li><a href="' . $golf_mk7_GTI['obraz'] . '" target="_blank">' . $golf_mk7_GTI['gatunek'] . '</a></li>';
                }
                echo "</ol>";
                ?>
             
            <img src="sroka.jpg" alt="Sroka zwyczajna,gromada ptaki">

        </section>
        <section class="stopka">
            Stronę o kręgowcach przygotował: GOLF
        </section>
    </body>

</html>