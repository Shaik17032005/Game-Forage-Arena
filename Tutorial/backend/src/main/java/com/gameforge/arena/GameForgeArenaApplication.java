package com.gameforge.arena;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

// This annotation tells Java that this is the starting point of our Web Server!
@SpringBootApplication
public class GameForgeArenaApplication {

	public static void main(String[] args) {
		SpringApplication.run(GameForgeArenaApplication.class, args);
		System.out.println("Spring Boot Server is running!");
	}

}
