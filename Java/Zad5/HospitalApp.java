package Zad5;

public class HospitalApp {
    public static void main(String[] args) {
        Hospital hospital = new Hospital();

        Doctor doctor = new Doctor("Kacper", "Profesor", 7500.0, 1300.0);
        Nurse nurse1 = new Nurse("Radek", "Kowalski", 5900.0, 800.0);
        Nurse nurse2 = new Nurse("Ola", "Dobra", 2200.0, 6.0);
        Nurse nurse3 = new Nurse("Maria", "Piguła",2100.0,3.0);
        Nurse nurse4 = new Nurse("Maria2", "Piguła",2100.0,3.0);
        Nurse nurse5 = new Nurse("Maria3", "Piguła",2100.0,3.0);
        Nurse nurse6 = new Nurse("Maria4", "Piguła",2100.0,3.0);

        hospital.add(doctor);
        hospital.add(nurse1);
        hospital.add(nurse2);
        hospital.add(nurse3);
        hospital.add(nurse4);
        hospital.add(nurse5);
        hospital.add(nurse6);
// dziala :)
        System.out.println(hospital.getInfo());
    }
}
