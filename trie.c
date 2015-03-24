#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define GET_BRANCH(c) ((c) > 'Z' ? (c) - 'a' : (c) - 'A')

struct node_t {
    struct node_t* branch[NUM_CHARS];
};

static int trie_create_node(struct node_t** node);
static void trie_destroy_node(struct node_t* node);

int trie_init(struct trie_t* trie) {
    if (!trie) { return TRIE_FAILURE; }
    memset(&(trie->root)[0], 0, sizeof(trie->root[0]) * NUM_CHARS);
    return TRIE_SUCCESS;
}

int trie_add(struct trie_t* trie, const char * const word, int len) {
    int i;
    int index;
    struct node_t* curr;
    int ret = TRIE_WORD_OLD;

    // handle first character separately
    index = GET_BRANCH(word[0]);
    if (!trie->root[index]) {
        if (trie_create_node(&(trie->root[index])) != TRIE_SUCCESS) {
            return TRIE_FAILURE;
        }
        ret = TRIE_WORD_NEW;
    }
    curr = trie->root[index];

    for (i = 1; i < len; ++i) {
        index = GET_BRANCH(word[i]);
        if (!curr->branch[index]) {
            if (trie_create_node(&(curr->branch[index])) != TRIE_SUCCESS) {
                return TRIE_FAILURE;
            }
            ret = TRIE_WORD_NEW;
        }
        curr = curr->branch[index];
    }
    return ret;
}

int trie_destroy(struct trie_t* trie) {
    int i;
    for (i = 0; i < NUM_CHARS; ++i) {
        if (trie->root[i]) {
            trie_destroy_node(trie->root[i]);
            trie->root[i] = 0;
        }
    }
    return TRIE_FAILURE;
}

int trie_create_node(struct node_t** node) {
    *node = malloc(sizeof(**node));
    if (!*node) { *node = 0; return TRIE_FAILURE; }
    memset(&((*node)->branch)[0], 0, sizeof(*node) * NUM_CHARS);
    return TRIE_SUCCESS;
}

void trie_destroy_node(struct node_t* node) {
    int i;
    for (i = 0; i < NUM_CHARS; ++i) {
        if (node->branch[i]) {
            trie_destroy_node(node->branch[i]);
        }
    }
    free(node);
    node = 0;
}

