package Zad3;

public class HospitalApp {
    public static void main(String[] args) {
        Hospital hospital = new Hospital();
        Doctor doctor = new Doctor("Kacper", "Profesor", 7500.0, 1300.0);
        Nurse nurse1 = new Nurse("Radek", "Kowalski", 5900.0, 800.0);
        Nurse nurse2 = new Nurse("Ola", "Dobra", 2200.0, 6.0);
        Nurse nurse3 = new Nurse("Maria", "Pigula", 2100.0, 3.0);
        hospital.addDoctor(doctor);
        hospital.addNurse(nurse1);
        hospital.addNurse(nurse2);
        hospital.addNurse(nurse3);
        System.out.println("Doctors:\n" + hospital.getDoctorsInfo());
        System.out.println("Nurses:\n" + hospital.getNursesInfo());
    }
}
