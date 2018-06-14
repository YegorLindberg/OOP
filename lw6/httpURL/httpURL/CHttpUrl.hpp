//
//  CHttpUrl.hpp
//  httpURL
//
//  Created by Moore on 04.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CHttpUrl_hpp
#define CHttpUrl_hpp

#include <string>
#include <regex>

enum Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    // выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
    // выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
    CHttpUrl(std::string const& url);
    /* инициализирует URL на основе переданных параметров.
     При недопустимости входных параметров выбрасывает исключение
     std::invalid_argument
     Если имя документа не начинается с символа /, то добавляет / к имени документа
     */
    CHttpUrl(std::string const& domain,
             std::string const& document,
             Protocol protocol = HTTP);
    /* инициализирует URL на основе переданных параметров.
     При недопустимости входных параметров выбрасывает исключение
     std::invalid_argument
     Если имя документа не начинается с символа /, то добавляет / к имени документа
     */
    CHttpUrl(std::string const& domain,
             std::string const& document,
             Protocol protocol,
             unsigned short port);
    // возвращает строковое представление URL-а. Порт, являющийся стандартным для
    // выбранного протокола (80 для http и 443 для https) в URL не должен включаться
    std::string GetURL() const;
    // возвращает доменное имя
    std::string GetDomain() const;
    /*
     Возвращает имя документа. Примеры:
     /
     /index.html
     /images/photo.jpg
     */
    std::string GetDocument() const;
    // возвращает тип протокола
    Protocol GetProtocol() const;
    std::string GetProtocolString() const;
    // возвращает номер порта
    unsigned short GetPort() const;
    
private:
    std::string m_url = "";
    std::string m_domain = "";
    std::string m_document = "";
    Protocol m_protocol = HTTP;
    unsigned short m_port = 80;
    
    void AddDomain(std::string const& possibleDomain);
    void AddDocument(std::string const& possibleDocument);
    void AddProtocol(std::string const& possibleProtocol);
    void AddPort(std::string const& possiblePort = "");
    void AddUrl();
    std::smatch GetParseResult();
    std::string GetLowerString(std::string const& str);
};


#endif /* CHttpUrl_hpp */
