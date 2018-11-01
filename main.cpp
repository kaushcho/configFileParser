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

#include <iostream>
#include <memory>

#include "ConfigurationFileHolder.h"
#include "ConcreteConfigurationHolder.h"

typedef std::shared_ptr<ConcreteConfigurationHolder> ConfigurationFileHolderPtr_t;

int main()
{
    ConfigurationFileHolderPtr_t myConfigFileHolder = std::make_shared<ConcreteConfigurationHolder>();

    myConfigFileHolder->LoadConfigurationParameters();

    // The configuration object holds the configuration items. The items have been loaded into the configuration
    // object and inserted into an std::map (often implemented using a binary tree). This could also be stored in
    // an std::unordered_map which would be more like a hash table. The data structure lookup for the specific 
    // configuration item only happens when the Getter for the configuration item is called. 
    std::cout << "Log File Path: " << myConfigFileHolder->GetLogFilePath() << std::endl;
    std::cout << "Project name: " << myConfigFileHolder->GetDefaultProjectName() << std::endl;
    std::cout << "Maximum log size: " << myConfigFileHolder->GetLogSizeMax() << std::endl;
    std::cout << "CDF Data interval in ms: " << myConfigFileHolder->GetLogResultsMs() << std::endl;
    std::cout << "Is Virtual Channel Logging Enabled: " << myConfigFileHolder->IsVirtualChannelLoggingEnabled() << std::endl;
    std::cout << "Is Log Interpretation Enabled: " << myConfigFileHolder->IsLogInterpretationEnabled() << std::endl;
    std::cout << "Is Log Window Enabled: " << myConfigFileHolder->IsLogWindowEnabled() << std::endl;
    std::cout << "Is Log Decision Enabled: " << myConfigFileHolder->IsLogDecisionEnabled() << std::endl;

    return 0;

}