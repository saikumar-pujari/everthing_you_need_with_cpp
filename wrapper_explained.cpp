#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// WRAPPER EXPLAINED - LIKE A CHILD! 
// ============================================================================
// A wrapper is like a BOX around something. It protects it, organizes it,
// and gives it new powers!

// ============================================================================
// EXAMPLE 1: Simple Wrapper - A BOX around an integer
// ============================================================================

class IntegerWrapper {
private:
    int value;  // The actual integer inside the box
    
public:
    // Constructor - PUT something into the box
    IntegerWrapper(int v) {
        value = v;
        cout << "📦 Wrapped integer " << v << " into a box!\n";
    }
    
    // Get value out of the box
    int getValue() {
        return value;
    }
    
    // Do something special with the wrapped value
    void printDouble() {
        cout << "Double of " << value << " is: " << (value * 2) << "\n";
    }
};

// ============================================================================
// EXAMPLE 2: Wrapper around a String - Adding Safety
// ============================================================================

class SafeString {
private:
    string text;  // The actual string inside the box
    
public:
    SafeString(string s) {
        text = s;
    }
    
    // Safe access - can't break it from outside!
    void display() {
        cout << "🎁 Inside box: " << text << "\n";
    }
    
    // Add extra features
    int getLength() {
        return text.length();
    }
    
    void makeUppercase() {
        for (char &c : text) {
            c = toupper(c);
        }
        cout << "🔤 Made uppercase: " << text << "\n";
    }
};

// ============================================================================
// EXAMPLE 3: Wrapper around an Array - Adding Functionality
// ============================================================================

class ArrayWrapper {
private:
    int arr[5];
    int size;
    
public:
    ArrayWrapper() {
        size = 0;
        cout << "📦 Created empty array box!\n";
    }
    
    // Add items to the box
    void add(int num) {
        if (size < 5) {
            arr[size] = num;
            size++;
            cout << "✅ Added " << num << " to box\n";
        } else {
            cout << "❌ Box is full!\n";
        }
    }
    
    // Print all items
    void printAll() {
        cout << "🎁 Items in box: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    // Get sum of all items
    int getSum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

// ============================================================================
// EXAMPLE 4: Real-world Example - Wrapper around a Student
// ============================================================================

class Student {
private:
    string name;
    int rollNo;
    float marks;
    
public:
    Student(string n, int r, float m) {
        name = n;
        rollNo = r;
        marks = m;
    }
    
    void displayInfo() {
        cout << "👤 Name: " << name << ", Roll: " << rollNo 
             << ", Marks: " << marks << "\n";
    }
    
    bool isPassed() {
        return marks >= 35;
    }
    
    string getGrade() {
        if (marks >= 90) return "A+";
        else if (marks >= 80) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 60) return "C";
        else if (marks >= 35) return "D";
        else return "F";
    }
};

// ============================================================================
// MAIN - Let's use all these wrappers!
// ============================================================================

int main() {
    cout << "\n🌟 WRAPPER CONCEPT EXPLAINED 🌟\n";
    cout << "====================================\n\n";
    
    // Example 1: Integer Wrapper
    cout << "EXAMPLE 1: IntegerWrapper\n";
    cout << "─────────────────────────\n";
    IntegerWrapper num1(5);
    cout << "Value inside: " << num1.getValue() << "\n";
    num1.printDouble();
    cout << "\n";
    
    // Example 2: Safe String Wrapper
    cout << "EXAMPLE 2: SafeString\n";
    cout << "─────────────────────\n";
    SafeString str1("hello");
    str1.display();
    cout << "Length: " << str1.getLength() << "\n";
    str1.makeUppercase();
    cout << "\n";
    
    // Example 3: Array Wrapper
    cout << "EXAMPLE 3: ArrayWrapper\n";
    cout << "──────────────────────\n";
    ArrayWrapper arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.printAll();
    cout << "Sum of all: " << arr.getSum() << "\n";
    cout << "\n";
    
    // Example 4: Student Wrapper
    cout << "EXAMPLE 4: Student (Real-World)\n";
    cout << "───────────────────────────────\n";
    Student student1("Saikumar", 101, 92);
    student1.displayInfo();
    cout << "Passed: " << (student1.isPassed() ? "YES ✅" : "NO ❌") << "\n";
    cout << "Grade: " << student1.getGrade() << "\n";
    
    return 0;
}

/* 
KEY TAKEAWAYS ABOUT WRAPPERS:
==============================

1. PROTECTION: The wrapper protects the data inside
   - You can't directly mess with the data
   - Only access through safe methods

2. ORGANIZATION: Everything related to one thing is in one box
   - Name, age, marks all together in Student class
   - Not scattered around

3. EXTRA FEATURES: You can add special abilities
   - IntegerWrapper can print double
   - SafeString can make uppercase
   - Student can calculate grade

4. REUSABILITY: You can use the same wrapper many times
   - Create many students
   - Each has their own data

5. SIMPLICITY: User doesn't see complex internals
   - Just use the simple methods
   - Don't worry about implementation

ANALOGY:
========
Wrapper is like a GIFT BOX:
- 📦 Inside: Actual gift (int, string, array, etc.)
- 🎁 Outside: Pretty wrapping (methods, functions)
- 🔒 Protection: Can't steal/damage the gift
- ✨ Features: Ribbon, bow, tag (extra abilities)
*/
