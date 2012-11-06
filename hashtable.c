//
//  hashtable.c
//  HashTable
//
//  Created by 孙 旭 on 12-11-6.
//  Copyright (c) 2012年 孙 旭. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"

#ifdef ENABLE_DEBUG
#define TRACE(str,para1,para2,para3) \
do{ \
printf(str,para1,para2,para3); \
}while(0);
#else
#define TRACE(str,para1,para2,para3) 
#endif

typedef struct hash_node {
    int                     key;                //key
    int                     value;              //value
    struct hash_node *      next;               //next node
}node;
typedef node* pnode;

//add element to hash table list
static bool add_list_element(pnode head, int key, int value){
    if(NULL == head){//invalid input
        return false;
    }
    
    //find the tail of the list
    while(NULL != head->next){
        head = head->next;
    }
    
    //create new node
    pnode new_node      = malloc(sizeof(node));
    if(NULL == new_node){//memory allocation failure
        return false;
    }
    new_node->key       = key;
    new_node->value     = value;
    new_node->next      = NULL;
    
    //add the new node to the tail
    head->next         = new_node;
    
    TRACE("add new node to list,\t\t addr=%p,\t key=%d,\t value=%d \n",
          new_node, key, value);
    return true;
}

//remove elemen from list
static void remove_list_element(pnode parent_node){
    if(NULL == parent_node || NULL == parent_node->next){//invalid input
        return ;
    }
    
    //connect next node to pre node
    pnode old_node = parent_node->next;
    parent_node->next = old_node->next;
    
    TRACE("remove node from list,\t\t addr=%p,\t key=%d,\t value=%d \n",
          old_node, old_node->key, old_node->value);
    free(old_node);//free memery
}

//remove list
static void remove_list(pnode head){
    pnode next = NULL;
    while (NULL != head) {
        next = head->next;
        TRACE("remove list,\t\t\t\t addr=%p,\t key=%d,\t value=%d \n",
              head, head->key, head->value);
        free(head);         //remove head node
        head = next;        //next node is head
    }
}

static pnode        hash_table = NULL;      //pointer to hash bable
static int          hash_size;              //hash table size

//count hash value
static int hash_value(int key){
    return key % hash_size;
}

//creat hash table
bool init_hash_tab(int size){
    if(NULL != hash_table){
        return false;
    }
    
    hash_size = size;
    hash_table = malloc(sizeof(node) * hash_size);
    if(NULL == hash_table){
        return false;
    }
    memset(hash_table, 0, sizeof(node) * hash_size);
    TRACE("init hash table,\t\t\t addr=%p,\t size=%d,\t null=%d \n",
          hash_table, hash_size, 0);
    return true;
}

//destroy hash table
void destroy_hash_tab(){
    if(NULL == hash_table){
        return ;
    }
    
    for (int i = 0; hash_size > i; i++) {//free hash table list
        TRACE("remove hash table list,\t\t hash=%d,\t head=%p,\t null=%d \n",
              i, hash_table[i].next, 0);
        remove_list(hash_table[i].next);
    }
    TRACE("destroy hash table,\t\t addr=%p,\t null=%d,\t null=%d \n",
          hash_table, 0, 0);
    free(hash_table);//free hash table
    hash_table = NULL;
}

//add element to hash table
int insert_hash_tab(int key, int value){
    int hash = hash_value(key);     //count hash value
    add_list_element(&hash_table[hash], key, value);
    TRACE("add element to hash table,\t hash=%d,\t key=%d,\t value=%d \n",
          hash, key, value);
    return hash;
}

//delete element from hash table
bool remove_hash_element(int key){
    int hash = hash_value(key);     //count hash value
    pnode head = &hash_table[hash];
    while(NULL != head->next){
        if(key == head->next->key){
            TRACE("remove element from table,\t addr=%p,\t key=%d,\t value=%d \n",
                  head->next, head->next->key, head->next->value);
            remove_list_element(head);
            return true;
        }
        head = head->next;
    }
    TRACE("remove element failed, \t\t key=%d,\t null=%d,\t null=%d \n",
          key, 0, 0);
    return false;
}

//search element from hash table
bool search_hash_tab(int key, int* value){
    int hash = hash_value(key);     //count hash value
    pnode head = hash_table[hash].next;
    while(NULL != head){
        if(key == head->key){
            *value = head->value;
            TRACE("search element from table,\t addr=%p,\t key=%d,\t value=%d \n",
                  head, head->key, head->value);
            return true;
        }
        head = head->next;
    }
    TRACE("search element failed, \t\t key=%d,\t null=%d,\t null=%d \n",
          key, 0, 0);
    return false;
}
