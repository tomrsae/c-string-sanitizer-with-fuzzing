#include <stdlib.h>
#include <string.h>

typedef struct MapNode {
    char key;
    char* val;
    int val_len;

    struct MapNode* next;
} MapNode;

MapNode* generate_illegal_char_map() {
    MapNode* n3 = malloc(sizeof(MapNode));
    MapNode* n2 = malloc(sizeof(MapNode));
    MapNode* n1 = malloc(sizeof(MapNode));

    n3->key = '&';
    n3->val = "&amp;";
    n3->next = NULL;
    n3->val_len = 5;

    n2->key = '<';
    n2->val = "&lt;";
    n2->next = n3;
    n2->val_len = 4;

    n1->key = '>';
    n1->val = "&gt;";
    n1->next = n2;
    n1->val_len = 4;

    return n1;
}

char* sanitize(const char* input_str, int size) {
    char* str = malloc(sizeof(char));
    *str = '\0';

    if (input_str == NULL || size < 2)
        return str;

    MapNode* p_map = generate_illegal_char_map();

    int curr_len = 1;
    for (int i = 0; i < size; i++) {
        const char* concat_str = &input_str[i];
        int concat_len = 1;

        for (MapNode *p_node = p_map;
            p_node != NULL;
            p_node = p_node->next)
        {
            if (input_str[i] == p_node->key) {
                concat_str = p_node->val;
                concat_len = p_node->val_len;
                break;
            }
        }

        str = realloc(str, curr_len + concat_len);
        strncat(str, concat_str, concat_len);
        curr_len += concat_len;
    }

    while (p_map != NULL) {
        MapNode* p_temp = p_map;
        p_map = p_map->next;
        free(p_temp);
    }

    return str;
}