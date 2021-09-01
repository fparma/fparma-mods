class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class GVAR(attributes) {
                displayName = "FPArma - Attributes";
                collapsed = 1;
                class Attributes {
                    class GVAR(hasFPDuplexPriority) {
                        property = QGVAR(hasFPDuplexPriority);
                        control = "Checkbox";
                        displayName = "ACRE-FPDuplex priority";
                        tooltip = "Set this unit as a priority speaker on ACRE radio channels. FPDuplex will not interrupt this unit's transmissions when someone else speaks!";
                        expression = "if (_value) then { _this setVariable ['%s', _value, true]; }";
                        typeName = "BOOL";
                        condition = "objectBrain";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
