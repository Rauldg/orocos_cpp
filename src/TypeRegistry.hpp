#pragma once

#include <string>
#include <map>
#include <memory>


namespace Typelib
{
    class Registry;
}

namespace orocos_cpp
{

class TypeRegistry;
typedef std::shared_ptr<TypeRegistry> TypeRegistryPtr;

class TypeRegistry
{
    std::map<std::string, std::string> typeToTypekit;
    std::map<std::string, unsigned> taskStateToID;

public:
    TypeRegistry();
    
    /**
     * Loads all type registries in order to receive the nessesary information.
     */
    bool loadTypeRegistries();
    
    bool getTypekitDefiningType(const std::string &typeName, std::string &typekitName);

    /**
     * Returns the ID of a given state name of a task.
     * @param task_model_name e.g. "auv_control::AccelerationController"
     * @param state_name e.g. "CONTROLLING"
     * @param id the corresponding state ID
     *
     * @returns false if the state or the task is unknown
     */
    bool getStateID(const std::string &task_model_name, const std::string &state_name, unsigned& id) const;

protected:
    /**
     * Loads a tlb file to the registry.
     * @param path the path to the tlb file
     */
    bool loadRegistry(const std::string &path, Typelib::Registry* registry);

    /**
     * Saves the stateToIDMapping from a given tlb file.
     * @param path the path to the tlb file
     */
    bool loadStateToIDMapping(const std::string &path);

    /**
     * Saves the typeToTypekitMapping from a given typelist file.
     * @param path the path to the typelist file
     * @param typekitName the name of the corresponding typekit
     */
    bool loadTypeToTypekitMapping(const std::string &path, const std::string &typekitName);
};
}
