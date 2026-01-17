#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    int i, j;
    int u, v;
    int viewID;

    char names[50][50];
    int adj[50][50] = {0};

    printf("Enter number of users: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name for User %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("Enter number of connections: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter connection (user1 user2): ");
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }

    printf("Enter user ID to view friends and suggestions: ");
    scanf("%d", &viewID);
    viewID--;

    printf("Friends of %s:", names[viewID]);
    for (i = 0; i < n; i++) {
        if (adj[viewID][i] == 1) {
            printf(" %s", names[i]);
        }
    }
    printf("\n");

    printf("Mutual Friends for %s:", names[viewID]);
    for (i = 0; i < n; i++) {
        if (i != viewID && adj[viewID][i] == 0) {
            int count = 0;
            for (j = 0; j < n; j++) {
                if (adj[viewID][j] == 1 && adj[i][j] == 1) {
                    count++;
                }
            }
            if (count > 0) {
                printf(" %s (Mutual Count: %d)", names[i], count);
            }
        }
    }

    return 0;
}
