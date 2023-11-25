<div class="main">
    <div class="but">
    <?php
    $conn=mysqli_connect('localhost','root','','nartopolis');
    mysqli_set_charset($conn, 'utf8');
    $pyt=mysqli_query($conn, 'SELECT buty.rozmiar, buty.nazwafoto, buty.flex, buty.cena, buty.kolor, buty.model, buty.rodzaj, marka.marka FROM buty INNER JOIN marka ON buty.id_marki = marka.id');
    echo "<table>";
    while($res=mysqli_fetch_array($pyt)){
    echo "<h2>".$res['marka']."  |  ".$res['model']."</h2>".
    "<img src=".$res['nazwafoto'].">".
    "<p>Rozmiar: ".$res['rozmiar']." cm"."<br>".
    "Flex: ".$res['flex']."<br>".
    "Kolor: ".$res['kolor']."<br>".
    "Płeć: ".$res['rodzaj']."<br>".
    "Cena: ".$res['cena']." zł"
    ."</p>"."<br>"."</th>"; 
    }
    echo "</table>";
    mysqli_close($conn);
    ?>
</div>