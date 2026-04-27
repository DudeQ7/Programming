<!DOCTYPE html>
<html lang="pl-PL">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Video On Demand</title>
    <link rel="stylesheet" href="styl3.css">
</head>
<body>
    <section class="bannerl">
        <h1>Internetowa wypożyczalnia filmów</h1>
    </section>
    <section class="bannerr">
        <table>
            <tr>
                <td>Kryminał</td>
                <td>Horror</td>
                <td>Przygodowy</td>
            </tr>
            <tr>
                <td>20</td>
                <td>30</td>
                <td>20</td>
            </tr>
        </table>
    </section>
    <section class="polecamy">
        <h3>Polecamy</h3>
        <?php
        $db = mysqli_connect('localhost','root','','db12');
        if(!$db) {
            echo "error";
        } else {
            $q3 = mysqli_query($db,'SELECT id, nazwa, opis, zdjecie from produkty where id in (18, 22, 23, 25);');
        while ($res = mysqli_fetch_array($q3)){
            echo "<section class=\"film\">
                    <h4>".$res['id'].". ".$res['nazwa']."</h4><br>
                    <img src=\"".$res['zdjecie']."\" alt=\"film\"><br>
                    <p>".$res['opis']."</p>
                    </section>";
        }
        }
        mysqli_close($db);
        ?>
    </section>
    <section class="fantasy">
        <h3>Filmy fantastyczne</h3>
        <?php
        $db = @mysqli_connect('localhost','root','','dane3');
        if(!$db) {
            echo "error";
        } else {
            $q1 = mysqli_query($db,'SELECT id, nazwa, opis, zdjecie from produkty where rodzaje_id=12;');
        while ($res1 = mysqli_fetch_array($q1)){
            $hogwart = 'film';
            echo "<section class=$hogwart 

                    <h4>".$res1['id'].". ".$res1['nazwa']."</h4><br>
                    <img src=\"".$res1['zdjecie']."\" alt=\"film\"><br>
                    <p>".$res1['opis']."</p>
                    </section>";
        }
        
        }
        mysqli_close($db);
        ?>
    </section>
    
    <footer>
        <form action="video.php" method="post">
            <label for="">Usuń film nr.:</label>
            <input type="num" id="num">
            <input type="submit" value="Usuń film">
        </form><br>
        <?php
            $num = $_POST["num"];
            $db = @mysqli_connect('localhost','root','','dane3');
            $q2 = @mysqli_query($db, 'DELETE from produkty where id=$num;');
        ?>
        Stronę wykonał: Natan Świątkowski
    </footer>
</body>
</html>