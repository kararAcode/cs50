#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX 9 // max candidates
int candidate_count; //candidate count

// PROTOTYPES
bool vote(string candidate);
void print_winner(void);

// CANDIDATE STRUCTURE
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int main(int argc, string argv[])
{
    if (argc < 2) // checks if program is being used properly
    {
        printf("Usage: ./plurality candidate(s)\n");
        return 1;
    }
    candidate_count = argc - 1;

    // Create Candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int num_votes = get_int("Number of voters: "); // number of voters
    for (int i = 0; i < num_votes; i++) // Generates inputs based on number of voters
    {
        vote(get_string("Vote: "));
    }

    print_winner();
}

bool vote(string candidate)
// adds to candidate vote count if valid
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, candidate) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
// prints winner(s) based on the number of votes
{
    string winners[candidate_count];
    int winner_index = 0;
    int most_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > most_votes)
        {
            winners[winner_index] = candidates[i].name;
            most_votes = candidates[i].votes;
        }

        else if (candidates[i].votes == most_votes)
        {
            winner_index += 1;
            winners[winner_index] = candidates[i].name;
            most_votes = candidates[i].votes;
        }
    }

    // prints winner(s)
    for (int i = 0; i <= winner_index; i++)
    {
        printf("%s\n", winners[i]);
    }
}