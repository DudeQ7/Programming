var indigo = document.getElementById('indigo').onclick ;
var steel = document.getElementById('steel').onclick ;
var olive = document.getElementById('olive').onclick ;
var textElements = document.querySelectorAll('body, p, span, div, h1, h2, h3, h4, h5, h6');


function indigo(){
    body.style.backgroundColor = "indigo";
}
function steel(){
    body.style.backgroundColor = "Steelblue";
}
function olive(){
    body.style.backgroundColor = "olive";

}
function tester() {
    var selectedColor = document.getElementById('selekcja').value;
    var textElements = document.querySelectorAll('body, p, span, div, h1, h2, h3, h4, h5, h6');

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
