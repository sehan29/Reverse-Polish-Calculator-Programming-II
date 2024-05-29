#include<stdio.h>


typedef struct {
    char notation[100];  // To store the Reverse Polish notation
    char result[50];     // To store the result or error message
} RPNRecord;


void Insert_Reverse_Polish_Notation()
{
    int c;
    char back_btn;
    RPNRecord record;
    char Expression[100];
    printf("\t -- Enter Only Digits and ('/', '*', '-', '+') Operators in Here --\n\n");
    printf("Enter Revese Polish Notation - ");
    while ((c = getchar()) != '\n' && c != EOF) { }
    fgets(Expression,100,stdin);
    //Expression[strcspn(Expression, "\n")] = 0;
   // printf("%s\n",Expression);
    int result = evaluatePostfix(Expression,&record);

    printf("--------------------------------------------------------------------------\n");
    printf("Result of Reverse Polish Notation = %d\n", result);
    printf("--------------------------------------------------------------------------\n");

    FILE *file = fopen("Reverse_Polish_Notation.txt", "a");  // Open the file in append mode
    if (file != NULL) {

        int notationWidth = 40;
        int notationLength = strlen(record.notation);
        int spaceCount = notationWidth - notationLength;

        // Print notation and result, with notation padded to be 60 characters long
        fprintf(file, "%s", record.notation);
        for (int i = 0; i < spaceCount; i++) {
            fputc(' ', file);  // Add spaces to pad the notation
        }
        fprintf(file, "%s\n", record.result);

        fclose(file);

    } else {
        printf("Failed to open file for writing.\n");
    }

    printf("\n<-- If You Want To Go Main Menu (Y/N) : ");
        scanf("%s",&back_btn);

    if(back_btn == 'Y' || back_btn == 'y')
    {
        system("cls");
        Header();
        Main_Body_content();
        Main_Selection();
    }
    else
    {
        system("cls");
        Exit_Message();
        exit(0);
    }
}


void Insert_Reverse_Polish_Notation()
{
    int c;
    char back_btn;
    RPNRecord record;
    char Expression[100];
    printf("\t -- Enter Only Digits and ('/', '*', '-', '+') Operators in Here --\n\n");
    printf("Enter Revese Polish Notation - ");
    while ((c = getchar()) != '\n' && c != EOF) { }
    fgets(Expression,100,stdin);
    //Expression[strcspn(Expression, "\n")] = 0;
   // printf("%s\n",Expression);
    int result = evaluatePostfix(Expression,&record);

    printf("--------------------------------------------------------------------------\n");
    printf("Result of Reverse Polish Notation = %d\n", result);
    printf("--------------------------------------------------------------------------\n");

    FILE *file = fopen("Reverse_Polish_Notation.txt", "a");  // Open the file in append mode
    if (file != NULL) {

        int notationWidth = 40;
        int notationLength = strlen(record.notation);
        int spaceCount = notationWidth - notationLength;

        // Print notation and result, with notation padded to be 60 characters long
        fprintf(file, "%s", record.notation);
        for (int i = 0; i < spaceCount; i++) {
            fputc(' ', file);  // Add spaces to pad the notation
        }
        fprintf(file, "%s\n", record.result);

        fclose(file);

    } else {
        printf("Failed to open file for writing.\n");
    }

    printf("\n<-- If You Want To Go Main Menu (Y/N) : ");
        scanf("%s",&back_btn);

    if(back_btn == 'Y' || back_btn == 'y')
    {
        system("cls");
        Header();
        Main_Body_content();
        Main_Selection();
    }
    else
    {
        system("cls");
        Exit_Message();
        exit(0);
    }
}

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



main() {

    Development_Team();

    return 0;
}
