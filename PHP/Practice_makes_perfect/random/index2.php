<!DOCTYPE html>
<html lang="en">
<head>
</head>
<body>
<link rel="stylesheet" href="style.css" type="text/css">
<h1>LOL</h1>
</body>
</html>
<?php 
$host = 'localhost';
$user = 'root';
$password = '';
$dbname = 'wedkowanie';
$conn = mysqli_connect($host,$user,$password,$dbname);
if(!$conn) { 
    exit("ERROR: Could not connect to DB");
}


else {
    echo "Connected successfully";
    $lol = mysqli_query($conn,'Select id,nazwa, wystepowanie FROM ryby WHERE styl_zycia = 2;');

    if (!$lol) {
        die("ERROR: Query failed. " . mysqli_error($conn));
    }

    echo "<ul>";

    while ($result = mysqli_fetch_array($lol)) {
        echo "<li>" . $result['id']."   " . $result['nazwa']. " " . $result['wystepowanie'] . " zl</li>";
    }

    echo "</ul>";
}

// Display in a table
echo "Tabela potegi:";
$conn = mysqli_connect($host,$user,$password,$dbname);
if (!$conn) {
    exit("Blad polaczenia");
}
else { 
    echo "Polaczenie poprawne";
}
$code = mysqli_query($conn,'Select id,nazwa, wystepowanie FROM ryby WHERE styl_zycia = 2;');
if(!$code) {
    die("Error: Query failed" . mysqli_error($conn));
}
echo "<table>";
while($result = mysqli_fetch_array($code)) {
    echo "<tr><td>" . $result['id'] . "</td><td>" . $result['nazwa'] . "</td><td>" . $result['wystepowanie'] . " zl </td></tr>";
}
echo "</table>";
mysqli_close($conn);
?>
