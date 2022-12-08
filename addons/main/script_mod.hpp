// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX z
#define PREFIX fpa

#include "script_version.hpp"

#define VERSION         MAJOR.MINOR
#define VERSION_STR     MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR      MAJOR,MINOR,PATCHLVL,BUILD
#define VERSION_PLUGIN  MAJOR.MINOR.PATCHLVL.BUILD

#define FPA_TAG FPA

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 2.10
