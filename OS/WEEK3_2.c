#include <stdio.h>
#include <unistd.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char str[], int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&str[start], &str[i]);
        permutation(str, start + 1, end);
        swap(&str[start], &str[i]);
    }
}

int main() {
    char str[100];

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child Process\n");

        printf("Enter a string: ");
        scanf("%s", str);

        printf("Permutations are:\n");
        permutation(str, 0, strlen(str) - 1);
    }
    else {
        printf("Parent Process\n");
    }

    return 0;
}