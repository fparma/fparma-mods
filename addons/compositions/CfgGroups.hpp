
// Auto-generated file
#include "script_component.hpp"

class CfgGroups
{
    class Empty
    {
        side = 8;
        name = "Compositions";
        class GVAR(compositions)
        {
            name = "FPARMA";
            class fpa_BunkersTowers
            {
                name = "Bunkers & Towers";
                class fpa_Bunkersmsandbagsdshkm
                {
                    name = "Bunker - sm (sandbags, dshkm)";
                    #include "src\Bunkers & Towers\Bunker - sm (sandbags, dshkm).hpp"
                };
                class fpa_Bunkertowersandbags
                {
                    name = "Bunker - tower (sandbags)";
                    #include "src\Bunkers & Towers\Bunker - tower (sandbags).hpp"
                };
            };
        };
    };
};