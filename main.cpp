#include <iostream>
#include <memory>
#include "ConfigurationFileHolder.h"
#include "BludConfigurationHolder.h"
typedef std::shared_ptr<BludConfigurationHolder> ConfigurationFileHolderPtr_t;

int main()
{
    ConfigurationFileHolderPtr_t myConfigFileHolder = std::make_shared<BludConfigurationHolder>();

    myConfigFileHolder->LoadConfigurationParameters();
    std::cout << "From Main: " << myConfigFileHolder->GetLogFilePath() << std::endl;
    

    return 0;

}