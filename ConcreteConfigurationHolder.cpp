#include "BludConfigurationHolder.h"
#include <typeinfo>

BludConfigurationHolder::BludConfigurationHolder()
{
    m_bludConfigFile = std::ifstream(k_bludConfigFilePath, std::ios::in);
}

void BludConfigurationHolder::LoadConfigurationParameters()
{
    if (!m_bludConfigFile.is_open())
    {
        std::cerr << "Failed to open configuration file."; // this should be logged in a log file
    }
    else
    {
        for (std::string line; std::getline(m_bludConfigFile, line);)
        {
            if (line.front() == '#')
                continue;

            PopulateConfigurationObjects_(line);
        }
    }
}
// Unfortunately this function has be massive
void BludConfigurationHolder::PopulateConfigurationObjects_(std::string const& line)
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
uint32_t BludConfigurationHolder::WordCountInString_(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
std::string BludConfigurationHolder::GetLogFilePath() const
{
   auto searchConfigItem = m_configurationDictionary.find("logfilepath");

   if (searchConfigItem != m_configurationDictionary.end())
   {
       std::cout << "Type is: " << typeid(searchConfigItem->second).name() << std::endl;
       m_logFilePath = searchConfigItem->second;
   }
    else
        std::cerr << "Configuration does not exist in file" << std::endl; // should be logged

    return m_logFilePath;
}

std::string BludConfigurationHolder::GetDefaultProjectName() const
{
    return m_logDefaultProjectName;
}

uint64_t BludConfigurationHolder::GetLogSizeMax() const
{
    return m_logsizeMax;
}

uint8_t BludConfigurationHolder::GetLogResultsMs() const
{
    return m_logResultsMs;
}

bool BludConfigurationHolder::IsVirtualChannelLoggingEnabled() const
{
    return m_enableVirtualChannelLogging;
}
bool BludConfigurationHolder::IsLogInterpretationEnabled() const
{
    return m_enableLogInterpretation;
}

bool BludConfigurationHolder::IsLogWindowEnabled() const
{
    return m_enableLogWindow;
}

bool BludConfigurationHolder::IsLogDecisionEnabled() const
{
    return m_enableLogDecision;
}