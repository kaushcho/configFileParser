#pragma once

class ConfigurationFileHolder
{
public:
    ConfigurationFileHolder() = default;
    virtual ~ConfigurationFileHolder() = default;
    // Open configuration file and load settings
    virtual void LoadConfigurationParameters() = 0;

};