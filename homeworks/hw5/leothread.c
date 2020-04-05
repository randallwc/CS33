#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//create a node structure that has the number of the node and the label
struct node {
	int num;
	int label;
};

int leonard( int x )
{
	if(x == 1 || x == 0)
	{
		return 1;
	}
	// use recursion to get the numbers for the leonard tree
	return leonard(x - 1) + leonard(x - 2) + 1;
}

void *thread(void *vargp) /* Thread routine */
{
	//cast the void* to be a node*
	struct node* curr_node = (struct node*) vargp;

	//start the tree with the left child node
	struct node* l_child = malloc(sizeof(struct node));
	l_child->num = curr_node->num - 1;
	l_child->label = curr_node->label + 1;

	//check if curr_node num is less than or equal to 1 because if it is we must free it
	if(curr_node->num <= 1){
		printf("[%d]\n", curr_node->label);
		free(l_child);
		pthread_exit(NULL);
		return NULL;
	}
	
	//if we passed the last test and did not exit then this means this child node will have children
	if(l_child->num > 1){
		printf("(%d\n", l_child->label);
	}

	pthread_t thread_id;

	//create a child node for the l_child node recursively
	pthread_create(&thread_id, NULL, thread, l_child);
	pthread_join(thread_id, NULL);

	//print out the label again if num is greater than 1
	if(l_child->num > 1)
	{
		printf("%d)\n",l_child->label);
	}

	//free the left child
	free(l_child);

	//if the current node has a num greater than or equal to 2 then it will have a right child
	if(curr_node->num >= 2)
	{	
		//make a right child
		struct node* r_child = malloc(sizeof(struct node));

		pthread_t thread_id;

		r_child->num = curr_node->num - 2;
		r_child->label = curr_node->label + 1 + leonard((curr_node->num) - 1);

		//if the num of the r_child is more than 1 then it will have children so we print
		if(r_child->num > 1)
		{
			printf("(%d\n", r_child->label);
		}

		//create a child node for the r_child node recursively
		pthread_create(&thread_id, NULL, thread, r_child);
		pthread_join(thread_id, NULL);

		//if it had children then we print this
		if(r_child->num > 1)
		{
			printf("%d)\n",r_child->label);
		}

		//free the right child
		free(r_child);
	}
	return NULL;
}

int main(int argc, char **argv)
{
	//check for the two arguments {./(program name), N}
	if (argc != 2){
		printf("Must enter a positive int argument or you have invalid number of arguments\n");
		return -1;
	}

	//the arguments will be {./(program name), N}
	//convert strring to an interger
	int n = atoi(argv[1]);

	//check if n is less than or equal to 0 then return
	if ( n <= 0 ){
		printf("Must enter a positive non zero number for N\n");
		return -1;
	}

	//check if n is equal to 1
	if( n == 1 ){
		printf("[0]\n");
		return 0;
	}

	//make a main_node to start the tree
	struct node m_node;
	m_node.label = 0;
	m_node.num = n;

	//create the thread and print out the level
	pthread_t thread_id;
	printf("(0\n");

	//start the create and join thread for this thread tree
	pthread_create(&thread_id, NULL, thread, (void*)&m_node);
	pthread_join(thread_id, NULL);

	printf("0)\n");
	return 0;
}