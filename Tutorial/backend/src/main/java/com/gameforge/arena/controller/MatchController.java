package com.gameforge.arena.controller;

import com.gameforge.arena.model.Player;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/matches")
public class MatchController {

    // We need to access the players list from the PlayerController
    // @Autowired tells Spring: "Please link this automatically for me!"
    @Autowired
    private PlayerController playerController;

    private List<String> matchHistory = new ArrayList<>();

    // GET /matches -> View all past matches
    @GetMapping
    public List<String> getMatchHistory() {
        return matchHistory;
    }

    // POST /matches -> Start a battle!
    // Example URL: /matches?player1Id=abc-123&player2Id=xyz-987
    @PostMapping
    public String startMatch(@RequestParam String player1Id, @RequestParam String player2Id) {
        // 1. Get both players
        Player p1 = playerController.getPlayerById(player1Id);
        Player p2 = playerController.getPlayerById(player2Id);

        // Check if either player doesn't exist
        if (p1 == null || p2 == null) {
            return "Error: One or both players not found.";
        }

        // 2. Simple Battle Logic (We calculate who wins instantly in the backend)
        // For our API, let's just make the player with higher health + attack win!
        int p1Strength = p1.getHealth() + p1.getAttackPower();
        int p2Strength = p2.getHealth() + p2.getAttackPower();

        String result;
        if (p1Strength >= p2Strength) {
            p1.addWin();
            p2.addLoss();
            result = p1.getName() + " defeats " + p2.getName() + "!";
        } else {
            p2.addWin();
            p1.addLoss();
            result = p2.getName() + " defeats " + p1.getName() + "!";
        }

        // 3. Save to history and return result
        matchHistory.add(result);
        return result;
    }
}
