#include <stdio.h>

// Function to count and print scoring combinations
int countAndPrint(int scoring_possibilities[], int score_pos_left, int current_score, int current_combination[], int index)
{
    // Check if the target score is reached
    if (current_score == 0)
    {
        // Initialize variables to count different scoring plays
        int td_2pt = 0;
        int td_fg = 0;
        int td = 0;
        int fg = 0;
        int safety = 0;

        // Count different scoring plays in the current combination
        for (int i = 0; i < index; i++)
        {
            if (current_combination[i] == 2){
                safety += 1;
            }
            if (current_combination[i] == 3){
                fg += 1;
            }
            if (current_combination[i] == 6){
                td += 1;
            }
            if (current_combination[i] == 7){
                td_fg += 1;
            }
            if (current_combination[i] == 8){
                td_2pt += 1;
            }
        }

        // Print the combination of scoring plays
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", td_2pt, td_fg, td, fg, safety);
        printf("\n");

        // Indicate that a valid combination has been found
        return 1;
    }

    // Check for invalid conditions or if no scoring possibilities are left
    if (current_score < 0 || score_pos_left <= 0){
        return 0;
    }

    // Include the current scoring possibility and recursively call the function
    current_combination[index] = scoring_possibilities[score_pos_left - 1];
    int includeCount = countAndPrint(scoring_possibilities, score_pos_left, current_score - scoring_possibilities[score_pos_left - 1], current_combination, index + 1);

    // Exclude the current scoring possibility and recursively call the function
    int excludeCount = countAndPrint(scoring_possibilities, score_pos_left - 1, current_score, current_combination, index);

    // Return the total count of combinations (included and excluded)
    return excludeCount + includeCount;
}

int main()
{
    int user_score;
    int scoring_possibilities[] = {8, 7, 6, 3, 2};
    int score_pos_left = sizeof(scoring_possibilities) / sizeof(scoring_possibilities[0]);
    int current_combination[10000];

    // Continue until the user enters 0 or 1
    while (1){
        printf("Enter 0 or 1 to STOP: ");
        scanf("%d", &user_score);
        if (user_score == 0 || user_score == 1){
            break; // Exit the loop
        }
        else{
            // Calculate and print the number of combinations
            printf("Number of combinations: %d\n", countAndPrint(scoring_possibilities, score_pos_left, user_score, current_combination, 0));
        }
    }

    return 0;
}
