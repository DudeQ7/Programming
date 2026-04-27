package Zad4;

public class Attacker extends GameCharacter {
    private double attackBonus;

    public Attacker(String name, double attack, double defense, double energy, double attackBonus) {
        super(name, attack, defense, energy);
        this.attackBonus = attackBonus;
    }

    @Override
    public double getTotalAttack() {
        return this.attack * (1 + this.attackBonus);
    }

    @Override
    public double getTotalDefense() {
        return this.defense;
    }
}
