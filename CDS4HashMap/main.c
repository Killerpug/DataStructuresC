#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Hash_Map.h"

int main() {
    srand(time(NULL));
    Hash_Table* table1 = create_map();
    Hash_Table* table2 = create_map();
    for (int i = 0; i < 50; ++i) {
        add_mtomap(1, "exfeu", &table1);
        add_mtomap(2, "exfeu", &table1);
        add_mtomap(3, "exfeu", &table1);
        add_mtomap(4, "exfej", &table1);
        add_atomap(6, &table1);
        add_atomap(7, &table1);
        add_atomap(8, &table1);
        add_atomap(9, &table1);
        add_atomap(1, &table1);

    }
    add_atomap(1, &table2);
    add_mtomap(5, "exfet", &table2);
    add_mtomap(6, "exfey", &table2);
    add_mtomap(8, "exfeu", &table1);
    printf("map is empty? %d\n", is_empty_map(table2));
    printf("key is contained?: %d\n", contains_key("exfeu", table1));
    printf("item is contained?: %d\n", contains_value(5, table1));
    //replace_entry(8,"exfeu", table1, ALL);
    T data = get_entry("exfeu", table1);
    print_map(table1);
    remove_entry("exfej", &table1, ALL);
    remove_entry("exfey", &table2, FIRST);
    print_map(table2);
    clear_map(table1);
    clear_map(table2);

    return 0;
}