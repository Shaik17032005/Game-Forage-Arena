-- 1. Create the PLAYERS table
CREATE TABLE players (
    id VARCHAR(36) PRIMARY KEY,       -- A unique ID for every player (like our UUIDs)
    name VARCHAR(50) NOT NULL,        -- Player's name (up to 50 characters, cannot be empty)
    health INT NOT NULL,              -- Health points (Numbers)
    attack_power INT NOT NULL,        -- Attack damage (Numbers)
    score INT DEFAULT 0,              -- If we don't provide a score, it defaults to 0
    wins INT DEFAULT 0,               -- Defaults to 0 wins
    losses INT DEFAULT 0              -- Defaults to 0 losses
);

-- 2. Create the MATCHES table
CREATE TABLE matches (
    id SERIAL PRIMARY KEY,            -- SERIAL means the database will auto-count the ID (1, 2, 3...)
    player1_id VARCHAR(36) NOT NULL,  -- The ID of the first player
    player2_id VARCHAR(36) NOT NULL,  -- The ID of the second player
    winner_id VARCHAR(36) NOT NULL,   -- The ID of the winner
    played_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- Automatically records the exact time the match happened!

    -- FOREIGN KEYS: These rules tell the database that player1_id MUST match an 'id' that actually exists in the 'players' table!
    FOREIGN KEY (player1_id) REFERENCES players(id),
    FOREIGN KEY (player2_id) REFERENCES players(id),
    FOREIGN KEY (winner_id) REFERENCES players(id)
);
