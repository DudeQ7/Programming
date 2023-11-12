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
    <section class="flex">

    <section class="lewy">
        <img src="Avatar.png" alt="Użytkownik forum">
        <?php
        //skrypt 1 
        //zapytanie 3 
        $query = 'SELECT konta.nick,konta.postow FROM konta INNER JOIN pytania on konta.id=pytania.konta_id;
        ';
        $hogwart = mysqli_query($conn, $query);
        
        ?>

        <video controls autoplay muted loop>
        <source src="video.mp4" type="video/mp4">
        </video>
    </section>
    <section class="prawy">
        <form method="post" action="index.php">
        <textarea id="test" rows = "4" cols="40"> </textarea><br>
        <input type="submit" name="lol" placeholder="Dodaj odpowiedź">
        </form>
            <h2>Odpowiedzi na pytanie</h2>
                <ol>
                    <li>SKRYPT 3 </li>
                </ol>
    </section>
    </section>
    <section class="stopka">
        Autor : Golf 7,5 GTI <a href="http://lego.com" target="_blank">Zobacz nasze relacje</a
    </section>
</body>
</html>