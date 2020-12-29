#include <cmath>
#include <string>
#include <iostream>
using namespace std;
const int memorySize = 30;
class contiguosFileAllocationMethod {

    public:
        string name;
        int start= rand() % memorySize/2;
        int size;
        int end;
        void getEndContiguos();
};
  
class LinkedFileAllocationMethod {
    public:
        string name;
        int start=rand() % memorySize / 2;
        int data [4];
        void fillData();
        
};

class IndexedFileAllocationMethod {
    public:
        string name;
        int start = rand() % memorySize / 2;
        int data[4];
        void fillData();
};

void contiguosFileAllocationMethod::getEndContiguos() {
     end=start + size - 1;
}

void LinkedFileAllocationMethod::fillData() {
    for (int i = 0; i < 4; i++) {
        data[i] = rand() % memorySize;

    }
}

void IndexedFileAllocationMethod::fillData() {
    for (int i = 0; i < 4; i++) {
        data[i] = rand() % memorySize;

    }
}

void fillArray(string memory[]) {
    for (int i = 0; i < 30; i++) {
        memory[i] = "Not Filled";
    }
}
int main()
{
    srand(time(NULL));
    int choice;
    string memory[memorySize];
    fillArray(memory);
    do
    {
        
        cout << "******* Welcome to the File Allocation Program ********\n";
        cout << "MENU:\n\nEnter 1 for Contigiuos File Allocation\n";
        cout << "Enter 2 for Linked File Allocation\n";
        cout << "Enter 3 for Indexed File Allocation\n";
        cout << "Enter 4 for Exit\n\n";
        cin >> choice;


        if (choice == 1) {
            contiguosFileAllocationMethod newContigiousFile;
            cout << "Enter file Name : ";
            cin >> newContigiousFile.name;
            cout << endl;
            newContigiousFile.start;
            cout << "Enter file size : ";
            cin >> newContigiousFile.size;
            cout << endl;
            newContigiousFile.getEndContiguos();
            cout << "Start Partition is : " << newContigiousFile.start;
            cout << endl;
            for (int i = newContigiousFile.start; i <= newContigiousFile.end; i++) {
                if (memory[i] == "Not Filled") {
                    memory[i] = "Filled with file " + newContigiousFile.name;
                }
                else {
                    cout << "Memory Partition is not free " << endl;
                    cout << newContigiousFile.name << " have to wait..." << endl;
                    break;
                }
            }
            for (int j = 0; j < memorySize; j++) {
                cout << j << ": ";
                cout << memory[j] << endl;
            }
        }
        else if (choice == 2) {
           
            LinkedFileAllocationMethod newLinkedFile;
            cout << "Enter file Name : ";
            cin >> newLinkedFile.name;
            cout << endl;
            newLinkedFile.start;
            newLinkedFile.fillData();
            for (int i = 0; i < memorySize; i++) {
                if (newLinkedFile.data[0] == i || newLinkedFile.data[1] == i || newLinkedFile.data[2] == i || newLinkedFile.data[3] == i) {
                    memory[i] = "Filled with file " + newLinkedFile.name;
                }
                else
                    continue;
            }
            for (int j = 0; j < memorySize; j++) {
                cout << j << ": ";
                cout << memory[j] << endl;
            }
        }

        else if (choice == 3) {
            IndexedFileAllocationMethod newIndexedFile;
            cout << "Enter file Name : ";
            cin >> newIndexedFile.name;
            cout << endl;
            newIndexedFile.start;
            newIndexedFile.fillData();
            for (int i = 0; i < memorySize; i++) {
                if (newIndexedFile.data[0] == i || newIndexedFile.data[1] == i || newIndexedFile.data[2] == i || newIndexedFile.data[3] == i) {
                    memory[i] = "Filled with file " + newIndexedFile.name;
                }
                else
                    continue;
            }
            for (int j = 0; j < memorySize; j++) {
                cout << j << ": ";
                cout << memory[j] << endl;
            }
        }
        else if (choice == 4) {
            break;
        }

    } while (choice != 4);
}