#ifndef _RUCH_H
#define _RUCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct _Map
{
    int x;
    int y;
    char typ;
} Map;

typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;
int explore(char *token);
int move(char *token);
int rotate_rigt(char *token);
int rotatr_left(char *token);
char * make_request(char *url);
static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp);

#endif