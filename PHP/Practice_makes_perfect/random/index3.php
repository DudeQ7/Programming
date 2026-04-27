<html>
<body>
<?php
if (isset($_GET['draws']) && isset($_GET['correctNumbers']) && isset($_GET['drawsWithCorrectNumbers'])) {
    $numDraws = $_GET['draws'];
    $correctNumbersArray = explode(",", $_GET['correctNumbers']);
    $drawsWithCorrectNumbers = explode(",", $_GET['drawsWithCorrectNumbers']);

    echo "<h2>Wyniki losowań:</h2>";

    for ($i = 0; $i < $numDraws; $i++) {
        echo "Losowanie " . ($i + 1) . " - Liczba poprawnych liczb: " . $correctNumbersArray[$i] . "<br>";
    }

    echo "<h2>Numery losowań z co najmniej 3 poprawnymi liczbami:</h2>";

    foreach ($drawsWithCorrectNumbers as $drawNumber) {
        echo "Losowanie " . $drawNumber . "<br>";
    }
} else {
    echo "Brak wyników do wyświetlenia.";
}
?>
</body>
</html>
