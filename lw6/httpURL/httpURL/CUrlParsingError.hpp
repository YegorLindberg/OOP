//
//  CUrlParsingError.hpp
//  httpURL
//
//  Created by Moore on 08.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CUrlParsingError_hpp
#define CUrlParsingError_hpp

#include <stdio.h>
#include <string>

class CUrlParsingError : public std::invalid_argument
{
public:
    CUrlParsingError(std::string const& message);
    std::string What() const;
private:
    std::string m_msg;
};

#endif /* CUrlParsingError_hpp */
