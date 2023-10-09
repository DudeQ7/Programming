<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="styl4.css" type="text/css">

</head>
<body>
    <section class="baner">
    <h1>Forum wielbicieli psow</h1>
    </section>
    <section class="lewy">
        <img src="obraz.jpg" alt="foksterier">
    </section>
    <section class="prawy_1">
        <h2>Zapisz sie</h2>
        <form class="form">
            <label>login:</label>
            <input type="login" name="login"></input>  </br>
            <label>haslo:</label>
            <input type="password"  name="password"></input>   </br>
            <label>Powtorz haslo:</label>
            <input type="password" name="password2"></input>   </br>
            <input type="submit" name="test" value="Zapisz" ></input>  </br>
        </form>
    <?php 
    $user = 'root';
    $ip = 'localhost';
    $password = '';
    $db = 'psy';
    $conn = mysqli_connect($ip, $user, $password);
    $query = "SELECT * FROM uzytkownicy;";
    echo "<p>" . mysqli_error($conn) . "</p";
    $potega = mysqli_query($conn, $query);
    while ($row = mysqli_fetch_array($potega)) {
        echo $row['uzytkownicy.id'];
    }

    ?>

    </section> </br>
    <section class="prawy_2">
        <h2>Zapraszamy wszystkich </h2>
        <ol>
            <li>wlascicieli psow </li>
            <li>weterynarzy </li>
            <li>tych co chca kupic psa</li>
            <li>tych co lubia psy </li>
        </ol>
        <a href="regulamin.html" target="_blank">Przeczytaj regulamin</a>
    </section>
    <section class="stopka">
        Strone wykonal: JAAAAAAAAAAAA MUHAHAHHAHAHHA
    </section>
</body>
</html>
