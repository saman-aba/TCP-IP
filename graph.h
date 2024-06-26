#include "gluethread/glthread.h"

#define INTERFACE_NAME_SIZE     16
#define NODE_NAME_SIZE          16
#define MAX_INTF_PER_NODE       10

typedef struct node_ node_t;
typedef struct link_ link_t;
typedef struct glthread_ {}glthread_t;

typedef struct interface_ {
    char name[INTERFACE_NAME_SIZE];
    struct node_ *node;
    struct link_ *link;
} interface_t;

struct link_{

    interface_t interface1;
    interface_t interface2;
    unsigned int cost;
};

struct node_{
    char name[NODE_NAME_SIZE];
    interface_t *intf[MAX_INTF_PER_NODE];
    glthread_t graph_glue;
    unsigned int udp_port_number;
    int udp_sock_fd;
};

typedef struct graph_{
    char topology_name[32];
    glthread_t node_list;
}graph_t;

graph_t *create_new_graph(char *topology_name);
node_t *create_graph_node(graph_t *graph, 
		char *node_name);
void insert_link_between_two_nodes(node_t *node1, 
		node_t *node2, 
		char *from_interface_name, 
		char *to_interface_name, 
		unsigned int cost)

