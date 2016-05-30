//  Created by Andres Quinones
//  Copyright (c) 2015 Andres Quinones. All rights reserved.
//	TestSet.cpp
//	Program tests the SetADT, the DisplaySet function in Set.Cpp and the UniteSet function
// 	also located in Set.cpp

#include <iostream>
#include <stdio.h>
#include "Set.h"

using namespace std;
void TestSet()
{
	cout << "Test 1:"<< endl;
	Set<int> a_set;
     cout << "Empty set a_set created and IsEmpty() returns  "
          << a_set.IsEmpty() << endl;

    cout << "Test 2:"<< endl;
    a_set.Add(1);
    cout << "The integer 1 was added to the set. Search for 1 returns "<< a_set.Contains(1)<< endl;

    cout << "Test 3:"<< endl << "Integers 1,10,3,10,5,10 added. (See TestSet.cpp for proof)"<<endl;
    a_set.Add(10); 
    a_set.Add(3);      
    a_set.Add(10);      
    a_set.Add(5);      
    a_set.Add(10);  

    cout << "Test 4:"<< endl;
     cout << "Number of elements in a_set:  "
          << a_set.GetCurrentSize() << endl;   

    cout << "Test 5:"<< endl;
    cout << "Current items in a_set:";
    DisplaySet(a_set);
    cout << endl
    	<<"Search for 10 (item in set already): returns " << a_set.Contains(10)<< endl
    	<<"Search for 21 (item not in set already): returns " << a_set.Contains(21)<< endl;

    cout << "Test 6:"<< endl;
    int a=15;
   	while(a_set.Add(a))
   		a++;
   	cout << "Maximum capacity reached when adding sequential numbers. Add returned 0."<< endl;
   	cout << "Current items in a_set:";
    DisplaySet(a_set);

    cout << "Test 7:"<< endl;
	cout<< "Attempt to add 1 (which is already in the set) returns a " << a_set.Add(1)<< endl;

    cout << "Test 8:"<< endl;
    a_set.Clear();
    cout << "Set cleared. Current items in a_set:";
    DisplaySet(a_set);
    cout<< endl << "Attempt to remove from empty set returns a " << a_set.Remove(1) << endl;

    cout << "Test 9:"<< endl;
    a_set.Add(1);
    cout << "Current items in a_set:";
    DisplaySet(a_set);
    cout << endl;
    bool test = a_set.Remove(1);
    if(test==1)
    	cout <<"Item removed successfully"<< endl;
    else
    	cout << "Item not removed successfully" << endl;
    cout << "Current items in a_set:"<< endl;
    DisplaySet(a_set);
    cout << endl;
}

void TestUniteSets()
{
	cout << "In TestUniteSets:"<< endl << "Test a:"<< endl;
	 Set<int> a, b, c;
	 c = UniteSets(a,b);
	cout  << "Empty Sets a and b created and united. Current items in Set c:";
	 DisplaySet(c);	cout << endl;

	cout << "Test b:"<< endl;
	cout << "Adding 5 different elements to empty set a."<< endl;
	 for(int i=0;i<5;i++)
		 a.Add(i);
	 c = UniteSets(a,b);
	cout << "Sets a and b united. Current items in Set c:";
	 DisplaySet(c);	cout << endl;

	cout << "Test c:"<< endl;
	cout << "Changing contents of set a to {1,20,30}"<< endl;
	 a.Clear(); a.Add(1); a.Add(20); a.Add(30);
	cout << "Changing contents of set b to {40,50}"<< endl;
	 b.Clear(); b.Add(40); b.Add(50);
     c = UniteSets(a,b);
	cout << "Sets a and b united. Current items in set a:";
	 DisplaySet(a);
	cout << endl << "Current items in set b:";
	 DisplaySet(b);
	cout << endl << "Current items in Set c:";
	 DisplaySet(c);	cout << endl;

	cout << "Test d:"<< endl;
	cout << "Changing contents of set a to {1,20,30}"<< endl;
	 a.Clear(); a.Add(1); a.Add(20); a.Add(30);
	cout << "Changing contents of set b to {20,30,0,40}"<< endl;
	 b.Clear(); b.Add(20); b.Add(30); b.Add(0); b.Add(40);
	 c = UniteSets(a,b);
	cout << "Sets a and b united. Current items in set a:";
	 DisplaySet(a);
	cout << endl << "Current items in set b:";
	 DisplaySet(b);
	cout << endl << "Current items in Set c:";
	 DisplaySet(c);	cout << endl;
}

int main(int argc, const char * argv[])
{
	TestSet();
	TestUniteSets();

	return 1;
}










