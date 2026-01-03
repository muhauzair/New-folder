#include<iostream>
#include<cmath>
using namespace std;
bool exists(int arr[], int size, int val){
    for(int i = 0; i < size; i++){
        if(arr[i] == val) 
        return true;
    }
    return false;
}
int main(){
    int totalSets;
    cout<<"*********************************************"<<endl;
    cout<<"*   MULTI-SET DISCRETE MATHS SET OPERATOR   *"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"This program only deal with at most 3 sets.";
    cout<<"Enter number of sets: ";
    cin>>totalSets;
    int setSizes[50];
    int sets[50][100];
    for(int i = 0; i < totalSets; i++){
        cout<<"Enter number of elements in Set "<<i + 1<<": ";
        cin>>setSizes[i];
        cout<<"Enter elements for Set "<<i + 1<<": ";
        for(int j = 0; j < setSizes[i]; j++)
            cin>>sets[i][j];
    }
    int choice;
    do{
        cout<<"--- CHOOSE OPERATION ---"<<endl;
        cout<<"1. Union\n";
        cout<<"2. Intersection\n";
        cout<<"3. Difference\n";
        cout<<"4. Power Set\n";
        cout<<"5. Text-Based Venn Diagram (All Sets)\n";
        cout<<"0. Exit\n";
        cout<<"Choice: ";
        cin>>choice;
        int s1, s2;
        switch (choice){
            case 1:{
                if(totalSets==1){
                    cout<<"Union is not possible. Please enter at least 2 sets. "<<endl;
                    break;
                }
                else if(totalSets==2||totalSets==3){  
                cout<<"Enter two set numbers for UNION (e.g. 1 3): ";
                cin>>s1>>s2;
                s1--; s2--;

                cout<<"Union = { ";
                for(int i = 0; i < setSizes[s1]; i++)
                    cout<<sets[s1][i]<<" ";

                for(int i = 0; i < setSizes[s2]; i++)
                    if(!exists(sets[s1], setSizes[s1], sets[s2][i]))
                        cout<<sets[s2][i]<<" ";

                cout<<"}\n";
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 2:{
                if(totalSets==1){
                    cout<<"Intersection is not possible. Please enter at least 2 sets. "<<endl;
                    break;
                }
                else if(totalSets==2||totalSets==3){   
                cout<<"Enter two set numbers for INTERSECTION (e.g. 1 2): ";
                cin>>s1>>s2;
                s1--; s2--;
                cout<<"Intersection = { ";
                for(int i = 0; i < setSizes[s1]; i++)
                    if(exists(sets[s2], setSizes[s2], sets[s1][i]))
                        cout<<sets[s1][i]<<" ";

                cout<<"}"<<endl;
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 3:{
                if(totalSets==1){
                    cout<<"Differnce isn't possible. Please enter at least 2 sets. "<<endl;
                    break;
                }
                else if(totalSets==2||totalSets==3){ 
                cout<<"Enter two set numbers for DIFFERENCE A - B (e.g. 2 1): ";
                cin>>s1>>s2;
                s1--; s2--;
                cout<<"Difference = { ";
                for(int i = 0; i < setSizes[s1]; i++)
                    if(!exists(sets[s2], setSizes[s2], sets[s1][i]))
                        cout<<sets[s1][i]<<" ";
                cout<<"}"<<endl;
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 4:{
                 if(totalSets==1||totalSets==2||totalSets==3){
                cout<<"Enter set number for POWER SET (e.g. 3): ";
                cin>>s1;
                s1--;
                int psize = pow(2, setSizes[s1]);
                cout<<"Power Set has "<<psize<<" subsets:"<<endl;
                for(int i = 0; i < psize; i++){
                    cout<<"{ ";
                    for(int j = 0; j < setSizes[s1]; j++)
                        if(i & (1 << j))
                            cout<<sets[s1][j]<<" ";
                    cout<<"}"<<endl;
                }
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 5:{   
                if(totalSets == 1){
                    cout << "Only in A: { ";
                    for(int i = 0; i < setSizes[s1]; i++)
                        cout<<sets[s1][i]<<" ";
                    cout<<"}"<<endl;    
                }
                else if(totalSets == 2){
                    int A = 0, B = 1;
                    cout << "Common in A and B: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in A: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(!exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in B: { ";
                    for(int i = 0; i < setSizes[B]; i++){
                        int x = sets[B][i];
                        if(!exists(sets[A], setSizes[A], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "----------------------------------\n";
                }
                else if(totalSets == 3){
                    int A = 0, B = 1, C = 2;
                    cout << "Common in ALL (A ∩ B ∩ C): { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[B], setSizes[B], x) && exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Common in A and B only: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[B], setSizes[B], x) && !exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Common in A and C only: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[C], setSizes[C], x) && !exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Common in B and C only: { ";
                    for(int i = 0; i < setSizes[B]; i++){
                        int x = sets[B][i];
                        if(exists(sets[C], setSizes[C], x) && !exists(sets[A], setSizes[A], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in A: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(!exists(sets[B], setSizes[B], x) && !exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in B: { ";
                    for(int i = 0; i < setSizes[B]; i++){
                        int x = sets[B][i];
                        if(!exists(sets[A], setSizes[A], x) && !exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in C: { ";
                    for(int i = 0; i < setSizes[C]; i++){
                        int x = sets[C][i];
                        if(!exists(sets[A], setSizes[A], x) && !exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "----------------------------------\n";
                }
                else {
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
                break;
            }
        } 
    } while(choice != 0);
    return 0;
}
