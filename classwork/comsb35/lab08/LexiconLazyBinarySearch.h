/**
* Defines LexiconLazyBinarySearch class
*
* @author      Bethany Armitage
* Course:      COMS B35
* Created:     Thu 03/27/2014 
* Source File: LexiconLazyBinarySearch.h
*/

#include <vector>
#include <string>
using namespace std;

#ifndef LEXICONLAZYBINARYSEARCH_H_
#define LEXICONLAZYBINARYSEARCH_H_

/**
 * A class that represents a list of words and that can be interrogated to
 * determine whether or not word exists in the list. The file that contains
 * the list of words is sent to the constructor.
 */

class LexiconLazyBinarySearch {
public:
	/**
	 * Initializes the lexicon, given the file name that contains the list
	 * of words.
	 * @param lexiconFileName file name that contains the list of words.
	 */
	LexiconLazyBinarySearch(string lexiconFileName);

	/**
     * searches for word in lexicon via a binary search algorithm that
     * does not check mid index each time through (lazy binary search)
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

#endif /* LEXICON_H_ */
