from collections import deque
from queue import Queue

def bfs(maze, start, end):
    # inisialisasi queue dan visited
    queue = deque([start])
    visited = set([start])
    dist = {start: 0}
    directions = {start: ''}
    length = 0
    # iterasi selama queue tidak kosong
    while queue:
        current = queue.popleft()
        x, y = current
        # cek apakah sudah mencapai titik tujuan
        if current == end:
            return dist[current], length, directions[current]
        length += 1
        # cek seluruh arah yang mungkin
        for dx, dy, direction in [(1, 0, 'T'), (0, 1, 'S'), (-1, 0, 'B'), (0, -1, 'U')]:
            next_x, next_y = x+dx, y+dy
            next_pos = (next_x, next_y)
            
            # cek apakah selanjutnya berada di dalam labirin dan belum pernah dikunjungi
            if (0 <= next_x < len(maze) and 0 <= next_y < len(maze[0]) and maze[next_x][next_y] != '#' and next_pos not in visited):
                # tambahkan ke queue, visited, dan update jarak dan arah
                queue.append(next_pos)
                visited.add(next_pos)
                dist[next_pos] = dist[current] + 1
                directions[next_pos] =  directions[current] + direction
    
    # jika tidak ada jalan yang ditemukan, kembalikan nilai -1
    return -1, -1, ''

# membaca input
h, w = map(int, input().split())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
n = int(input())
maze = [['.' for _ in range(w)] for _ in range(h)]
for _ in range(n):
    x, y = map(int, input().split())
    maze[x-1][y-1] = '#'

# menjalankan BFS dari posisi awal ke posisi tujuan
result = bfs(maze, (x1-1, y1-1), (x2-1, y2-1))

# output hasil
if result[0] == -1:
    print("Tidak ada jalan yang ditemukan")
else:
    print(result[0])
    print(result[1])
    print(result[2])