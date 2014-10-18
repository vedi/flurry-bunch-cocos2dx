//
// Created by Shubin Fedor on 16/10/14.
//


#ifndef __CCFlurryBunch_H_
#define __CCFlurryBunch_H_

#include <string>
#include <map>
#include "json/document.h"

class CCFlurryBunch {
public:
    static CCFlurryBunch *getInstance();
    static bool initialize(char const *apiKey);
private:
    std::string apiKey;

    CCFlurryBunch();

public:
    void startSession(char const *apiKey);

    void setAppVersion(char const *appVersion);

    void setContinueSessionMillis(long milliseconds);

    void setDebugLogEnabled(bool enabled);

    void setUserId(char const *userId);

    void setAge(int age);

    void logEvent(char const *eventId, std::map<std::string, std::string> &params);

    void logError(char const *errorId, char const *message, std::map<std::string, std::string> &params);

    void logPageView();

    void logTimedEventBegin(char const *eventId, std::map<std::string, std::string> &params);

    void logTimedEventEnd(char const *eventId, std::map<std::string, std::string> &params);

private:

    static rapidjson::Value *mapToJson(std::map <std::string, std::string> &dict);
};


#endif //__CCFlurryBunch_H_
