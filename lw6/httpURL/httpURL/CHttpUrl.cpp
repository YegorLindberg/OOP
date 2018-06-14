//
//  CHttpUrl.cpp
//  httpURL
//
//  Created by Moore on 04.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CHttpUrl.hpp"
#include "CUrlParsingError.hpp"
#include <regex>
#include <iostream>
#include <algorithm>

CHttpUrl::CHttpUrl(std::string const& url)
:m_url(url)
{
    std::smatch parseResult = GetParseResult();
    AddProtocol(parseResult[1]);
    AddDomain(parseResult[2]);
    AddPort(parseResult[3]);
    AddDocument(parseResult[4]);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
:m_protocol(protocol)
{
    AddDomain(domain);
    AddPort();
    AddDocument(document);
    AddUrl();
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
:m_protocol(protocol)
{
    AddDomain(domain);
    AddPort(std::to_string(port));
    AddDocument(document);
    AddUrl();
}

std::smatch CHttpUrl::GetParseResult()
{
    std::regex regex(R"(^(https?)://([A-Za-z0-9-.]+)(?::([0-9]+))?(?:\/(.*))?$)", std::regex_constants::icase);
    std::smatch result;
    if (!std::regex_match(m_url, result, regex))
    {
        throw CUrlParsingError("You have printed uncorrect url");
    }
    return result;
}

void CHttpUrl::AddUrl()
{
    if (m_protocol == HTTP)
    {
        m_url = "http://" + m_domain + (m_port != 80 ? ':' + std::to_string(m_port) + m_document : m_document);
    }
    else
    {
        m_url = "https://" + m_domain + (m_port != 443 ? ':' + std::to_string(m_port) + m_document : m_document);
    }
}

std::string CHttpUrl::GetLowerString(std::string const& str)
{
    std::string result = "";
    for (size_t i = 0; i < str.size(); i++)
    {
        result += tolower(str[i]);
    }
    return result;
}

std::string CHttpUrl::GetProtocolString() const
{
    return m_protocol == HTTP ? "http" : "https";
}

void CHttpUrl::AddProtocol(std::string const& possibleProtocol)
{
    auto lowerProtocol = GetLowerString(possibleProtocol);
    if (lowerProtocol == "http")
    {
        m_protocol = HTTP;
    }
    else if (lowerProtocol == "https")
    {
        m_protocol = HTTPS;
    }
}

void CHttpUrl::AddDomain(std::string const& possibleDomain)
{
    std::regex regex(R"(^([A-Za-z0-9-.]+)$)", std::regex_constants::icase);
    std::smatch result;
    if (!std::regex_match(possibleDomain, result, regex))
    {
        throw CUrlParsingError("Uncorrect domain");
    }
    m_domain = possibleDomain;
}

void CHttpUrl::AddPort(std::string const& possiblePort)
{
    if (possiblePort == "")
    {
        if (m_protocol == HTTP)
        {
            m_port = 80;
        }
        else
        {
            m_port = 443;
        }
        return;
    }
    
    int port = 0;
    try
    {
        port = std::stoi(possiblePort);
    }
    catch(...)
    {
        throw CUrlParsingError("Uncorrect port");
    }
    
    if (port >= 1 && port <= 65535)
    {
        m_port = static_cast<unsigned short>(port);
    }
    else
    {
        throw CUrlParsingError("Uncorrect port");
    }
}

void CHttpUrl::AddDocument(std::string const& possibleDocument)
{
    if (possibleDocument.size() == 0 || possibleDocument[0] != '/')
    {
        m_document = '/' + possibleDocument;
    }
    else
    {
        m_document = possibleDocument;
    }
}

std::string CHttpUrl::GetURL() const
{
    return m_url;
}

std::string CHttpUrl::GetDomain() const
{
    return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
    return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
    return m_port;
}
