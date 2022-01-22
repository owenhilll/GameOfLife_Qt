# GameOfLife_Qt
Simulating the game of life using Qt creator and c++. Each individual cell is color coded, pink for alive or white for dead. A user controlled slider determines how quickly the 'game' is simulated. Once this timer is set, each cell checks its neighboring cells, if there are 3 'alive neighboring cells and the current cell is dead, the cell becomes alive. If the cell is alive and has 3 or more nieghboring cells also alive, the cell dies. 