#include "Lists\CNode.h"
#include "Lists\fun.h"
#include <gtest\gtest.h>

#include "stdlib.h"

CNode* cr(int* e, int len) {
	if(len == 0)
		return 0;
	else {
		CNode* start = new CNode();
		start->val = e[0];
		CNode* t = start;
		for (int i = 1; i < len; i++) {
			t->next = new CNode();
			t = t->next;
			t->val = e[i];
		}
		t->next = 0;
		return start;
	}
}

void del(CNode* a) {
  CNode* e;
  while(a != 0) {
    e = a;
    a = a->next;
    delete e;
  }
}


TEST(CNode, can_sort_empty_list)
{
  CNode* a = 0;
  ASSERT_NO_THROW(merge_sort(&a));
  EXPECT_EQ(a, (CNode*) 0);
}

TEST(CNode, can_sort_one_element_list)
{
  CNode* a = new CNode();
  CNode* b = a;
  a -> val = 1;
  a -> next = 0;
  ASSERT_NO_THROW(merge_sort(&a));
  EXPECT_EQ(a, b);
}

TEST(CNode, can_sort_few_elements_list)
{
  CNode* a;
  for (int size = 2; size < 20; size++) {
    int* mas = new int[size];
    for (int i = 0; i < size; i++) 
      mas[i] =  rand();
    a = cr(mas, size);
    ASSERT_NO_THROW(merge_sort(&a));
    int sum = 0;
    CNode* b = a;
    for (int i = 0; i < size-1; i++) { 
      sum += (b->val <= b->next->val);
      b = b->next;
    }
    EXPECT_EQ(sum, size-1);
    delete[] mas;
    del(a);
  }
}
