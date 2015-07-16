#ifndef COMPONENTS_ESM_DEBUGPROFILE_H
#define COMPONENTS_ESM_DEBUGPROFILE_H

#include <string>

namespace ESM
{
    class ESMReader;
    class ESMWriter;

    struct DebugProfile
    {
        static unsigned int sRecordId;

        enum Flags
        {
            Flag_Default = 1,       // add to newly opened scene subviews
            Flag_BypassNewGame = 2, // bypass regular game startup
            Flag_Global = 4         // make available from main menu (i.e. not location specific)
        };

        std::string mId;

        std::string mDescription;

        std::string mScriptText;

        unsigned int mFlags;

        bool mIsDeleted;

        DebugProfile();

        void load (ESMReader& esm);
        void save (ESMWriter& esm) const;

        /// Set record to default state (does not touch the ID).
        void blank();
    };
}

#endif
