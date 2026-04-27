package Zad4;

public abstract class GameCharacter {
    protected String name;
    protected double attack;
    protected double defense;
    protected double energy;

    public GameCharacter(String name, double attack, double defense, double energy) {
        this.name = name;
        this.attack = attack;
        this.defense = defense;
        this.energy = energy;
    }

    public abstract double getTotalAttack();
    public abstract double getTotalDefense();

    public double getEnergy() {
        return energy;
    }

    public void setEnergy(double energy) {
        this.energy = energy;
    }
}
