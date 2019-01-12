# 八皇后问题

n = 8
sol = [0] * n # sol[idx]表示：棋盘中第idx行皇后的位置为该行第sol[idx]个格子
count = 0

def DFS(row):
    global count
    for col in range(n):
        # 检查冲突
        ok = True
        for i in range(row):
            # 列冲突和对角线冲突
            if col == sol[i] or abs(col - sol[i]) == row - i:
                ok = False
                break
        if not ok:
            continue
        if row == n - 1:
            count += 1
        else:
            sol[row] = col
            DFS(row + 1)


import time

# 主程序
tic = time.time()
DFS(0)                          # 从第 0 行开始试探
toc = time.time()
print("Total solutions: %d" % count) 
print("Elapsed time: %f seconds" % (toc - tic))
