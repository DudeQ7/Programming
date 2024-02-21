class Course {
    public String id;
    public double price;
    public String title;
    public String description;
    public void displayInfo() {
        System.out.println("Identyfikator: " + id);
        System.out.println("Informacje o kursie: " + title);
        System.out.println("Opis: " + description);
        System.out.println("Cena: " + price + "zł");
    }
}

class OnlineCourse extends Course {
    public int videoLength;
    public int timeToFinish;

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Czas filmów w kursie: " + videoLength + "min");
        System.out.println("Czas potrzebny na przerobienie: " + timeToFinish + "min");
    }
}

class OfflineCourse extends Course {
    public String city;
    public int numberOfLessons;

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Miasto: " + city);
        System.out.println("Liczba spotkań: " + numberOfLessons);
        System.out.println("---------------------------------");
    }
}

class BootcampOnline extends OnlineCourse {
    public String teacher;
    public int consultationHours;

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Prowadzący: " + teacher);
        System.out.println("Konsultacje: " + consultationHours + " godzin");
    }
}

 public class main {
    public static void main(String[] args) {
        OnlineCourse onlineCourse = new OnlineCourse();
        onlineCourse.id = "KursJavaOnline1";
        onlineCourse.title = "Najlepszy kurs online";
        onlineCourse.description = "Taki kurs online, że lepszego nie ma";
        onlineCourse.price = 9.99;
        onlineCourse.videoLength = 45;
        onlineCourse.timeToFinish = 6075;
        onlineCourse.displayInfo();

        OfflineCourse offlineCourse = new OfflineCourse();
        offlineCourse.id = "KursJavaOffline1";
        offlineCourse.title = "Najlepszy kurs offline";
        offlineCourse.description = "Taki kurs offline, że lepszego nie ma";
        offlineCourse.price = 0.99;
        offlineCourse.city = "Szczecin";
        offlineCourse.numberOfLessons = 3;
        offlineCourse.displayInfo();

        BootcampOnline bootcampOnline = new BootcampOnline();
        bootcampOnline.id = "KursJavaBootcamp1";
        bootcampOnline.title = "Najlepszy bootcamp";
        bootcampOnline.description = "Taki bootcamp, że lepszego nie ma";
        bootcampOnline.price = 4.99;
        bootcampOnline.videoLength = 300;
        bootcampOnline.timeToFinish = 1000;
        bootcampOnline.teacher = "Jan Kowalski";
        bootcampOnline.consultationHours = 10;
        bootcampOnline.displayInfo();
    }
}
