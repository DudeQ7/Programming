<?php
$ip = 'localhost';
$user = 'root';
$password = '';
$db_name = 'db19'; // laptop
$conn = mysqli_connect($ip,$user,$password,$db_name);
?>
<!DOCTYPE html 5 >
<html lang="pl-PL">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Forum o psach</title>
    <link rel="stylesheet" href="styl.css">
</head>
<body>
    <section class="baner">
        <h1>Forum miłośników psów</h1>
    </section>

    <section class="lewy">
        <img src="Avatar.png" alt="Użytkownik forum">
        <?php
        //skrypt 1  BABA G :)
        //zapytanie 3 
        $query = 'SELECT konta.nick,konta.postow,pytania.pytanie FROM konta INNER JOIN pytania on konta.id=pytania.konta_id LIMIT 1 ;
        ';
        $hogwart = mysqli_query($conn, $query);
     while($connect = mysqli_fetch_array($hogwart)){
        echo "<h4>Użytkownik $connect[0]</h4>";
        echo "<p>$connect[1] postów na forum</p>";
        echo "<p>$connect[2]</p>";
     }
     mysqli_close($conn);
        
        ?>
        <video controls autoplay muted loop>
        <source src="video.mp4" type="video/mp4">
        </video>
    </section>
    <section class="prawy">
    <form method="post" action="index.php">
        <textarea name="text" rows="4" cols="40"></textarea><br>
        <input type="submit" name="lol" value="Dodaj odpowiedź">
    </form>

    <?php
    if(isset($_POST['lol']) && $_POST['lol'] != '' && isset($_POST['text']) && $_POST['text'] != '') {
        //zapytanie_1 pole odpowiedz ma ma wartosc z pola wielowierszowego
        $conn_2 = mysqli_connect($ip, $user, $password, $db_name);
        $zmienna_hogwartu = $_POST['text'];
        $query = "INSERT INTO odpowiedzi
        (id, Pytania_id, konta_id, odpowiedz)
        VALUES
        (null, 1, 5, '$zmienna_hogwartu')";
        
        // Execute your query here
        mysqli_query($conn_2, $query);

        // Close the database connection
        mysqli_close($conn_2);
    }
    ?>

        </form>
            <h2>Odpowiedzi na pytanie</h2>
                <ol>
                    <?php
                    //zapytanie 4
                    $conn_3 = mysqli_connect($ip, $user, $password, $db_name);
                    $query_lol = 'SELECT odpowiedzi.id, odpowiedzi.odpowiedz, konta.nick
                    FROM odpowiedzi
                    INNER JOIN konta ON odpowiedzi.konta_id = konta.id
                    INNER JOIN pytania ON odpowiedzi.Pytania_id = pytania.id
                    WHERE pytania.id = 1;';
                    $lego = mysqli_query($conn_3,$query_lol); 

                    while($banas = mysqli_fetch_array($lego)){
                        echo "<li>";

                        echo "$banas[1] <i>$banas[2]</i> <hr> <br>";
                        echo "</li>";
                    }
                    ?>  
                </ol>
    </section>
    <section class="stopka">
        Autor : Golf 7,5 GTI <a href="https://lego.com" target="_blank">Zobacz nasze relacje</a>
    </section>
</body>
</html>