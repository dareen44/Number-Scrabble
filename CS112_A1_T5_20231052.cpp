/*
Program: In Number Scrabble "Game 2", players select numbers from a list ranging from 1 to 9 in turns. Once chosen, a number cannot be selected again.
The game concludes in three scenarios: a player wins by selecting three numbers that sum up to 15, all numbers are picked without any player achieving a sum of 15, resulting in a draw, or a player picks three numbers that sum up to 15 before all numbers are chosen, leading to a win.
*/
// Author: Dareen Elsayed Ragab, S11 ,20231052
// Version: 3.0
// Date: 2/3/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Welcome message and display instructions
void welcome_instructions()

{
    cout << "*** Welcome to Number Scrabble Game ***" << endl;
    cout << endl;
    cout << "The game's instructions\n"
            "1- Number scrabble is played with the list of numbers between 1 and 9.\n"
            "2- Each player takes turns picking a number from the list.\n"
            "3- Once a number has been picked, it cannot be picked again.\n"
            "4- If a player has picked three numbers that add up to 15, that player wins the game.\n"
            "5- If all the numbers are used and no player gets exactly 15, the game is a draw."
         << endl;
    cout << endl;
}
// verify number range of player1,2
void check_valid_input(vector<int> &player_total,vector<int> &list_of_game ,int n)
{
    while (true)
    {
        cout<<"player{"<<n<<"} : enter a number between 1 and 9: "<< endl;
        double player;
        cin>> player;
        cin.clear();
        cin.ignore(10000, '\n');
        if (player != static_cast<int>(player))
        cout<<"Floating-point numbers are not allowed!"<< endl;
        
        else {
        auto play = find(list_of_game.begin(), list_of_game.end(), player);
        if (play == list_of_game.end()) {
            cout << "Error: This value is not in the range of the available numbers!" << endl;
        } else {
            player_total.push_back(player);
            list_of_game.erase(play);
            break;
        
        }
    }   
   }           
}
// to print all lists of players
void All_lists_of_players(vector<int> &player1_total,vector<int> &player2_total)
{
    cout<< endl;
    cout<<"All numbers of player1: "<< endl;
    for(int num : player1_total)
        cout<< num << " ";
    cout << endl;
    cout<<"All numbers of player2: "<< endl;
    for (int num : player2_total)
        cout << num << " ";
    cout<< endl;
    cout<<"---------------------------------------------" << endl; 
}
// to check which player won
bool check_win(vector <int> &player_total)
{
    sort(player_total.begin(), player_total.end());  // Sort the list(ascending order of the list)
    int n = player_total.size(); // lengh of the list 
    for (int i=0; i<(n - 2); i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int current_sum = player_total[i] + player_total[left] + player_total[right];
            if (current_sum == 15)
                return true;    
            else if (current_sum < 15)
                left ++;
            else
                right --;
        }
            
    } 
    return false;  
        
}
          


int main()
{
    vector<int> player1_total, player2_total;
    
    // welcome message and instructions
    welcome_instructions();

    // list to pick a number 
    vector<int> list_of_game =  {1, 2, 3, 4, 5, 6, 7, 8, 9};

    while (true)
    {
        // print available numbers in the list of game for player1 
        cout << "Available numbers:"<< endl;
        for(int num: list_of_game)
        
            cout<< num << " "; 
        cout << endl;

        // Player 1 input and verify valid input
        check_valid_input(player1_total,list_of_game,1);
        if (check_win(player1_total))
        {
            All_lists_of_players(player1_total, player2_total);
            cout<< "player 1 wins!"<< endl;
            return 0;
        }else if (list_of_game.empty())
            break;

        // print available numbers in the list of game for player2 
        cout << "Available numbers:"<< endl;  
        for(int num: list_of_game)
        
            cout<< num << " "; 
        cout << endl;

        // Player 2 input and verify valid input
        check_valid_input(player2_total,list_of_game,2);
        if (check_win(player2_total))
        {
            All_lists_of_players(player1_total, player2_total);
            cout<< "player 2 wins!"<< endl;
            return 0;
        }
    }
    // If all the numbers are used and no player gets exactly 15
    All_lists_of_players(player1_total,player2_total); 
    cout<< "The game is a draw!"<< endl;
    return 0;
}
