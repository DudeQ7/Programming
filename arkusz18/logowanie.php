<?php
$ip = 'localhost';
$user = 'root';
$db_password = '';
$db_name = 'db21';
$conn = mysqli_connect($ip,$user,$db_password,$db_name);
?>


<!DOCTYPE html>
<html lang="Pl-pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Forum o psach</title>
    <link rel="stylesheet" href="styl4.css">
</head>
<body>
    <section class="baner">
        <h1>Forum wielbicieli psów</h1>
    </section>
    <section class="lewy" >
        <img src="obraz.jpg" alt="foksterier">
    </section>
    <section class="prawy1">
        <h2>Zapisz się</h2>
        <form method="post" action="logowanie.php" name="formularzalfa">
            login:<input type="text" name="login" id="login"> <br>
            hasło:<input type="password" name="password" id="password"> <br>
            powtórz hasło:<input type="password"name="password2" id="password2">
                          <input type="submit" value="Zapisz">
        </form>

        <?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $login = $_POST["login"];
    $password = $_POST["password"];
    $password2 = $_POST["password2"];
    $bledy = false;
    if (empty($login) || empty($password) || empty($password2)) {
        echo "<p>Ty Geju jedno z pól jest puste!</p>";
        $bledy = true;
    } else {
        // Check if the login already exists
        $checkLoginQuery = "SELECT login FROM uzytkownicy WHERE login = '$login'";
        $result = mysqli_query($conn, $checkLoginQuery);
        if (!$result) {
            echo "<p>Błąd podczas sprawdzania loginu</p>";
            $bledy = true;
        } else {
            $existingLogin = mysqli_fetch_assoc($result);

            if ($existingLogin) {
                echo "<p>Ty Geju taki login juz istnieje, daj inny</p>";
                $bledy = true;
            } elseif ($password != $password2) {
                echo "<p>Ty geju, te hasła są różne, popraw to !!!</p>";
                $bledy = true;
            } else {
                // Proceed with user registration
                $hash = hash('sha1',$password);
                $query_2 = "INSERT INTO uzytkownicy (id, login, haslo) VALUES (null, '$login', '$hash')";
                $potega = mysqli_query($conn, $query_2);

                if ($potega) {
                    echo "<p>Konto zostało dodane</p>";
                    echo "<br><p>Dane konta: login:'$login' haslo: '**********' </p>";
                } else {
                    echo "<p>Błąd podczas dodawania konta</p>";
                    $bledy = true;
                }
            }
        }
    }
    if (!$bledy) {
        mysqli_close($conn);
    }
}
?>

    </section>
    <section class="prawy2">
        <h2>Zapraszamy wszystkich</h2>
        <ol>
            <li>właścicieli psów</li>
            <li>weterynarzy</li>
            <li>tych, co chcą kupić psa</li>
            <li>tych,co lubią psy</li>
        </ol>
        <a href="regulamin.html">Przeczytaj regulamin forum</a>
    </section>
    <footer>
        Stronę wykonał: Volkswagen Mark VIII GTI 
    </footer>
</body>
</html>