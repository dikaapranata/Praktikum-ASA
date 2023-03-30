#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);
    char kandidat[MAX][MAX];
    for (int i = 0; i < n; i++) {
        scanf("%s", kandidat[i]);
    }
    int votes[MAX];
    memset(votes, 0, sizeof(votes));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(kandidat[i], kandidat[j]) == 0) {
                votes[i]++;
            }
        }
    }
    int max_votes = 0;
    int max_index = 0;
    for (int i = 0; i < n; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            max_index = i;
        }
    }
    printf("%s\n", kandidat[max_index]);
    return 0;
}
