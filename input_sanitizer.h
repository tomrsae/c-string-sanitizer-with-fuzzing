#include <stdlib.h>
#include <string.h>

typedef struct MapNode {
    char key;
    char* val;

    struct MapNode* next;
} MapNode;

MapNode* generate_illegal_char_map() {
    MapNode* n3 = malloc(sizeof(MapNode));
    MapNode* n2 = malloc(sizeof(MapNode));
    MapNode* n1 = malloc(sizeof(MapNode));

    n3->key = '&';
    n3->val = "&amp;\0";
    n3->next = NULL;

    n2->key = '<';
    n2->val = "&lt;\0";
    n2->next = n3;

    n1->key = '>';
    n1->val = "&gt;\0";
    n1->next = n2;

    return n1;
}

char* sanitize(const char* str) {
    if (str == NULL) return "\0";
    
    int len = strlen(str);
    if (len < 2) return "\0"; 

    char* temp_str = NULL;
    MapNode* p_map = generate_illegal_char_map();

    for (int i = 0; i < len; i++) {
        int realloc_sz = 1;
        const char* replace_val = NULL;
        MapNode* p_node = p_map;

        while (p_node != NULL) {
            if (str[i] == p_node->key) {
                replace_val = p_node->val;
                realloc_sz = strlen(replace_val);
                break;
            }

            p_node = p_node->next;
        }

        int curr_len = 0;
        if (temp_str != NULL)
            curr_len = strlen(temp_str);

        int new_len = curr_len + realloc_sz + 1;
        temp_str = realloc(temp_str, new_len);
        if (replace_val == NULL) {
            replace_val = &str[i];
        }
        
        strncat(temp_str, replace_val, realloc_sz);
        temp_str[new_len] = '\0';
    }

    while (p_map != NULL) {
            MapNode* p_temp = p_map;
            p_map = p_map->next;
            free(p_temp);
    }

    return temp_str;
}