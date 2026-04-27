package Zad4;

public class Team {
    private String name;
    private GameCharacter[] characters;

    public Team(String name, GameCharacter[] characters) {
        this.name = name;
        this.characters = characters;
    }

    public double getTotalAttack() {
        double totalAttack = 0;
        for (GameCharacter character : characters) {
            totalAttack += character.getTotalAttack();
        }
        return totalAttack;
    }

    public double getTotalDefense() {
        double totalDefense = 0;
        for (GameCharacter character : characters) {
            totalDefense += character.getTotalDefense();
        }
        return totalDefense;
    }

    public double getTotalEnergy() {
        double totalEnergy = 0;
        for (GameCharacter character : characters) {
            totalEnergy += character.getEnergy();
        }
        return totalEnergy;
    }

    public void attack(Team other) {
        double attackDifference = this.getTotalAttack() - other.getTotalDefense();
        if (attackDifference > 0) {
            double newEnergy = other.getTotalEnergy() - attackDifference;
            for (GameCharacter character : other.characters) {
                character.setEnergy(newEnergy / 3);
            }
        }
    }
}
