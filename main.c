//
//  main.c
//  HashTable
//
//  Created by 孙 旭 on 12-11-6.
//  Copyright (c) 2012年 孙 旭. All rights reserved.
//

#include <stdio.h>
#include "hashtable.h"

int main(int argc, const char * argv[])
{
    int value = 0;
    
    init_hash_tab(10);
    
    insert_hash_tab(10, 20);
    insert_hash_tab(120, 45);
    insert_hash_tab(8, 54);
    insert_hash_tab(0, 78);
    insert_hash_tab(1, 97);
    insert_hash_tab(45, 879);
    insert_hash_tab(4, 5456);
    insert_hash_tab(19, 578);
    
    search_hash_tab(10, &value);
    printf("%d \n",value);
    search_hash_tab(120, &value);
    printf("%d \n",value);
    search_hash_tab(8, &value);
    printf("%d \n",value);
    search_hash_tab(0, &value);
    printf("%d \n",value);
    search_hash_tab(1, &value);
    printf("%d \n",value);
    search_hash_tab(45, &value);
    printf("%d \n",value);
    search_hash_tab(10, &value);
    printf("%d \n",value);
    search_hash_tab(453, &value);
    printf("%d \n",value);
    
    remove_hash_element(0);
    remove_hash_element(10);
    remove_hash_element(15);
    remove_hash_element(45);
    remove_hash_element(19);
    remove_hash_element(8);
    
    destroy_hash_table();
    
    return 0;
}

