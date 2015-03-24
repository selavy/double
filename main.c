#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define INPUT stdin
#define OUTPUT stdout

int main(int argc, char **argv) {
    struct trie_t trie;
    const char * word = "abcdeABCDE";
    const char * word2 = "abcdABCDEF";
    int ret;

    if (trie_init(&trie) != TRIE_SUCCESS) {
        perror("trie_init failed");
        exit(1);
    }

    ret = trie_add(&trie, word, strlen(word)+1);
    if (ret == TRIE_FAILURE) {
        perror("trie_add: failure");
        exit(1);
    } else if (ret == TRIE_WORD_NEW) {
        printf("%s: new word\n", word);
    } else {
        printf("%s: old word\n", word);
    }
    ret = trie_add(&trie, word, strlen(word)+1);
    if (ret == TRIE_FAILURE) {
        perror("trie_add: failure");
        exit(1);
    } else if (ret == TRIE_WORD_NEW) {
        printf("%s: new word\n", word);
    } else {
        printf("%s: old word\n", word);
    }
    ret = trie_add(&trie, word2, strlen(word2)+1);
    if (ret == TRIE_FAILURE) {
        perror("trie_add: failure");
        exit(1);
    } else if (ret == TRIE_WORD_NEW) {
        printf("%s: new word\n", word2);
    } else {
        printf("%s: old word\n", word2);
    }

    if (trie_destroy(&trie) != TRIE_SUCCESS) {
        perror("trie_destory failed");
        exit(1);
    }
    return 0;
}
