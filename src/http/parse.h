/*
 *      Filename: src/http/parse.h
 *      Author: Anders - qinyuanlong@gmail.com
 *      Create: 2018-05-03 15:09:31
 */


#ifndef _PARSE_H_INCLUDE
#define _PARSE_H_INCLUDE

// the request line in http first line.
// example:  GET /pub/WWW/TheProject.html HTTP/1.1
struct request_info {
	char    *path;     // request path
	char    *method;   // get,post,etc
	char    *version;  // http version
}

struct head_info{
    char *host;
	char *user_agent;
	char *content_type;
	char *content_length;
	char *connection;
}

struct body_info{
	char *body;
}

#endif
