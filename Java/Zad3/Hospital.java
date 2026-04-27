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

    public Doctor[] getDoctors() {
        return doctors;
    }

    public void setDoctors(Doctor[] doctors) {
        this.doctors = doctors;
    }

    public Nurse[] getNurses() {
        return nurses;
    }

    public void setNurses(Nurse[] nurses) {
        this.nurses = nurses;
    }

    public int getD_count() {
        return d_count;
    }

    public void setD_count(int d_count) {
        this.d_count = d_count;
    }

    public int getN_count() {
        return n_count;
    }

    public void setN_count(int n_count) {
        this.n_count = n_count;
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
