#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<algorithm>
using namespace std;

vector<string> loadWords()
{
    vector<string> words;
    string line;
    ifstream fin("wordList.txt");
    while(getline(fin,line))
    {
        if(line.length()>0)
          words.push_back(line);
    }
    return words;
}
string choose_word()
{
    vector<string>word_list=loadWords();
    srand(time(0));
    int random_index=rand()%word_list.size();
    return word_list[random_index];
}
bool display_word(string word_to_guess,const vector<char>&guessed_letters)
{
    bool winStatus=true;
    for(auto c:word_to_guess)
    {
        if(find(guessed_letters.begin(),guessed_letters.end(),c)!=guessed_letters.end())
        {
            cout<<c<<" ";
        }
        else
        {
            cout<<"_  ";
            winStatus=false;
        }
        
    }
    cout<<endl;
    return winStatus;
}
int main(int argc, char const *argv[])
{
    string word_to_guess=choose_word();
    vector<char> guessed_letters;
    bool winStatus=false;
    int lives=6;

    cout<<"Welcomw to The HANGMAN!"<<endl;
    while(lives>0)
    {
        cout<<"Lives Remaining : "<<lives<<endl;
        winStatus= display_word(word_to_guess,guessed_letters);
        if(winStatus)
        {
            cout<<"Congratulations!!! You Guessed the Right Word"<<word_to_guess<<endl;
            break;
        }
        char guess;
        cout<<"Guess a Letter: "<<endl;
        cin>>guess;
        guessed_letters.push_back(guess);

        if(word_to_guess.find(guess)!=string::npos)
        {
        
            cout<<"Correct Guess! "<<endl;
        }
        else
        {
         cout<<"Incorrect Guess! "<<endl;
         lives--;   
        }
    }
    if(lives==0)
    {
     cout<<"You Lost ! Better Luck Next Time "<<endl;
     cout<<"The word was:  "<<word_to_guess<<endl;
    }
    return 0;
}
