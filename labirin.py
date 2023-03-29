from collections import deque

n, m = map(int, input().split())
maze = [list(input()) for _ in range(n)]

start = None
end = None
for i in range(n):
    for j in range(m):
        if maze[i][j] == 'A':
            start = (i, j)
        elif maze[i][j] == 'B':
            end = (i, j)

def bfs(maze, start, end):
    queue = deque([start])
    visited = set()
    directions = {'D': (1, 0), 'U': (-1, 0), 'R': (0, 1), 'L': (0, -1)}
    came_from = {}

    while queue:
        current = queue.popleft()
        if current == end:
            return came_from

        for direction, (dx, dy) in directions.items():
            next_pos = (current[0] + dx, current[1] + dy)
            if (
                0 <= next_pos[0] < n and
                0 <= next_pos[1] < m and
                maze[next_pos[0]][next_pos[1]] != '#' and
                next_pos not in visited
            ):
                queue.append(next_pos)
                visited.add(next_pos)
                came_from[next_pos] = (current, direction)

    return None

def reconstruct_path(came_from, start, end):
    current = end
    path = []
    while current != start:
        current, direction = came_from[current]
        path.append(direction)
    path.reverse()
    return path

came_from = bfs(maze, start, end)
if came_from is None:
    print('Tidak')
else:
    path = reconstruct_path(came_from, start, end)
    print('Ya')
    print(len(path))
    print(''.join(path))