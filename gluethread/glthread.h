

#define FIELD_OFFSET( s, f) \
	(unsigned int)&((s*)0)->f
	
typedef struct glthread_node_ {
	struct glthread_node_ *left;
	struct glthread_node_ *right;
	
} glthread_node_t;

typedef struct gldll_{
	glthread_node_t *head;
	int (*key_match_fn)( void*, void*);
	int (*comparison_fn)( void*, void*);
	unsigned int offset;
} gldll_t;


