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

body{
    font-family: Garamond;
}
.baner {
    background-color:saddlebrown;
    color:white;
    text-align: center;
    height: 50px;  
    vertical-align:top;
} 
.lewy {
    background-color: tan;
    height: 500px;
    width: 40%;
    float: left;
    vertical-align:top;
}
.prawy_1,.prawy_2{
    background-color: tan;
    height: 250px;
    width:60%;
    vertical-align: top;
    float: left;
}
.stopka {
    background-color: saddlebrown;
    color:white;
    width: 100%;
    float: left;
    vertical-align: top;
}
.form {
    background-color: saddlebrown;
    color: white;
    padding-top: 10px;
    padding-bottom:10px;
    padding-left: 30px;
    padding-right: 30px;
    width: 300px;
}
#login,#password,#password2,#test{
padding: 5px;
}
p::before{
    content: "Status:  ";
}

