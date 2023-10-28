#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "dlist.h"
//print list
static void print_dlist(const DList *dlist){
	DListNode *node;
	int *data, i;
	//print list size
	fprintf(stdout,"List size: %d\n", dlist_size(dlist));
	
	i = 0;
	node = dlist_head(dlist);
	
	while(1){
		data = dlist_data(node);
		fprintf(stdout,"list.node[%03d]=%03d, %p <- %p -> %p \n", i, *data,node->prev, node, node->next);
		
		i++;
		
		if(dlist_is_tail(node))
			break;
		else
			node = dlist_next(node);
		
	}
	return;
}

int main(int argc, char **argv){
	DList dlist;
	DListNode *node;
	int *data, i;
	int *counter;
	
	dlist_init(&dlist, free);
	//Fill the linked list
	node=dlist_head(&dlist);
	
	for(i=1;i<=10;i++){
		
		if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
            
        *data=i;    
	
		if(dlist_ins_next(&dlist, NULL, data)==NULL){
			dlist_ins_next(&dlist, NULL, data);
		}
		else
			dlist_ins_next(&dlist,dlist_tail(&dlist),data);
		
	
	}
	print_dlist(&dlist);
	system("pause");
	
	node = dlist_head(&dlist);
	for (i = 0; i < 7; i++)
	node = dlist_next(node);	  
	data = dlist_data(node);
    node = dlist_next(node);
    fprintf(stdout,"\nRemoving a node after the one containing: %03d\n", *data);
    dlist_remove(&dlist, node, (void**)&data);				
    print_dlist(&dlist);
  
    
    fprintf(stdout,"\nRemoving a node at the head.\n");
	dlist_remove(&dlist, dlist_head(&dlist), (void**)&data);
	print_dlist(&dlist);

	
	fprintf(stdout,"\nInserting 23 at the tail.\n");
	*data = 23;	
	dlist_ins_next(&dlist,dlist_tail(&dlist),data);	
	print_dlist(&dlist);

	
	node = dlist_head(&dlist);
	for(i = 0; i < 5; i++)
	node = dlist_next(node);
	data = dlist_data(node);
	
	fprintf(stdout,"\nInserting 47 before the one containing: %03d\n",*data);
	int new_data = 47;
	dlist_ins_prev(&dlist, node, &new_data);
	print_dlist(&dlist);
		
	
	fprintf(stdout,"\nRemoving a node before the tail.\n");
	node = dlist_tail(&dlist)->prev;
	dlist_remove(&dlist, node, (void**)&data);
	print_dlist(&dlist);

	// Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&dlist);
	
	return 0;
}
