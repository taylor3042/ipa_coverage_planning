//#line 2 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the ipa_building_navigation package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __ipa_building_navigation__BUILDINGNAVIGATIONCONFIG_H__
#define __ipa_building_navigation__BUILDINGNAVIGATIONCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace ipa_building_navigation
{
  class BuildingNavigationConfigStatics;

  class BuildingNavigationConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      virtual ~AbstractParamDescription() = default;

      virtual void clamp(BuildingNavigationConfig &config, const BuildingNavigationConfig &max, const BuildingNavigationConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const BuildingNavigationConfig &config1, const BuildingNavigationConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, BuildingNavigationConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const BuildingNavigationConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, BuildingNavigationConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const BuildingNavigationConfig &config) const = 0;
      virtual void getValue(const BuildingNavigationConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T BuildingNavigationConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T BuildingNavigationConfig::* field;

      virtual void clamp(BuildingNavigationConfig &config, const BuildingNavigationConfig &max, const BuildingNavigationConfig &min) const override
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const BuildingNavigationConfig &config1, const BuildingNavigationConfig &config2) const override
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, BuildingNavigationConfig &config) const override
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const BuildingNavigationConfig &config) const override
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, BuildingNavigationConfig &config) const override
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const BuildingNavigationConfig &config) const override
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const BuildingNavigationConfig &config, boost::any &val) const override
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      virtual ~AbstractGroupDescription() = default;

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, BuildingNavigationConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, BuildingNavigationConfig &top) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const override
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<BuildingNavigationConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(BuildingNavigationConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("tsp_solver"==(*_i)->name){tsp_solver = boost::any_cast<int>(val);}
        if("problem_setting"==(*_i)->name){problem_setting = boost::any_cast<int>(val);}
        if("planning_method"==(*_i)->name){planning_method = boost::any_cast<int>(val);}
        if("max_clique_path_length"==(*_i)->name){max_clique_path_length = boost::any_cast<double>(val);}
        if("maximum_clique_size"==(*_i)->name){maximum_clique_size = boost::any_cast<int>(val);}
        if("map_downsampling_factor"==(*_i)->name){map_downsampling_factor = boost::any_cast<double>(val);}
        if("check_accessibility_of_rooms"==(*_i)->name){check_accessibility_of_rooms = boost::any_cast<bool>(val);}
        if("return_sequence_map"==(*_i)->name){return_sequence_map = boost::any_cast<bool>(val);}
        if("display_map"==(*_i)->name){display_map = boost::any_cast<bool>(val);}
      }
    }

    int tsp_solver;
int problem_setting;
int planning_method;
double max_clique_path_length;
int maximum_clique_size;
double map_downsampling_factor;
bool check_accessibility_of_rooms;
bool return_sequence_map;
bool display_map;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int tsp_solver;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int problem_setting;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int planning_method;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double max_clique_path_length;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int maximum_clique_size;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double map_downsampling_factor;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool check_accessibility_of_rooms;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool return_sequence_map;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool display_map;
//#line 231 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("BuildingNavigationConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const BuildingNavigationConfig &__max__ = __getMax__();
      const BuildingNavigationConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const BuildingNavigationConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const BuildingNavigationConfig &__getDefault__();
    static const BuildingNavigationConfig &__getMax__();
    static const BuildingNavigationConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const BuildingNavigationConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void BuildingNavigationConfig::ParamDescription<std::string>::clamp(BuildingNavigationConfig &config, const BuildingNavigationConfig &max, const BuildingNavigationConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class BuildingNavigationConfigStatics
  {
    friend class BuildingNavigationConfig;

    BuildingNavigationConfigStatics()
    {
BuildingNavigationConfig::GroupDescription<BuildingNavigationConfig::DEFAULT, BuildingNavigationConfig> Default("Default", "", 0, 0, true, &BuildingNavigationConfig::groups);
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.tsp_solver = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.tsp_solver = 3;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.tsp_solver = 3;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("tsp_solver", "int", 0, "TSP solver", "{'enum': [{'name': 'NearestNeighbor', 'type': 'int', 'value': 1, 'srcline': 9, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Use the nearest neighbor TSP algorithm.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'GeneticSolver', 'type': 'int', 'value': 2, 'srcline': 10, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Use the genetic TSP algorithm.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'ConcordeSolver', 'type': 'int', 'value': 3, 'srcline': 11, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Use the Concorde TSP algorithm.', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'TSP solver'}", &BuildingNavigationConfig::tsp_solver)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("tsp_solver", "int", 0, "TSP solver", "{'enum': [{'name': 'NearestNeighbor', 'type': 'int', 'value': 1, 'srcline': 9, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Use the nearest neighbor TSP algorithm.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'GeneticSolver', 'type': 'int', 'value': 2, 'srcline': 10, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Use the genetic TSP algorithm.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'ConcordeSolver', 'type': 'int', 'value': 3, 'srcline': 11, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Use the Concorde TSP algorithm.', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'TSP solver'}", &BuildingNavigationConfig::tsp_solver)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.problem_setting = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.problem_setting = 2;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.problem_setting = 2;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("problem_setting", "int", 0, "Problem setting of the sequence planning problem", "{'enum': [{'name': 'SimpleOrderPlanning', 'type': 'int', 'value': 1, 'srcline': 16, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Plan the optimal order of a simple set of locations.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'CheckpointBasedPlanning', 'type': 'int', 'value': 2, 'srcline': 17, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Two-stage planning that creates local cliques of locations (= checkpoints) and determines the optimal order through the members of each clique as well as the optimal order through the cliques.', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'Problem setting of the sequence planning problem'}", &BuildingNavigationConfig::problem_setting)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("problem_setting", "int", 0, "Problem setting of the sequence planning problem", "{'enum': [{'name': 'SimpleOrderPlanning', 'type': 'int', 'value': 1, 'srcline': 16, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Plan the optimal order of a simple set of locations.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'CheckpointBasedPlanning', 'type': 'int', 'value': 2, 'srcline': 17, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Two-stage planning that creates local cliques of locations (= checkpoints) and determines the optimal order through the members of each clique as well as the optimal order through the cliques.', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'Problem setting of the sequence planning problem'}", &BuildingNavigationConfig::problem_setting)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.planning_method = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.planning_method = 2;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.planning_method = 2;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("planning_method", "int", 0, "Trolley placement method (only applies to CheckpointBasedPlanning problem)", "{'enum': [{'name': 'DragTrolleyWhenNecessary', 'type': 'int', 'value': 1, 'srcline': 23, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Drag the trolley if it is too far away from next room.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'PrecomputeRoomGroupsAndCorrespondingTrolleyPosition', 'type': 'int', 'value': 2, 'srcline': 24, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Put rooms together in groups and calculate a corresponding trolley positions.', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'Trolley placement method (only applies to CheckpointBasedPlanning problem)'}", &BuildingNavigationConfig::planning_method)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("planning_method", "int", 0, "Trolley placement method (only applies to CheckpointBasedPlanning problem)", "{'enum': [{'name': 'DragTrolleyWhenNecessary', 'type': 'int', 'value': 1, 'srcline': 23, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Drag the trolley if it is too far away from next room.', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'PrecomputeRoomGroupsAndCorrespondingTrolleyPosition', 'type': 'int', 'value': 2, 'srcline': 24, 'srcfile': '/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg', 'description': 'Put rooms together in groups and calculate a corresponding trolley positions.', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'Trolley placement method (only applies to CheckpointBasedPlanning problem)'}", &BuildingNavigationConfig::planning_method)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_clique_path_length = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_clique_path_length = std::numeric_limits<double>::infinity();
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_clique_path_length = 12.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<double>("max_clique_path_length", "double", 0, "Max A* path length between two rooms that are assigned to the same clique, in [m] (only applies to CheckpointBasedPlanning problem)", "", &BuildingNavigationConfig::max_clique_path_length)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<double>("max_clique_path_length", "double", 0, "Max A* path length between two rooms that are assigned to the same clique, in [m] (only applies to CheckpointBasedPlanning problem)", "", &BuildingNavigationConfig::max_clique_path_length)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.maximum_clique_size = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.maximum_clique_size = 2147483647;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.maximum_clique_size = 9001;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("maximum_clique_size", "int", 0, "Maximal number of nodes belonging to one trolley clique (only applies to CheckpointBasedPlanning problem)", "", &BuildingNavigationConfig::maximum_clique_size)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<int>("maximum_clique_size", "int", 0, "Maximal number of nodes belonging to one trolley clique (only applies to CheckpointBasedPlanning problem)", "", &BuildingNavigationConfig::maximum_clique_size)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.map_downsampling_factor = 1e-05;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.map_downsampling_factor = 1.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.map_downsampling_factor = 0.25;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<double>("map_downsampling_factor", "double", 0, "The map may be downsampled during computations (e.g. of A* path lengths) in order to speed up the algorithm, if set to 1 the map will have original size, if set to 0 the algorithm won't work", "", &BuildingNavigationConfig::map_downsampling_factor)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<double>("map_downsampling_factor", "double", 0, "The map may be downsampled during computations (e.g. of A* path lengths) in order to speed up the algorithm, if set to 1 the map will have original size, if set to 0 the algorithm won't work", "", &BuildingNavigationConfig::map_downsampling_factor)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.check_accessibility_of_rooms = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.check_accessibility_of_rooms = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.check_accessibility_of_rooms = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<bool>("check_accessibility_of_rooms", "bool", 0, "Tells the sequence planner if it should check the given room centers for accessibility from the starting position", "", &BuildingNavigationConfig::check_accessibility_of_rooms)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<bool>("check_accessibility_of_rooms", "bool", 0, "Tells the sequence planner if it should check the given room centers for accessibility from the starting position", "", &BuildingNavigationConfig::check_accessibility_of_rooms)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.return_sequence_map = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.return_sequence_map = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.return_sequence_map = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<bool>("return_sequence_map", "bool", 0, "Tells the server if the map with the sequence drawn in should be returned", "", &BuildingNavigationConfig::return_sequence_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<bool>("return_sequence_map", "bool", 0, "Tells the server if the map with the sequence drawn in should be returned", "", &BuildingNavigationConfig::return_sequence_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.display_map = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.display_map = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.display_map = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<bool>("display_map", "bool", 0, "Show the resulting map with paths (only if return_sequence_map=true)", "", &BuildingNavigationConfig::display_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(BuildingNavigationConfig::AbstractParamDescriptionConstPtr(new BuildingNavigationConfig::ParamDescription<bool>("display_map", "bool", 0, "Show the resulting map with paths (only if return_sequence_map=true)", "", &BuildingNavigationConfig::display_map)));
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(BuildingNavigationConfig::AbstractGroupDescriptionConstPtr(new BuildingNavigationConfig::GroupDescription<BuildingNavigationConfig::DEFAULT, BuildingNavigationConfig>(Default)));
//#line 369 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<BuildingNavigationConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<BuildingNavigationConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<BuildingNavigationConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    BuildingNavigationConfig __max__;
    BuildingNavigationConfig __min__;
    BuildingNavigationConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const BuildingNavigationConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static BuildingNavigationConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &BuildingNavigationConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const BuildingNavigationConfig &BuildingNavigationConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const BuildingNavigationConfig &BuildingNavigationConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const BuildingNavigationConfig &BuildingNavigationConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<BuildingNavigationConfig::AbstractParamDescriptionConstPtr> &BuildingNavigationConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<BuildingNavigationConfig::AbstractGroupDescriptionConstPtr> &BuildingNavigationConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const BuildingNavigationConfigStatics *BuildingNavigationConfig::__get_statics__()
  {
    const static BuildingNavigationConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = BuildingNavigationConfigStatics::get_instance();

    return statics;
  }

//#line 9 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_NearestNeighbor = 1;
//#line 10 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_GeneticSolver = 2;
//#line 11 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_ConcordeSolver = 3;
//#line 16 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_SimpleOrderPlanning = 1;
//#line 17 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_CheckpointBasedPlanning = 2;
//#line 23 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_DragTrolleyWhenNecessary = 1;
//#line 24 "/home/taylor/room_exp/src/ipa_building_navigation/cfg/BuildingNavigation.cfg"
      const int BuildingNavigation_PrecomputeRoomGroupsAndCorrespondingTrolleyPosition = 2;
}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __BUILDINGNAVIGATIONRECONFIGURATOR_H__
