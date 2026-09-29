import React, { useState, useEffect } from 'react';

// This is a simple React Component representing our 'Players' page
function PlayersPage() {
  
  // 1. State: This holds our data. When it changes, React automatically updates the screen!
  const [playersList, setPlayersList] = useState([]);
  const [loading, setLoading] = useState(true);

  // 2. useEffect: This runs code automatically when the page first loads
  useEffect(() => {
    
    // We use 'fetch' to call our Java Spring Boot API!
    fetch('http://localhost:8080/players')
      .then(response => response.json()) // Convert the response to JSON
      .then(data => {
        setPlayersList(data); // Save the players into our State
        setLoading(false);    // Turn off the loading screen
      })
      .catch(error => {
        console.error("Error fetching players:", error);
      });

  }, []); // The empty brackets mean "Only run this once when the page loads"

  // 3. What the user actually sees (JSX - HTML mixed with JavaScript)
  return (
    <div style={{ padding: '20px' }}>
      <h1>GameForge Arena - Players</h1>
      
      {loading ? (
        <p>Loading players from server...</p>
      ) : (
        <table border="1" cellPadding="10">
          <thead>
            <tr>
              <th>Name</th>
              <th>Health</th>
              <th>Attack</th>
              <th>Score</th>
            </tr>
          </thead>
          <tbody>
            {/* We 'map' (loop) over our list and create an HTML row for every player */}
            {playersList.map(player => (
              <tr key={player.id}>
                <td>{player.name}</td>
                <td>{player.health}</td>
                <td>{player.attackPower}</td>
                <td>{player.score}</td>
              </tr>
            ))}
          </tbody>
        </table>
      )}
    </div>
  );
}

export default PlayersPage;
