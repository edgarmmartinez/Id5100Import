#include <cstdint>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

typedef struct  {
    uint8_t     freq[3];

    uint8_t     offset[2];

    uint8_t     toneSqlValue[2];
    
    uint8_t     DTCS;

    uint8_t     :4;
    uint8_t     tuningStep:4;

    uint8_t     unknown;
    
    uint8_t     dtcsPolarity:2;
    uint8_t     dupMode:2;
    uint8_t     toneMode:4;

    char        alphaTag[17];
    char        UR[7];
    char        RPT1[7];
    char        RPT2[7];
} Id5100MemCh;

typedef enum {
    // These enums equal the HW representation for these tones. e.g. A value of 6 represents tone 82.5Hz
    TONE_67_0 = 0,
    TONE_69_3,
    TONE_71_9,
    TONE_74_4,
    TONE_77_0,
    TONE_79_7,
    TONE_82_5,
    TONE_85_4,
    TONE_88_5,
    TONE_91_5,
    TONE_94_8,
    TONE_97_4,
    TONE_100_0,
    TONE_103_5,
    TONE_107_2,
    TONE_110_9,
    TONE_114_8,
    TONE_118_8,
    TONE_123_0,
    TONE_127_3,
    TONE_131_8,
    TONE_136_5,
    TONE_141_3,
    TONE_146_2,
    TONE_151_4,
    TONE_156_7,
    TONE_159_8,
    TONE_162_2,
    TONE_165_5,
    TONE_167_9,
    TONE_171_3,
    TONE_173_8,
    TONE_177_3,
    TONE_179_9,
    TONE_183_5,
    TONE_186_2,
    TONE_189_9,
    TONE_192_8,
    TONE_196_6,
    TONE_199_5,
    TONE_203_5,
    TONE_206_5,
    TONE_210_7,
    TONE_218_1,
    TONE_225_7,
    TONE_229_1,
    TONE_233_6,
    TONE_241_8,
    TONE_250_3,
    TONE_254_1

} Tone;

struct ToneStr {
    static const std::map< ::Tone,string> createMapStr () {
        std::map< ::Tone,string> m;

        m[TONE_67_0] = "67.0Hz";
        m[TONE_69_3] = "69.3Hz";
        m[TONE_71_9] = "71.9Hz";
        m[TONE_74_4] = "74.4Hz";
        m[TONE_77_0] = "77.0Hz";
        m[TONE_79_7] = "79.7Hz";
        m[TONE_82_5] = "82.5Hz";
        m[TONE_85_4] = "85.4Hz";
        m[TONE_88_5] = "88.5Hz";
        m[TONE_91_5] = "91.5Hz";
        m[TONE_94_8] = "94.8Hz";
        m[TONE_97_4] = "97.4Hz";
        m[TONE_100_0] = "100.0Hz";
        m[TONE_103_5] = "103.5Hz";
        m[TONE_107_2] = "107.2Hz";
        m[TONE_110_9] = "110.9Hz";
        m[TONE_114_8] = "114.8Hz";
        m[TONE_118_8] = "118.8Hz";
        m[TONE_123_0] = "123.0Hz";
        m[TONE_127_3] = "127.3Hz";
        m[TONE_131_8] = "131.8Hz";
        m[TONE_136_5] = "136.5Hz";
        m[TONE_141_3] = "141.3Hz";
        m[TONE_146_2] = "146.2Hz";
        m[TONE_151_4] = "151.4Hz";
        m[TONE_156_7] = "156.7Hz";
        m[TONE_159_8] = "159.8Hz";
        m[TONE_162_2] = "162.2Hz";
        m[TONE_165_5] = "165.5Hz";
        m[TONE_167_9] = "167.9Hz";
        m[TONE_171_3] = "171.3Hz";
        m[TONE_173_8] = "173.8Hz";
        m[TONE_177_3] = "177.3Hz";
        m[TONE_179_9] = "179.9Hz";
        m[TONE_183_5] = "183.5Hz";
        m[TONE_186_2] = "186.2Hz";
        m[TONE_189_9] = "189.9Hz";
        m[TONE_192_8] = "192.8Hz";
        m[TONE_196_6] = "196.6Hz";
        m[TONE_199_5] = "199.5Hz";
        m[TONE_203_5] = "203.5Hz";
        m[TONE_206_5] = "206.5Hz";
        m[TONE_210_7] = "210.7Hz";
        m[TONE_218_1] = "218.1Hz";
        m[TONE_225_7] = "225.7Hz";
        m[TONE_229_1] = "229.1Hz";
        m[TONE_233_6] = "233.6Hz";
        m[TONE_241_8] = "241.8Hz";
        m[TONE_250_3] = "250.3Hz";
        m[TONE_254_1] = "254.1Hz";
        
        return m;
    }
    
    static const std::map<string,::Tone> createMapVal () {
        std::map<string,::Tone> m;

        m["67.0Hz"] = TONE_67_0;
        m["69.3Hz"] = TONE_69_3;
        m["71.9Hz"] = TONE_71_9;
        m["74.4Hz"] = TONE_74_4;
        m["77.0Hz"] = TONE_77_0;
        m["79.7Hz"] = TONE_79_7;
        m["82.5Hz"] = TONE_82_5;
        m["85.4Hz"] = TONE_85_4;
        m["88.5Hz"] = TONE_88_5;
        m["91.5Hz"] = TONE_91_5;
        m["94.8Hz"] = TONE_94_8;
        m["97.4Hz"] = TONE_97_4;
        m["100.0Hz"] = TONE_100_0;
        m["103.5Hz"] = TONE_103_5;
        m["107.2Hz"] = TONE_107_2;
        m["110.9Hz"] = TONE_110_9;
        m["114.8Hz"] = TONE_114_8;
        m["118.8Hz"] = TONE_118_8;
        m["123.0Hz"] = TONE_123_0;
        m["127.3Hz"] = TONE_127_3;
        m["131.8Hz"] = TONE_131_8;
        m["136.5Hz"] = TONE_136_5;
        m["141.3Hz"] = TONE_141_3;
        m["146.2Hz"] = TONE_146_2;
        m["151.4Hz"] = TONE_151_4;
        m["156.7Hz"] = TONE_156_7;
        m["159.8Hz"] = TONE_159_8;
        m["162.2Hz"] = TONE_162_2;
        m["165.5Hz"] = TONE_165_5;
        m["167.9Hz"] = TONE_167_9;
        m["171.3Hz"] = TONE_171_3;
        m["173.8Hz"] = TONE_173_8;
        m["177.3Hz"] = TONE_177_3;
        m["179.9Hz"] = TONE_179_9;
        m["183.5Hz"] = TONE_183_5;
        m["186.2Hz"] = TONE_186_2;
        m["189.9Hz"] = TONE_189_9;
        m["192.8Hz"] = TONE_192_8;
        m["196.6Hz"] = TONE_196_6;
        m["199.5Hz"] = TONE_199_5;
        m["203.5Hz"] = TONE_203_5;
        m["206.5Hz"] = TONE_206_5;
        m["210.7Hz"] = TONE_210_7;
        m["218.1Hz"] = TONE_218_1;
        m["225.7Hz"] = TONE_225_7;
        m["229.1Hz"] = TONE_229_1;
        m["233.6Hz"] = TONE_233_6;
        m["241.8Hz"] = TONE_241_8;
        m["250.3Hz"] = TONE_250_3;
        m["254.1Hz"] = TONE_254_1;

        return m;
    };

    const std::map< ::Tone,string> toneStr;
    const std::map<string,::Tone> toneVal;
};

const std::map < ::Tone,string> toneStr = ToneStr::createMapStr ();
const std::map <string,::Tone> toneVal = ToneStr::createMapVal ();

typedef enum {
    FM          = 0,
    FM_N        = 1,
    AM          = 3,
    AM_N        = 4,
    DV          = 5
} Modulation;

struct ModulationStr {
    static const std::map< ::Modulation,string> createMapStr () {
        std::map<Modulation,string> m;

        m[FM]   = "FM";
        m[FM_N] = "FM-N";
        m[AM]   = "AM";
        m[AM_N] = "AM-N";
        m[DV]   = "DV";

        return m;
    }

    static const std::map<string,::Modulation> createMapVal () {
        std::map<string,::Modulation> m;

        m["FM"]         = FM; 
        m["FM-N"]       = FM_N;
        m["AM"]         = AM;
        m["AM-N"]       = AM_N;
        m["DV"]         = DV;

        return m;
    }

    static const std::map< ::Modulation,string> modulationStr;
    static const std::map<string,::Modulation> modulationVal;
};

const std::map< ::Modulation,string> modulationStr = ModulationStr::createMapStr ();
const std::map<string,::Modulation> modulationVal = ModulationStr::createMapVal ();

typedef enum {
} Dtcs;

typedef enum {
    TS_5K = 0,
    TS_6_25K = 1,
    TS_8_33K = 2,
    TS_10K = 4,
    TS_12_5K = 5,
    TS_15K = 6,
    TS_20K = 7,
    TS_25K = 8,
    TS_30K = 9,
    TS_50K = 10,
    TS_AUTO = 14
} TuningStep;

struct TuningStepStr {
    static const std::map< ::TuningStep,string> createMapStr () {
        std::map< ::TuningStep,string> m;

        m[TS_5K]    = "5kHz";
        m[TS_6_25K] = "6.25kHz";
        m[TS_8_33K] = "8.33kHz";
        m[TS_10K]   = "10kHz";
        m[TS_12_5K] = "12.5kHz";
        m[TS_15K]   = "15kHz";
        m[TS_20K]   = "20kHz";
        m[TS_25K]   = "25kHz";
        m[TS_30K]   = "30kHz";
        m[TS_50K]   = "50kHz";
        m[TS_AUTO]  = "AUTO";
        
        return m; 
    }

    static const std::map<string,::TuningStep> createMapVal () {
        std::map<string,::TuningStep> m;

        m["5kHz"]         = TS_5K;
        m["6.25kHz"]      = TS_6_25K;
        m["8.33kHz"]      = TS_8_33K;
        m["10kHz"]        = TS_10K;
        m["12.5kHz"]      = TS_12_5K;
        m["15kHz"]        = TS_15K;
        m["20kHz"]        = TS_20K;
        m["25kHz"]        = TS_25K;
        m["30kHz"]        = TS_30K;
        m["50kHz"]        = TS_50K;
        m["AUTO"]       = TS_AUTO;
        
        return m; 
    }

    static const std::map< ::TuningStep,string> tuningStepStr;
    static const std::map<string,::TuningStep> tuningStepVal;
};

const std::map< ::TuningStep,string> tuningStepStr = TuningStepStr::createMapStr();
const std::map<string,::TuningStep> tuningStepVal = TuningStepStr::createMapVal();

typedef enum {
    OFF = 0,
    TONE = 1,
    TSQL = 3,
    DTCS = 5,
    TSQLR,
    DTCSR,
    DTCST,
    TONET_DTCSR,
    DTCST_TSQLR,
    TONET_TSQLR
} ToneMode;

struct ToneModeStr {
    static const std::map< ::ToneMode,string> createMapStr () {
        std::map<ToneMode,string> m;

        m[OFF] = "OFF";
        m[TONE] = "TONE";
        m[TSQL] = "TSQL";
        m[DTCS] = "DTCS";
        m[TSQLR] = "TSQL-R";
        m[DTCSR] = "DTCS-R";
        m[DTCST] = "DTCS(T)";
        m[TONET_DTCSR] = "TONE(T)/DTCS(R)";
        m[DTCST_TSQLR] = "DTCS(T)/TSQL(R)";
        m[TONET_TSQLR] = "TONE(T)/TSQL(R)";

        return m;
    }

    static const std::map<string,::ToneMode> createMapVal () {
        std::map<string,::ToneMode> m;

        m["OFF"]                = OFF;
        m["TONE"]               = TONE;
        m["TSQL"]               = TSQL;
        m["DTCS"]               = DTCS;
        m["TSQL-R"]             = TSQLR;
        m["DTCS-R"]             = DTCSR;
        m["DTCS(T)"]            = DTCST;
        m["TONE(T)/DTCS(R)"]      = TONET_DTCSR;
        m["DTCS(T)/TSQL(R)"]     = DTCST_TSQLR;
        m["TONE(T)/TSQL(R)"]      = TONET_TSQLR;

        return m;
    }

    static const std::map< ::ToneMode,string> toneModeStr;
    static const std::map<string,::ToneMode> toneModeVal;
};

const std::map< ::ToneMode,string> toneModeStr = ToneModeStr::createMapStr();
const std::map<string,::ToneMode> toneModeVal = ToneModeStr::createMapVal();

typedef enum {
    DUP_OFF = 0,
    DUP_NEG = 1,
    DUP_POS = 2
} DuplexMode;

struct DuplexModeStr {
    static const std::map< ::DuplexMode,string> createMapStr () {
        std::map< ::DuplexMode,string> m;

        m[DUP_OFF] = "OFF";
        m[DUP_NEG] = "DUP-";
        m[DUP_POS] = "DUP+";

        return m;
    }

    static const std::map<string,::DuplexMode> createMapVal () {
        std::map<string,::DuplexMode> m;

        m["OFF"]        = DUP_OFF;
        m["DUP-"]       = DUP_NEG;
        m["DUP+"]       =DUP_POS;

        return m;
    }

    static const std::map< ::DuplexMode,string> duplexModeStr;
    static const std::map<string,::DuplexMode> duplexModeVal;
};

const std::map< ::DuplexMode,string> duplexModeStr = DuplexModeStr::createMapStr ();
const std::map<string,::DuplexMode> duplexModeVal = DuplexModeStr::createMapVal ();

typedef enum {
    BOTH_N = 0,
    TN_RR = 1,
    TR_RN = 2,
    BOTH_R = 3
} DtcsPolarity;

struct DtcsPolarityStr {
    static const std::map< ::DtcsPolarity,string> createMapStr () {
        std::map< ::DtcsPolarity,string> m;

        m[BOTH_N]       = "BOTH N";
        m[TN_RR]        = "TN-RR";
        m[TR_RN]        = "TR-RN";
        m[BOTH_R]       = "BOTH R";

        return m;
    }

    static const std::map<string,::DtcsPolarity> createMapVal () {
        std::map<string,::DtcsPolarity> m;

        m["BOTH N"]      = BOTH_N;
        m["TN-RR"]       = TN_RR;
        m["TR-RN"]       = TR_RN;
        m["BOTH R"]      = BOTH_R;

        return m;
    }

    static const std::map< ::DtcsPolarity,string> dtcsPolarityStr;
    static const std::map<string,::DtcsPolarity> dtcsPolarityVal;
};

const std::map< ::DtcsPolarity,string> dtcsPolarityStr = DtcsPolarityStr::createMapStr ();
const std::map<string,::DtcsPolarity> dtcsPolarityVal = DtcsPolarityStr::createMapVal ();

class  ChannelInfo {
public: // ??? change to private, but add "get" functions
    uint32_t            freqValue;
    uint8_t             freqUnk;
    uint16_t            offsetValue;
    Tone                tone;
    Tone                toneSql;
    Modulation          modulation;
//    Dtcs               dtcs;      // 103 enums. No need for now, just do it as uint8_t
    uint8_t             dtcs;
    TuningStep          tuningStep;
    uint8_t             unknown;
    ToneMode            toneMode;
    DuplexMode          dupMode;
    DtcsPolarity        dtcsPolarity;
    char                alphaTag[17];   // value is 16 chars, plus one for null
    char                urTag[9];       // value is 8 chars, plus one for null
    char                repeater1[9];   // value is 8 chars, plus one for null
    char                repeater2[9];   // value is 8 chars, plus one for null

    bool        isValid;
    float       frequency;
    float       offset;
    float       multiplier;

public:
    ChannelInfo (void) {
        isValid = false;
    };

    ChannelInfo (const Id5100MemCh * pBuffer) {
        isValid = false;
        Decode (pBuffer);
    };

    ChannelInfo (const uint8_t * pBuffer) {
        isValid = false;
        Decode (pBuffer);
    };

    void Encode (uint8_t * pBuffer) {
        Encode ((Id5100MemCh *) pBuffer);
    };

    // Add return status to most of these, OK vs. ERROR
    void Encode (Id5100MemCh * pMem) {
        for (int i = 0; i < 49; i++) {
//            cout << std::hex << ((uint8_t *)pMem)[i] << " ";
            printf ("%02x ", ((uint8_t *)pMem)[i]);
        }
//        cout << endl;
        printf ("\n");

        pMem->freq[0] = (freqUnk << 1) | (freqValue >> 16);
        pMem->freq[1] = (freqValue >> 8) & 0xff;
        pMem->freq[2] = freqValue & 0xff;

        pMem->offset[0] = offsetValue >> 8;
        pMem->offset[1] = offsetValue & 0xff;

        pMem->toneSqlValue[0] = (uint8_t) ((uint32_t) tone << 2) | ((uint32_t) (toneSql >> 4) & 0x3) ;
        pMem->toneSqlValue[1] = (uint8_t) ((uint32_t) toneSql & 0x0f) << 4 | ((uint32_t) modulation & 0x0f);

        pMem->DTCS = (uint8_t) dtcs;

        pMem->tuningStep = (uint8_t) tuningStep & 0x0f;

        pMem->unknown = unknown;

        pMem->dtcsPolarity = (uint8_t) dtcsPolarity;
        pMem->dupMode = (uint8_t) dupMode;
        pMem->toneMode = (uint8_t) toneMode;

        memcpy (pMem->alphaTag, alphaTag, 17);
        EncodeAsciiSeven (urTag, (uint8_t *) pMem->UR);
        EncodeAsciiSeven (repeater1, (uint8_t *) pMem->RPT1);
        EncodeAsciiSeven (repeater2, (uint8_t *) pMem->RPT2);

        for (int i = 0; i < 49; i++) {
            printf ("%02x ", ((uint8_t *)pMem)[i]);
//            std::cout << std::hex << ((uint8_t *)pMem)[i] << " ";
        }
        cout << endl;
        cout << "---------------" << endl;
    };

    void Decode (const uint8_t * pBuffer) {
        const Id5100MemCh *   pMem = (Id5100MemCh *) pBuffer;

        Decode (pMem);
    };
        
    void Decode (const Id5100MemCh * pMem) {
        freqValue = (pMem->freq[0] & 0x01) << 16 | pMem->freq[1] << 8 | pMem->freq[2];
        freqUnk = pMem->freq[0] >> 1;    // The 7 MSBs of the byte
        offsetValue = pMem->offset[0] << 8 | pMem->offset[1];
        tone = static_cast< ::Tone> (pMem->toneSqlValue[0] >> 2);
        toneSql = static_cast< ::Tone> ((pMem->toneSqlValue[0] & 0x03) << 4 | pMem->toneSqlValue[1] >> 4);
        modulation = static_cast< ::Modulation> (pMem->toneSqlValue[1] & 0x0f);
        dtcs = (uint8_t) pMem->DTCS;
        tuningStep = static_cast< ::TuningStep> (pMem->tuningStep);
        unknown = pMem->unknown;
        toneMode = static_cast< ::ToneMode> (pMem->toneMode);
        dupMode = static_cast< ::DuplexMode> (pMem->dupMode);
        dtcsPolarity = static_cast< ::DtcsPolarity> (pMem->dtcsPolarity);
        memcpy (alphaTag, pMem->alphaTag, 17);
        DecodeAsciiSeven ((uint8_t*) pMem->UR, urTag);
        DecodeAsciiSeven ((uint8_t*) pMem->RPT1, repeater1);
        DecodeAsciiSeven ((uint8_t*) pMem->RPT2, repeater2);

        multiplier = Multiplier (freqUnk);
        frequency = freqValue * multiplier;
        offset = offsetValue * multiplier;
        isValid = true;
    };
    
    void Frequency (float newFrequency) {
        frequency = newFrequency;

        freqValue = (uint32_t) (round(newFrequency / Multiplier (newFrequency)));
        printf ("%.4f became 0x%06x\n", newFrequency/Multiplier(newFrequency), freqValue);

        // offsetValue could change depending on the frequency set, so let's reset it
        Offset (offset);
        freqUnk = FreqUnk (frequency);

    };

    void Offset (float newOffset) {
        offset = newOffset;

        offsetValue = (uint16_t) (round(offset / Multiplier (frequency)));
        return;
    };

    void Tone (::Tone newTone) {
        tone = newTone;
        return;
    };

    void ToneSql (::Tone newTone) {
        toneSql = newTone;
        return;
    };

    void Modulation (::Modulation newModulation) {
        modulation = newModulation;
        return;
    };

    void Dtcs (uint8_t  newDtcs) {
        dtcs = newDtcs;
        return;
    };

    void TuningStep (::TuningStep newTs) {
        tuningStep = newTs;
        return;
    };

    void ToneMode (::ToneMode newToneMode) {
        toneMode = newToneMode;
        return;
    };

    void DupMode (::DuplexMode    newDupMode) {
        dupMode = newDupMode;
        return;
    };

    void DtcsPolarity (::DtcsPolarity     newDtcsPol) {
        dtcsPolarity = newDtcsPol;
        return;
    };

        
    void PaddedCopy (string src, char * pDst, int copySize) {
        int copyMax = copySize-1;
        int i;

        // Copy name portion, up to max name size
        for (i = 0; src[i] != '\0' && i < copyMax; i++) {
            pDst[i] = src[i];
        }

        //  Pad with spaces
        for (; i < copyMax; i++) {
            pDst[i] = ' ';
        }

        // Add null ending
        pDst[i] = '\0';

        return;
    };

    //  alphaTag should always be a NULL terminated, space padded, string
    void AlphaTag (string newAlpha) {
        PaddedCopy (newAlpha, alphaTag, sizeof(alphaTag));
        return;
    };

    void UrTag (string newUrTag) {
        PaddedCopy (newUrTag, urTag, sizeof(urTag));
        return;
    };

    void Repeater1 (string newRpt1) {
        PaddedCopy (newRpt1, repeater1, sizeof(repeater1));
        return;
    };

    void Repeater2 (string newRpt2) {
        PaddedCopy (newRpt2, repeater2, sizeof(repeater2));
        return;
    };

    void EncodeAsciiSeven (string newStr, uint8_t * pDst) {
        EncodeAsciiSeven (newStr.data(), pDst);
        return;
    }

    // Pack eight 7-bit values into seven bytes
    void EncodeAsciiSeven (char * pNewStr, uint8_t * pDst) {
        int copyMax = 8;
        uint8_t ch;

        memset (pDst, 0, copyMax);
        for (int byte = 0; byte < copyMax; byte++) {
            uint8_t ch = (uint8_t) pNewStr[byte] & 0x7f;
            if (byte > 0) {
                pDst[byte-1] |= ch >> (7-byte);
            }

            if (byte < 7) {
                pDst[byte] |= ch << (byte+1);
            }
        }

        return;
    };

    void DecodeAsciiSeven (uint8_t * pSrc, char * pDst) {
        int copyMax = 8;
        uint8_t ch;

        memset (pDst, 0, copyMax);
        for (int byte = 0; byte < copyMax; byte++) {
            if (byte > 0) {
                pDst[byte] |= pSrc[byte-1] << (7-byte);
            }

            if (byte < 7) {
                pDst[byte] |= pSrc[byte] >> (byte+1);
            }
        }
    };

    float Multiplier (uint8_t freqUnk) {
        switch (freqUnk) {
            case 0x12:
                return 0.00625;
                break;
            case 0x24:
                return 0.0083333333;
                break;
            default:
                return 0.005;
                break;
        }
    };

    float Multiplier (float freq) {
        if (freq >= 118.0 && freq < 137.0) {
            return 0.0083333333;
        }

        if ((freq >= 137.0 && freq <= 174.0) ||
            (freq >= 375.0 && freq < 550)) {
            float remainder = (int) (freq * 1000) % 5;
            printf ("Modulo 5 of %f is %f\n", freq * 1000, remainder);
            if (remainder == 0) {
                return 0.005;
            }
        }
        return 0.00625;
    };

    uint8_t FreqUnk (float freq) {
        if (freq >= 118.0 && freq < 137.0) {
            return 0x24;
        }

        if ((freq >= 137.0 && freq <= 174.0) ||
            (freq >= 375.0 && freq < 550)) {
            float remainder = (int) (freq * 1000) % 5;
            printf ("Modulo 5 of %f is %f\n", freq * 1000, remainder);
            if (remainder == 0) {
                return 0x00;
            }
        }

        return 0x12;
    };

};

const int       MemChannels = 1000;

class CsvRow {
public:
    std::vector<string> row;

    CsvRow (void);
    CsvRow (string inputLine) {
        Decode (inputLine);
    };

    void Decode (string inputLine) {
        const char * pCurr = inputLine.c_str();
        const char * pToken = NULL;
        string  newToken;

        while (*pCurr != '\0') {
            pToken = pCurr;
            while (*pCurr != ',' && *pCurr != '\0') {
//                cout << *pCurr << endl;
                if (*pCurr == '\"') {
                    pCurr++;
                    while (*pCurr != '\"' && *pCurr != '\0') {
                        pCurr++;
                    }
                }
                
                if (*pCurr != '\0') {
                    pCurr++;
                }
            }
                
            newToken.assign(pToken, pCurr - pToken);
//            cout << "tk: " << newToken << endl;
            row.push_back (newToken);

            if (*pCurr != '\0') {
                pCurr++;
            }
        }

        for (int elem = 0; elem < row.size(); elem++) {
            cout << row[elem] << ",";
        }
        cout << endl;
    }
};

/*
 * CSV import/export columns for ID-5100a:
 *
 *      E.g.:
 *      CH No,Frequency,Dup,Offset,TS,Mode,Name,SKIP,TONE,Repeater Tone,TSQL Frequency,DTCS Code,DTCS Polarity,DV SQL,DV CSQL Code,Your Call Sign,RPT1 Call Sign,RPT2 Call Sign
 *      0,145.7,DUP-,0.6,5kHz,FM,149.975 etc etc,PSKIP,OFF,67.0Hz,67.0Hz,23,BOTH N,OFF,0,AAAAAAAA,V53W   C,
 *      1,145.7125,DUP-,0.6,5kHz,FM-N,PSkip,SKIP,OFF,69.3Hz,67.0Hz,23,TN-RR,OFF,0,BBBBBBBB,ZS6PTA C,
 *      2,145.7,DUP-,0.6,5kHz,FM,Tone 162.2,PSKIP,OFF,71.9Hz,67.0Hz,23,TR-RN,OFF,0,11111111,V53W   C,V53W   G
 *      3,145.7125,DUP-,0.6,5kHz,FM-N,Tone 162.2,PSKIP,OFF,74.4Hz,67.0Hz,23,BOTH R,OFF,0,55555555,ZS6PTA C,ZS6PTA G
 *      4,149.975,OFF,0.6,5kHz,FM,Tone 186.2,SKIP,OFF,77.0Hz,67.0Hz,23,BOTH N,OFF,0,12345678,,
 *      5,149.975,OFF,0.6,5kHz,DV,Tone 254.1,PSKIP,OFF,79.7Hz,67.0Hz,23,TN-RR,OFF,0,ABCDEFGH,,
 *      6,149.975,OFF,0.6,5kHz,DV,TSQL 74.4,PSKIP,OFF,82.5Hz,218.1Hz,23,TR-RN,OFF,0,CQCQCQ,,
 *      7,149.975,OFF,0.6,5kHz,FM,TSQL 159.8,SKIP,OFF,85.4Hz,225.7Hz,23,BOTH R,OFF,0,CQCQCQ,,
 *      99,129.7,OFF,0,25kHz,AM,DFW-AA Dispatch,OFF,OFF,88.5Hz,88.5Hz,23,BOTH N,OFF,0,CQCQCQ,,
 *      100,129.825,OFF,0,25kHz,AM,DFW-D18-D40RampC,OFF,OFF,88.5Hz,88.5Hz,23,BOTH N,OFF,0,CQCQCQ,,
 *      101,129.9,OFF,0,25kHz,AM,DFW - UPS,OFF,OFF,88.5Hz,88.5Hz,23,BOTH N,OFF,0,CQCQCQ,,
 *
 *      CS-5100 nuances:
 *              Export replaces commas in alpha tag with spaces!!!
 *              Must do separate files for each 100 channel bank
 *              Must import each separate file individually, one per 100 channel bank
 *              Some fields mix numbers and text (e.g. Tone = "88.5Hz")
 *      
 * 
 */

typedef enum{           // CSV Column Title
    Csv_ChNumber = 0,   // CH No
    Csv_Frequency,      // Frequency
    Csv_Dup,            // Dup
    Csv_Offset,         // Offset
    Csv_TS,             // TS
    Csv_Modulation,     // Mode
    Csv_Name,           // Name
    Csv_Skip,           // SKIP
    Csv_ToneMode,       // TONE
    Csv_RepeaterTone,   // RepeaterTone
    Csv_TsqlFreq,       // TSQL Frequency
    Csv_DtcsCode,       // DTCS Code
    Csv_DtcsPolarity,   // DTCS Polarity
    Csv_DvSql,          // DV SQL
    Csv_DvCsql,         // DV CSQL Code
    Csv_UrCall,         // Your Call Sign
    Csv_Rpt1,           // RPT1 Call Sign
    Csv_Rpt2            // RPT Call Sign
} Id5100CsvColumns;

std::vector<CsvRow> *    importCsv (char * csvFileName, ChannelInfo * pChInfo[]) {

    std::string         inputLine;
    std::ifstream       csvFile (csvFileName, std::ios::ate);
    std::streamsize     csvSize = csvFile.tellg();
    std::vector<CsvRow> *       pCsvRows = new std::vector<CsvRow> ();

    csvFile.seekg(0, std::ios::beg);

    // Process headers (Discard for now)
    std::getline (csvFile, inputLine);

    while (std::getline (csvFile, inputLine)) {
        cout << "Parsing: " << inputLine << endl;
        pCsvRows->push_back (*(new CsvRow (inputLine)));
    }

    return pCsvRows;
};

void modifyChannelInfo (ChannelInfo * pChannelInfo [], std::vector<CsvRow> * pCsvRows, char * pBuffer){
    Id5100MemCh * pChMem = (Id5100MemCh *) pBuffer;

    for (std::vector<CsvRow>::iterator it = pCsvRows->begin(); it != pCsvRows->end(); it++) {

        if (it->row[Csv_Frequency].size() == 0) {
            continue;
        }
        int chNumber = stoi(it->row[Csv_ChNumber]);
        cout << chNumber << ": " << stof(it->row[Csv_Frequency]) << endl;

        pChannelInfo[chNumber]->Frequency (stof(it->row[Csv_Frequency]));
        pChannelInfo[chNumber]->Offset (stof(it->row[Csv_Offset]));

        try {
            pChannelInfo[chNumber]->Tone (toneVal.at(it->row[Csv_RepeaterTone]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: Tone " << it->row[Csv_RepeaterTone] << oor.what() << endl;
            pChannelInfo[chNumber]->Tone (Tone::TONE_88_5);
//            continue;
        }

        try {
            pChannelInfo[chNumber]->ToneSql (toneVal.at(it->row[Csv_TsqlFreq]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: ToneSQL " << it->row[Csv_TsqlFreq] << oor.what() << endl;
            pChannelInfo[chNumber]->ToneSql (Tone::TONE_88_5);
//            continue;
        }

        try {
            pChannelInfo[chNumber]->Modulation (modulationVal.at(it->row[Csv_Modulation]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: Modulation " << it->row[Csv_Modulation] << oor.what() << endl;
            continue;
        }

        if (it->row[Csv_DtcsCode] != "") {
            pChannelInfo[chNumber]->Dtcs (stoi(it->row[Csv_DtcsCode]));     // ??? Change this to looong enum (103 values)
        }

        try {
            pChannelInfo[chNumber]->TuningStep (tuningStepVal.at(it->row[Csv_TS]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: tuning step " << it->row[Csv_TS] << oor.what() << endl;
            continue;
        }

        try {
            pChannelInfo[chNumber]->ToneMode (toneModeVal.at(it->row[Csv_ToneMode]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: tone Mode " << it->row[Csv_ToneMode] << oor.what() << endl;
            continue;
        }

        try {
            pChannelInfo[chNumber]->DupMode (duplexModeVal.at(it->row[Csv_Dup]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: duplex mode " << it->row[Csv_Dup] << oor.what() << endl;
            continue;
        }

        try {
            pChannelInfo[chNumber]->DtcsPolarity (dtcsPolarityVal.at(it->row[Csv_DtcsPolarity]));
        } catch (const std::out_of_range &oor) {
            cout << "Out of range exception: dtcs polarity " << it->row[Csv_DtcsPolarity] << oor.what() << endl;
            continue;
        }
        
        pChannelInfo[chNumber]->AlphaTag(it->row[Csv_Name].data());
        pChannelInfo[chNumber]->UrTag (it->row[Csv_UrCall]);
        pChannelInfo[chNumber]->Repeater1 (it->row[Csv_Rpt1]);
        pChannelInfo[chNumber]->Repeater2 (it->row[Csv_Rpt2]);

        pChannelInfo[chNumber]->Encode(&pChMem[chNumber]);
    }

    return;
};

void exportBin (char * pBinBuffer, int size, char * pOutFileName) {
    std::ofstream binOutFile (pOutFileName, std::ios::binary);
    
    binOutFile.write (pBinBuffer, size);
}

int main (int argc, char ** argv) {
    if (argc != 2 && argc != 4) {
        cout << "Usage: " << argv[0] << " <icf BIN input file> [<csv input data> <bin output file]\n";
        return 1;
    }

    std::ifstream binFile(argv[1], std::ios::binary | std::ios::ate);
    std::streamsize size = binFile.tellg();
    binFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (binFile.read(buffer.data(), size)) {
        cout << "Read " << size << " bytes\n";
    }

    Id5100MemCh *               pMem = (Id5100MemCh *) buffer.data();
    ChannelInfo *               pChannelInfo[MemChannels];
    std::vector<CsvRow> *       pCsvRows;

    cout << fixed;
    cout << setprecision(4);

    for (int i = 0; i < MemChannels; i++) {
        pChannelInfo[i] = new ChannelInfo ((const Id5100MemCh *) &(pMem[i]));
        float multiplier = 0.0;
    }

    for (int i = 0; i < MemChannels; i++) {
        cout << "Channel " << i << ": " <<
            pChannelInfo[i]->alphaTag <<
            ", freq:" << pChannelInfo[i]->frequency <<
            ", offset:" << pChannelInfo[i]->offset <<
            ", Tone:" << toneStr.at(pChannelInfo[i]->tone) <<
            ", ToneSQL:" << toneStr.at(pChannelInfo[i]->toneSql) <<
            ", Mod:" << modulationStr.at(pChannelInfo[i]->modulation) <<
            ", TS:" << tuningStepStr.at(pChannelInfo[i]->tuningStep) <<
            ", ToneMode:" << toneModeStr.at(pChannelInfo[i]->toneMode) <<
            ", dupMode:" << duplexModeStr.at(pChannelInfo[i]->dupMode) <<
            ", dtcsPol:" << dtcsPolarityStr.at(pChannelInfo[i]->dtcsPolarity) <<
            std::endl; 
    }

    if (argc > 2) {
        cout << "Importing Csv" << endl;

        pCsvRows = importCsv (argv[2], pChannelInfo);

        cout << "Modifying ChannelInfo structures" << endl;

        modifyChannelInfo (pChannelInfo, pCsvRows, buffer.data());

        cout << "------------------------------\n";

        for (int i = 0; i < 10; i++) {
            cout << "Channel " << i << ": " <<
                pChannelInfo[i]->alphaTag <<
                ", freq:" << pChannelInfo[i]->frequency <<
                ", offset:" << pChannelInfo[i]->offset <<
                ", Tone:" << toneStr.at(pChannelInfo[i]->tone) <<
                ", ToneSQL:" << toneStr.at(pChannelInfo[i]->toneSql) <<
                ", Mod:" << modulationStr.at(pChannelInfo[i]->modulation) <<
                ", TS:" << tuningStepStr.at(pChannelInfo[i]->tuningStep) <<
                ", ToneMode:" << toneModeStr.at(pChannelInfo[i]->toneMode) <<
                ", dupMode:" << duplexModeStr.at(pChannelInfo[i]->dupMode) <<
                ", dtcsPol:" << dtcsPolarityStr.at(pChannelInfo[i]->dtcsPolarity) <<
                std::endl; 
        }

        cout << "Outputing new bin file" << endl;
        exportBin (buffer.data(), size, argv[3]);
    }

    return 0;
}

