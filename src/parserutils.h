#ifndef _PU
#define _PU
#include "parserDef.h"


// parse tree data structures
typedef union _treeData treeData;

// typedef struct {
// 	token T;
// 	t_node* child;
// 	t_node* sibling;
// } leafnode;

// typedef struct {
// 	nonterminal NT;
// 	t_node* child;
// 	t_node* sibling;
// } nlnode;

union _treeData {
	token T;
	nonterminal NT;
};

typedef struct _tnode{
	int TorNT; // tag (T:0, NT:1)
	struct _tnode* sibling;
	struct _tnode* children;
	treeData data;
} t_node;



// union node {
// 	nlnode n;
// 	leafnode l;
// };

// stack
typedef struct _stacknode {
	symbol S;
	int TorNT; // 0: T, 1: NT
	struct _stacknode* next;
	t_node* treeptr;
} stacknode;


typedef struct {
	stacknode* top;
} stack;


stacknode* createNode(symbol S, int TorNT);

stacknode* deepCopy(rhsnode* rhs);

void push(stack* s, stacknode* newNode);

t_node* pop(stack* s, int n);

nonterminal getNonTerminal(char* str);

char* getNonTerminalName(nonTermid ntid);

terminal getTerminal(char* str);

char* getTerminalName(tokenid tid);

#endif