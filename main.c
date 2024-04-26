

#include "gluethread/glthread.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct __attribute__((__packed__)) emp_ {
	char name[30];
	unsigned int salary;
	char designation[30];
	unsigned int emp_id;
	glthread_node_t glnode;
} emp_t;

void print_emp_details(glthread_node_t *glnode){
	unsigned int offt = FIELD_OFFSET(emp_t, glnode);
	emp_t *tmp_emp = (emp_t*)(glnode - offt);
	printf("Name : %s\n Salary : %d\n Designation : %s\n ID : %d",
		tmp_emp->name,
		tmp_emp->salary,
		tmp_emp->designation,
		tmp_emp->emp_id);
}

int main()
{
	gldll_t *emp_list = 
		(gldll_t *)malloc(sizeof(gldll_t));
	

	emp_t* emp;
	emp = (emp_t *)malloc(sizeof(emp_t));

	memcpy(emp->name ,"saman", 5);
	emp->salary = 300000;
	memcpy(emp->designation, "unknown",7);
	emp->emp_id = 5;
	emp_list->head = &emp->glnode;
	

	print_emp_details(&emp->glnode);
	

	return 0;
}
