package com.gameforge.arena.model;

import java.util.UUID;

// This is the Java version of our C++ Player class!
public class Player {
    private String id;
    private String name;
    private int health;
    private int attackPower;
    private int score;
    private int wins;
    private int losses;

    // Constructor
    public Player(String name, int health, int attackPower) {
        // We use UUID to generate a unique random ID for every player, like "f47ac10b-58cc-4372-a567-0e02b2c3d479"
        this.id = UUID.randomUUID().toString();
        this.name = name;
        this.health = health;
        this.attackPower = attackPower;
        this.score = 0;
        this.wins = 0;
        this.losses = 0;
    }

    // --- Getters (Required by Spring Boot to automatically convert to JSON) ---
    public String getId() { return id; }
    public String getName() { return name; }
    public int getHealth() { return health; }
    public int getAttackPower() { return attackPower; }
    public int getScore() { return score; }
    public int getWins() { return wins; }
    public int getLosses() { return losses; }

    // --- Setters / Actions ---
    public void addWin() {
        this.wins++;
        this.score += 50;
    }
    
    public void addLoss() {
        this.losses++;
    }
}
