package Zad5;
public class Hospital {
    private Person[] employees;
    private int count;

    public Hospital() {
        employees = new Person[5];
        count = 0;

    }

    public void add(Person person) {
        if (count < employees.length){
            employees[count] = person;
            count++;
        }
     else{
            System.out.println("Nie mozesz miec wiecej niz 5 pracownikow :( ");
        }
    }

    public String getInfo() {
        StringBuilder info = new StringBuilder("Pracownicy szpitala:\n");
        for (int i = 0; i < count; i++) {
            Person employee = employees[i];
            info.append("Imię: ").append(employee.getFirstName())
                    .append(", Nazwisko: ").append(employee.getLastName())
                    .append(", Wypłata: ").append(employee.getSalary());
            if (employee instanceof Doctor) {
                info.append(", Premia: ").append(((Doctor) employee).getBonus());
            } else if (employee instanceof Nurse) {
                info.append(", Nadgodziny: ").append(((Nurse) employee).getOvertime());
            }
            info.append("\n");
        }
        return info.toString();
    }
}
