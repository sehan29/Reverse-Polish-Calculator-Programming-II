#include<stdio.h>

int evaluatePostfix(char *expr,RPNRecord *record);




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


    return 0;
}
