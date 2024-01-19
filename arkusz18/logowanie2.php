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
        <form method="post" action="logowanie2.php" name="formularzalfa">
            login:<input type="text" name="login" id="login"> <br>
            hasło:<input type="password" name="password" id="password"> <br>
            powtórz hasło:<input type="password"name="password2" id="password2">
                          <input type="submit" value="Zapisz">
        </form>
        </form>
<?php
    $login = isset($_POST['login']) ? $_POST['login'] : '';
    $formpassword = isset($_POST['password']) ? $_POST['password'] : '';
    $formpassword2 = isset($_POST['password2']) ? $_POST['password2'] : '';
    if(!empty($login)&&(!empty($haslo))&&(!empty($powhaslo))){
    $query = "SELECT login FROM uzytkownicy WHERE login LIKE '$login';";
    $executequery = mysqli_query($conn,$query);
    $result = mysqli_num_rows($executequery);
    if($result > 0 ){
        echo "Taki uzytkownik juz istnieje!";
    }
    else {
        if($haslo == $powhaslo){
            $hash = sha1($haslo);
            $query2 = "INSERT INTO uzytkownicy (id, login, haslo) VALUES (NULL, '$login', '$hash');";
            mysqli_query($conn,$query2);
            echo "Uzytkownik zosta dodany :)";
    }
        else{
            echo "Hasla sie nie zgadzaja";
        }
    
    }
    
}
    else{
        echo "Wypelnij wszystkie pola";
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