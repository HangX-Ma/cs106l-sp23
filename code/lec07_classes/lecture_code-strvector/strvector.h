//in case mutliple files in a project include strvector, 
//this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>


class StrVector {
    public:
        //type alias (this is how iterator types work!)
        using iterator = std::string*;

        //define an initial size for your underlying array
        const size_t kInitialSize = 2;
        
        //constructors and destructor

    private:
       
};

#endif // STRVECTOR_H


