#include "graph.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void
insert_link(node_t *node1,
            node_t *node2,
            char *from_intf_name,
            char *to_intf_name,
            unsigned int cost){
    link_t *link = calloc(1, sizeof(link_t));

    strncpy(link->interface1.name,from_intf_name, INTERFACE_NAME_SIZE);
    link->interface1.name[INTERFACE_NAME_SIZE - 1] = '\0';
    strncpy(link->interface2.name, to_intf_name, INTERFACE_NAME_SIZE);
    link->interface2.name[INTERFACE_NAME_SIZE - 1] = '\0';

    link->interface1.link = link;
    link->interface2.link = link;

    link->interface1.node = node1;
    link->interface2.node = node2;

    int empty_intf_slot;

    empty_intf_slot = get_node_intf_available_slot(node1);
    node1->intf[empty_intf_slot];
    empty_intf_slot = get_node_intf_available_slot(node2);
    node2->intf[empty_intf_slot];
}
graph_t *
create_new_graph(char *topology_name)
{
	graph_t *graph = calloc(1, sizeof(graph_t));
	strncpy(graph->topology_name, topology_name, 32);
	graph->topology_name[32] = '\0';

	init_glthread(&graph->node_list);
	return graph;
}

node_t *
create_graph_node(graph_t *graph, char *node_name){

	node_t *node = calloc(1, sizeof(node_);
	strncpy(node->node_name, node_name, NODE_NAME_SIZE);
	node->node_name[NODE_NAME_SIZE] = '\0';

	init_glthread(&node->graph_glue);
	glthread_add-next(&graph->node_list, &node->graph_glue);
	return node;
}
