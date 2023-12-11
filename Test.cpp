#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isValidSentence(const string& sentence) {
    // Rule 1: String starts with a capital letter.
    // Check if the first character at position 0 is uppercase; if it is not, return false.
    if (!isupper(sentence[0])) {
        return false;
    }

    // Rule 2: String has an even number of quotation marks.
    // Count the occurrences of '"' characters within the range [sentence.begin(), sentence.end()) and check if the count is even.
    int quotationMarkCount = count(sentence.begin(), sentence.end(), '"');
    if (quotationMarkCount % 2 != 0) {
        return false;
    }

    // Rule 3: String ends with one of the specified sentence termination characters.
    // Retrieve the last character of the string and check if it is not one of the specified terminators.
    char lastChar = sentence.back();
    if (!(lastChar == '.' || lastChar == '?' || lastChar == '!')) {
        return false;
    }

    // Rule 4: String has no period characters other than the last character.
    // Iterate through each character in the string, and if a period is found at a position other than the last character, return false.
    for (int j = 0; j < sentence.length(); j++) {
        if (sentence[j] == '.' && j != sentence.length() - 1) {
            return false;
        }
    }

    // Rule 5: Numbers below 13 are spelled out.
    // Iterate through each character in the string and, if a digit is encountered, extract the entire number sequence.
    // Attempt to convert the numeric sequence to an integer, and check if the resulting value is less than 13.
    // If the conversion fails (invalid argument), or the value is out of range, return false as the string violates the rule.

    for (int i = 0; i < sentence.length(); i++) {
        if (isdigit(sentence[i])) {
            string numberAsString = "";
            while (i < sentence.length() && isdigit(sentence[i])) {
                numberAsString += sentence[i];
                i++;
            }

            try {
                // Attempt to convert to int, and see if less than 13.
                if (stoi(numberAsString) < 13) {
                    return false;
                }
            }
            catch (const invalid_argument& ia) {
                cerr << "Invalid argument: " << ia.what() << endl;
                return false;
            }
            catch (const out_of_range& oor) {
                cerr << "Out of range please enter a smaller number: " << oor.what() << endl;
                return false;
            }
        }
    }

    // All rules passed, so the sentence is valid.
    return true;
}

int main() {
   
    cout << "Please enter a sentence: ";
    string sentence;
    getline(cin, sentence);
    // Output the result of the isValidSentence function. The ternary operator is used to print either "Valid sentence" or "Invalid sentence".
    cout << (isValidSentence(sentence) ? "Valid sentence" : "Invalid sentence") << endl;
    
    return 0;
}
