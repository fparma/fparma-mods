class CfgMovesBasic;
class CfgMovesMaleSdr:CfgMovesBasic 
{
  class States
  {
    class Unconscious;
    class kka3_unc_1: Unconscious
    {
      file = QPATHTOF(anims\kka3_unc_1.rtm);
      collisionShape = "A3\anims_f\Data\Geom\Sdr\geom_empty.p3d";
      actions = "ReviveWoundedDefaultActions";
      looped = 1;
      useIdles = 1;
      interpolationRestart = 0;
      interpolationSpeed = 60;
      leaning = "empty";
      aiming = "empty";
      aimingBody = "empty";
      head = "headNo";
      forceAim = 1;
      variantAfter[] = {17,17,17};
      variantsPlayer[] = {};
      variantsAI[] = {};
      InterpolateTo[] = {};
      ConnectTo[] = {};
    };
    class kka3_unc_2: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_2.rtm);
    };
    class kka3_unc_3: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_3.rtm);
    };
    class kka3_unc_4: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_4.rtm);
    };
    class kka3_unc_5: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_5.rtm);
    };
    class kka3_unc_6: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_6.rtm);
    };
    class kka3_unc_7: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_7.rtm);
    };
    class kka3_unc_8: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_8.rtm);
    };
    class kka3_unc_1_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_1_1.rtm);
    };
    class kka3_unc_2_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_2_1.rtm);
    };
    class kka3_unc_3_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_3_1.rtm);
    };
    class kka3_unc_4_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_4_1.rtm);
    };
    class kka3_unc_5_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_5_1.rtm);
    };
    class kka3_unc_6_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_6_1.rtm);
    };
    class kka3_unc_7_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_7_1.rtm);
    };
    class kka3_unc_8_1: kka3_unc_1
    {
      file = QPATHTOF(anims\kka3_unc_8_1.rtm);
    };
  };
};