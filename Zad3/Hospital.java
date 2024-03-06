package Zad3;
public class Hospital {
    private  Doctor[] doctors;
    private Nurse[] nurses;
    private  int d_count;
    private int n_count;
    public Hospital(){
        doctors = new Doctor[5]; //zakladamy ze jest 5 doktorow
        nurses = new Nurse[5]; //zakladamy ze jest 5 pielegniarek
        d_count = 0;
        n_count = 0;
    }
    public void  addDoctor(Doctor doctor){
        doctors[d_count++] = doctor;
    }
    public void  addNurse(Nurse nurse){
        nurses[n_count++] = nurse;
    }
    public String getDoctorsInfo() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < d_count; i++) {
            result.append(doctors[i].toString()).append("\n");
        }
        return result.toString();
    }

    public String getNursesInfo() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n_count; i++) {
            result.append(nurses[i].toString()).append("\n");
        }
        return result.toString();
    }
}
