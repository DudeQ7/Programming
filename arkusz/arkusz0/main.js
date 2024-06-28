function zamow(id){
var shop = document.getElementsByClassName("zamow");
var zmienna_2 = 0 ; 
for(i=0; i< shop.length; i++){
    if(id==shop[i]){
        zmienna_2 = 1 
    }

}
numer = zmienna_2 + 1 ;
ilosc = document.getElementById("tabelka").rows[nr].cells[2].innerText;
document.getElementById("tabelka").rows[nr].cells[2].innerHTML = parseInt(ilosc)+ 1
nazwa = document.getElementById("tabelka").rows[nr].cells[0].innerText;
alert("Zamowienie nr: " + nr + " Produkt " + nazwa)
braki()
}
function aktualizuj(id){
    nowa = prompt("Podaj nową ilość produktu: ") ;
    var update = document.getElementsByClassName("aktualizuj");
  
    var zmienna = 0 ; 
    for (i = 0 ; i< update.length ; i++){
        if(id == update[i]){
            zmienna = i ; 
        }
    }
    document.getElementById("tabelka").rows[zmienna+1].cells[2].innerHTML = nowa ; 
    braki()
}
function braki(){
    const tabelka = document.getElementById("tabelka");
    wiersze = document.getElementById("tabelka").rows[0].cells.length;
    for(i = 1; i<=wiersze; i++){
        ilosc = tabelka.rows[i].cells[2].innerText;
        if (ilosc == 0 ){
            console.log("babaG");
            tabelka.rows[i].cells[2].style.backgroundColor = "red";
        }
        else if (ilosc >0 && ilosc <= 5 ){
            tabelka.rows[i].cells[2].style.backgroundColor = "yellow";
        }
        else {
            tabelka.rows[i].cells[2].style.backgroundColor = "honeydew";
        }
    }
}