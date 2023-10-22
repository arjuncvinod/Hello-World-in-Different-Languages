import random

# Define constants
GRID_SIZE = 10
NUM_BOMBS = 10

# Create the grid
grid = [[0 for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

# Place bombs randomly
bombs = random.sample(range(GRID_SIZE * GRID_SIZE), NUM_BOMBS)
for bomb in bombs:
    row = bomb // GRID_SIZE
    col = bomb % GRID_SIZE
    grid[row][col] = -1

# Calculate the number of adjacent bombs for each cell
for row in range(GRID_SIZE):
    for col in range(GRID_SIZE):
        if grid[row][col] == -1:
            continue
        count = 0
        for i in range(max(0, row - 1), min(GRID_SIZE, row + 2)):
            for j in range(max(0, col - 1), min(GRID_SIZE, col + 2)):
                if grid[i][j] == -1:
                    count += 1
        grid[row][col] = count

# Define a function to display the grid
def display_grid():
    for row in grid:
        print(' '.join(str(cell) for cell in row))

# Play the game
while True:
    display_grid()
    row = int(input('Enter row: '))
    col = int(input('Enter column: '))
    if grid[row][col] == -1:
        print('Game over!')
        break
    elif grid[row][col] == 0:
        print('No bombs nearby')
    else:
        print(f'{grid[row][col]} bombs nearby')
    grid[row][col] = -2
    if all(all(cell < 0 for cell in row) for row in grid):
        print('You win!')
        break