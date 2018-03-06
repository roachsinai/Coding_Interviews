from collections import namedtuple
from collections import deque

Point = namedtuple('Point', 'x y')

g_field = [['w','.','.','.','.','.','.','.','.','w','w','.'],
           ['.','w','w','w','.','.','.','.','.','w','w','w'],
           ['.','.','.','.','w','w','.','.','.','w','w','.'],
           ['.','.','.','.','.','.','.','.','.','w','w','.'],
           ['.','.','.','.','.','.','.','.','.','w','.','.'],
           ['.','.','w','.','.','.','.','.','.','w','.','.'],
           ['.','w','.','w','.','.','.','.','.','w','w','.'],
           ['w','.','w','.','w','.','.','.','.','.','w','.'],
           ['.','w','.','w','.','.','.','.','.','.','w','.'],
           ['.','.','w','.','.','.','.','.','.','.','w','.']]

ROWS = len(g_field)
COLS = len(g_field[0])

def valid_point(p):
    if p.x < 0 or p.x >= ROWS or p.y < 0 or p.y >= COLS:
        return False
    else:
        return True

def get_conn(de):
    # de not empty
    while de:
        p = de.pop()
        for i in range(-1, 2):
            for j in range(-1, 2):
                neighbor = Point(p.x+i, p.y+j)
                if valid_point(neighbor) and g_field[neighbor.x][neighbor.y] == 'w':
                    de.append(neighbor)
                    g_field[neighbor.x][neighbor.y] = '.'

def main():
    conn = 0
    de = deque()

    for i in range(ROWS):
        for j in range(COLS):
            if g_field[i][j] == 'w':
                conn += 1

                p = Point(i, j)
                de.append(p)
                g_field[i][j] = '.'

                get_conn(de)

    print(conn)

if __name__ == "__main__":
    main()
    print(g_field)