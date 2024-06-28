<html>
<body>
<form method="post">
    <label><b>Podaj liczby w przedziale od 1 do 49</b></label> <br>
    <?php
    for ($i = 1; $i <= 6; $i++) {
        echo '<input type="number" name="numbers[]" placeholder="Liczba od 1 do 49"> <br>';
    }
    ?>
    <label><b>Liczba losowań:</b></label> <br>
    <input type="number" name="numDraws" placeholder="Liczba losowań"> <br>
    <input type="submit" name="submit" value="Submit">
    <input type="submit" name="randomNumbers" value="Losowe liczby">
</form>

<?php
if (isset($_POST['submit']) || isset($_POST['randomNumbers'])) {
    $numbers = array();

    if (isset($_POST['numbers'])) {
        $numbers = $_POST['numbers'];
    } elseif (isset($_POST['randomNumbers'])) {
        for ($i = 1; $i <= 6; $i++) {
            $numbers[] = rand(1, 49);
        }
    }

    $numDraws = isset($_POST['numDraws']) ? $_POST['numDraws'] : 1000; // Liczba losowań do wykonania

    $correctNumbersArray = array(); // Tablica przechowująca wyniki dla każdego losowania
    $drawsWithCorrectNumbers = array(); // Tablica przechowująca numery losowań, w których były poprawne liczby

    for ($i = 1; $i <= $numDraws; $i++) {
        $drawNumbers = array();
        for ($j = 1; $j <= 6; $j++) {
            $drawNumbers[] = rand(1, 49);
        }

        $correctNumbers = count(array_intersect($numbers, $drawNumbers));
        $correctNumbersArray[] = $correctNumbers;

        if ($correctNumbers >= 3) {
            $drawsWithCorrectNumbers[] = $i;
        }
    }

    // Przekierowanie do strony z wynikami
    $queryString = http_build_query(array(
        'draws' => $numDraws,
        'numbers' => implode(",", $numbers),
        'correctNumbers' => implode(",", $correctNumbersArray),
        'drawsWithCorrectNumbers' => implode(",", $drawsWithCorrectNumbers)
    ));
    header("Location: wyniki.php?" . $queryString);
    exit();
}
?>
</body>
</html>
