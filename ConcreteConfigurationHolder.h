/*MIT License

Copyright (c) [2018] [Kaushik Choudhary]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/ 

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

// Concrete class that implements the interface from the Configuration Holder class
// In addition to that, this class provides an interface to access objects containing 
// key value pairs for configuration items from a known configuration file containing
// configurations in the form of key and value pairs on each separate line.
// This class ignores comments in the configuration file when commented using a '#' 
// character
class ConcreteConfigurationHolder: public ConfigurationFileHolder
{
private:
    // default configuration path
    const std::string k_configFilePath = "./SampleConfig.conf"; 
    std::ifstream m_configFile;

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
    ConcreteConfigurationHolder();
    ~ConcreteConfigurationHolder() = default;

    // Interface functions
    void LoadConfigurationParameters() override;

    // Configuration parameter Getters
    // The getters are not const because there are no setters
    // We set the values for the parameters in the getter function. 
    // This is done to be perform lazy initialization of the member 
    // variables carrying the configuration parameters.
    std::string GetLogFilePath();
    std::string GetDefaultProjectName();
    uint64_t GetLogSizeMax();
    uint8_t GetLogResultsMs();
    bool IsVirtualChannelLoggingEnabled();
    bool IsLogInterpretationEnabled();
    bool IsLogWindowEnabled();
    bool IsLogDecisionEnabled();


};