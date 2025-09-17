# Tournament Bracket Generator

A comprehensive C-based tournament management system that simulates single-elimination tournaments using binary tree data structures. This console application provides a complete tournament experience from player registration to champion declaration.

## Overview

The Tournament Bracket Generator is designed to handle competitive tournaments with automatic bracket generation, match simulation, and result tracking. The system uses a binary tree structure to represent the tournament bracket, where each node represents either a player or the winner of a match between two sub-brackets.

## Key Features

### Tournament Management

- **Dynamic Tournament Creation**: Supports tournaments with any power-of-2 number of players (4, 8, 16, 32, etc.)
- **Automatic Round Calculation**: Calculates the required number of rounds based on player count
- **Bracket Structure**: Uses binary tree implementation for efficient tournament representation

### Player Management

- **Player Registration**: Register multiple players with unique names
- **Player Search**: Search functionality to find specific players within the tournament bracket
- **Score Tracking**: Maintains individual player scores throughout the tournament

### Match System

- **Dual Mode Operation**:
  - **Manual Mode**: Allows manual score entry for each match
  - **Random Simulation**: Automatically generates random scores for quick tournament simulation
- **Match Logging**: Comprehensive logging of all matches with scores and winners
- **Progressive Rounds**: Supports standard tournament rounds (Quarterfinals, Semifinals, Finals)

### Visualization & Output

- **Bracket Display**: Visual representation of the tournament bracket structure
- **File Export**: Save tournament brackets to text files
- **Match Logging**: Detailed match history with scores and outcomes
- **Round Naming**: Automatic labeling of tournament rounds

## Technical Architecture

### Data Structures

- **Binary Tree**: Core tournament bracket representation
- **Node Structure**: Each node contains player name, score, and child pointers
- **Tournament Structure**: Manages overall tournament metadata

### Modular Design

The application follows a modular architecture with specialized components:

- **Tournament Core** (`tournament.c`): Tournament creation and management
- **Match Engine** (`match.c`): Match simulation and player node management
- **Bracket Display** (`bracket.c`): Tournament bracket visualization
- **Player System** (`player.c`): Player registration and search functionality
- **File I/O** (`fileio.c`): Bracket saving and match logging
- **Utilities** (`utils.c`): Round naming and helper functions

### File Outputs

- **`bracket.txt`**: Hierarchical tournament bracket structure
- **`tournament_log.txt`**: Chronological match results and scores

## Tournament Flow

The system manages tournaments through a complete lifecycle:

1. **Initialization**: Create tournament with specified player count
2. **Registration**: Register all participating players
3. **Execution**: Conduct matches round by round until a champion emerges
4. **Documentation**: Generate bracket files and match logs
5. **Analysis**: Search and review tournament results

## Technical Specifications

- **Language**: C (ANSI C compatible)
- **Memory Management**: Dynamic memory allocation for flexible tournament sizes
- **Data Persistence**: File-based output for tournament records
- **Platform**: Cross-platform console application
- **IDE Support**: Developed with Dev-C++ IDE configuration included

## Sample Tournament Structure

```
Champion (Score)
├── Semifinal Winner 1 (Score)
│   ├── Quarterfinal Winner A (Score)
│   │   ├── Player 1 (Score)
│   │   └── Player 2 (Score)
│   └── Quarterfinal Winner B (Score)
│       ├── Player 3 (Score)
│       └── Player 4 (Score)
└── Semifinal Winner 2 (Score)
    ├── Quarterfinal Winner C (Score)
    │   ├── Player 5 (Score)
    │   └── Player 6 (Score)
    └── Quarterfinal Winner D (Score)
        ├── Player 7 (Score)
        └── Player 8 (Score)
```

This tournament management system demonstrates practical application of data structures and algorithms in competitive gaming scenarios, providing both educational value and functional tournament organization capabilities.
