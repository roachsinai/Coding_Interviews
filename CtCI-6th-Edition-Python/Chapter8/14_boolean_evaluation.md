# 问题

对于一个由布尔值和位操作符组成的表达式，试求有多少种不同的求值顺序（添加括号来控制不同部分的优先级）使得表达式最后的值为`True`?

+ $T[i][j]$表示在$[i,j]$之内添加括号之后表达式的值为`True`的个数。
+ $F[i][j]$表示在$[i,j]$之内添加括号之后表达式的值为`False`的个数。

$$T[i][j]=\sum_{k=i}^{j-1}\begin{cases} 
		total-F[i][k]*F[k+1][j], & oper[k]='|' \\
		T[i][k]*F[k+1][j]+T[k+1][j]*F[i][k], & oper[k]='\hat{}' \\
			T[i][k]*T[k+1][j],  & other 
	\end{cases}$$
$$F[i][j]=\sum_{k=i}^{j-1}\begin{cases} 
		F[i][k]*F[k+1][j], & oper[k]='|' \\
		T[i][k]*T[k+1][j]+F[k+1][j]*F[i][k], & oper[k]=' \hat{} ' \\
			total-T[i][k]*T[k+1][j],  & other 
	\end{cases}$$

```
# Driver Code
symbols = "TTFT"
operators = "|&^"

# There are 4 ways
# ((T|T)&(F^T)), (T|(T&(F^T))),
# (((T|T)&F)^T) and (T|((T&F)^T))
```

# 代码

```
def count_parenth(symb, oper):
    n = len(symbols)
    T = [[0] * n for _ in range(n)]
    F = [[0] * n for _ in range(n)]

    for i in range(n):
        if symb[i] == 'T':
            T[i][i] = 1
        else:
            F[i][i] = 1

    # path 布尔值i,j之间的差（path = j - i）
    for path in range(1, n):
        for i, j in zip(range(0, n - path), range(path, n)):
            # 在每一对i,j之间依次遍历分割点（从i开始）
            for g in range(0, path):
                # k 表示i之后的第k个位运算符的位置（即在这个位置左右分别添加括号）
                k = i + g
                total = (T[i][k] + F[i][k]) * (T[k + 1][j] + F[k + 1][j])
                if oper[k] == '&':
                    T[i][j] += T[i][k] * T[k + 1][j]
                    F[i][j] += (total - T[i][k] *
                                            T[k + 1][j])
                if oper[k] == '|':
                    F[i][j] += F[i][k] * F[k + 1][j]
                    T[i][j] += (total - F[i][k] *
                                            F[k + 1][j])
                if oper[k]=='^':
                    T[i][j] += (F[i][k] * T[k + 1][j] +
                                T[i][k] * F[k + 1][j])
                    F[i][j] += (T[i][k] * T[k + 1][j] +
                                F[i][k] * F[k + 1][j])
    return T[0][n - 1]


print(count_parenth(symbols, operators))
```

# Refs

[Boolean Parenthesization-LintCode](https://blog.csdn.net/zhaohengchuan/article/details/78937943)
