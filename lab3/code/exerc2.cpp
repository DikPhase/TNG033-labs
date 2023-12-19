/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   
#include <fstream>
#include <cassert>
#include <algorithm>


// A function to test the output of the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

std::string lowerCase(std::string& str);

std::string removeSpecialChars(const std::string& str);

/***************************
 * Main function           *
 **************************/

int main() {  
    std::cout << "Text file: ";
	std::string file_name;
	std::cin >> file_name;

	std::ifstream in_File{"../code/" + file_name};  // modify path, if needed

	if (!in_File) {
		std::cout << "Could not open input file!!\n";
		return 0;
	}
    
    std::map<std::string, int> table;
    int counter{0};  // Count total words from in_File

    //ADD CODE to build table
    std::string words;
    while (in_File >> words) {                // Read in word from in_File 
        std::string line = lowerCase(words);  // Convert word to lowercase
        table[removeSpecialChars(line)] += 1; // Remove special chars and add the word to the table.
        counter++;                            // Do += 1 to increment the assiciated word and count number of times in the map
    }
    std::vector<std::pair<std::string, int>> freq;

    //ADD CODE to build vector freq
    std::transform(table.begin(), table.end(), std::back_inserter(freq), // Copy everything from 'table' map and put in 'freq' vector
        [](const std::pair<const std::string, int>& element) { return element;});
    
    std::sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; // Decending order. If true then 'a' pair shoudl come before 'b' pair
        }
        return a.first < b.first;  // Using < with strings is comparing the alphabetical order 
        });
    for (auto e : freq) {
        std::cout << e.first << " " << e.second << "\n"; // Print the vector to console
    }


    /* ************** Testing **************** */

    test(table, freq, file_name, counter);
}


/*******************************
 * Test implementation         *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"../code/out_" + file_name}; //modify path, if needed

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }

    /*
     * uppgift1_kort: 69 words
     * uppgift1.txt: 1063 words
     */
    assert(total == n);    // test if total number of words is correct
    assert(t == result1);  // test if map/table contents are correct

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    assert(v == result2);  // test if vector contents are correct

    std::cout << "\nPassed all tests successfully!!\n";
}


// Change all chars to a uniform 'case'. i.e either uppercase or lowercase
std::string lowerCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char i) {return std::tolower(i); });
    return str;
}


// Remove special chars unless they are ' or - 
std::string removeSpecialChars(const std::string& str) {
    std::string result;
    // Remove chars that sets true for std::ispunct(), place chars at end of result string through back_inserter iterator
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result), [](unsigned char i) { return std::ispunct(i) && i != '\'' && i != '-'; });
    return result;
}