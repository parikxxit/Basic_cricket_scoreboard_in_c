#include <stdio.h>
#include <string.h>
#include<conio.h>

int team1score=0;
int team2score=0;
int overs;
int max_size = 100;


void Print_score(char team1[], char team2[], int team1score, int team2score, int wickets1, int wickets2, int as){
    //system("CLS");
    printf("############################################################");
    printf("\n###########################################################\n");
    printf("\t\t\t %s -  %d/ %d \n", team1, team1score,wickets1);
    if(as == 1){
        printf("\t\t\t %s - %d/%d", team2, team2score, wickets2);
    }
    else{
            printf("\t\t\t %s - %d/%d  (Yet to bat)", team2, team2score, wickets2);
    }

    printf("\n#########################################################");
    printf("\n##########################################################\n");

}
void Print_result(char name1[], char name2[]){
        if(team1score>team2score){
            printf("\a % s Wins", name1);
        }
        else if(team1score<team2score){
            printf("\a % s Wins", name2);
        }
        else{
            printf("\aMatch Drawn.");
        }
}

int main()
{
    char name1[max_size], name2[max_size];
    int overs,balls,wickets1,wickets2;
	int ball,ball1,a,run;
	printf("Welcome! Let's Have some score on the ScoreBoard\a\n");
    printf("Enter the name of Team batting first\n");
    scanf("%s", &name1);
    printf("Enter the name of Team batting second \n");
    scanf("%s", &name2);
    printf("How many overs are there in a match ?\n");
    
    scanf("%d", &overs);
    balls = 6*overs;
    wickets1 = 0;
    wickets2 = 0;
    
    ball = 0, ball1 = 0;
    while(ball < balls && wickets1 < 10)
    {
        Print_score(name1, name2, team1score, team2score, wickets1, wickets2, 0);
        printf("\nEnter what happened in this ball from the choices given \n");
        printf("1) Runs \n 2) Wide-Ball \n 3) No-Ball \n 4) Wide-Ball + Runs \n 5) No-Ball + Runs \n 6) Wicket \n");
        scanf("%d", &a);
        if(a==1)
        {
            printf("Enter The runs Scored in this ball \n");
            scanf("%d", &run);
            team1score += run;
            ball++;

        }
        else if(a==2)
        {
            team1score++;
        }
        else if(a==3)
        {
            team1score++;
        }
        else if(a==4)
        {
            printf("Enter The runs Scored in this wide  ball \n");
            scanf("%d", &run);
            team1score += run + 1;
        }
        else if(a==5)
        {
            printf("Enter The runs Scored in this no ball \n");
            scanf("%d", &run);
            team1score += run + 1;
        }
        else if(a==6)
        {
            wickets1++;
            ball++;
        }
        else{
            printf("Enter the valid choices\n");
        }

    }
    printf("\n\aInnings second begins\n");
    while(ball1 < balls && wickets1 < 10)
    {
        Print_score(name1, name2, team1score, team2score, wickets1, wickets2, 1);
        printf("\nEnter what happened in this ball from the choices given \n");
        printf("1) Runs \n 2) Wide-Ball \n 3) No-Ball \n 4) Wide-Ball + Runs \n 5) No-Ball + Runs \n 6) Wicket \n");
        scanf("%d", &a);
        if(a==1)
        {
            printf("Enter The runs Scored in this ball \n");
            scanf("%d", &run);
            team2score += run;
            ball1++;

        }
        else if(a==2)
        {
            team2score++;
        }
        else if(a==3)
        {
            team2score++;
        }
        else if(a==4)
        {
            printf("Enter The runs Scored in this wide  ball \n");
            scanf("%d", &run);
            team2score += run + 1;
        }
        else if(a==5)
        {
            printf("Enter The runs Scored in this no ball \n");
            scanf("%d", &run);
            team2score += run + 1;
        }
        else if(a==6)
        {
            wickets2++;
            ball1++;
        }
        else{
            printf("Enter the valid choices\n");
        }

        if(team2score > team1score)
           break;
    }
    Print_result(name1, name2);


    return 0;
}