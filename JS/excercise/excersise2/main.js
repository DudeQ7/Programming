let firstname  = "Michal";
let lastname = "plaszczak";
let age =21;
let student = true;
age += 1;
console.log("Hello:",firstname);//jak w pythonie
console.log(lastname);
console.log("You are this level of starosc:",age);
console.log("Student:",student);
document.getElementById("p1").innerHTML = "Hello " + firstname;
document.getElementById("p2").innerHTML = "You are: " + age + "old";
document.getElementById("p3").innerHTML = "Enrolled: " + student