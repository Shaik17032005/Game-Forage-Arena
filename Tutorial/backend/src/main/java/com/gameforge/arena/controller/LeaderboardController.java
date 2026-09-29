package com.gameforge.arena.controller;

import com.gameforge.arena.model.Player;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/leaderboard")
public class LeaderboardController {

    @Autowired
    private PlayerController playerController;

    @GetMapping
    public List<Player> getLeaderboard() {
        // 1. Get the list of all players
        List<Player> allPlayers = playerController.getAllPlayers();
        
        // 2. Make a copy so we don't ruin the original list
        List<Player> sortedList = new ArrayList<>(allPlayers);
        
        // 3. Sort them using a Lambda Expression (Java's version of our custom rule)
        sortedList.sort((p1, p2) -> Integer.compare(p2.getScore(), p1.getScore()));
        
        // 4. Return the sorted list (Spring converts it to JSON!)
        return sortedList;
    }
}
