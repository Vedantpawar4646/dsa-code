#include<iostream>
using namespace std;
class set_operation {
int temp, i;
int count = 0;
int set[10];
public:
void insert();
int search(int key);
void display();
void remove();
void set_union();
void set_difference(set_operation &s2);
void set_intersection(set_operation &s2);
bool is_subset(set_operation &s2); // New method for subset operation
};
void set_operation::insert() {
if (count >= 10) {
cout << "Set is full. Cannot insert more elements.\n";
return;
}
cout << "Enter the number: ";
cin >> temp;
if (search(temp) == -1) {
set[count++] = temp;
cout << "Element inserted successfully.\n";
} else {
cout << "Element already exists in the set.\n";
}
}
void set_operation::display() {
if (count == 0) {
cout << "Set is empty.\n";
return;
}
cout << "Elements in the set:\n";
for (int i = 0; i < count; i++) {
cout << set[i] << " ";
}
cout << endl;
}
int set_operation::search(int key) {
for (int i = 0; i < count; i++) {
if (set[i] == key) {
return i;
}
}
return -1;
}
void set_operation::remove() {
int ele;
cout << "Enter element to be removed: ";
cin >> ele;
int index = search(ele);
if (index != -1) {
for (i = index; i < count - 1; i++) {
set[i] = set[i + 1];
}
count--;
cout << "Element removed successfully.\n";
} else {
cout << "Element not found in the set.\n";
}
}
void set_operation::set_difference(set_operation &s2) {
cout << "Set difference:\n";
for (int i = 0; i < count; i++) {
if (s2.search(set[i]) == -1) {
cout << set[i] << " ";
}
}
cout << endl;
}
void set_operation::set_intersection(set_operation &s2) {
cout << "Set intersection:\n";
for (int i = 0; i < count; i++) {
if (s2.search(set[i]) != -1) {
cout << set[i] << " ";
}
}
cout << endl;
}
bool set_operation::is_subset(set_operation &s2) {
for (int i = 0; i < count; i++) {
if (s2.search(set[i]) == -1) {
return false; // If any element of this set is not found in s2, it's not a subset
}
}
return true; // All elements of this set are found in s2, so it's a subset
}
int main() {
set_operation s1, s2;
int ch, temp;
do{
cout << "\n-----------Welcome------------";
cout << "\n1. Add Element to Set 1";
cout << "\n2. Add Element to Set 2";
cout << "\n3. Display Set 1";
cout << "\n4. Display Set 2";
cout << "\n5. Search Element in Set 1";
cout << "\n6. Search Element in Set 2";
cout << "\n7. Remove Element from Set 1";
cout << "\n8. Remove Element from Set 2";
cout << "\n9. Set Difference (Set 1 - Set 2)";
cout << "\n10. Set Intersection";
cout << "\n11. Check if Set 1 is a Subset of Set 2";
cout << "\n12. Exit";
cout << "\nEnter your choice: ";
cin >> ch;
switch (ch) {
case 1:
cout << "\nAdd Element to Set 1\n";
s1.insert();
break;
case 2:
cout << "\nAdd Element to Set 2\n";
s2.insert();
break;
case 3:
cout << "\nDisplay Set 1\n";
s1.display();
break;
case 4:
cout << "\nDisplay Set 2\n";
s2.display();
break;
case 5:
cout << "Enter element to be searched in Set 1: ";
cin >> temp;
if (s1.search(temp) != -1)
cout << "Element found in Set 1.\n";
else
cout << "Element not found in Set 1.\n";
break;
case 6:
cout << "Enter element to be searched in Set 2: ";
cin >> temp;
if (s2.search(temp) != -1)
cout << "Element found in Set 2.\n";
else
cout << "Element not found in Set 2.\n";
break;
case 7:
cout << "Remove Element from Set 1\n";
s1.remove();
break;
case 8:
cout << "Remove Element from Set 2\n";
s2.remove();
break;
case 9:
s1.set_difference(s2);
break;
case 10:
s1.set_intersection(s2);
break;
case 11:
if (s1.is_subset(s2))
cout << "Set 1 is a subset of Set 2.\n";
else
cout << "Set 1 is not a subset of Set 2.\n";
break;
case 12:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice! Please enter a valid option.\n";
break;
}
} while (ch != 12);
return 0;
}




