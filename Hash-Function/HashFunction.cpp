#include "HashFucntion.h"

#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>
#include <sstream>
#include <assert.h>

//using namespace std;

//namespace HashFunction {
//
//    // implementation of a basic addition hash
//    unsigned int badHash(const char* data, unsigned int length) {
//        unsigned int hash = 0;
//
//        for (unsigned int i = 0; i < length; ++i)
//            hash += data[i];
//
//        return hash;
//    }

    //// m_loadedTextures is a std::map< unsigned int, Texture* >
    //Texture* loadTexture(const char* filename) {
    //    unsigned int fileID = hash(filename);
    //    Texture* texture = nullptr;
    //    auto iter = m_loadedTextures.find(fileID);
    //    // integer search faster that string comparison
    //    if (iter == m_loadedTextures.end()) {
    //        texture = loadTextureResource(filename);
    //        m_loadedTextures.insert(
    //            std::make_pair(fileID, texture));
    //    }
    //    else
    //        texture = iter.second;
    //    return texture;
    //}
    //Texture* getTexture(unsigned int ID) {
    //    auto iter = m_loadedTextures.find(ID);
    //    if (iter == m_loadedTextures.end()
    //        return nullptr;
    //    else
    //        return iter.second;
    //}
