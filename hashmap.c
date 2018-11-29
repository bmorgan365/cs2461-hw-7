#include "hashmap.h"
#include <stdlib.h>
/**
 * REPLACE -Werror:
 *      -Wall -Wextra "-Werror" -pedantic
 */

/**
 * Allocate a new HashMap with the specified number of buckets
 */
struct hashmap* hm_create(int num_buckets){
    int i;
    //allocate memory for hashmap struct
    struct hashmap* hm = (struct hashmap*) malloc(sizeof(struct hashmap));
    //allocate memory for map(llnode**)
    hm->map = (struct llnode**) malloc(sizeof(struct llnode*) * num_buckets);
    //allocate memory for llnode elements of map and set next llnode to null
    for(i = 0; i < num_buckets; i++){
        hm->map[i] = (struct llnode*) malloc(sizeof(struct llnode));
        hm->map[i]->next = NULL;
    }

    return hm;
}

/**
 * return the value associated with the key that is passed in within the HashMap that is passed in.
 * If the element is not found, return -1
 */
int hm_get(struct hashmap* hm, char* word, char* document_id){
    return 0;
}

/**
 * Put the key value pair into the HashMap that is passed in. If the word and document id
 * combination already exists within the HashMap, its value will be overwritten with the new one
 */
void hm_put(struct hashmap* hm, char* word, char* document_id, int num_occurrences){

}

/**
 * Remove the key value pair in the HashMap that is associated with the given key
 */
void hm_remove(struct hashmap* hm, char* word, char* document_id){
    
}

/**
 * deallocate the HashMap that is passed in and all of its elements
 */
void hm_destroy(struct hashmap* hm){
    int i;
    //set next to null then deallocate memory for each bucket
    for(i = 0; i < hm->num_buckets; i++){
        hm->map[i]->next = NULL;
        free(hm->map[i]);
    }
    //deallocate memory for map of (llnode*)s
    free(hm->map);
    //deallocate memory for hashmap* struct
    free(hm);
}

/**
 * Take the given word and document id and map them to a bucket in the HashMap
 * Sum the ASCII codes of all of the characters then modulo by the # of buckets
 */
int hash(struct hashmap* hm, char* word, char* document_id){
    return 0;
}
