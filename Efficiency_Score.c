#include <stdio.h>

int getYesNo(const char *question);
void WeeklyScore(int week[5]);
void Efficiency_Score(int a[5]);

int Score[5];

int main() {
    for (int i = 1; i <= 5; i++) {
        int skip=0;
        int deduction=0;
        int points=0;

        printf("\nEnter Day %d details\n", i);

        if (getYesNo("Did you workout today?\n")) {
            points += 40;
            printf("Enter the number of sets skipped (0 if none): ");
            scanf("%d", &skip);
            deduction+=5*skip;
        }

        if (getYesNo("Did you study today?\n")) {
            printf("Good!\n");
            points+=25;
        } else {
            deduction+=5;
        }

        if (getYesNo("Were you late to the bus this morning?\n")) {
            deduction+=5;
        } else {
            printf("Good!\n");
            points+=10;
        }

        if (getYesNo("Did your screentime exceed 2.5 hours?\n")) {
            deduction+=5;
        } else {
            printf("Good!\n");
            points+=10;
        }

        if (getYesNo("Did you sleep before 11:30?\n")) {
            printf("Good Job!\n");
            points+=15;
        } else {
            deduction+=10;
        }

        Score[i-1]=points-deduction;
    }

    WeeklyScore(Score);
    Efficiency_Score(Score);

    return 0;
}

int getYesNo(const char *question) {
    char ans;

    while (1) {
        printf("%s (Y/N): ", question);
        scanf(" %c", &ans);

        if (ans == 'Y')
            return 1;
        else if (ans == 'N')
            return 0;
        else
            printf("Invalid input. Please enter Y or N.\n");
    }
}

void WeeklyScore(int week[5]) {
    printf("\nWeekly Scores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Day %d: %d\n", i + 1, week[i]);
    }
}

void Efficiency_Score(int a[5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += a[i];
    }

    float efficiency = (sum / 500.00) * 100.00;
    printf("\nYour Weekly Efficiency Score is %.2f\n", efficiency);
}