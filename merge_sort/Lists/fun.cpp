#include "CNode.h"
#include "fun.h"


void sort1(CNode**, int);
void merge(CNode**, CNode**);

void merge_sort(CNode** start){
	CNode* a = *start;
	int u = 0;
  if (*start != 0) {
	  while (a != 0) {
		  a = a->next;
		  u++;
	  }
	sort1(start, u);
  }
}

void sort1(CNode** start, int n) {
	if(n > 2) {
		CNode* a = *start;
		for (int i = 0; i < n/2 - 1; i++)
			a = a->next;
		CNode* b = a->next;
		a->next = 0;
		sort1(start, n/2);
		sort1(&b, n/2 + n%2);
		merge(start, &b);
	} else {
		if ((*start)->next != 0) {
			if ((*start)->next->val < (*start)->val) {
				CNode* l = (*start);
				*start = (*start)->next;
				(*start)->next = l;
				(*start)->next->next = 0;
			}
		}
	}
}

void merge(CNode** left, CNode** right) {
	CNode* t = new CNode();
	CNode* s1 = t;
	CNode* a = *left;
	CNode* b = *right;
	CNode* q;
	while ((a != 0) && (b != 0)) {
			if (a->val < b->val) {
				t->next = a;
				a = a->next;
				t = t->next;
			} else {
				t->next = b;
				b = b->next;
				t = t->next;
			}
	}
	if(a == 0) 
    t->next = b; 
  else 
    t->next = a;
	*left = s1->next;
	delete s1;
}





