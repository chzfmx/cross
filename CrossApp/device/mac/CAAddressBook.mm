//
//  CAAddressBook.cpp
//  CrossApp
//
//  Created by 秦乐 on 2017/2/21.
//  Copyright © 2017年 cocos2d-x. All rights reserved.
//

#include "CAAddressBook.h"
#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>

NS_CC_BEGIN

CAAddressBook::CAAddressBook()
{
}

CAAddressBook::~CAAddressBook()
{
}

void CAAddressBook::getAddressBook(const std::function<void(const std::vector<CAAddressBook::Date>&)>& callback)
{

}

NS_CC_END
