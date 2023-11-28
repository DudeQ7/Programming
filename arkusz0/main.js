const iloscProduktow = document.querySelectorAll('.ilosc');
const nazwaProduktow = document.querySelectorAll('.produkt');
const aktualizuj = document.querySelectorAll('.aktualizuj');
const zamow = document.querySelectorAll('.zamow');
var id_zamow = 0;

function sprawdz() {
    iloscProduktow.forEach((produkt) => {
        if (produkt.innerHTML == 0) {
            produkt.style.backgroundColor = 'red';
        } if(produkt.innerHTML >= 1 && produkt.innerHTML <= 5) {
            produkt.style.backgroundColor = 'yellow';
        } if(produkt.innerHTML >= 5) {
            produkt.style.backgroundColor = 'honeydew';
        }
    });
}

aktualizuj.forEach((przycisk, i) => {
    przycisk.addEventListener('click', () => {
        var nowailosc = prompt('Podaj nową ilość: ');
        iloscProduktow[i].innerHTML = nowailosc;
        sprawdz();
    });
});

zamow.forEach((przycisk, i) => {
    przycisk.addEventListener('click', () => {
        alert('Zamówienie nr: ' + id_zamow + ' Produkt: ' + nazwaProduktow[i].innerHTML);
        id_zamow++;
    });
});

sprawdz();
