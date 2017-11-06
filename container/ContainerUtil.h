//
//  ContainerUtil.h
//  HashMap
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#ifndef NoctisGames_ContainerUtil_h
#define NoctisGames_ContainerUtil_h

#include <container/HashMap.h>

#include <string>
#include <assert.h>

namespace NoctisGames
{
    class ContainerUtil
    {
    public:
        template<typename K, typename T, typename H>
        static void cleanUpHashMapOfPointers(HashMap<K, T*, H>& hashMap)
        {
            for (typename HashMap<K, T*, H>::Iterator i = hashMap.begin(); i != hashMap.end(); )
            {
                delete i.second();
                
                i = hashMap.erase(i);
            }
        }
        
    private:
        // ctor, copy ctor, and assignment should be private in a Singleton
        ContainerUtil();
        ContainerUtil(const ContainerUtil&);
        ContainerUtil& operator=(const ContainerUtil&);
    };
}

#endif /* NoctisGames_ContainerUtil_h */
