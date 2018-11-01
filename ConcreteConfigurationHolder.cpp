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

#include "ConcreteConfigurationHolder.h"

ConcreteConfigurationHolder::ConcreteConfigurationHolder()
{
    m_configFile = std::ifstream(k_configFilePath, std::ios::in);
}

void ConcreteConfigurationHolder::LoadConfigurationParameters()
{
    if (!m_configFile.is_open())
    {
        std::cerr << "Failed to open configuration file."; // this should be logged in a log file
    }
    else
    {
        for (std::string line; std::getline(m_configFile, line);)
        {
            if (line.front() == '#')
                continue;

            PopulateConfigurationObjects_(line);
        }
    }
}
// Unfortunately this function has be massive
void ConcreteConfigurationHolder::PopulateConfigurationObjects_(std::string const& line)
{
    std::istringstream wordsInLine(line);

    // Typical configuration file has two words - the key and the value
    // This is kind of a hack as we control the config file
    if (WordCountInString_(line) == 2)
    {
        std::string key, value;
        wordsInLine >> key;
        wordsInLine >> value;
        m_configurationDictionary.insert(std::make_pair(key, value));
    }
}

// Utility function shouldn't be in this class
uint32_t ConcreteConfigurationHolder::WordCountInString_(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

std::string ConcreteConfigurationHolder::GetLogFilePath() 
{
   auto searchConfigItem = m_configurationDictionary.find("logfilepath");

   if (searchConfigItem != m_configurationDictionary.end())
       m_logFilePath = searchConfigItem->second;
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_logFilePath;
}

std::string ConcreteConfigurationHolder::GetDefaultProjectName() 
{
    auto searchConfigItem = m_configurationDictionary.find("log_default_project");

   if (searchConfigItem != m_configurationDictionary.end())
       m_logDefaultProjectName = searchConfigItem->second;
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_logDefaultProjectName;
}

uint32_t ConcreteConfigurationHolder::GetLogSizeMax() 
{
    auto searchConfigItem = m_configurationDictionary.find("logsize_max");

    if (searchConfigItem != m_configurationDictionary.end())
        m_logsizeMax = std::stoi(searchConfigItem->second);
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_logsizeMax;
}

uint32_t ConcreteConfigurationHolder::GetLogResultsMs() 
{
    auto searchConfigItem = m_configurationDictionary.find("log_results_ms");

    if (searchConfigItem != m_configurationDictionary.end())
        m_logResultsMs = std::stoi(searchConfigItem->second);
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_logResultsMs;
}

bool ConcreteConfigurationHolder::IsVirtualChannelLoggingEnabled() 
{
    auto searchConfigItem = m_configurationDictionary.find("log_virtualChannels");

    if (searchConfigItem != m_configurationDictionary.end())
        std::istringstream(searchConfigItem->second) >> m_enableVirtualChannelLogging;
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_enableVirtualChannelLogging;
}
bool ConcreteConfigurationHolder::IsLogInterpretationEnabled() 
{
    auto searchConfigItem = m_configurationDictionary.find("log_interpretation");

    if (searchConfigItem != m_configurationDictionary.end())
        std::istringstream(searchConfigItem->second) >> m_enableLogInterpretation;
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_enableLogInterpretation;
}

bool ConcreteConfigurationHolder::IsLogWindowEnabled() 
{
    auto searchConfigItem = m_configurationDictionary.find("log_window");

    if (searchConfigItem != m_configurationDictionary.end())
        std::istringstream(searchConfigItem->second) >> m_enableLogWindow;
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_enableLogWindow;
}

bool ConcreteConfigurationHolder::IsLogDecisionEnabled() 
{
    auto searchConfigItem = m_configurationDictionary.find("log_decision");

    if (searchConfigItem != m_configurationDictionary.end())
        std::istringstream(searchConfigItem->second) >> m_enableLogDecision;
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_enableLogDecision;
}