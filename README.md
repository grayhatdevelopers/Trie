# Trie
A suffix trie implementation for the lowercase English language, with a spellchecker implementing the Levenshtein Distance Algorithm.
Author: Saad Bazaz

Please use dictionary.txt, as the program is currently tweaked to read dictionaries in that format. You can alter it to 
however you like.
If you find a way to improve the implementation, don't hesitate to message or send a pull request!

This file also contains the C++ implementation of Levenshtein distance algorithm combined with Suffix Trie.
Comments starting with '#' belong to the original author, Steve Hanov, who wrote it in Python for Rhymebrain.com (2011).

	// References:
	// 1. http://stevehanov.ca/blog/?id=114
	// 2. https://en.wikipedia.org/wiki/Levenshtein_distance
	// 3. http://norvig.com/spell-correct.html
	// 4. https://dzone.com/articles/the-levenshtein-algorithm-1
	// 5. https://en.wikipedia.org/wiki/BK-tree
	// 6. https://news.ycombinator.com/item?id=9737554
