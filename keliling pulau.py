def islandPerimeter(grid):
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4

                if row > 0 and grid[row-1][col] == 1:
                    perimeter -= 2

                if col > 0 and grid[row][col-1] == 1:
                    perimeter -= 2

    return perimeter

rows, cols = map(int, input().split())
grid = []
for i in range(rows):
    row = list(map(int, input().split()))
    grid.append(row)

print(islandPerimeter(grid))