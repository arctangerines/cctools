#include "list_util.h"

/// Add a path_access node to our cctools list
/// Perhaps this should return the temprary path_access var
void new_path_access_node(struct list *c,
		char *path,
		uint8_t access_fl)
{
	struct path_access *t = malloc(sizeof(struct path_access));
	t->read = (access_fl & READ_ACCESS) ? true : false;
	t->write = (access_fl & WRITE_ACCESS) ? true : false;
	t->stat = (access_fl & STAT_ACCESS) ? true : false;
	/// This string gotta be manually removed
	t->pathname = strdup(path);
	/// XXX: Maybe remove this from here?
	list_push_tail(c, t);
}

/// This is the function we pass list_clear to cleanup our cctools_list
void destroy_path_node(void *x)
{
	struct path_access *a = (struct path_access *)x;
	free(a->pathname);
	free(a);
}

/// Function to call at the __destructor
void destroy_contract_list(struct list *c)
{
	list_clear(c, destroy_path_node);
}

/// Search our cctools_list for the pathname
struct path_access *
find_path_in_list(struct list *c,
		char *path)
{
	list_first_item(c);
	void *x;
	while ((x = list_next_item(c))) {
		struct path_access *a = x;
		// XXX: Something of value here might be to check the tail before looping
		if (strcmp(a->pathname, path) == 0) {
			return a;
		}
	}
	return NULL;
}
