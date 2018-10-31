#pragma once
// C++ library includes
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <string>

// local includes
#include "ConfigurationFileHolder.h"


class BludConfigurationHolder: public ConfigurationFileHolder
{
private:
    // default BLUD configuration path
    const std::string k_bludConfigFilePath = "./TrimmedBludConf.conf"; 
    std::ifstream m_bludConfigFile;

    // data structure containing Configuration file 
    std::map<std::string, std::string> m_configurationDictionary;

    // Member variables containing configuration parameters
    std::string m_logFilePath; // does this need to be configured? 
    std::string m_logDefaultProjectName; // does this need to be configured
    uint64_t m_logsizeMax; 
    uint8_t m_logResultsMs; // Interval CDF data in ms
    bool m_enableVirtualChannelLogging;
    bool m_enableLogInterpretation;
    bool m_enableAggregation;
    bool m_enableLogWindow;
    bool m_enableLogDecision;


    // Private functions
    void PopulateConfigurationObjects_(std::string const&);
    uint32_t WordCountInString_(std::string const&);

public: 
    BludConfigurationHolder();
    ~BludConfigurationHolder() = default;

    // Interface functions
    void LoadConfigurationParameters() override;

    // Configuration parameter Getters
    std::string GetLogFilePath() const;
    std::string GetDefaultProjectName() const;
    uint64_t GetLogSizeMax() const;
    uint8_t GetLogResultsMs() const;
    bool IsVirtualChannelLoggingEnabled() const;
    bool IsLogInterpretationEnabled() const;
    bool IsLogWindowEnabled() const;
    bool IsLogDecisionEnabled() const;


};