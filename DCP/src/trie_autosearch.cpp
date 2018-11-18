//
// Created by Ashwath on 18.11.18.
//

#include <iostream>

/* Start of TRIE structure */
const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    bool isEndWord;
};

TrieNode* getNode(void){
    TrieNode *node = new TrieNode;
    node->isEndWord = false;
    for(int i=0; i<ALPHABET_SIZE; i++){
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, std::string word){
    TrieNode *node = root;
    for(int i=0; i<word.length(); i++){
        int index = word[i]-'a';
        if(!node->children[index]){
            node->children[index] = getNode();
        }
        node = node->children[index];
    }
    node->isEndWord = true;
}

bool search(TrieNode *root, std::string key){
    TrieNode *node = root;
    for(int i=0; i<key.length(); i++){
        int index = key[i]-'a';
        if(!node->children[index]){
            return false;
        }
        node = node->children[index];
    }
    return (node!=NULL && node->isEndWord);
}
/* End of TRIE structure */

/* Autosearch function */
bool isLastNode(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

// Recursive function to print auto-suggestions for given
// node.
void suggestionsRec( TrieNode* root, std::string currPrefix)
{
    // found a string in Trie with the given prefix
    if (root->isEndWord)
    {
        std::cout << currPrefix;
        std::cout << std::endl;
    }

    // All children struct node pointers are NULL
    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            // append current character to currPrefix string
            currPrefix.push_back(97 + i);

            // recur over the rest
            suggestionsRec(root->children[i], currPrefix);
            currPrefix.pop_back();
        }
    }
}

// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const std::string query)
{
    struct TrieNode* pCrawl = root;

    // Check if prefix is present and find the
    // the node (of last level) with last character
    // of given string.
    int level;
    int n = query.length();
    for (level = 0; level < n; level++)
    {
        int index = query[level]-'a';

        // no string in the Trie has this prefix
        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    // If prefix is present as a word.
    bool isWord = (pCrawl->isEndWord == true);

    // If prefix is last node of tree (has no
    // children)
    bool isLast = isLastNode(pCrawl);

    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (isWord && isLast)
    {
        std::cout << query << std::endl;
        return -1;
    }

    // If there are are nodes below last
    // matching character.
    if (!isLast)
    {
        std::string prefix = query;
        suggestionsRec(pCrawl, prefix);
        return 1;
    }
}


int main()
{
    struct TrieNode* root = getNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    int comp = printAutoSuggestions(root, "h");

    if (comp == -1)
        std::cout << "No other strings found with this prefix\n";

    else if (comp == 0)
        std::cout << "No string found with this prefix\n";

    return 0;
}
