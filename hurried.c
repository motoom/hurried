#include <stdio.h>
#include <stdlib.h>

// ?? cond ??

char *template = " \n\
	$$: 'You like this?'\n\
	$$ answers: 'Sure!'\n\
	$$ adds: 'Me too.'\n\
	";

typedef struct Node {
	char *str;
	struct Node *next;
	} Node;

void hurried(char *s, Node *vars)
{
	while(*s) {
		if (*s=='$' && *(s+1)=='$') {
			printf("%s", vars->str);
			vars = vars->next;
			s++;
			}
		else
			printf("%c", *s);
		s++;
		}			
}

// start=end=emptylist()
// append(end,newnode)
// append(end,newnode)
// append(end,newnode)

int main()
{
	Node *joe=(Node *)calloc(1, sizeof(Node));
	Node *start=joe;
	Node *end=start;
	start->str="Joe";

	Node *bob=(Node *)calloc(1, sizeof(Node));
	end->next=bob; end=bob;	
	bob->str="Bob";
	start->next=bob;

	Node *charlie=(Node *)calloc(1, sizeof(Node));
	end->next=charlie; end=charlie;
	charlie->str="Charlie";
	start->next=bob;

	
	hurried(template, start);
}
