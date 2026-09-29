package com.gameforge.arena.controller;

import com.gameforge.arena.service.MatchmakingService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/matchmaking")
public class MatchmakingController {

    private final MatchmakingService matchmakingService;

    @Autowired
    public MatchmakingController(MatchmakingService matchmakingService) {
        this.matchmakingService = matchmakingService;
    }

    @PostMapping("/queue")
    public String queuePlayer(@RequestParam String playerId, @RequestParam(defaultValue = "1000") int rating) {
        matchmakingService.queuePlayer(playerId, rating);
        return "Player " + playerId + " added to matchmaking queue.";
    }

    @GetMapping("/status")
    public String getStatus() {
        return "Players currently in queue: " + matchmakingService.getQueueSize();
    }
}
