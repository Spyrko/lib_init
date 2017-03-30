#pragma once

#include <lib_init/Base.hpp>
#include <orocos_callback_base/Port.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>
#include <maps/grid/MLSMap.hpp>
#include <envire_core/items/SpatioTemporal.hpp>
namespace init
{

class MLSProvider : public virtual Base
{
public:
    MLSProvider(const std::string& name) : Base(name) {}
    virtual ~MLSProvider() {}
    
    virtual cbProxies::OutputPort<envire::core::SpatioTemporal<maps::grid::MLSMapKalman > >& getMapPort() = 0;
    
    virtual bool generateMap() = 0;

};

class MLSSlopedProvider : public virtual Base
{
public:
    MLSSlopedProvider(const std::string& name) : Base(name) {}
    virtual ~MLSSlopedProvider() {}

    virtual cbProxies::OutputPort<envire::core::SpatioTemporal<maps::grid::MLSMapSloped > >& getMapPort() = 0;

    virtual bool generateMap() = 0;

};

class MLSPrecalculatedProvider : public virtual Base
{
public:
    MLSPrecalculatedProvider(const std::string& name) : Base(name) {}
    virtual ~MLSPrecalculatedProvider() {}

    virtual cbProxies::OutputPort<envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated > >& getMapPort() = 0;

    virtual bool generateMap() = 0;

};

}
