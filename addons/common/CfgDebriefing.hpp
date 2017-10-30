class CfgDebriefing {

    class Completed {
        title = "Mission Completed";
        subtitle = "Good job!";
        picture = "mil_circle";
        pictureColor[] = {0.0,0.3,0.6,1};
    };

    class Ended {
        title = "Mission Ended";
        picture = "mil_circle";
        pictureColor[] = {0.0,0.3,0.6,1};
    };

    class BluforDead {
        subtitle = "BLUFOR took too many casualties";
        picture = "b_inf";
        pictureColor[] = {0.0,0.3,0.6,1};
    };

    class OpforDead {
        subtitle = "OPFOR took too many casualties";
        picture = "o_inf";
        pictureColor[] = {0.5,0.0,0.0,1};
    };

    class IndepDead {
        subtitle = "INDFOR took too many casualties";
        picture = "n_inf";
        pictureColor[] = {0.0,0.5,0.0,1};
    };

    class CivDead {
        title = "Mission Failed";
        subtitle = "Too many civilians were killed";
        picture = "KIA";
        pictureColor[] = {0.4,0.0,0.5,1};
    };

    class TimeLimit {
        title = "Mission Failed";
        subtitle = "Time limit was reached";
        picture = "mil_circle";
        pictureColor[] = {0.7,0.6,0.0,1};
    };

    class AdminEnd {
        title = "Mission Ended";
        subtitle = "The mission was ended by an admin";
        picture = "mil_objective";
        pictureColor[] = {0.7,0.6,0.0,1};

    };
};

