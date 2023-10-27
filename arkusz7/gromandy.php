<?php
$db_name = 'db15';
$user = 'root';
$password = '';
$ip = 'localhost';
$conn = mysqli_connect($ip,$user,$password,$db_name);
$query = 'SELECT zwierzeta.id,zwierzeta.Gromady_id,zwierzeta.gatunek,zwierzeta.wystepowanie FROM zwierzeta INNER JOIN gromady ON zwierzeta.Gromady_id=gromady.id WHERE gromady.id = 4 OR gromady.id = 5 ;';
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
        <a href="gromady-ryby.html" target="_blank">gromady ryb</a>
        <a href="gromady-ptaki.html" target="_blank">gromady ptaki</a>
        <a href="gromady-ssaki.html" target="_blank">gromady ssaki</a>
        </section>
        <section class="logo">
            <h2>GROMADY KRĘGOWCÓW</h2>
        </section>
        <section class="lewy">
            <?php 
            while($hogwart= mysqli_fetch_array($hogwarton)){
                echo "<p>".$hogwart['id'].$hogwart['gatunek']."</p>";
                echo "<p>"."Wystepowanie:".$hogwart['wystepowanie']."Gromada:".$hogwart['gromada']."</p>";
            }
            mysqli_close($conn);
            ?>
        </section>
        <section class="prawy">
            <h1>PTAKI</h1>
            <ol>
                <li>Efekt skryptu 2</li>
            </ol>
            <img src="sroka.jpg" alt="Sroka zwyczajna,gromada ptaki">

        </section>
        <section class="stopka">
            Stronę o kręgowcach przygotował: GOLF
        </section>
    </body>

</html>