#param: n: 物品的个数
def knapsack_recursion(W, wt, val, n):
    if n == 0 or W == 0:
        return 0
    if wt[n-1] > W:
        return knapsack_recursion(W, wt, val, n-1)
    else:
        return max(val[n-1] + knapsack_recursion(W-wt[n-1], wt, val, n-1),
                    knapsack_recursion(W, wt, val, n-1))

def knapSack(W, wt, val, n):
    K = [[0 for x in range(W+1)] for x in range(n+1)]

    # Build table K[][] in bottom up manner
    for i in range(n+1):
        for w in range(W+1):
            if i==0 or w==0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]

    return K[n][W], K

def main():
    val = [60, 100, 120]
    wt = [1, 2, 3]
    W = 5
    n = len(val)
    print(knapsack_recursion(W, wt, val, n))
    _, dp = knapSack(W, wt, val, n)
    print('\n'.join('{}'.format(_) for _ in dp))

if __name__ == "__main__":
    main()
