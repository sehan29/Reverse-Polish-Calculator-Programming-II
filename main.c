#include<stdio.h>


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



main() {

    Development_Team();

    return 0;
}
