
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';

    return stack[top--];
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    char ch, temp;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            if (top != -1 && stack[top] == '(')
                temp = pop();
            else {
                printf("Invalid expression.\n");
                return 0;
            }
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch)
                    && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
        else {
            printf("Invalid character in expression.\n");
            return 0;
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid expression.\n");
            return 0;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
