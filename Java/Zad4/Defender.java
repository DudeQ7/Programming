package Zad4;

public class Defender extends GameCharacter {
    private double defenseBonus;

    public Defender(String name, double attack, double defense, double energy, double defenseBonus) {
        super(name, attack, defense, energy);
        this.defenseBonus = defenseBonus;
    }

    @Override
    public double getTotalAttack() {
        return this.attack;
    }

    @Override
    public double getTotalDefense() {
        return this.defense * (1 + this.defenseBonus);
    }
}
