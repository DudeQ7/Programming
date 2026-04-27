var body = document.getElementById('body');
var indigoButton = document.getElementById('indigo');
var steelButton = document.getElementById('steel');
var oliveButton = document.getElementById('olive');
var textElements = document.querySelectorAll('body, p, span, div, h1, h2, h3, h4, h5, h6');

function indigo() {
    body.style.backgroundColor = "indigo";
}

function steel() {
    body.style.backgroundColor = "Steelblue";
}

function olive() {
    body.style.backgroundColor = "olive";
}

function tester() {
    var selectedColor = document.getElementById('selekcja').value;
    textElements.forEach(function (element) {
        if (selectedColor === document.getElementById('white').value) {
            element.style.color = "white";
        } else if (selectedColor === document.getElementById('tan').value) {
            element.style.color = "tan";
        } else if (selectedColor === document.getElementById('bisque').value) {
            element.style.color = "bisque";
        } else if (selectedColor === document.getElementById('plum').value) {
            element.style.color = "plum";
        }
    });
}
function rozmiar() {
    var rozmiarValue = document.getElementById("rozmiar").value;
    textElements.forEach(function (element) {
        element.style.fontSize = rozmiarValue + "%";
    });
}
function punktor(){
    var punktordysk = document.getElementById("dysk");
    var punktordysk2 = document.getElementById("kwadrat");
    var modyfikuj = document.getElementById("lista");
    if(punktordysk.checked){
           modyfikuj.style.listStyleType ="disc";
    }
    else if(punktordysk2.checked){
        modyfikuj.style.listStyleType ="square";
    }
    else{
        modyfikuj.style.listStyleType ="circle";
    }
}
function border() {
    var zdjecie = document.getElementById("zdjecik");
    if (document.getElementById("borderik").checked) {
        zdjecie.style.border = "1px solid white";
    } else {
        zdjecie.style.border = "none";
    }
}
