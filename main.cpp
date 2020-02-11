#include "list.h"

#include <fstream>

int main(int argc, char *argv[]){

    fstream myInput;
    int inputCount, i, numFromFile = 0;

    myInput.open("input.txt", ios::in);
    myInput >> inputCount;

    for( i = 0; i < inputCount; ++i ){
        myInput >> numFromFile;
        /*
            TODO: insert code here to insert values 
        */
    }
    myInput.close();

    /*
        TODO: insert code here to achieve the below.
        Implement the following in code after the initial list has been read in.
            sort the list.
            Print the list.
            append the values found in 'input2.txt' using the above code as a template.
            Attempt to delete the following values: 10, 3, 52, 2
            Attempt to print the following values: 1, 5, 10, 32
            sort the remaining list.
            print the remaining list to the screen.
    */


    return 0;
}