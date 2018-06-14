//
//  CUrlParsingError.cpp
//  httpURL
//
//  Created by Moore on 08.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CUrlParsingError.hpp"

CUrlParsingError::CUrlParsingError(std::string const& msg)
:invalid_argument(msg),
m_msg(msg)
{
}

std::string CUrlParsingError::What() const
{
    return m_msg;
}
