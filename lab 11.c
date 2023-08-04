#include <stdio.h>
#include <limits.h>

// Function to calculate minimum number of coins required
int minCoins(int coins[], int m, int V)
{
    int table[V+1];
    table[0] = 0;

    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;

    for (int i=1; i<=V; i++)
    {
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return (table[V] == INT_MAX) ? -1 : table[V];
}

int main()
{
    int m;
    printf("Enter number of coin values: ");
    scanf("%d", &m);

    int coins[m];
    printf("Enter coin values:\n");
    for(int i=0; i<m; i++)
        scanf("%d", &coins[i]);

    int V;
    printf("Enter the amount: ");
    scanf("%d", &V);

    int result = minCoins(coins, m, V);
    if(result == -1)
        printf("It is impossible to make the amount with the given coins\n");
    else
        printf("Minimum number of coins required: %d\n", result);
    
    return 0;
}