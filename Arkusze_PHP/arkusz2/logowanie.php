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
    <section class="prawy">
        <h2>Zapisz sie</h2>
        <form class="form" method="POST">
            <label>login:</label>
            <input type="login" name="login"></input>  </br>
            <label>haslo:</label>
            <input type="password"  name="password"></input>   </br>
            <label>Powtorz haslo:</label>
            <input type="password" name="password2"></input>   </br>
            <input type="submit" name="test" value="Zapisz" ></input>  </br>
        </form>
    <?php 
    $ip = 'localhost';
    $user = 'root';
    $password = '';
    $db = 'db8';
    $conn = mysqli_connect($ip, $user, $password,$db);
    $query = "SELECT login FROM `uzytkownicy`;";
    $potega = mysqli_query($conn, $query);
    $handler = 0;
    $handler_exist = "Login występuje w bazie danych, konto nie zostało dodane!";
    $handler_pswd = "Hasła nie są takie same, konto nie zostało stworzone!";
    $handler_sucs = "Konto zostało dodane";
    $handler_fill = "Wypełnij wszystkie pola!";

    if (!empty($_POST['login']) && !empty($_POST['password']) && !empty($_POST['password2'])) {

        $login = $_POST['login'];
        $passwd = $_POST['password'];
        $passwd_r = $_POST['password2'];

        while ($arr = mysqli_fetch_array($potega)) {
            if ($_POST['login'] == $arr[0]) {
                echo "<p>$handler_exist</p>" . $conn->error;
                $handler = 1;
                break;
            }
        }

        if ($passwd != $passwd_r) {
            echo "<p>$handler_pswd</p>" . $conn->error;
            $handler = 1;
        }

        if ($handler == 0) {
            $hash = password_hash($passwd, PASSWORD_DEFAULT);
            $result = mysqli_query($conn, "INSERT INTO `uzytkownicy`(`id`, `login`, `haslo`) VALUES ('', '$login', '$hash')");
            echo "<p>$handler_sucs</p>";
        }
    } else {
        echo "<p>$handler_fill</p>";
        mysqli_close($conn);
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
