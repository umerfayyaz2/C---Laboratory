#include <iostream>
using namespace std;

int vowel_counter_function(const string &text, int current_index = 0)
{
    // Base Case: if the the lenght of our string variable reaches our current index it'll return nothing.
    if (current_index == text.length())
    {
        return 0;
    }

    char current_char_position = text[current_index];

    bool is_vowel_checker = (current_char_position == 'a' || current_char_position == 'e' || current_char_position == 'i' || current_char_position == 'o' || current_char_position == 'u' ||
                             current_char_position == 'A' || current_char_position == 'E' || current_char_position == 'I' || current_char_position == 'O' || current_char_position == 'U');

    int vowel_counter = vowel_counter_function(text, current_index + 1); // recursive case to check the rest of the string

    return is_vowel_checker ? vowel_counter + 1 : vowel_counter; // this will return the total vowel count
}

int main()
{

    string random_words;
    cout << "Please write something to check how many vowels are there: ";
    getline(cin, random_words);
    cout << endl;

    int total_vowels = vowel_counter_function(random_words);

    cout << "The total number of vowels: " << total_vowels << endl;
}