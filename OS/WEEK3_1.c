#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int n, arr[100], sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
        }

        printf("Child: Sum = %d\n", sum);
    }
    else {
        wait(NULL);

        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
        }

        if (isPrime(sum))
            printf("Parent: %d is a Prime number\n", sum);
        else
            printf("Parent: %d is not a Prime number\n", sum);
    }

    return 0;
}