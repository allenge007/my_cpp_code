#include <iostream>
using namespace std;
class Object {
    public:
        Object(int i) {
            id = i, count ++;
            cout<<"Object "<<id<<" is created."<<endl;
        }
        ~Object() {
            count --;
            cout << "Object " << id << " is deleted, we've got " << count << " object(s) now!" << endl; 
        }
    private:
        int id;
        static int count;
    
};
int Object :: count = 0;
const int maxn = 105;
void TestObjects(int n) {
    Object *p[maxn];
    for(int i = 1; i <= n; i ++)
        p[i] = new Object(i);
    for(int i = 1; i <= n; i += 2)
        delete p[i];
    for(int i = 2; i <= n; i += 2) 
        delete p[i];
}
int main()
{
    int object_num;
    cin >> object_num;
    TestObjects(object_num);
    return 0;
}
