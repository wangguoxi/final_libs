/*
 * =====================================================================================
 *
 *       Filename:  fev.h
 *
 *    Description:  a light-weight event framework
 *
 *        Version:  1.0
 *        Created:  11/13/2011 15:15:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  finaldie
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef _FEV_H_
#define _FEV_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct fev_state fev_state;

// fev fd mask
#define FEV_NIL     0x0
#define FEV_READ    0x1
#define FEV_WRITE   0x2
#define FEV_ERROR   0x4

typedef void (*pfev_read)(fev_state*, int fd, int mask, void* arg);
typedef void (*pfev_write)(fev_state*, int fd, int mask, void* arg);

fev_state* fev_create(int max_ev_size);
void fev_destroy(fev_state*);
int  fev_poll(fev_state*, int timeout);

int  fev_reg_event(fev_state*, int fd, int mask, pfev_read, pfev_write, void* arg);
int  fev_add_event(fev_state*, int fd, int mask);
int  fev_del_event(fev_state*, int fd, int mask);
int  fev_get_mask(fev_state*, int fd);
int  fev_get_fd(fev_state*);

typedef struct fev_module_t {
    const char* name;
    void  (*fev_module_unload)(fev_state*, void* ud);
    void* ud;
} fev_module_t;

int   fev_register_module(fev_state*, fev_module_t*);
void* fev_get_module_data(fev_state*, const char* module_name);

#ifdef __cplusplus
}
#endif

#endif
