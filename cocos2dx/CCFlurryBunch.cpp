//
// Created by Shubin Fedor on 16/10/14.
//

#include "CCFlurryBunch.h"
#include "CCPlatformDefine.h"
#include "CCBunchManager.h"
#include "CCNativeGateway.h"

#define BUNCH "FlurryBunch"

static CCFlurryBunch *INSTANCE = nullptr;

CCFlurryBunch *CCFlurryBunch::getInstance() {
    CC_ASSERT(INSTANCE);
    return INSTANCE;
}

CCFlurryBunch::CCFlurryBunch() {
    apiKey = "";
}

bool CCFlurryBunch::initialize(const char *apiKey) {
    if (INSTANCE == nullptr) {
        INSTANCE = new CCFlurryBunch();
        INSTANCE->apiKey = apiKey;
        CCBunchManager::registerBunch(BUNCH);
        INSTANCE->startSession(apiKey);
        return true;
    } else {
        return false;
    }
}

void CCFlurryBunch::startSession(const char *apiKey) {
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("apiKey", apiKey, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "startSession",
            dict
    );
}

void CCFlurryBunch::setAppVersion(const char *appVersion) {
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("appVersion", appVersion, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "setAppVersion",
            dict
    );
}

void CCFlurryBunch::logEvent(const char *eventId, std::map <std::string, std::string> &params) {
    rapidjson::Value *jsonParams = mapToJson(params);
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("eventId", eventId, dict.GetAllocator());
    dict.AddMember("parameters", jsonParams, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "logEvent",
            dict
    );
    delete jsonParams;
}

void CCFlurryBunch::logError(const char *errorId, const char *message, std::map <std::string, std::string> &params) {
    rapidjson::Value *jsonParams = mapToJson(params);
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("errorId", errorId, dict.GetAllocator());
    dict.AddMember("message", message, dict.GetAllocator());
    dict.AddMember("parameters", jsonParams, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "logError",
            dict
    );
    delete jsonParams;
}

void CCFlurryBunch::logPageView() {
    rapidjson::Document dict = rapidjson::Document();
    CCNativeGateway::dispatch(
            BUNCH,
            "logPageView",
            dict
    );
}

void CCFlurryBunch::logTimedEventBegin(const char *eventId, std::map <std::string, std::string> &params) {
    rapidjson::Value *jsonParams = mapToJson(params);
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("eventId", eventId, dict.GetAllocator());
    dict.AddMember("parameters", jsonParams, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "logTimedEventBegin",
            dict
    );
    delete jsonParams;
}

void CCFlurryBunch::logTimedEventEnd(const char *eventId, std::map <std::string, std::string> &params) {
    rapidjson::Value *jsonParams = mapToJson(params);
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("eventId", eventId, dict.GetAllocator());
    dict.AddMember("parameters", jsonParams, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "logTimedEventEnd",
            dict
    );
    delete jsonParams;
}

void CCFlurryBunch::setContinueSessionMillis(long milliseconds) {
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("milliseconds", (double)milliseconds, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "setContinueSessionMillis",
            dict
    );
}

void CCFlurryBunch::setDebugLogEnabled(bool enabled) {
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("enabled", enabled, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "setDebugLogEnabled",
            dict
    );
}

void CCFlurryBunch::setUserId(const char *userId) {
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("userId", userId, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "setUserId",
            dict
    );
}

void CCFlurryBunch::setAge(int age) {
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("age", age, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "setAge",
            dict
    );
}

rapidjson::Value *CCFlurryBunch::mapToJson(std::map <std::string, std::string> &dict) {
    rapidjson::Value *pRet = new rapidjson::Value();
    rapidjson::Value &ret = *pRet;

    for (std::map<std::string, std::string>::iterator it=dict.begin(); it!=dict.end(); ++it) {
        ret[it->first.c_str()] = it->second.c_str();
    }

    return pRet;
}
