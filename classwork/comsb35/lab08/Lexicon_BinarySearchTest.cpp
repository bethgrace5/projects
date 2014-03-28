/*
 * A program that exercises the Lexicon class.
 *
 * @author      Bethany Armitage
 * Course:      COMS B35
 * Created:     Thu 03/27/2014 
 * Source File: Lexicon_BinarySearchTest.cpp 
 */

#include "Lexicon.h"
#include "LexiconBinarySearch.h"
#include "LexiconLazyBinarySearch.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char*argv[]) {
   string filename("Enhanced North American Benchmark Lexicon.txt");
   if(argc == 2) {
      filename = argv[1];
   }
   cout << CLOCKS_PER_SEC << " CLOCKS_PER_SEC\n";
   string word;
   clock_t t0, t1;
   double seconds;
   LexiconLazyBinarySearch lexiconLazyBinarySearch(filename);
   LexiconBinarySearch lexiconBinarySearch(filename);
   Lexicon lexicon(filename);

   word = "aa";
   if(!lexicon.isWord(word))
      cout << "Error looking up " << word << endl;

   word = "zyzzyvas";
   if(!lexicon.isWord(word))
      cout << "Error looking up " << word << endl;

   word = "henbane";
   if(!lexicon.isWord(word))
      cout << "Error looking up " << word << endl;

   word = "axaxax";
   if(lexicon.isWord(word))
      cout << "Error looking up " << word << endl;

   word = "zzzzzzzzzz";
   if(lexicon.isWord(word))
      cout << "Error looking up " << word << endl;

   int iterations = 10000;

   t0 = clock();
   for(int i = 0; i < iterations; ++i) {
      lexiconBinarySearch.isWord("zydeco");
      lexiconBinarySearch.isWord("henbane");
   }
   t1 = clock();
   seconds = (double) (t1 - t0) / CLOCKS_PER_SEC;
   cout << seconds << " Seconds for regular binary search ("
               << iterations << " iterations)" << endl;

   t0 = clock();
   for(int i = 0; i < iterations; ++i) {
      lexiconLazyBinarySearch.isWord("zydeco");
      lexiconLazyBinarySearch.isWord("henbane");
   }
   t1 = clock();
   seconds = (double) (t1 - t0) / CLOCKS_PER_SEC;
   cout << seconds << " Seconds for lazy binary search ("
               << iterations << " iterations)" << endl;

   t0 = clock();
   for(int i = 0; i < iterations/100; ++i) {
      lexicon.isWord("zydeco");
      lexicon.isWord("henbane");
   }
   t1 = clock();
   seconds = (double) (t1 - t0) / CLOCKS_PER_SEC;
   cout << seconds << " Seconds for linear search ("
               << iterations/100 << " iterations)" << endl;
}
