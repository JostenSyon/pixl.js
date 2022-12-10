#ifndef MUI_LIST_VIEW_H
#define MUI_LIST_VIEW_H

#include "mui_mlib.h"
#include "m-array.h"
#include "m-string.h"
#include "mui_defines.h"
#include "mui_include.h"
#include <stdint.h>

struct mui_list_item_s;
typedef struct mui_list_item_s mui_list_item_t;
struct mui_list_view_s;
typedef struct mui_list_view_s mui_list_view_t;

typedef enum {
    MUI_LIST_VIEW_EVENT_SELECTED,
    MUI_LIST_VIEW_EVENT_LONG_SELECTED,
} mui_list_view_event_t;

typedef void (*mui_list_view_selected_cb)(mui_list_view_event_t event, mui_list_view_t *p_list_view,
                                          mui_list_item_t *p_item);

struct mui_list_item_s {
    uint16_t icon;
    string_t text;
    void *user_data;
};

ARRAY_DEF(mui_list_item_array, mui_list_item_t, M_POD_OPLIST);

#define LIST_SCROLL_UP 0
#define LIST_SCROLL_DOWN 1

struct mui_list_view_s {
    mui_view_t *p_view;
    uint16_t focus_index;
    mui_list_view_selected_cb selected_cb;
    mui_list_item_array_t items;
    void *user_data;
    uint16_t scroll_offset;
    uint8_t scroll_direction;
};

mui_list_view_t *mui_list_view_create();
void mui_list_view_free(mui_list_view_t *p_view);
mui_view_t *mui_list_view_get_view(mui_list_view_t *p_view);
void mui_list_view_set_user_data(mui_list_view_t *p_view, void *user_data);

//// view functions //
void mui_list_view_add_item(mui_list_view_t *p_view, uint32_t icon, char *text, void *user_data);
void mui_list_view_set_item(mui_list_view_t *p_view, uint16_t index, uint32_t icon, char *text, void *user_data);
uint32_t mui_list_view_item_size(mui_list_view_t *p_view);
void mui_list_view_set_selected_cb(mui_list_view_t *p_view, mui_list_view_selected_cb selected_cb);
void mui_list_view_clear_items(mui_list_view_t *p_view);
void mui_list_view_set_focus(mui_list_view_t *p_view, uint16_t focus_index);
uint16_t mui_list_view_get_focus(mui_list_view_t *p_view);

#endif