#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <algorithm>

using namespace std;

unsigned int BadHashFunction(const string& input) {
    unsigned int hash_value = 0;
    for (const auto& c : input)
    {
        hash_value = hash_value * 1313 + (unsigned char)c;
    }
    return hash_value;
}

unsigned int HashFunction(const string& input) {
    unsigned int hash_value = 0;
    for (const auto& c : input)
    {
        hash_value += (unsigned char)c;
    }
    return hash_value;
}

int main() {

    struct Info
    {
        string key;
        long int phone;
    };

    vector<Info> phonebook;

    ifstream infile("info.txt", ios::in);
    while (!infile.eof())
    {
        string line;
        getline(infile, line);
        istringstream is{ line };

        string name;
        string phone;

        getline(is, name, ',');
        getline(is, phone);

        phonebook.push_back(Info{ name, strtol(phone.c_str(),nullptr,10) });
    }

    //hash count
    constexpr int buckets = 6;
    vector < vector<Info> >hash_map;
    hash_map.resize(buckets);

    //fill in the hash map
    for (auto& i : phonebook)
    {
        unsigned int hash = HashFunction(i.key) % hash_map.size();
        hash_map[hash].push_back(i);
    }


    while (true)
    {
        string search_key;
        cout << endl << endl << "Enter search key " << endl;
        cin >> search_key;


        //hash count
        auto now = chrono::high_resolution_clock::now();
        unsigned int bucket_number = HashFunction(search_key) % hash_map.size();
        auto& bucket = hash_map[bucket_number];

        //int info = find_if(bucket.begin(), bucket.end(), [&](const Info& i) {return i.key == search_key; })->phone;
        int info = -1;
        for (auto& i : bucket)
        {
            if (i.key == search_key)
            {
                info = i.phone;
                break;
            }
        }

        auto duration_hash = chrono::high_resolution_clock::now() - now;

        if (info != -1)
        {
            cout << "I found " << search_key << " phone number " << info << endl;
        }
        else 
        {
            cout << search_key << " not found" << endl;
        }
        cout << "It took " << chrono::duration_cast<chrono::microseconds>(duration_hash).count() << " ms for the hash search" << endl;
    }

    return 0;
}