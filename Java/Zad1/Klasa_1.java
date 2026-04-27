package Zad1;

public class Klasa_1 {
    public static void main(String[] args) {
        Tire opona = new Tire();
        opona.setId(123);
        opona.setProducent("SuperTire");
        opona.setModel("ProContact");
        opona.setSeria("Winter pro");
        opona.setRozmiar(17);
        opona.setSzerokosc(225.0);

        ExhaustPart wydech = new ExhaustPart();
        wydech.setId(987);
        wydech.setProducent("Noisy Parts");
        wydech.setModel("Turbo Brum");
        wydech.setSeria("Noisy Exhaust");
        wydech.setStandard(true);

        System.out.println("Opona. Numer seryjny: " + opona.getId() + ", Producent: " + opona.getProducent() +
                ", Model: " + opona.getModel() + ", Seria: " + opona.getSeria() + ", Rozmiar: " +
                opona.getRozmiar() + ", Szerokość: " + opona.getSzerokosc());

        System.out.println("Wydech. Numer seryjny: " + wydech.getId() + ", Producent: " + wydech.getProducent() +
                ", Model: " + wydech.getModel() + ", Seria: " + wydech.getSeria() + ", EURO: " + wydech.isStandard());
    }
}
