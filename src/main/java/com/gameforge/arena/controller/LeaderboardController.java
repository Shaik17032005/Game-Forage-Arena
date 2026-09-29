package com.gameforge.arena.controller;

import org.springframework.web.bind.annotation.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/api/leaderboards")
public class LeaderboardController {

    // Simple in-memory storage for demonstration purposes
    private final Map<String, Integer> playerScores = new ConcurrentHashMap<>();

    @PostMapping("/{playerId}/score")
    public String updateScore(@PathVariable String playerId, @RequestParam int scoreDelta) {
        int newScore = playerScores.merge(playerId, scoreDelta, Integer::sum);
        return "Score updated. New score for " + playerId + ": " + newScore;
    }

    @GetMapping("/top")
    public List<Map.Entry<String, Integer>> getTopPlayers(@RequestParam(defaultValue = "10") int limit) {
        return playerScores.entrySet().stream()
                .sorted((e1, e2) -> e2.getValue().compareTo(e1.getValue()))
                .limit(limit)
                .collect(Collectors.toList());
    }
}
