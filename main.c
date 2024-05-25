#include<stdio.h>

int evaluatePostfix(char *expr,RPNRecord *record);

typedef struct {
    char notation[100];  // To store the Reverse Polish notation
    char result[50];     // To store the result or error message
} RPNRecord;



void Development_Team()
{
    char back_btn;

    printf("2021T01198 - M.P.A.CHAMIKARA\n");
    printf("2021T01205 - G.S.H GAMAGE\n");
    printf("2021T01226 - R.A.M.S.PERERA\n");
    printf("2021T01229 - W.M.D.PRIYANATH\n");
    printf("2021T01245 - W.P.R.UDANA\n");
    printf("2021T01252 - C.L.WETHTHASINGHE\n");

    printf("\n<-- If You Want To Go Back (Y/N) : ");
    scanf("%s",&back_btn);

    if(back_btn == 'Y' || back_btn == 'y')
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        exit(0);
    }
}


int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}


void infixToPostfixConversion(char* infix, char* postfix) {
    Stack s;
    CreateStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            Push(infix[i], &s);
        } else if (infix[i] == ')') {
            while (!IsStackEmpty(&s) && s.entry[s.top] != '(') {
                postfix[j++] = Pop(&s);
                postfix[j++] = ' ';
            }
            Pop(&s); // Remove '(' from stack
        } else {
            while (!IsStackEmpty(&s) && precedence(infix[i]) <= precedence(s.entry[s.top])) {
                postfix[j++] = Pop(&s);
                postfix[j++] = ' ';
            }
            Push(infix[i], &s);
        }
    }

    while (!IsStackEmpty(&s)) {
        postfix[j++] = Pop(&s);
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0'; // Remove the last space and terminate the string
}



int evaluatePostfix(char *expr,RPNRecord *record) {

    Stack s;
    CreateStack(&s);
    strcpy(record->notation, expr);
    int i = 0;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            int operand = 0;
            while (isdigit(expr[i])) {
                operand = operand * 10 + (expr[i] - '0');
                i++;
            }
            Push(operand, &s);
        } else if (isspace(expr[i])) {
            i++; // Skip spaces
        } else {
            if (IsStackEmpty(&s)) {

                sprintf(record->result, "Invalid Expression: Not Enough Operands!");
                printf("Invalid Expression: Not Enough Operands!\n");
                return FALSE; // Return an error value
            }
            int val2 = Pop(&s);


            if (IsStackEmpty(&s)) {

                sprintf(record->result, "Invalid Expression: Not Enough Operands!");
                printf("Invalid Expression: Not Enough Operands!\n");
                return FALSE; // Return an error value
            }

            int val1 = Pop(&s);

            switch (expr[i]) {
                case '+':

                    printf("Step: %d + %d = %d\n", val1, val2, val1 + val2);
                    Push(val1 + val2, &s);
                    break;
                case '-':

                    printf("Step: %d - %d = %d\n", val1, val2, val1 - val2);
                    Push(val1 - val2, &s);
                    break;
                case '*':

                    printf("Step: %d * %d = %d\n", val1, val2, val1 * val2);
                    Push(val1 * val2, &s);
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Error: Division by zero!\n");
                        return FALSE; // Return an error value
                    }

                    printf("Step: %d / %d = %d\n", val1, val2, val1 / val2);
                    Push(val1 / val2, &s);
                    break;
                default:

                    sprintf(record->result, "Invalid Expression: Not Enough Operands!");
                    printf("Invalid operator: %c\n", expr[i]);
                    return FALSE; // Return an error value
            }
            i++; // Move to the next character
        }
    }

    if (IsStackEmpty(&s)) {
        printf("Invalid expression: Not enough operands!\n");
        return FALSE; // Return an error value
    }

    int result = Pop(&s);

    if (!IsStackEmpty(&s)) {
        printf("Invalid expression: Too many operands!\n");
        return FALSE; // Return an error value
    }


    sprintf(record->result, "%d", result);

    return result;

}




main() {

    Development_Team();

    return 0;
}


void DisplaySavedNotations() {

    char back_btn;
    FILE *file = fopen("Reverse_Polish_Notation.txt", "r"); // Open the file for reading
    if (file == NULL) {
        printf("Unable to open file or file does not exist.\n");
        return;
    }

    char line[200]; // Buffer to hold each line read from the file
    printf("Saved Reverse Polish Notation and Result\n\n");
    printf("-------------------------------------------------------------------\n");
    printf("| REVERSE POLISH NOTATION \t | \t RESULT \t\t  |\n");
    printf("-------------------------------------------------------------------\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Print each line read from the file
        printf("-------------------------------------------------------------------\n");
    }

    fclose(file); // Close the file after reading

    printf("\n<-- If You Want To Go Back (Y/N) : ");
    scanf("%s",&back_btn);

    if(back_btn == 'Y' || back_btn == 'y')
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        Exit_Message();
        exit(0);
    }
}
