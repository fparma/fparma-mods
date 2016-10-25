#include "script_component.hpp"

GVAR(id) = format ["%1///%2///%3///%4", worldName, briefingName, dateToNumber date, round random 10000];
call COMPILE_FILE(sock);
