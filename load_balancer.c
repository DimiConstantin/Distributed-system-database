/*
 * Copyright (c) 2024, <>
 */

#include "load_balancer.h"
#include "server.h"

load_balancer *init_load_balancer(bool enable_vnodes) {
	load_balancer *lb = malloc(sizeof(load_balancer));
    lb->hash_function_docs = hash_string;
    lb->hash_function_servers = hash_uint;
    lb->test_server = NULL;
    return lb;
}

void loader_add_server(load_balancer* main, int server_id, int cache_size) {
    /* TODO: Remove test_server after checking the server implementation */
    main->test_server = init_server(cache_size);
    main->test_server->id = server_id;
}

void loader_remove_server(load_balancer* main, int server_id) {
    /* TODO */
}

response *loader_forward_request(load_balancer* main, request *req) {
    return server_handle_request(main->test_server, req);
}

void free_load_balancer(load_balancer** main) {
    /* TODO: get rid of test_server after testing the server implementation */
    free_server(&(*main)->test_server);
    free(*main);

    *main = NULL;
}


