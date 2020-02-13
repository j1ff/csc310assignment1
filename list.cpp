#include "list.h"
#include "myException.h"

/**************************** PUBLIC: Constructor ****************************/
/*
    Implementation hint(s): should initialize variables.
*/
list::list(void){
    p_Head = nullptr;
    p_Tail = nullptr;
    p_IsSorted = 1;   // 1 = TRUE
    p_NumberOfNodes = 0;
}

/**************************** PUBLIC: Destructor ****************************/
/*
    Implementation hint(s): Should ensure all dynamically allocated memory is deleted.
*/
list::~list(void){
 
}


/*****************************************************************************************/



/**************************** PUBLIC: appendValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to append value to end of list.
*/
void list::appendValue(int valueToAdd){
   p_InsertNode(valueToAdd);
}

/**************************** PUBLIC: deleteList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete the entire list.
*/
void list::deleteList(void){
    if(p_Head == nullptr){
        throw MyException("List is already empty!");
    } else {
        p_DeleteList();
    }
}

/**************************** PUBLIC: findValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to determine if node value is in list or not and notify user.
*/
s_NODE* list::findValue(int valueToFind){
    bool numberIsFound = false;
    bool allSearched = false;
    s_NODE *foundNode = nullptr;

    //if list is empty
    if(p_NumberOfNodes == 0){
        throw MyException("No values to search: List is empty!");
    //if list contains 1 value
    } else if(this->p_NumberOfNodes == 1){
        if(p_Head->value == valueToFind){
            foundNode = p_Head;
            return foundNode;
        }
    //if list has multiple values
    } else if(this->p_NumberOfNodes > 1){
        s_NODE *tmpHead = p_Head;
        s_NODE *tmpTail = p_Tail;
        //keep looping until value is found or all nodes have been visited
        while(foundNode == nullptr && allSearched == false){
            if(tmpHead->value == valueToFind){
                foundNode = tmpHead;
                return foundNode;
            } else if(tmpTail->value == valueToFind){
                foundNode = tmpTail;
                return foundNode;
            } else {
                //reset pointers for next while loop
                tmpHead = tmpHead->next;
                tmpTail = tmpTail->previous;
                //check to see if all nodes have been visited
                if(tmpHead == tmpTail->next || tmpTail == tmpHead){
                    allSearched = true;
                }    
            }
        }
        return foundNode;
    }
    
}

/**************************** PUBLIC: printList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to print the list to the screen. 
*/
void list::printList(void){
    if(this->p_NumberOfNodes == 0){
        throw MyException("Cannot print: List is empty!");
    } else {
    
        s_NODE *tmp = this->p_Head;
        
        for(int i = 0; i < this->p_NumberOfNodes; i++){
            cout<<tmp->value<<endl;
            tmp = tmp->next;
        }
        cout<<"-----End of List-----"<<endl;
    }
}

/**************************** PUBLIC: removeValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete value from list.
*/
void list::removeValue(int valueToRemove){
    p_DeleteNode(valueToRemove);    
}

/**************************** PUBLIC: sortList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to sort the list from smallest to largest.
*/
void list::sortList(void){
   int swapHelper;
   s_NODE *sortHelper;
   s_NODE *sortHelper2;
   
    if(this->p_IsSorted == 1){  //if list is already sorted
       //throw MyException("List is already sorted!");
        cout<<"List already sorted"<<endl;
    } else if(this->p_NumberOfNodes == 1){  //if list contains only one node
       //throw MyException("Only one item in list: No sorting needed.");
        cout<<"Only one item in list: Already sorted."<<endl;
    } else { 
        
       for(int i = 0; i < p_NumberOfNodes - 2; i++){
            //reset pointers to beginning of list
            sortHelper = this->p_Head;
            sortHelper2 = this->p_Head->next;
       
            for(int j = 0; j < p_NumberOfNodes - 1 - i; j++){
               if(sortHelper->value > sortHelper2->value){  //if a swap is needed
                   swapHelper = sortHelper->value;
                   sortHelper->value = sortHelper2->value;
                   sortHelper2->value = swapHelper;

                   //set up pointers for next pass
                   sortHelper = sortHelper2;
                   sortHelper2 = sortHelper2->next;
                } else {
                   //set up pointers for next pass
                   sortHelper = sortHelper2;
                   sortHelper2 = sortHelper2->next;
                }
            } 
        }
    }

}

/******************** PUBLIC: printValue  ********************/
void list::printValue(int valueToPrint){
    s_NODE *tmp = findValue(valueToPrint);
    if(tmp == nullptr){
        //throw MyException(valueToPrint + "is not in the list!");
        cout<<valueToPrint<<" is not in the list: can't be printed"<<endl;
    } else {
        cout<<tmp->value<<endl;
    }
}

/*****************************************************************************************/



/**************************** PRIVATE: p_CreateNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to create a node given a value.
*/
s_NODE* list::p_CreateNode(int newValue){
    s_NODE *newNode = new s_NODE;

    newNode->value = newValue;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    
    return newNode;
}

/**************************** PRIVATE: p_DeleteList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete the entire list.
*/
void list::p_DeleteList(void){
    s_NODE *tmp = p_Head;
        
    while(p_Head != nullptr){
        this->p_Head = this->p_Head->next;
        delete(tmp);
    }
    p_NumberOfNodes = 0;
}

/**************************** PRIVATE: p_DeleteNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete a given node.
*/
void list::p_DeleteNode(int valueToDelete){
    s_NODE *deleteHelper;
    s_NODE *nodeToDelete = findValue(valueToDelete);
    
    if(nodeToDelete == nullptr){    //if node was not found
        //throw MyException("Value not present in list!");
        cout<<"value not found"<<endl;
    }else if(this->p_NumberOfNodes == 1){   //node is only item in list
        this->p_Head = nullptr;
        this->p_Tail = nullptr;
        delete(nodeToDelete);
        this->p_NumberOfNodes--;

    } else if(p_Head == nodeToDelete){  //node is head
        deleteHelper = nodeToDelete->next;
        deleteHelper->previous = nullptr;
        delete(nodeToDelete);
        p_NumberOfNodes--;
    
    } else if(this->p_Tail == nodeToDelete){  //node is tail
        deleteHelper = nodeToDelete->previous;
        deleteHelper->next = nullptr;
        delete(nodeToDelete);
        this->p_NumberOfNodes--;
    
    } else {        //node is somewhere in middle of list
        deleteHelper = nodeToDelete->next;
        deleteHelper->previous = nodeToDelete->previous;
        deleteHelper = nodeToDelete->previous;
        deleteHelper->next = nodeToDelete->next;
        delete(nodeToDelete);
        this->p_NumberOfNodes--;
    }


}

/**************************** PRIVATE: p_InsertNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to insert a given value into the lis.
*/
void list::p_InsertNode(int valueToInsert){
    s_NODE *newNode = p_CreateNode(valueToInsert);
    

    //if the list is empty
    if(this->p_Head == nullptr){
        
        //set pointers of list
        this->p_Head = newNode;
        this->p_Tail = newNode;

        //set pointers of newNode
      
        
        this->p_IsSorted = 0;
        this->p_NumberOfNodes++;
    //if the list is not empty
    } else {
        this->p_Tail->next = newNode;
        newNode->previous = this->p_Tail;
        this->p_Tail = newNode;
         
        this->p_IsSorted = 0;
        this->p_NumberOfNodes++;
    }
}