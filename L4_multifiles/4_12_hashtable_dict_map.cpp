/*
Maps

So far in this course you have seen container data structures, like the vector and the array. 
Additionally, you have used classes in your code for this project. Container data structures are 
fantastic for storing ordered data, and classes are useful for grouping related data and functions together, 
but neither of these data structures is optimal for storing associated data.
Dictionary Example

A map (alternatively hash table, hash map, or dictionary) is a data structure that uses key/value pairs 
to store data, and provides efficient lookup and insertion of the data. The name "dictionary" should 
provide an excellent idea of how these work, since a dictionary is a real life example of a map. 
Here is a slightly edited entry from www.dictionary.com defining the word "word":

    word

        a unit of language, consisting of one or more spoken sounds or their written representation, 
        that functions as a principal carrier of meaning.
        speech or talk: to express one's emotion in words.
        a short talk or conversation: "Marston, I'd like a word with you."
        an expression or utterance: a word of warning.

Data Representation

If you were to store this data in your program, you would probably want to be able to quickly look up 
the definitions using the key "word". With a map, a vector of definitions could be stored as the value 
corresponding to the "word" key:
Key string 	Value vector<string>
"word" 	<"a unit of language, consisting of one or more spoken sounds or their written representation, 
that functions as a principal carrier of meaning.", "speech or talk: to express one's emotion in words.", "a short 
talk or conversation: 'Marston, I'd like a word with you.'", "an expression or utterance: a word of warning.">'

In the following notebook, you will learn how to use an unordered_map, which is the C++ standard library 
implementation of a map. Although C++ has several different implementations of map data structures 
which are similar, unordered_map is the structure that you will use in your project.

Dictionary Example in Code

In the cell below, we have created a hash table (unordered_map) to store the data from the example above. 
To create an unordered_map in C++, you must include the <unordered_map> header, and the sytnax for 
declaring an unordered_map is as follows:

unordered_map <key_type, value_type> variable_name;

In the code below, we check if the key is in the unordered_map using the .find() method. 
If the key does not exist in the map, then .find() returns an unordered_map::end() type. 
Otherwise, .find() returns a C++ iterator, which is a pointer that points to the beginning of 
the iterable key-value pair.

We haven't covered iterators in this course, and you won't need them for this project, 
but they are a lot like pointers that can "iterate" forward or backward through a range.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::cout;
using std::unordered_map;
using std::string;


int main() {
    // Create strings to use in the hash table.
    string key = "word";
    string def_1 = "a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
    string def_2 = "speech or talk: to express one's emotion in words";
    string def_3 = "a short talk or conversation: 'Marston, I'd like a word with you.'";
    string def_4 = "an expression or utterance: a word of warning";
    unordered_map <string, vector<string>> my_dictionary;

    // Check if key is in the hash table.
    if (my_dictionary.find(key) == my_dictionary.end()) {
        cout << "The key 'word' is not in the dictionary." << "\n";
        cout << "Inserting a key-value pair into the dictionary." << "\n\n";
        // Set the value for the key.
        my_dictionary[key] = vector<string> {def_1, def_2, def_3, def_4};
    }

    // The key should now be in the hash table. You can access the
    // value corresponding to the key with square brackets [].
    // Here, the value my_dictionary[key] is a vector of strings.
    // We iterate over the vector and print the strings.
    cout << key << ": \n";
    auto definitions = my_dictionary[key];
    for (string definition : definitions) {
        cout << definition << "\n";
    }
}
