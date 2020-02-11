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
    if(p_Head != nullptr){
        this->deleteList();
    }
}


/*****************************************************************************************/



/**************************** PUBLIC: appendValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to append value to end of list.
*/
void list::appendValue(int valueToAdd){
    s_NODE *newNode = p_CreateNode(valueToAdd);
    
    //if the list is empty
    if(this->p_Head == nullptr){
        
        //set pointers of list
        p_Head = newNode;
        p_Tail = newNode;

        //set pointers of newNode
        newNode->previous = nullptr;
        newNode->next = nullptr;
        
        p_IsSorted = 0;
        p_NumberOfNodes++;
    //if the list is not empty
    } else if(p_Tail != nullptr) {
        
        p_Tail->next = newNode;
        p_Tail = newNode;

        p_IsSorted = 0;
        p_NumberOfNodes++;
    }


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
bool list::findValue(int valueToFind){
    bool numberIsFound = false;
    bool allSearched = false;
    s_NODE *foundNode = nullptr;

    //if list is empty
    if(p_NumberOfNodes == 0){
        throw MyException("No values to search: List is empty!");
    //if list contains 1 value
    } else if(this->p_NumberOfNodes == 1){
        if(p_Head->value == valueToFind){
            numberIsFound = true;
        }
    //if list has multiple values
    } else if(this->p_NumberOfNodes > 1){
        s_NODE *tmpHead = p_Head;
        s_NODE *tmpTail = p_Tail;
        //keep looping until value is found or all nodes have been visited
        while(numberIsFound == false && allSearched == false){
            if(tmpHead->value == valueToFind || tmpTail->value == valueToFind){
                numberIsFound = true;
                return numberIsFound;
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
    }
    return numberIsFound;
}

/**************************** PUBLIC: printList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to print the list to the screen. 
*/
void list::printList(void){
    s_NODE *tmp = p_Head;
    
    for(int i = 0; i < this->p_NumberOfNodes; i++){
        cout<<tmp->value<<endl;
        tmp = tmp->next;
    }
}

/**************************** PUBLIC: removeValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete value from list.
*/
void list::removeValue(int){



}

/**************************** PUBLIC: sortList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to sort the list from smallest to largest.
*/
void list::sortList(void){

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
        p_Head = p_Head->next;
        delete(tmp);
    }
    p_NumberOfNodes = 0;
}

/**************************** PRIVATE: p_DeleteNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete a given node.
*/
void list::p_DeleteNode(int){

}

/**************************** PRIVATE: p_InsertNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to insert a given value into the lis.
*/
void list::p_InsertNode(int){

}