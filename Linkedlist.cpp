/********************************************************    
    Review of C++. 
    7/1/2019
    review of nodes and linked-list. Functions included:
        insert_head
        insert_middle
        delete_node
        searh_node
 ********************************************************/
#include<iostream>
#include<cstring>
using namespace std;

struct ListNode
{
    int count;
    string item;
    ListNode* next;
};

typedef ListNode* ListNodePtr;

void head_insert(ListNodePtr& head, int& lengthList);
/* You should always keep one pointer bariable pointing to
   the head of a linked list. This pointer baribale is a 
   way to name the linked list. 
   This function creates new dynamic variable, add data 
   make the new node point to the head node and make the 
   head pointer points to the new node. */

void print_list(ListNodePtr node, int lengthList);
/* Print the content of the node */

ListNodePtr seach(ListNodePtr head, string target, int& num);
/* shearch funciton for the linked list */

void print_node(ListNodePtr node, int num);
/* print the infromation on a single node and determine 
   what happen next */

void insert_middle(ListNodePtr& after_me, int& lengthList);
/* This function inserts node after the pointer that is
   passed and increment the length by 1. */

void delete_node(ListNodePtr head, int num, int &lengthList);
/* This function deletes the node right after the pointer
   that is passed in and decrement the length by 1. */

int main(void)
{
    string branch;
    int lengthList = 1;
    int num;
    ListNodePtr head, find;
    head = new ListNode;
    
    /* There are two ways of modifiying the data in the node.
       We can treate it like a pointer that points to the 
       variable in the struct. */
    (*head).count = 10;

    /* Or we can use the -> arrow operator, which combines 
       the actions of a dereferencing operator * and a dot 
       operator to specify a member of a dynamic struct or 
       object that is pointed to by a given pointer. */
    head->count = 12; 
    head->item = "egg";
    head->next = NULL;

    print_list(head, lengthList);

    for (int i=0; i<5; i++)
    {
        head_insert(head, lengthList);
    }
    
    print_list(head, lengthList);

    find = seach(head, "key", num);
    print_node(find, num);

    cout << "Insert, Delete or Quit program? ";
    cin  >> branch;

    if (branch == "Insert"||branch == "insert")
    {
        insert_middle(find, lengthList);
    }
    else if (branch == "Delete" || branch == "delete")
    {
        delete_node(head, num, lengthList);
    }

    print_list(head, lengthList);
    cout << "End of program.\n";
    return 0;
}

void head_insert(ListNodePtr& head, int& lengthList)
{
    // 1. Create new temp_ptr and new node.
    ListNodePtr temp_ptr;
    temp_ptr = new ListNode;

    // 2. Add data in
    cout << "Enter Item Name: ";
    cin  >> temp_ptr->item;
    cout << "Enter Item Quantity: ";
    cin  >> temp_ptr->count;

    // 3. New node points to the previous head node.
    temp_ptr->next = head;
    
    // 4. Head pointer points to the new node.
    head = temp_ptr;
    lengthList++;
}

void print_list(ListNodePtr node, int lengthList)
{   
    // keep looping until the list has no more next node.
    // careful that we don't want to modify the NodePtr node
    // that we passed in this function.
    ListNodePtr here=node;
    cout << endl;
    do  
    {
        cout << "You need to buy " << (*here).count << " "
             << (*here).item << "(s)." << endl;
        here = here->next;
    } while (here != NULL);
    cout << "This list has " << lengthList << " node(s)\n\n"; 
}

ListNodePtr seach(ListNodePtr head, string target, int& num)
{
    ListNodePtr here=head;
    num = 1;
    while (here->next != NULL&&here->item != target)
    {   
        here = here->next;
        num++;
    }
    if (here->item == target)
    {
        return here;
    } else 
    {
        return NULL;
    }
}

void print_node(ListNodePtr node, int num)
{
    if (node==NULL)
    {
        cout << "Did not find the key.\n";
    } else 
    {
        cout << "You find " << (*node).count << " "
             << (*node).item << "(s)." << endl;
        cout << "This is the " << num
             << "th node in the list.\n\n";
    }
}

void insert_middle(ListNodePtr& after_me, int &lengthList)
{
    ListNodePtr tempPtr = new ListNode;

    // 1. Add data in
    cout << "Enter Item Name: ";
    cin >> tempPtr->item;
    cout << "Enter Item Quantity: ";
    cin >> tempPtr->count;

    // 2. Swap next node
    tempPtr->next = after_me->next;
    after_me->next = tempPtr;
 
    // 3. Length increment by one
    lengthList++;
}

void delete_node(ListNodePtr head, int num, int& lengthList)
{
    ListNodePtr tempPtr;
    ListNodePtr before = head;

    for (int i=1; i<num-1; i++)
    {
        before = before->next;
    }
    // 1. unlink after_me from the adjacent node.
    tempPtr = before->next;
    before->next = tempPtr->next;

    // 2. return the memory back to the heap space. 
    delete tempPtr; 

    // 3. decrement list length.
    lengthList--;
}