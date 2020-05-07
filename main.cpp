// The # is a preprocessor command
#include <iostream>
#include <string>
#include "Person.h"
#include "Tweeter.h"
#include "status.h"
#include "Utility.h"
#include "Accum.h"
#include "Resource.h"
using std::cout;
using std::endl;
using std::string;
using std::cin;

template <class T>
T max(T const& t1, T const& t2) {
    return t1 < t2 ? t2 : t1;
}

void casting() {
    Tweeter ghostmonk("Nicholas", "Hillier", 43, "@ghostmonk");
    Person* p = &ghostmonk;
    auto* pt = dynamic_cast<Tweeter*>(p);
    cout << pt->GetName() << endl;
}

void indirectionInheritance() {
    Person nick("Nicholas", "Hillier", 43);
    Person& rNick = nick;
    Person* pNick = &nick;

    Tweeter ghostmonk("Nicholas", "Hillier", 43, "@ghostmonk");
    Person* pGhostmonk = &ghostmonk;
    Person& rpGhostmonk = ghostmonk;
    Tweeter& rtGhostmonk = ghostmonk;

    cout << rNick.GetName() << endl;
    cout << pNick->GetName() << endl;
    cout << ghostmonk.GetName() << endl;
    cout << pGhostmonk->GetName() << endl;
    cout << rpGhostmonk.GetName() << endl;
    cout << rtGhostmonk.GetName() << endl;

}

void manualMemoryManagement() {
    Person nick("Nicholas", "Hillier", 43);
    nick.AddResource();
    nick.SetFirstName("Nicholas2");
    nick.AddResource();
    Person nick2 = nick;
}

void resourceManagement() {
    {
        Resource local("local");
        cout << local.GetName() << endl;
    }
    Resource* pResource = new Resource("New Resource");
    string string1 = pResource->GetName();
    int j=3;
    Resource* pResourceCopy = pResource;
    string string2 = pResource->GetName();

    delete pResource;
    pResource = nullptr;
    delete pResourceCopy;
    pResourceCopy = nullptr;
}

void constAndPointers() {
    int i = 3;
    int j = 4;
    int* pI = &i;
    //int* pII = &pI;
    int const * pcI = pI; // pointer to a const
    //*pcI = 4;
    //pcI = 4;
    pcI = &j;
    j = *pcI;

    int* const cpI = pI; // const pointer
    *cpI = 4;
    //cpI = &j;
    int const * const crazy = pI; // const pointer to a const
    //*crazy = 4;
    //crazy = &j;
    j = *crazy;
}

void constTrickieness() {
    int i = 3;
    int const ci = 4;
    i = 4;
    //ci = 5;

    int& ri = i;
    ri = 5;

    int const & cri = i;
    //cri = 7;
    cout << cri << endl;
    i = 7;
    cout << cri << endl;
}

void pointerExercise() {
    int a = 3;
    int& rA = a;

    cout << a << endl;
    rA = 5;
    cout << a << endl;

    Person nick("Nicholas", "Hillier", 43);
    Person& rNick = nick;
    rNick.SetNumber(44);
    cout << nick.GetNumber() << endl;

    int* pA = &a;
    *pA = 4;
    cout << a << endl;

    Person* pNick = &nick;
    (*pNick).SetNumber(45);
    pNick->SetNumber(46);
    cout << nick.GetNumber() << " " << nick.GetName() << endl;
    cout << pNick->GetNumber() << " " << pNick->GetName() << endl;
}

void usingTemplateSpecialization() {
    Accum<Person> persons(Person("Nicholas", "Hillier", 43));
    persons += Person("Tracey", "Huot", 41);
    cout << persons.GetTotal() << endl;
}

void usingTemplatedClass() {
    Accum<int> integers(0);
    integers += 1;
    integers += 2;
    cout << integers.GetTotal() << endl;

    Accum<string> strings("Whoa! ");
    strings += "Hello ";
    strings += "World";
    cout << strings.GetTotal() << endl;
}

void usingTemplatedFunction() {
    Person nick("Nicholas", "Hillier", 43);
    Person tracey("Tracey", "Huot", 41);
    cout << max(nick, tracey).GetName() << " is max!" << endl;
}

void usingOverloadedOperators() {
    Person nick("Nicholas", "Hillier", 43);
    Person tracey("Tracey", "Huot", 41);
    if(nick > tracey) {
        cout << "Nicholas is older than Tracey" << endl;
    }

    if(nick > 40) {
        cout << "Nicholas is older than 40" << endl;
    }

    if(45 > nick) {
        cout << "Nicholas is younger than 45" << endl;
    }
}

void functionTalk() {
    int x;
    cout << "Enter a number" << endl;
    cin >> x;
    cout << x << " is prime? " << IsPrime(x) << endl;
    cout << x << " is two more prime? " << Is2MorePrime(x) << endl;

}

void ternary() {
    int x = 99;
    while(x > 0) {
        cout << "Enter a number" << endl;
        cin >> x;
        string sign = x > 0 ? "positive" : "negative or zero";
        cout << "Your number is " << sign << endl;
    }
}

void basicSwitch() {
    int x;
    cout << "Please enter a number" << endl;
    cin >> x;
    while(x > 0) {
        switch(x) {
            case 1:
                cout << "You entered 1" << endl;
                break;
            case 2:
            case 3:
                cout << "You entered 2 or 3" << endl;
                break;
            case 4:
                cout << "Your entered 4" << endl;
                break;
            default:
                cout << "You entered a number larger than 4" << endl;
        }
        cout << "Please enter a number" << endl;
        cin >> x;
    }
}

void basicFor() {
    int x;
    cout << "Enter a number" << endl;
    cin >> x;

    bool isPrime = true;

    for(int i = 2; i <= x/i; i++) {
        int factor = x/i;
        if(x == i*factor) {
            cout << "factor found: " << i << " * " << factor << endl;
            isPrime = false;
        }
    }
    cout << x << " is ";

    if(!isPrime)
        cout << "not ";
    cout << "prime" << endl;
}

void basicWhile() {
    int x;
    cout << "Enter a number" << endl;
    cin >> x;

    bool isPrime = true;
    int i = 2;

    while(i <= x/i) {
        int factor = x/i;
        if(x == i*factor) {
            cout << "factor found: " << i << " * " << factor << endl;
            isPrime = false;
        }
        i++;
    }
    cout << x << " is ";

    if(!isPrime)
        cout << "not ";
    cout << "prime" << endl;
}

void basicIf() {
    int x,y;
    cout << "Enter two numbers " << endl;
    cin >> x >> y;
    cout << x;
    if(x > y) {
        cout << " is larger than ";
    } else {
        cout << " is smaller than ";
    }
    cout << y << endl;

    if(x + y > 10)
        cout << "Thanks for choosing larger numbers!" << endl;
}

void enums() {
    Status s = Pending;
    cout << "Status " << s << endl;
    s = Approved;
    cout << "Status " << s << endl;

    FileError fe = FileError::notfound;
    fe = FileError::ok;
    NetworkError ne = NetworkError::ok;
}

void inheritance() {
    Tweeter tweeter("Nicholas", "Hillier", 43, "ghostmonk");
    cout << tweeter.GetName() << endl;
}

void checkPerson() {
    Person p1("Nicholas", "Hillier", 43);
    Person p2;
    string name = p1.GetName();
    cout << name << endl;
}

void runInts() {
    int i1 = 1;
    cout << "i1 = " << i1 << endl;

    int i2;
    i2 = 2;
    std::cout << "i2 = " << i2 << endl;

    int i3(3);
    cout << "i3 = " << i3 << endl;

    int i4{ 4 };
    cout << "i4 = " << i4 << endl;

    double d1 = 2.2;
    double d2 = i1;
    int i5 = static_cast<int>(d1);
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "i5 = " << i5 << endl;

    char c1 = 'a';
    cout << "c1 = " << c1 << endl;

    bool b1 = false;
    cout << "b1 = " << b1 << endl;
    b1 = i1;
    cout << "b1 = " << b1 << endl;
    b1 = d1;
    cout << "b1 = " << b1 << endl;

    auto a1 = 1;
    auto a2 = 2.2;
    auto a3 = 'c';
    auto a4 = "s";
    auto a5 = true;
    auto a6 = 3L;
    auto a7 = 1'000'000'000'000;
    auto a8 = 0xFF;
    auto a9 = 0b111;

    a1 = static_cast<int>(a2);

    unsigned char n1 = 128;
    char n2 = 128;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    n1 = 254;
    n2 = 254;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
}

void basicHelloWorld() {
    cout << "Hello, World!" << endl;
    cout << "Type your name!" << endl;
    string name;
    cin >> name;
    cout << "Hello, " << name << endl;
}

/*
 * This is my comment for the main line
 */
int main() {
    //basicHelloWorld();
    //runInts();
    //checkPerson();
    //inheritance();
    //enums();
    //basicIf();
    //basicWhile();
    //basicFor();
    //basicSwitch();
    //ternary();
    //functionTalk();
    //usingOverloadedOperators();
    //usingTemplatedFunction();
    //usingTemplatedClass();
    //usingTemplateSpecialization();
    //pointerExercise();
    //constTrickieness();
    //resourceManagement();
    //manualMemoryManagement();
    //indirectionInheritance();
    casting();
    return 0;
}
