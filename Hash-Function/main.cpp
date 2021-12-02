#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;


const int bucket = 200;

class HashTableEntry {
public:
    int age;
    string name;
    string address;
    HashTableEntry(int age, string name, string address) {
        this->age = age;
        this->name = name;
        this->address = address;
    }
};

class HashMapTable {

private:
    HashTableEntry** t;
public:
    HashMapTable() {
        t = new HashTableEntry * [bucket];
        for (int i = 0; i < bucket; i++) {
            t[i] = NULL;
        }
    }

    //my hashFunc
    int HashFunc(int k) {
        return k % bucket;
    }

    //insert
    void Insert(int k, string v, string n) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->name != v) {
            h = HashFunc(h + 1);
        }
        if (t[h] != NULL)
            delete t[h];
        t[h] = new HashTableEntry(k, v, n);
    }

    //searchkey
    int SearchKey(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->age != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
            return -1;
        else
            return t[h]->age;
    }

    //remove key
    void Remove(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL) {
            if (t[h]->age == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL) {
            cout << "No Element found at key " << k << endl;
            return;
        }
        else {
            delete t[h];
        }
        cout << "Element Deleted" << endl;
    }
    ~HashMapTable() {
        for (int i = 0; i < bucket; i++) {
            if (t[i] != NULL)
                delete t[i];
            delete[] t;
        }
    }
};

int main() {
    HashMapTable hash;
    int k;
    string v;
    string n;
    int c;
    while (1) {
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Enter name: ";
            cin >> v;
            cout << "Enter age: ";
            cin >> k;
            cout << "Enter address: ";
            cin >> n;
            hash.Insert(k, v, n);
            break;
        case 2:
            cout << "Enter name to be searched: ";
            cin >> k;
            if (hash.SearchKey(k) == -1) {
                cout << "No name found at key " << k << endl;
                continue;
            }
            else {
                cout << "Information at key " << v << n << " : ";
                cout << hash.SearchKey(k) << endl;
            }
            break;
        case 3:
            cout << "Enter key to be deleted: ";
            cin >> k;
            hash.Remove(k);
            break;
        case 4:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }
    return 0;
}