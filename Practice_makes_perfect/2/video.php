<?php
$conn = mysqli_connect('localhost', 'root', '', 'db14');

if (!$conn) {
    die("Błąd połączenia z bazą danych: " . mysqli_connect_error());
}

$query = "SELECT id, nazwa, opis, zdjecie FROM produkty WHERE id IN (18, 22, 23, 25);";
$potega = mysqli_query($conn, $query);
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="utf-8" />
    <title>Video On Demand</title>
    <link rel="stylesheet" href="styl3.css" type="text/css">
</head>    
<body>
<div class="baner_lewy">
    <h1>Internetowa wypożyczalnia filmów</h1>
</div>

<div class="baner_prawy">
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
</div>

<div class="lista_polecamy">
    <h3>Polecamy</h3>
    echo "<img src="";
    <?php
    $zmienna_testowa = "film";
    while ($hogwart = mysqli_fetch_array($potega)) {
        echo "<div class='$zmienna_testowa'>";
        echo "<h4>" . $hogwart['id'] . $hogwart['nazwa'] . "</h4>";
        echo "<img src='" . $hogwart['zdjecie'] . "' alt='filmy'>";
        echo "<p>" . $hogwart['opis'] . "</p>";
        echo "</div>";
    }
    mysqli_close($conn);
    ?>
</div> 

<div class="Filmy_fantastyczne">
    <h3>Filmy fantastyczne</h3>
    <?php 
    $conn_2 = mysqli_connect('localhost', 'root', '', 'db12');

    if (!$conn_2) {
        die("Błąd połączenia z bazą danych: " . mysqli_connect_error());
    }

    $query_2 = "SELECT id, nazwa, opis, zdjecie FROM produkty WHERE Rodzaje_id = 12;";
    $potega_2 = mysqli_query($conn_2, $query_2);
    while ($moc = mysqli_fetch_array($potega_2)) {
        $zmienna = "film";
        echo "<div class='$zmienna'>";
        echo "<h4>" . $moc['id'] . $moc['nazwa'] . "</h4>";
        echo "<img src='" . $moc['zdjecie'] . "' alt='filmy'>";
        echo "<p>" . $moc['opis'] . "</p>";
        echo "</div>";
    }
    mysqli_close($conn_2);
    ?>
</div>

<footer>
    <form method="post" name="lol">
        Usuń film nr:<input type="number" name="usun">
        <input type="submit" name="wyslij" value="Usuń film">
        <?php
        if (isset($_POST['wyslij'])) {
            $name = $_POST['usun'];
            $conn_3 = mysqli_connect('localhost', 'root', '', 'dane3');

            if (!$conn_3) {
                die("Błąd połączenia z bazą danych: " . mysqli_connect_error());
            }

            $query_3 = "DELETE FROM produkty WHERE id = $name";
            $ultimate = mysqli_query($conn_3, $query_3);
            
            if ($ultimate) {
                echo "Usunięto wiersz z id równym " . $name;
            } else {
                echo "Wystąpił błąd podczas usuwania wiersza.";
            }

            mysqli_close($conn_3);
        } else {
            echo "Formularz jest pusty";
        }
        ?>
    </form>

    Stronę wykonał: <a href="mailto:wow@gmail.com">Michał Chojnowski</a>
    </footer>
</body>
</html>
