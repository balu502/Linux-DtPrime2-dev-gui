#ifndef PROTOCOL_LIB_H
#define PROTOCOL_LIB_H


#include <QMap>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QColor>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include <QChar>
#include <QTime>
#include <QPointF>
#include <QCryptographicHash>
#include <QDomDocument>


#include <QDebug>

enum Protocol_State{mNotExist,mWait,mDrop,mRun,mData,mAnalysis,mReAnalysis};

#define COUNT_EXP 2
#define COUNT_CH 5                                      // count of channel
#define FLUOR_NAME {"Fam","Hex","Rox","Cy5","Cy5.5"}    // name
#define MAX_COUNT_TUBE 384

#include "protocol_lib_global.h"

//--- rt_HeaderTest -----------------------------------------------------------
typedef struct
{
    QString                 ID_Test;
    QString 				Name_Test;
    int 					Type_analysis;
    QString 				Hash;
    unsigned long 			CRC32;
    int 					Active_channel;
    int 					Volume_Tube;
    QVector<QString>		program;
    QString					comment;

}rt_HeaderTest;

//--- rt_Preference ---------------------------------------------------------
typedef struct
{
    QString                 name;
    QString                 value;
    QString                 unit;

}rt_Preference;

//--- rt_ChannelTest ----------------------------------------------------------
class rt_ChannelTest
{
    public:

    int                         ID_Channel;
    int                         number;			// 0-Fam 1-Hex ...
    QString                     name;
    QVector<rt_Preference *>    preference_ChannelTest;

    ~rt_ChannelTest()
    {
        for(unsigned int i=0; i<preference_ChannelTest.size(); i++) delete preference_ChannelTest[i];
        preference_ChannelTest.clear();
    }
};

//--- rt_TubeTest -------------------------------------------------------------
class rt_TubeTest
{
    public:

    int 						ID_Tube;
    QString						name;
    int                         color;
    QVector<rt_ChannelTest *>   channels;
    QVector<rt_Preference *>    preference_TubeTest;

    ~rt_TubeTest()
    {
        for(unsigned int i=0; i<channels.size(); i++) delete channels[i];
        channels.clear();
        for(unsigned int i=0; i<preference_TubeTest.size(); i++) delete preference_TubeTest[i];
        preference_TubeTest.clear();
    }
};

//--- rt_Test -----------------------------------------------------------------
class rt_Test
{
    public:

    rt_HeaderTest				header;
    QVector<rt_TubeTest *>      tubes;
    QVector<rt_Preference *>	preference_Test;

    ~rt_Test()
    {
        for(unsigned int i=0; i<tubes.size(); i++) delete tubes[i];
        tubes.clear();
        for(unsigned int i=0; i<preference_Test.size(); i++) delete preference_Test[i];
        preference_Test.clear();
    }
};

//--- rt_Channel --------------------------------------------------------------
class rt_Channel
{
    public:

    int 					ID_Channel;
    QString 				Unique_NameChannel;
    QVector<QString> 		result_Channel;
    QVector<rt_Preference*> preference_Channel;

    ~rt_Channel()
    {
        result_Channel.clear();
        for(unsigned int i=0; i<preference_Channel.size(); i++) delete preference_Channel[i];
        preference_Channel.clear();
    }
};

//--- rt_Tube -----------------------------------------------------------------
class rt_Tube
{
    public:

    int 					ID_Tube;
    QString                 Unique_NameTube;
    int 					pos;                    // 0-95 0-385 ...
    int 					color;
    bool 					active;
    QVector<rt_Channel *>   channels;
    QVector<QString>		result_Tube;
    QVector<rt_Preference*>	preference_Tube;

    ~rt_Tube()
    {
        for(unsigned int i=0; i<channels.size(); i++) delete channels[i];
        channels.clear();
        result_Tube.clear();
        for(unsigned int i=0; i<preference_Tube.size(); i++) delete preference_Tube[i];
        preference_Tube.clear();
    }
};

//--- rt_Sample ---------------------------------------------------------------
class rt_Sample
{
    public:

    QString 				ID_Sample;
    QString					Unique_NameSample;
    QString 				ID_Test;
    rt_Test                 *p_Test;
    QVector<rt_Tube *>		tubes;
    QVector<QString>		result_Sample;
    QVector<rt_Preference*>	preference_Sample;

    ~rt_Sample()
    {
        for(unsigned int i=0; i<tubes.size(); i++) delete tubes[i];
        tubes.clear();
        result_Sample.clear();
        for(unsigned int i=0; i<preference_Sample.size(); i++) delete preference_Sample[i];
        preference_Sample.clear();
    }
};

//--- rt_GroupSamples ---------------------------------------------------------
class rt_GroupSamples
{
    public:

    QString 				ID_Group;
    QString                 Unique_NameGroup;
    QVector<rt_Sample *>	samples;
    QVector<QString>		result_Group;
    QVector<rt_Preference *>	preference_Group;

    ~rt_GroupSamples()
    {
        for(unsigned int i=0; i<samples.size(); i++) delete samples[i];
        samples.clear();
        result_Group.clear();
        for(unsigned int i=0; i<preference_Group.size(); i++) delete preference_Group[i];
        preference_Group.clear();
    }
};

//--- rt_Plate ----------------------------------------------------------------
class rt_Plate
{
    public:

    int 						ID_Plate;
    QString                  	Unique_NamePlate;

    QVector<rt_GroupSamples *>  groups;

    void PlateSize(int count, int &row, int &col)
    {
       switch(count)
       {
        default:
        case 96:    row = 8;    col = 12;   break;
        case 384:   row = 16;   col = 24;   break;
        case 48:    row = 6;    col = 8;    break;
        case 32:    row = 4;    col = 8;    break;
       case 192:    row = 12;   col = 16;   break;
       }
    }

    ~rt_Plate()
    {
        for(unsigned int i=0; i<groups.size(); i++) delete groups[i];
        groups.clear();
    }
};

//--- rt_Measurement ----------------------------------------------------------
class rt_Measurement
{
    public:

    short fn;                       // number of measurement
    short type_meas;                // type measurement: 1-main 2-melting curve
    short block_number;             //
    short cycle_rep;                //
    short optical_channel;          // 0 - Fam, 1 - Hex, 2 - Rox, 3 - Cy5, 4 - Cy5.5 ...
    short num_exp;                  // number of current expo
    short exp_value;                // value of current expo
    short blk_exp;		    		//

    QVector<short> measurements;

    ~rt_Measurement()
    {
        measurements.clear();
    }

};
//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
class PROTOCOL_LIBSHARED_EXPORT rt_Protocol
{

public:
    QVector<rt_Measurement *> 		meas;			// Raw data
    QVector<QString>				program;		// Program of Amplification
    QVector<rt_Test *>				tests;			// Tests
    rt_Plate						Plate;			// Plate
    QVector<rt_Test *>              Plate_Tests;    // distribution tests on Plate 96,384,...
    //QVector<Criterion_Test*>        Criterion;      // Tests Criterion of Analysis
    QVector<rt_Preference *>        preference_Pro; // Preference of the protocol

    //--- device parameters ---
    QString SerialName;
    QString uC_Versions;
    int     FluorDevice_MASK;
    QString Type_ThermoBlock;
    QString DeviceParameters;   // 512*n (n=1-4)

    QVector<QString> COEFF_Spectral;         // CrossTalk between channels
    QVector<QString> COEFF_Optic;            // Optical unevenness (plate)
    QVector<QString> COEFF_UnequalCh;        // Optical unevenness (channels)

    QVector<short> Exposure;                // first exposure (for all channels)

    //--- public parameters ---

    int count_Tubes;                    // count of tubes on the plate: 96,384,48,...
    int active_Channels;                // active_channels: 0x11111 (4 bit on channel)

    QString name;                       // Name of Protocol
    QString barcode;                    // barcode
    QString time_created;               // time/date of created
    QString regNumber;                  // regNumber
    QString owned_by;                   // Owned_by(Operator)
    Protocol_State state;               // state of protocol(run,analysis,...)
    QVector<short> enable_tube;         // status of drawing protocols tubes
    QVector<int> color_tube;         	// color of protocols tubes
    QString xml_filename;               // XML protocol (input xml,r96,rt protocol)
    QString hash_protocol;              // Hash of protocol
    bool validity_hash;                 // Validity of current protocol (data safety)

    //--- PCR measurements ---
    int count_PCR;                      // count PCR measurements
    QVector<double> PCR_RawData;        // PCR raw data
    QVector<double> X_PCR;              // X_PCR
    QVector<double> PCR_Filtered;       // PCR filtered raw data
    QVector<double> PCR_Bace;           // PCR Bace data
    //QVector<POINT_TAKEOFF*> list_PointsOff;   // list PointsOFF
    QVector<double> Threshold_Ct;       // Threshold for calculate Ct
    QVector<short>  PCR_FinishFlash;    // Analysis of Finish Flash (percent)
    //QVector<SPLINE_CP*> list_SplineCp;  // list Spline_Fitting Cp (alternative variant)
    QVector<double> NormCp_Value;       // coefficients normalization(Cp)
    QVector<double> NormCt_Value;       // coefficients normalization(Ct)

    //--- MC measurements ---
    int count_MC;                       // count MC measurements
    QVector<double> MC_RawData;         // MC raw data
    QVector<double> X_MC;               // X_MC (temperature)
    QVector<double> MC_Filtered;        // MC filtered raw data
    QVector<double> MC_dF_dT;           // dF/dT MC analysis data
    QVector<double> MC_TPeaks;          // Temperature peaks (2 per channel)
    double T_initial;                   // Initial Temperatures in Melting Curve
    double dT_mc;                       // dT in Melting Curve

    //--- additional parameters of ProgramAmpl ---
    QVector<double> PrAmpl_value;
    QVector<double> PrAmpl_time;
    QVector<int> PrAmpl_color;
    QString      PrAmpl_name;
    QVector<int> PrAmpl_countLevelsCycles;
    QVector<QString> PrAmpl_timesInBlocks;
    int PrAmpl_minimumLevel;

    //--- reserve ---
    QMap<QString, QVector<QString>*> Map_Reserve;

    //--- public function ---

    void Clear_Protocol();

    rt_Protocol();
    ~rt_Protocol(){ Clear_Protocol();}
};


PROTOCOL_LIBSHARED_EXPORT   int Read_XML(rt_Protocol *p, QString fn, bool only_config = false);
PROTOCOL_LIBSHARED_EXPORT   void Parsing_ProgramAmplification(rt_Protocol*);                            // Parsing Programm

PROTOCOL_LIBSHARED_EXPORT   bool SaveAsXML(rt_Protocol *p, QString fn, bool only_config = false); // Save as XML
PROTOCOL_LIBSHARED_EXPORT   bool SaveResultsXML(rt_Protocol *p, QString fn_in, QString fn_out="");  // save resutls
PROTOCOL_LIBSHARED_EXPORT   QDomElement MakeElement(QDomDocument &doc, QString name, QString text);
PROTOCOL_LIBSHARED_EXPORT   QDomElement MakeElementResults(QDomDocument &doc, QString name, QVector<QString> *v);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_Test(QDomDocument &doc, rt_Test *ptest);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_SourceSet(QDomDocument &doc, rt_GroupSamples *pgroup, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_Sample(QDomDocument &doc, rt_Sample *psample, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_Device(QDomDocument &doc, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_Measurements(QDomDocument &doc, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_AnalysisCurves(QDomDocument &doc, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   QDomElement SaveXML_AnalysisVersion(QDomDocument &doc, rt_Protocol *p);

PROTOCOL_LIBSHARED_EXPORT   int Convert_NameToIndex(QString name, int column_count);            // Name(A1..) to Index(0-95(383))
PROTOCOL_LIBSHARED_EXPORT   QString Convert_IndexToName(int pos, int column_count);             // Index(0-95(383)) to Name(A1..)
PROTOCOL_LIBSHARED_EXPORT   QString FindNameByTest(rt_Test *ptest, int id_tube, int id_channel);//

PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Group(QDomNode &node, rt_GroupSamples *group, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Sample(QDomNode &node, rt_Sample *sample, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Tube(QDomNode &node, rt_Tube *tube, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Channel(QDomNode &node, rt_Channel *channel, rt_Protocol *p);
PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Test(QDomNode &node, rt_Test *ptest);
PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Measure(QDomNode &node, rt_Measurement *measure);
PROTOCOL_LIBSHARED_EXPORT   void LoadXML_Preference(QDomNode &node, rt_Preference *preference);

PROTOCOL_LIBSHARED_EXPORT   void Sleep(int ms);
PROTOCOL_LIBSHARED_EXPORT   QString GetRandomString(int count = 12);


#endif // PROTOCOL_LIB_H
