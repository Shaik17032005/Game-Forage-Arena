package com.gameforge.arena.controller;

import com.gameforge.arena.model.Player;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

// @RestController tells Spring Boot: "This class handles web requests!"
@RestController
@RequestMapping("/players") // All URLs in this file will start with /players
public class PlayerController {

    // This is our list of players (just like std::vector in C++)
    // We store it in memory for now until we learn Databases in Phase 9
    private List<Player> playersList = new ArrayList<>();

    // 1. GET /players -> Returns all players
    // @GetMapping tells Spring to trigger this function when someone visits /players
    @GetMapping
    public List<Player> getAllPlayers() {
        return playersList; // Spring automatically converts this list into JSON format for us!
    }

    // 2. POST /players -> Creates a new player
    // @PostMapping triggers when someone sends data to /players
    // @RequestParam grabs the data they sent in the URL (e.g., /players?name=Imran&hp=100&attack=20)
    @PostMapping
    public Player createPlayer(
            @RequestParam String name, 
            @RequestParam int hp, 
            @RequestParam int attack) {
        
        // Create the new player
        Player newPlayer = new Player(name, hp, attack);
        
        // Add them to our list
        playersList.add(newPlayer);
        
        // Return the created player so the user can see their new unique ID
        return newPlayer; 
    }

    // 3. GET /players/{id} -> Returns a specific player by their ID
    // @PathVariable grabs the {id} directly from the URL path (e.g. /players/f47ac10b...)
    @GetMapping("/{id}")
    public Player getPlayerById(@PathVariable String id) {
        // Loop through our list to find the matching ID
        for (Player p : playersList) {
            if (p.getId().equals(id)) {
                return p; // Found them!
            }
        }
        return null; // Player not found
    }
}
