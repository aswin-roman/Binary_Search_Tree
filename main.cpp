
#include <iostream>
#include"BST.cpp"

int main()
{
    std::cout << "Hello World!\n";

    BST t1;
    int data = 50;
    int arr[] = {50};
    for (int i : arr)
    {
        Node* root_local = t1.InsertData(&i);
    }
    


    t1.Print();
    
    for (int i : arr)
    {
        t1.Delete(&i);
        t1.Print();
    }

}
