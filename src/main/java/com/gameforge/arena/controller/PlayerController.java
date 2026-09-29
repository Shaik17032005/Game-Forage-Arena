package com.gameforge.arena.controller;

import org.springframework.web.bind.annotation.*;
import java.util.UUID;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@RestController
@RequestMapping("/api/players")
public class PlayerController {

    private final Map<String, String> players = new ConcurrentHashMap<>();

    @PostMapping("/register")
    public String registerPlayer(@RequestParam String username) {
        String playerId = UUID.randomUUID().toString();
        players.put(playerId, username);
        return "Player registered successfully. ID: " + playerId;
    }

    @GetMapping("/{playerId}")
    public String getPlayer(@PathVariable String playerId) {
        return players.getOrDefault(playerId, "Player not found");
    }
}
