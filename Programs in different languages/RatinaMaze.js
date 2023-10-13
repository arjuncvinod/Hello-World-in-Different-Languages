function solveMaze(maze) {
  const numRows = maze.length;
  const numCols = maze[0].length;

  const solution = Array(numRows).fill().map(() => Array(numCols).fill(0));

  function isSafe(x, y) {
    return x >= 0 && y >= 0 && x < numRows && y < numCols && maze[x][y] === 1;
  }

  function findPath(x, y) {
    if (x === numRows - 1 && y === numCols - 1) {
      solution[x][y] = 1;
      return true; // Reached the destination
    }

    if (isSafe(x, y)) {
      solution[x][y] = 1;

      // Move right
      if (findPath(x, y + 1)) {
        return true;
      }

      // Move down
      if (findPath(x + 1, y)) {
        return true;
      }

      // If no path found, backtrack
      solution[x][y] = 0;
      return false;
    }

    return false;
  }

  if (!findPath(0, 0)) {
    console.log("No path found.");
  } else {
    console.log("Solution:");
    console.log(solution);
  }
}

const maze = [
  [1, 0, 0, 0],
  [1, 1, 0, 1],
  [0, 1, 0, 0],
  [1, 1, 1, 1]
];

solveMaze(maze);
