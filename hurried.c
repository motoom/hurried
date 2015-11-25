#include <stdio.h>
#include <stdlib.h>

char *template = " \n\
	$$ says: 'Are you going to the grocery?'\n\
	$$ says: 'Yes, I want to buy these articles:'\n\
	{{\
	 - a $$\n\
	}}\
	$$ says: 'Ok, cya lat0rz alligat0rz!'\n\
	";


typedef struct Node {
	char *str; // Initialize either 'str' or 'list', but not both. The other must be NULL.
	struct Node *list;
	struct Node *next; // Pointer to next node, NULL if this is the last node in the list.
	} Node;


char *expandrecursive(char *s, Node *vars, int level)
{
	char *anchor=s;
	
	while(*s) {
		if (*s=='$' && *(s+1)=='$') {
			printf("%s", vars->str);
			vars = vars->next;
			s+=2;
			}
		else if (*s=='{' && *(s+1)=='{') {
			s=expandrecursive(s+2, vars->list, level+1);
			vars = vars->next;
			}
		else if (*s=='}' && *(s+1)=='}') {
			if (vars)
				s=anchor;
			else
				return s+2;
			}
		else {
			printf("%c", *s);
			s++;
			}
		}
	return NULL;
}


void hurried(char *s, Node *vars)
{
	expandrecursive(s, vars, 0);
}



// start=end=emptylist()
// append(end,newnode)
// append(end,newnode)
// append(end,newnode)
//
// MAKENODE
// NEWLIST
// APPENDLIST

int main()
{
	// A node
	Node *joe=(Node *)calloc(1, sizeof(Node));
	joe->str="Joe";
	// A list (must have a node first)
	Node *start=joe, *end=joe; // first node in list

	Node *bob=(Node *)calloc(1, sizeof(Node));
	bob->str="Bob";
	end->next=bob; end=bob;	

		Node *lemon=(Node *)calloc(1, sizeof(Node));
		lemon->str="lemon";
		//
		Node *subliststart=lemon, *sublistend=lemon;

		Node *banana=(Node *)calloc(1, sizeof(Node));
		banana->str="banana";
		sublistend->next=banana; sublistend=banana;

	Node *articles=(Node *)calloc(1, sizeof(Node));
	articles->list=subliststart;
	end->next=articles; end=articles;	
	
	Node *charlie=(Node *)calloc(1, sizeof(Node));
	end->next=charlie; end=charlie;
	charlie->str="Charlie";
	
	hurried(template, start);
	
	// TODO: recursive dealloc
}
