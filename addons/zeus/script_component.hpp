#define COMPONENT zeus
#include "\z\fpa\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#include "\z\fpa\addons\main\script_macros.hpp"

// fixed next CBA
#undef RETDEF
#define RETDEF(VARIABLE,DEFAULT_VALUE) (if (isNil {VARIABLE}) then [{DEFAULT_VALUE}, {VARIABLE}])

#define RSC_DYNAMIC_DIALOG_ID 8800701
