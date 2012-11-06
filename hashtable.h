//
//  hashtable.h
//  HashTable
//
//  Created by 孙 旭 on 12-11-6.
//  Copyright (c) 2012年 孙 旭. All rights reserved.
//

#ifndef HashTable_hashtable_h
#define HashTable_hashtable_h

#include <stdbool.h>

#define ENABLE_DEBUG

//init hash table
bool init_hash_tab();

//insert element to hash table
int insert_hash_tab();

//delete element from hash table
bool remove_hash_element(int key);

//search element from hash table
bool search_hash_tab(int key, int* value);

//destroy hash table
void destroy_hash_tab();

#endif
