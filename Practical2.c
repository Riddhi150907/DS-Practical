
#include <stdio.h>

int main() {
    int a[100], n, i, pos, value, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n1. Traversal\n2. Insertion\n3. Deletion\n4. Searching\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Array elements: ");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else if (choice == 2) {
        printf("Enter position and value: ");
        scanf("%d%d", &pos, &value);
        if (pos < 1 || pos > n + 1 || n >= 100) {
            printf("Invalid position or full array");
        } else {
            for (i = n; i >= pos; i--)
                a[i] = a[i - 1];
            a[pos - 1] = value;
            n++;
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
        }
    }
    else if (choice == 3) {
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        if (pos < 1 || pos > n) {
            printf("Invalid position");
        } else {
            for (i = pos - 1; i < n - 1; i++)
                a[i] = a[i + 1];
            n--;
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
        }
    }
    else if (choice == 4) {
        printf("Enter value to search: ");
        scanf("%d", &value);
        for (i = 0; i < n && a[i] != value; i++);
        if (i < n)
            printf("Found at position %d", i + 1);
        else
            printf("Element not found");
    }
    else {
        printf("Invalid choice");
    }

    return 0;
}
