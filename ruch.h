#ifndef _RUCH_H
#define _RUCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"

typedef struct _Map
{
    cJSON *x;
    cJSON *y;
    cJSON *typ;

    struct _Map *next_x;
    struct _Map *next_y;

    struct _Map *prew_x;
    struct _Map *prew_y;

} Map;

typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;

char * explore(char *token);
char * move(char *token);
char * rotate_rigt(char *token);
char * rotatr_left(char *token);
char * make_request(char *url);
static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp);
char * supports_full_hd(char * monitor);

#endif