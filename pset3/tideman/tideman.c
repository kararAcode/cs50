#include <stdio.h>
#include <cs50.h>
#include <string.h>

// DATA TYPES
typedef struct
{
    int winner;
    int loser;
}
pair;

// Global variables and constants
int pair_count;
#define MAX 9
int candidate_count;
string candidates[MAX];

int preferences[MAX][MAX];
pair pairs[36]; // max num of pairs
bool locked[MAX][MAX];

// PROTOTYPES
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool creates_cycle(int n);
void lock_pairs(void);
void print_winner(void);



int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./tideman candidate(s)\n");
        return 1;
    }
    candidate_count = argc-1;

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i+1];
    }



    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];
        for (int j = 1; j <= candidate_count; j++)
        {
            string choice = get_string("Rank %i: ", j);
            vote(j-1, choice, ranks);
        }
        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();

}

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        preferences[ranks[i]][ranks[i]] = 0;
        for (int j = 0+i+1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    int index = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0+i+1; j < candidate_count; j++)
        {


            if (preferences[i][j] > preferences[j][i])
            {
                pair candidate_pair;
                candidate_pair.winner = i;
                candidate_pair.loser = j;
                pairs[index] = candidate_pair;
                index++;
                pair_count++;
            }

            else if (preferences[j][i] > preferences[i][j])
            {
                pair candidate_pair;
                candidate_pair.winner = j;
                candidate_pair.loser = i;
                pairs[index] = candidate_pair;
                index++;
                pair_count++;
            }
        }
    }
}

void sort_pairs(void)
{
    int strongest_victory = 0;
    int index = 0;
    pair sorted_pairs[pair_count];
    for (int i = 0; i < pair_count; i++)
    {

        if (!index)
        {
            sorted_pairs[0] = pairs[i];
        }

        for (int j = 0; j <= index-1; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] > preferences[sorted_pairs[j].winner][sorted_pairs[j].loser])
            {
                for (int k = index-1; k >= j; k--)
                {
                    sorted_pairs[k+1] = sorted_pairs[k];
                }
                sorted_pairs[j] = pairs[i];
            }
        }
        index++;
    }

    for (int l = 0; l < pair_count; l++)
    {
        pairs[l] = sorted_pairs[l];
    }
}

bool creates_cycle(int n)
{

    if (n == 1)
    {
        return false;
    }

    if (!creates_cycle(n-1))
    {
        for (int i = 0; i < n; i++)
        {
            bool true_in_col = false;
            for (int j = 0; j < n; j++)
            {
                if (locked[j][i] == true)
                {
                    true_in_col = true;
                }
            }

            if (true_in_col == false)
            {
                return false;
            }
        }

        return true;
    }

    else
    {
        return true;
    }
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int j = pairs[i].winner;
        int k = pairs[i].loser;
        locked[j][k] = true;
        if (creates_cycle(candidate_count))
        {
            locked[j][k] = false;
        }
    }
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool true_in_col = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                true_in_col = true;
            }
        }

        if (!true_in_col)
        {
            printf("%s\n", candidates[i]);
        }
    }
}