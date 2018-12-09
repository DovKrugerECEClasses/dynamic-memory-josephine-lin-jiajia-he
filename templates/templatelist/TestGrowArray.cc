#include "GrowArray.hh"
#include "string"
using namespace std;

class Elephant{
private:
    string name;
public:
    Elephant():name(){}
    Elephant(const string& name): name(name){}
    friend ostream& operator << (ostream&s, const Elephant& e){
        return s<<e.name;
    }
};


int main(){
    GrowArray<int> a;
    //TODO: GrowArray b(1000)
    GrowArray<int> b(1000);
    for(int i=0;i<10;i++){
        a.addEnd(i);
    }
    a.removeEnd();
    cout << a <<endl;
    cout << b <<endl;

    GrowArray<Elephant> e;
    e.addEnd(Elephant("Alice"));
    e.addEnd(Elephant("Betty"));
    cout << e<<"\n";
}
