#ifndef COEFF_STRUCT
#define COEFF_STRUCT

struct Fluor_SpectralInfo				// 30 byte
    {
        char fluor_name[12];
        short id_group;
        short coeff[8];
    };
struct SpectralCoeff_Compensation   	// 512 byte
    {
        char signature[30];
        short count;
        Fluor_SpectralInfo Info_Spectral[16];
    };
struct OpticalCoeff_Compensation        // 512 byte
    {
        char signature[30];
        char fluor_name[12];
        short coeff[192];
        char reserve[86];
    };
struct Fluor_UnequalInfo                // 18 byte
    {
       char fluor_name[12];
       short id_group;
       short coeff[2];
    };
struct UnequalCoeff_Compensation        // 512 byte
    {
        char signature[30];
        short count;
        Fluor_UnequalInfo Info_Unequal[16];
        char reserve[192];
    };

#endif // COEFF_STRUCT

