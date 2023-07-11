#ifndef REPOSITORY_CC_STATIC_HASHING_H_
#define REPOSITORY_CC_STATIC_HASHING_H_

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

#include "file.h"

const int NO_BUCKETS_SH_ = 7;
const int READ_HEADER_FILE_SH_ = 1048;
const int LENGTH_ADDRESS_SH_ = sizeof(long int);
const int SIZE_BLOCK_SH_ = READ_HEADER_FILE_SH_ - LENGTH_ADDRESS_SH_;
const int SIZE_ROW_INT_SH_ = sizeof(int) + sizeof(long int);
const int ROW_CAPACITY_SH_ = SIZE_BLOCK_SH_ / SIZE_ROW_INT_SH_;

namespace repository {

    class StaticHashing : public File {
    
        public:
             
            StaticHashing(){}
            StaticHashing(const std::string& name){ name_ = name; ext_ = EXT_INDEX_; }
            ~StaticHashing(){}

            void InitAddressBucket();
            static long int GetFileSizeSH(const std::string& name);
            
            static int ReadInt(const std::string& name, long int position);
            static long int ReadAddress(const std::string& name, long int position);
            static void UpdateInt(const std::string& name, long int position, int new_address);
            static void UpdateAddress(const std::string& name, long int position, long int new_address);
            
            
            static std::vector<long int> GetBucketsAddress(const std::string& name);

            static void CreateBlock(const std::string& name, int position);
            static int GetHash(int key);
            static std::list< std::pair< int, long int>> ReadBlock(const std::string& name,int position);
            static void AddLineToBlock(const std::string& name,int position, std::list< std::pair<int, long int> > list_data_pair, int data, long int data_address);
            static long int GetAddress(const std::string& name,long int bucket_address, int key );
            static long int GetBucketAddress(const std::string& name,int hash);
            static void RemoveDataInt(const std::string& name, int position, int data, std::list< std::pair<int, long int>> list_data_pair);
        

    }; 

}  // end namespace repository

#endif  // REPOSITORY_CC_STATIC_HASHING_H_