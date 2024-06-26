#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int userBatting, userBowling;
    int userWicket = 0, systemWicket = 0;
    int over, user, option;
    int userScore = 0, systemScore = 0;
    int computerToss, computerBowling, computerBatting;

    printf("Ladies and Gentlemen, a great match between the user and the system. Let's see who will win the match\n");
    printf("How many overs do you want to play?\n");
    scanf("%d", &over);
    printf("Total 5 wickets in each team\n");
    printf("It's toss time. What is your call?\n");
    printf("Head (0), Tail (1): ");
    scanf("%d", &user);

    computerToss = rand() % 2;

    if (computerToss == user) {
        printf("Congratulations, you won the toss\n");
        printf("What do you want to choose, batting or bowling first? [(1): bat or (2): ball]\n");
        scanf("%d", &option);

        if (option == 1) {
            printf("You chose batting first (System will bowl to you)\n");
            printf("Enter 1: One run, 2: Two runs, 3: Three runs, 4: Four runs, 5: Five runs, 6: Six runs\n");

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    printf("Bat:");
                    scanf("%d", &userBatting);
                    computerBowling = (rand() % 6) + 1;
                    if (userBatting != computerBowling) {
                        printf("You hit: %d runs, System chose: %d\n", userBatting, computerBowling);
                        userScore += userBatting;
                    } else {
                        userWicket++;
                        printf("Oops, you're out because your choice and the computer's choice are the same. You: %d, System chose: %d\n", userBatting, computerBowling);
                    }
                    if (userWicket == 5) break;
                }
                if (userWicket == 5) break;
                printf("After completing %d over(s), the score is %d runs with the loss of %d wicket(s)\n", i, userScore, userWicket);
            }

            printf("Total score: %d\n", userScore);
            printf("2nd innings start in a few sec, \"now it's your turn to bowl and defend your Score\" (Target): %d\nchoose the same number as system chooses for taking wicket\n", (userScore + 1));

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    printf("Ball:");
                    scanf("%d", &userBowling);
                    computerBatting = (rand() % 6) + 1;

                    if (userBowling != computerBatting) {
                        printf("System hit: %d runs, You chose: %d\n", computerBatting, userBowling);
                        systemScore += computerBatting;
                    } else {
                        systemWicket++;
                        printf("Yes, you got it, %d wickets gone of System because your choice and the computer's choice are the same. You: %d, System chose: %d\n", systemWicket, userBowling, computerBatting);
                    }
                    if (systemWicket == 5) break;
                }
                if (systemWicket == 5) break;
                printf("After completing %d over(s), the score is %d runs with the loss of %d wicket(s)\n", i, systemScore, systemWicket);
            }

            if (userScore > systemScore) {
                printf("Congratulations, you won the game by: %d runs\n", (userScore - systemScore));
            } else if (userScore < systemScore) {
                printf("Oo you lose the game by: %d wickets, but nice try. Best of Luck for the next game\n", (5 - systemWicket));
            } else {
                printf("Oo it is a tie score between You and the System %d - %d runs, Well played\n", userScore, systemScore);
            }
        } else if (option == 2) {
            printf("You chose bowling first (System will bat first...)\n");
            printf("Enter 1: One run, 2: Two runs, 3: Three runs, 4: Four runs, 5: Five runs, 6: Six runs\n");

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    printf("Ball:");
                    scanf("%d", &userBowling);
                    computerBatting = (rand() % 6) + 1;

                    if (userBowling != computerBatting) {
                        printf("System hit: %d runs, You chose: %d\n", computerBatting, userBowling);
                        systemScore += computerBatting;
                    } else {
                        systemWicket++;
                        printf("Yes, you got it, %d wickets gone of System because your choice and the computer's choice are the same. You: %d, System chose: %d\n", systemWicket, userBowling, computerBatting);
                    }
                    if (systemWicket == 5) break;
                }
                if (systemWicket == 5) break;
                printf("After completing %d over(s), the score is %d runs with the loss of %d wicket(s)\n", i, systemScore, systemWicket);
            }

            printf("Total score: %d\n", systemScore);
            printf("2nd innings start in a few sec, \"now it's your turn to bat and chase the Score\" (Target): %d\n", (systemScore + 1));

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    printf("Bat:");
                    scanf("%d", &userBatting);
                    computerBowling = (rand() % 6) + 1;
                    if (userBatting != computerBowling) {
                        printf("You hit: %d runs, System chose: %d\n", userBatting, computerBowling);
                        userScore += userBatting;
                    } else {
                        userWicket++;
                        printf("Oops, you're out because your choice and the computer's choice are the same. You: %d, System chose: %d\n", userBatting, computerBowling);
                    }
                    if (userWicket == 5) break;
                }
                if (userWicket == 5) break;
                printf("After completing %d over(s), the score is %d runs with the loss of %d wicket(s)\n", i, userScore, userWicket);
            }

            if (userScore > systemScore) {
                printf("Congratulations, you won the game by: %d wickets\n", (5 - systemWicket));
            } else if (userScore < systemScore) {
                printf("You lose the game by: %d runs, but nice try. Best of Luck for the next game\n", (systemScore - userScore));
            } else {
                printf("Oo it is a tie score between You and the System %d - %d runs, Well played\n", userScore, systemScore);
            }
        }
    } else {
        printf("System won the toss and chose batting first\n");
        printf("Enter 1: One run, 2: Two runs, 3: Three runs, 4: Four runs, 5: Five runs, 6: Six runs\n");

        for (int i = 1; i <= over; i++) {
            for (int j = 1; j <= 6; j++) {
                printf("Ball:");
                scanf("%d", &userBowling);
                computerBatting = (rand() % 6) + 1;

                if (userBowling != computerBatting) {
                    printf("System hit: %d runs, You chose: %d\n", computerBatting, userBowling);
                    systemScore += computerBatting;
                } else {
                    systemWicket++;
                    printf("Yes, you got it, %d wickets gone of System because your choice and the computer's choice are the same. You: %d, System chose: %d\n", systemWicket, userBowling, computerBatting);
                }
                if (systemWicket == 5) break;
            }
            if (systemWicket == 5) break;
            printf("After completing %d over(s), the score is %d runs with the loss of %d wicket(s)\n", i, systemScore, systemWicket);
        }

        printf("Total score: %d\n", systemScore);
        printf("2nd innings start in a few sec, \"now it's your turn to bat and chase the Score\" (Target): %d\n", (systemScore + 1));

        for (int i = 1; i <= over; i++) {
            for (int j = 1; j <= 6; j++) {
                printf("Bat:");
                scanf("%d", &userBatting);
                computerBowling = (rand() % 6) + 1;
                if (userBatting != computerBowling) {
                    printf("You hit: %d runs, System chose: %d\n", userBatting, computerBowling);
                    userScore += userBatting;
                } else {
                    userWicket++;
                    printf("Oops, you're out because your choice and the computer's choice are the same. You: %d, System chose: %d\n", userBatting, computerBowling);
                }
                if (userWicket == 5) break;
            }
            if (userWicket == 5) break;
            printf("After completing %d over(s), the score is %d runs with the loss of %d wicket(s)\n", i, userScore, userWicket);
        }

        if (userScore > systemScore) {
            printf("Congratulations, you won the game by: %d wickets\n", (5 - systemWicket));
        } else if (userScore < systemScore) {
            printf("You lose the game by: %d runs, but nice try. Best of Luck for the next game\n", (systemScore - userScore));
        } else {
            printf("Oo it is a tie score between You and the System %d - %d runs, Well played\n", userScore, systemScore);
        }
    }

    return 0;
}
