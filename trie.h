#ifndef TRIE_H_
#define TRIE_H_

#define NUM_CHARS (('z' - 'a') + 1)

struct node_t;
struct trie_t {
    struct node_t* root[NUM_CHARS];
};

#define TRIE_SUCCESS 0
#define TRIE_FAILURE -1
#define TRIE_WORD_NEW 1
#define TRIE_WORD_OLD 2

int trie_init(struct trie_t* trie);
int trie_add(struct trie_t* trie, const char * const word, int len);
int trie_destroy(struct trie_t* trie);


#endif // TRIE_H_
