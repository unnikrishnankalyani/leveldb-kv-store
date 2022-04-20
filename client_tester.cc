#include <iostream>
#include <cassert>

#include <leveldb/cache.h>          
#include <leveldb/comparator.h>     
#include <leveldb/dumpfile.h>       
#include <leveldb/export.h>         
#include <leveldb/iterator.h>       
#include <leveldb/slice.h>          
#include <leveldb/table_builder.h>  
#include <leveldb/write_batch.h>    
#include <leveldb/c.h>              
#include <leveldb/db.h>             
#include <leveldb/env.h>            
#include <leveldb/filter_policy.h>  
#include <leveldb/options.h>        
#include <leveldb/status.h>         
#include <leveldb/table.h> 

#include "custom_fs.cc"

int main(int argc, char* argv[]) {
    
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    
    leveldb::Env* actual_env = leveldb::Env::Default();
    leveldb::Env* env = new CustomEnv(actual_env);
    options.env = env;
    
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    leveldb::Status s = db->Put(leveldb::WriteOptions(), "1", "val1");

    std::string ans = "";
    if (s.ok()) s = db->Get(leveldb::ReadOptions(), "1", &ans);

    std::cout<<ans<<"\n";

    return 0;
}
