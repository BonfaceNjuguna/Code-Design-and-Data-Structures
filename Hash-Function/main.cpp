#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <algorithm>

using namespace std;

unsigned int HashFunction(const string& input) {
    unsigned int hash_value = 0;
    for (const auto& c : input)
    {
        hash_value = hash_value * 1313 + (unsigned char)c;
    }
    return hash_value;
}

unsigned int BadHashFunction(const string& input) {
    unsigned int hash_value = 0;
    for (const auto& c : input)
    {
        hash_value += (unsigned char)c;
    }
    return hash_value;
}

int main() {

    std::vector<string> words;

    ifstream infile("text.txt", ios::in);
    while (!infile.eof())
    {
        string line;
        getline(infile, line);
        istringstream is{ line };
        string word;

        while (is >> word)
        {
            words.push_back(word);
        }
    }

    //hash count
    constexpr int buckets = 100000;
    vector < vector<string> >hash_map;
    hash_map.resize(buckets);

    //fill in the hash map
    for (auto& w : words)
    {
        unsigned int hash = HashFunction(w) % hash_map.size();
        hash_map[hash].push_back(w);
    }

    /*for (auto& b : hash_map)
    {
        sort(b.begin(), b.end());
    }*/

    while (true)
    {
        string search_key;
        cout << endl << endl << "Enter search key " << endl;
        cin >> search_key;

        //naive count
        auto now = chrono::high_resolution_clock::now();
        //int inaive = count(words.begin(), words.end(), search_key);
        bool inaive_found = find(words.begin(), words.end(), search_key) != words.end();
        auto duration_naive = chrono::high_resolution_clock::now() - now;

        //hash count
        now = chrono::high_resolution_clock::now();
        unsigned int bucket_number = HashFunction(search_key) % hash_map.size();
        auto& bucket = hash_map[bucket_number];

        //int ihash = count(bucket.begin(), bucket.end(), search_key);
        bool ihash_found = find(bucket.begin(), bucket.end(), search_key) != bucket.end();
        //bool ihash_found = binary_search(bucket.begin(), bucket.end(), search_key);
        auto duration_hash = chrono::high_resolution_clock::now() - now;
        //assert(ihash == inaive);

        if (inaive_found)
        {
            cout << "I found " << search_key << endl;
        }
        else 
        {
            cout << search_key << " not found" << endl;
        }
        cout << "It took " << chrono::duration_cast<chrono::microseconds>(duration_naive).count() << " ms for the naive search" << endl;

        if (ihash_found)
        {
            cout << "I found " << search_key << endl;
        }
        else
        {
            cout << search_key << " not found" << endl;
        }
        cout << "It took " << chrono::duration_cast<chrono::microseconds>(duration_hash).count() << " ms for the hash search" << endl;

       /* cout << "I found " << inaive << " occurences of " << search_key << endl;
        cout << "It took " << chrono::duration_cast<chrono::microseconds>(duration_naive).count() << " ms for the naive search" << endl;

        cout << "I found " << ihash << " occurences of " << search_key << endl;
        cout << "It took " << chrono::duration_cast<chrono::microseconds>(duration_hash).count() << " ms for the hash search" << endl;*/
    }

    return 0;
}