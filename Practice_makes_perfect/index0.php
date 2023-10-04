


<?php
$con = mysqli_connect('localhost', 'root', '', 'db1');
$query = 'SELECT marka FROM pojazd';
$que = mysqli_query($con, $query);
echo "<table>";
$il = mysqli_num_rows($que);
while ($result = mysqli_fetch_array($que)) {
    for ($i = 0; $i<$il; $i++) {
    echo "<tr>"."<td>".$result['marka']."</td>"."</tr>"; //$result[1]. $result[2] .
}}
echo "</table>";
mysqli_close($con);

?>

