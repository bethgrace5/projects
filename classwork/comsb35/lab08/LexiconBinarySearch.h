/**
* Defines Lexicon class
*
* @author      Bethany Armitage
* Course:      COMS B35
* created:     Thu 03/27/2014 
* Source File: LexiconBinarySearch.h
*/

#include <vector>
#include <string>
using namespace std;

#ifndef LEXICONBINARYSEARCH_H_
#define LEXICONBINARYSEARCH_H_

/**
 * A class that represents a list of words and that can be interrogated to
 * determine whether or not word exists in the list. The file that contains
 * the list of words is sent to the constructor.
 */

class LexiconBinarySearch {
public:
	/**
	 * Initializes the lexicon, given the file name that contains the list
	 * of words.
	 * @param lexiconFileName file name that contains the list of words.
	 */
	LexiconBinarySearch(string lexiconFileName);

	/**
	 * Searches for word using binary search algorithm
	 * @param word the word for which to search
	 * @return true if word exists in lexicon, and false otherwise
	 */
	bool isWord(string word);

private:
	vector<string> lexicon;

	/**
	 * Loads lexicon from lexiconFileName, exiting with an error message 
	 * on stderr if lexiconFileName cannot be opened.
	 * @param lexiconFileName file name that contains the list of words.
	 */
	void loadLexicon(string lexiconFileName);
};

#endif /* LEXICONBINARYSEARCH_H_ */
