/*
 * =====================================================================================
 *
 *       Filename:  fcache_list.h
 *
 *    Description:  fcache list, this is not a thread-safe version
 *
 *        Version:  1.0
 *        Created:  08/17/2012 10:30:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  finaldie
 *
 * =====================================================================================
 */

#ifndef _FCACHE_LIST_H_
#define _FCACHE_LIST_H_

typedef struct _fcache_node_t {
    void*   data;
} fcache_node_t;

typedef struct _fcache_list_mgr fc_list;

fc_list*        fcache_list_create();
void            fcache_list_destory(fc_list* plist);
int             fcache_list_empty(fc_list* plist);
fcache_node_t*  fcache_list_make_node();
void            fcache_list_destory_node(fcache_node_t* node);
int             fcache_list_push(fc_list* plist, fcache_node_t* node, size_t size);
fcache_node_t*  fcache_list_pop(fc_list* plist);
fcache_node_t*  fcache_list_delete_node(fcache_node_t* node);
void            fcache_list_update_node(fcache_node_t* node, size_t size);
int             fcache_list_move_node(fcache_node_t* node, fc_list* to);
size_t          fcache_list_size(fc_list* plist);
size_t          fcache_list_data_size(fc_list* plist);
size_t          fcache_list_node_size(fcache_node_t* node);
fc_list*        fcache_list_node_owner(fcache_node_t* node);

#endif