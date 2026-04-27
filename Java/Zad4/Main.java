package Zad4;

public class Main {
    public static void main(String[] args) {
        GameCharacter[] team1Characters = {
                new Attacker("Jan", 100, 100, 100, 0.2),
                new Attacker("Marta", 100, 100, 100, 0.2),
                new Defender("Krzyś", 100, 100, 100, 0.2)
        };

        GameCharacter[] team2Characters = {
                new Attacker("Mateusz", 100, 100, 100, 0.2),
                new Attacker("Maja", 100, 100, 100, 0.2),
                new Defender("Bartek", 100, 100, 100, 0.2)
        };

        Team team1 = new Team("Informatycy", team1Characters);
        Team team2 = new Team("Programiści", team2Characters);

        team1.attack(team2);
        team2.attack(team1);

        System.out.println("Energia drużyny 1 po bitwie: " + team1.getTotalEnergy());
        System.out.println("Energia drużyny 2 po bitwie: " + team2.getTotalEnergy());
    }
}
