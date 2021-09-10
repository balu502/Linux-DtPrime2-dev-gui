#include "protocol_lib.h"


//-----------------------------------------------------------------------------
//---
//-----------------------------------------------------------------------------
rt_Protocol::rt_Protocol()
{

}
//-----------------------------------------------------------------------------
//--- Clear Protocol
//-----------------------------------------------------------------------------
void rt_Protocol::Clear_Protocol()
{
    uint i;

    name.clear();                       // name
    barcode.clear();                    // barcode
    time_created.clear();               // time_created
    regNumber.clear();                  // regNumber
    owned_by.clear();                   // owned_by
    program.clear(); 					// program of amplification
    enable_tube.clear();				// enable_tube
    color_tube.clear();					// color_tube
    //list_Channels.clear();				// list_Channels
    PCR_RawData.clear();                // clear PCR_RawData
    X_PCR.clear();                      // clear X_PCR
    PCR_Filtered.clear();               // clear PCR_Filtered
    PCR_Bace.clear();                   // clear PCR_Bace
    Threshold_Ct.clear();               // clear Threshold
    PCR_FinishFlash.clear();            // clear PCR_FinishFlash
    MC_RawData.clear();                 // clear MC_RawData
    X_MC.clear();                       // clear X_MC
    MC_Filtered.clear();                // clear MC_Filtered
    MC_dF_dT.clear();                   // clear MC_dF_dT
    MC_TPeaks.clear();                  // clear MC_TPeaks

    NormCp_Value.clear();               // clear NormCp_Value
    NormCt_Value.clear();               // clear NormCt_Value

    SerialName.clear();
    uC_Versions.clear();
    FluorDevice_MASK = 0;
    active_Channels = 0;
    Type_ThermoBlock.clear();
    DeviceParameters.clear();
    COEFF_Spectral.clear();             // clear COEFF_Spectral
    COEFF_Optic.clear();                // clear COEFF_Optic
    COEFF_UnequalCh.clear();            // clear COEFF_UnequalCh
    Exposure.clear();                   // clear Exposure

    /*for(i=0; i<list_PointsOff.size(); i++)
    {
       POINT_TAKEOFF *pp_off = list_PointsOff.at(i);
       delete pp_off;
    }
    list_PointsOff.clear();                                         // clear list_PointsOff

    for(i=0; i<list_SplineCp.size(); i++)
    {
        SPLINE_CP *p_SplineCp = list_SplineCp.at(i);
        delete p_SplineCp;
    }
    list_SplineCp.clear();*/

    for(i=0; i<meas.size(); i++) delete meas[i];
    meas.clear();   												// clear measure

    Plate_Tests.clear();                                            // clear Plate_Tests
    /*Criterion_Test *criterion;
    for(i=0; i<Criterion.size(); i++)
    {
        criterion = (Criterion_Test*)Criterion.at(i);
        delete criterion;
    }
    Criterion.clear();*/

    for(i=0; i<preference_Pro.size(); i++) delete preference_Pro[i];// clear preference_Pro
    preference_Pro.clear();

    for(i=0; i<tests.size(); i++) delete tests[i];
    tests.clear();   												// clear tests

    for(i=0; i<Plate.groups.size(); i++) delete Plate.groups[i];
    Plate.groups.clear();                                           // clear Plate

    PrAmpl_value.clear();
    PrAmpl_time.clear();
    PrAmpl_color.clear();
    PrAmpl_name = "";
    PrAmpl_countLevelsCycles.clear();
    PrAmpl_timesInBlocks.clear();
    PrAmpl_minimumLevel = 0;

    hash_protocol = "";
    validity_hash = false;

    for(i=0; i<Map_Reserve.size(); i++)
    {
        QVector<QString> *vec = Map_Reserve.values().at(i);
        vec->clear();
        delete vec;
    }
    Map_Reserve.clear();
}
//-----------------------------------------------------------------------------
//--- Read_XML
//-----------------------------------------------------------------------------
int Read_XML(rt_Protocol *prot, QString fn, bool only_config)
{
    int i,j,k;
    int res = 0;
    QString text;
    QStringList list;
    bool ok;
    QColor color;
    int key;

    int row=0,col=0;

    prot->Clear_Protocol();

    //qDebug() << "file name: " << fn;

    QFile file(fn);
    QDomDocument    doc;
    QDomElement     root;
    QDomNode        child;
    QDomNode        node;
    QDomNode        item;

    rt_Test         *test;
    rt_GroupSamples *group;
    rt_Measurement  *measure;
    rt_Preference   *preference;

    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(!doc.setContent(&file))
        {
            file.close();
            return(false);
        }
        file.close();

        root = doc.documentElement();

        //---
        col = root.firstChildElement("xsize").text().toInt();
        row = root.firstChildElement("ysize").text().toInt();
        prot->count_Tubes = col*row;

        prot->color_tube.clear();
        prot->enable_tube.clear();
        color = QColor(Qt::gray);
        key = color.rgb();
        for(i=0; i<prot->count_Tubes; i++)
        {
            prot->color_tube.append(key);
            prot->enable_tube.append(0);
        }

        //---

        for(i=0; i<root.childNodes().size(); i++)
        {
            child = root.childNodes().at(i);

            //--- Header ------------------------------------------------------
            if(child.nodeName() == "name") {prot->name = child.toElement().text(); continue;}
            if(child.nodeName() == "barcode") {prot->barcode = child.toElement().text(); continue;}
            if(child.nodeName() == "regNumber") {prot->regNumber = child.toElement().text(); continue;}
            if(child.nodeName() == "nameOperator") {prot->owned_by = child.toElement().text(); continue;}
            if(child.nodeName() == "created") {prot->time_created = child.toElement().text(); continue;}
            if(child.nodeName() == "status")
            {
                text = child.toElement().text().trimmed();
                prot->state = mNotExist;
                if(text == "wait")              prot->state = mWait;
                if(text == "drop")              prot->state = mDrop;
                if(text == "run")               prot->state = mRun;
                if(text == "measurements")      prot->state = mData;
                if(text == "analysis")          prot->state = mAnalysis;
                if(text == "reanalysis")        prot->state = mReAnalysis;
                continue;
            }
            if(child.nodeName() == "activeChannels") {prot->active_Channels = child.toElement().text().toInt(&ok,16); continue;}
            //if(child.nodeName() == "xsize") {col = child.toElement().text().toInt(&ok); continue;}
            //if(child.nodeName() == "ysize") {row = child.toElement().text().toInt(&ok); continue;}

            //--- Program of Amplification ------------------------------------
            if(child.nodeName() == "amProgramm")
            {
                text = child.toElement().text();
                list = text.split("\r\n");
                for(j=0; j<list.size(); j++) prot->program.append(list.at(j));
                Parsing_ProgramAmplification(prot);
                continue;
            }

            //--- Properties of Protocol --------------------------------------
            if(child.nodeName() == "properties")
            {
                for(j=0; j<child.childNodes().size(); j++)
                {
                    node = child.childNodes().at(j);
                    preference = new rt_Preference;
                    prot->preference_Pro.append(preference);
                    LoadXML_Preference(node, preference);
                }
                continue;
            }

            //--- Information about TESTs: ------------------------------------
            if(child.nodeName() == "tests")
            {
                for(j=0; j<child.childNodes().size(); j++)
                {
                    node = child.childNodes().at(j);
                    test = new rt_Test();
                    prot->tests.append(test);
                    LoadXML_Test(node, test);
                }
                continue;
            }

            //--- sourceSet ---------------------------------------------------
            if(child.nodeName() == "sourceSet")
            {
                for(j=0; j<child.childNodes().size(); j++)
                {
                    node = child.childNodes().at(j);
                    group = new rt_GroupSamples();
                    prot->Plate.groups.append(group);
                    LoadXML_Group(node, group, prot);
                }
                continue;
            }

            //--- device parameters -------------------------------------------
            if(child.nodeName() == "device" && !only_config)
            {
                for(j=0; j<child.childNodes().size(); j++)
                {
                    item = child.childNodes().at(j);

                    if(item.nodeName() == "SerialName") {prot->SerialName = item.toElement().text(); continue;}
                    if(item.nodeName() == "uC_Versions") {prot->uC_Versions = item.toElement().text(); continue;}
                    if(item.nodeName() == "Type_ThermoBlock") {prot->Type_ThermoBlock = item.toElement().text(); continue;}
                    if(child.nodeName() == "FluorDevice_MASK") {prot->FluorDevice_MASK = child.toElement().text().toInt(&ok,16); continue;}
                    if(item.nodeName() == "Optical_MASK") {prot->DeviceParameters = item.toElement().text(); continue;}

                    //... Coeff_Spectral ...
                    if(item.nodeName() == "Coeff_Spectral")
                    {
                        prot->COEFF_Spectral.clear();

                        for(k=0; k<item.childNodes().size(); k++)
                        {
                            node = item.childNodes().at(k);
                            text = node.toElement().text();
                            prot->COEFF_Spectral.append(text);
                        }
                        continue;
                    }

                    //... Coeff_UnequalCh ...
                    if(item.nodeName() == "Coeff_UnequalCh")
                    {
                        prot->COEFF_UnequalCh.clear();

                        for(k=0; k<item.childNodes().size(); k++)
                        {
                            node = item.childNodes().at(k);
                            text = node.toElement().text();
                            prot->COEFF_UnequalCh.append(text);
                        }
                        continue;
                    }

                    //... Coeff_Optic ...
                    if(item.nodeName() == "Coeff_Optic")
                    {
                        prot->COEFF_Optic.clear();

                        for(k=0; k<item.childNodes().size(); k++)
                        {
                            node = item.childNodes().at(k);
                            text = node.toElement().text();
                            prot->COEFF_Optic.append(text);
                        }
                        continue;
                    }

                }
                continue;
            }

            //--- measurements ------------------------------------------------
            if(child.nodeName() == "measurements" && !only_config)
            {
                for(j=0; j<child.childNodes().size(); j++)
                {
                    node = child.childNodes().at(j);
                    measure = new rt_Measurement();
                    prot->meas.append(measure);
                    LoadXML_Measure(node,measure);
                }
                continue;
            }
        }


        return(true);
    }
    else return(false);


}
//-----------------------------------------------------------------------------
//--- Load XML Group
//-----------------------------------------------------------------------------
void LoadXML_Group(QDomNode &node, rt_GroupSamples *group, rt_Protocol *prot)
{
    int i,j;
    bool ok;
    QString text;

    rt_Sample       *sample;

    QDomNode        child;
    QDomNode        item;

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);

        if(child.nodeName() == "IDGroup")
        {
            text = child.toElement().text().trimmed();
            if(text.isEmpty()) {Sleep(5); text = GetRandomString(5);}
            group->ID_Group = text;
            continue;
        }
        if(child.nodeName() == "name") {group->Unique_NameGroup = child.toElement().text(); continue;}
        if(child.nodeName() == "samples")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                item = child.childNodes().at(j);
                sample = new rt_Sample();
                group->samples.append(sample);
                LoadXML_Sample(item,sample,prot);
            }
            continue;
        }
    }
}

//-----------------------------------------------------------------------------
//--- Load XML Sample
//-----------------------------------------------------------------------------
void LoadXML_Sample(QDomNode &node, rt_Sample *sample, rt_Protocol *prot)
{
    int i,j,k;
    bool ok;
    QString id_test;

    rt_Tube         *tube;
    rt_Test         *test;
    rt_Preference   *preference;

    QDomNode        child;
    QDomNode        item;
    QDomNode        item_preference;

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);

        if(child.nodeName() == "IDSample") {sample->ID_Sample = child.toElement().text(); continue;}
        if(child.nodeName() == "IDTest") {sample->ID_Test = child.toElement().text(); continue;}
        if(child.nodeName() == "name") {sample->Unique_NameSample = child.toElement().text(); continue;}
        if(child.nodeName() == "properties")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                item = child.childNodes().at(j);
                preference = new rt_Preference();
                sample->preference_Sample.append(preference);
                for(k=0; k<item.childNodes().size(); k++)
                {
                    item_preference = item.childNodes().at(k);
                    if(item_preference.nodeName() == "name") {preference->name = item_preference.toElement().text(); continue;}
                    if(item_preference.nodeName() == "value") {preference->value = item_preference.toElement().text(); continue;}
                    if(item_preference.nodeName() == "unit") {preference->unit = item_preference.toElement().text(); continue;}
                }
            }
        }
        if(child.nodeName() == "tubes")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                item = child.childNodes().at(j);
                tube = new rt_Tube();
                sample->tubes.append(tube);
                LoadXML_Tube(item,tube,prot);
            }
            continue;
        }
    }

    id_test = sample->ID_Test;
    for(i=0; i<prot->tests.size(); i++)
    {
        test = prot->tests.at(i);
        if(id_test == test->header.ID_Test)
        {
            sample->p_Test = test;
            break;
        }
    }
}

//-----------------------------------------------------------------------------
//--- Load XML Tube
//-----------------------------------------------------------------------------
void LoadXML_Tube(QDomNode &node, rt_Tube *tube, rt_Protocol *prot)
{
    int i,j;
    bool ok;
    int r,g,b,key;
    QColor color;

    rt_Channel      *channel;

    QDomNode        child;
    QDomNode        item;

    int pos = node.firstChildElement("pos").toElement().text().toInt();
    color = node.firstChildElement("color").toElement().text().toInt(&ok,16);
    color.getRgb(&r,&g,&b);
    key = QColor(b,g,r).rgb() & 0xffffff;
    tube->pos = pos;
    if(pos >= 0) prot->enable_tube.replace(pos, 1);
    if(pos >= 0) prot->color_tube.replace(pos, key);
    tube->color = key;

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);

        if(child.nodeName() == "IDTube") {tube->ID_Tube = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "name") {tube->Unique_NameTube = child.toElement().text(); continue;}
        //if(child.nodeName() == "pos") {tube->pos = child.toElement().text().toInt(&ok); continue;}
        //if(child.nodeName() == "color") {tube->color = child.toElement().text().toInt(&ok,16); continue;}
        if(child.nodeName() == "channels")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                item = child.childNodes().at(j);
                channel = new rt_Channel();
                tube->channels.append(channel);
                LoadXML_Channel(item,channel,prot);
            }
            continue;
        }
     }
}

//-----------------------------------------------------------------------------
//--- Load XML Channel
//-----------------------------------------------------------------------------
void LoadXML_Channel(QDomNode &node, rt_Channel *channel, rt_Protocol *prot)
{
    int i,j;
    bool ok;

    QDomNode        child;
    QDomNode        item;
    rt_Preference   *preference;

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);

        if(child.nodeName() == "IDChannel") {channel->ID_Channel = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "properties")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                item = child.childNodes().at(j);
                preference = new rt_Preference;
                channel->preference_Channel.append(preference);
                LoadXML_Preference(item, preference);
            }
            continue;
        }
    }
}
//-----------------------------------------------------------------------------
//--- Parsing_ProgramAmplification
//-----------------------------------------------------------------------------
void Parsing_ProgramAmplification(rt_Protocol *prot)
{
    int i,j,k,m;
    QString text;
    QStringList fields;
    int count_PCR = 0;
    int count_MC = 0;
    QVector<int> vec_state;
    QVector<QPointF> vec_level;
    QPointF point;
    double time,value;
    int count_LC;
    QString time_levels = "";

    prot->dT_mc = 0.;
    prot->T_initial = 0.;

    prot->PrAmpl_value.clear();
    prot->PrAmpl_time.clear();
    prot->PrAmpl_color.clear();
    prot->PrAmpl_name = "";
    prot->PrAmpl_countLevelsCycles.clear();
    prot->PrAmpl_timesInBlocks.clear();
    prot->PrAmpl_minimumLevel = 100;

    enum {null,pcr,mc,hold}state;
    int state_block;

    QVector<QString> prog = prot->program;

    state = null;
    state_block = 0;
    for(i=0; i<prog.size(); i++)
    {
        text = prog.at(i);
        fields = text.trimmed().split(QRegExp("\\s+"));
        if(fields.at(0) == "XLEV")
        {
            k = fields.at(6).toInt();
            switch(k)
            {
            case 1: state = pcr;    break;
            case 2: state = mc;
                    if(prot->T_initial == 0.)
                    {
                        prot->T_initial = fields.at(1).toDouble()/100.;
                        prot->dT_mc = fields.at(3).toDouble()/100.;
                    }
                    break;
            default:
                    state = null;   break;
            }

            state_block |= state;
            vec_state.append((int)state);

            value = (double)(fields.at(1).toInt())/100.;
            time = fields.at(2).toInt();
            point.setX(value);
            point.setY(time);
            vec_level.append(point);

            if(k == 1 || k == 2)
            {
                if(time < prot->PrAmpl_minimumLevel) prot->PrAmpl_minimumLevel = time;
            }

            if(!time_levels.isEmpty()) time_levels += " ";
            time_levels += QString::number((int)point.y());
        }
        if(fields.at(0) == "XCYC")
        {
            k = fields.at(1).toInt();
            switch(state_block)
            {
            case 1:     count_PCR += k;   break;        // pcr
            case 2:     count_MC  += k;   break;        // mc
            default:                      break;
            }

            for(j=0; j<k; j++)
            {
                for(m=0; m<vec_level.size(); m++)
                {
                    value = vec_level.at(m).x();
                    if(state == mc) value = prot->dT_mc*j + value;
                    prot->PrAmpl_value.append(value);
                    prot->PrAmpl_time.append(vec_level.at(m).y());
                    prot->PrAmpl_color.append(vec_state.at(m));
                }
            }

            count_LC = (short)k | ((short)vec_level.size()) << 16;
            prot->PrAmpl_countLevelsCycles.append(count_LC);
            prot->PrAmpl_timesInBlocks.append(time_levels);
            time_levels = "";

            vec_level.clear();
            vec_state.clear();
            state = null;
            state_block = 0;
        }
        if(fields.at(0) == "XHLD")
        {
            if(vec_level.size() == 1)
            {
                prot->PrAmpl_value.append(vec_level.at(0).x());
                prot->PrAmpl_time.append(100);
                prot->PrAmpl_color.append(3);
                prot->PrAmpl_countLevelsCycles.append(0x10001);
                prot->PrAmpl_timesInBlocks.append("100");
            }
            vec_level.clear();
            vec_state.clear();
        }
        if(fields.at(0) == "XSAV" && fields.size() > 1)
        {
            text = fields.at(1);
            prot->PrAmpl_name = text.trimmed();
        }
    }
    prot->count_PCR = count_PCR;
    prot->count_MC = count_MC;

    //qDebug() << "count_PCR_MC = " << count_PCR << count_MC;
}
//-----------------------------------------------------------------------------
//--- Load XML Preference
//-----------------------------------------------------------------------------
void LoadXML_Preference(QDomNode &node, rt_Preference *preference)
{
    int i;
    QDomNode child;

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);
        if(child.nodeName() == "name") {preference->name = child.toElement().text(); continue;}
        if(child.nodeName() == "value") {preference->value = child.toElement().text(); continue;}
        if(child.nodeName() == "unit") {preference->unit = child.toElement().text(); continue;}
    }
}
//-----------------------------------------------------------------------------
//--- Load XML Test
//-----------------------------------------------------------------------------
void LoadXML_Test(QDomNode &node, rt_Test *ptest)
{
    int i,j,k,m,n;
    bool ok;
    QString text;
    QStringList list;
    QByteArray ba;
    quint16 crc16;
    QColor color;
    int r,g,b,key;
    int id = 0x20000;

    QString Name,Value;
    bool new_property;

    QDomNode        child;
    QDomNode        item;
    QDomNode        tube_node;
    QDomNode        ch_item;
    QDomNode        ch_node;
    QDomNode        properties;
    QDomNode        properties_item;
    QDomElement     color_element;

    rt_TubeTest     *tube;
    rt_ChannelTest  *channel;
    rt_Preference   *preference_test;
    rt_Preference   *preference;

    QString text_xml;
    QTextStream stream(&text_xml);

    if(node.isElement())        // save test as text(QString) in preference: name = xml_node  value = text
    {
        //text_xml = node.toElement().toText();
        node.save(stream, QDomNode::CDATASectionNode);

        for(i=0; i<ptest->preference_Test.size(); i++)  // Delete previous preference with name == "xml_node"
        {
            preference_test = ptest->preference_Test.at(i);
            if(preference_test->name == "xml_node")
            {
                delete preference_test;
                ptest->preference_Test.erase(ptest->preference_Test.begin() + i);
                break;
            }
        }
        preference_test = new rt_Preference;
        preference_test->name = "xml_node";
        preference_test->value = text_xml;
        ptest->preference_Test.append(preference_test);
    }

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);

        if(child.nodeName() == "IDTest") {ptest->header.ID_Test = child.toElement().text(); continue;}
        if(child.nodeName() == "nameTest") {ptest->header.Name_Test = child.toElement().text(); continue;}
        if(child.nodeName() == "method") {ptest->header.Type_analysis = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "activeChannels") {ptest->header.Active_channel = child.toElement().text().toInt(&ok,16); continue;}
        if(child.nodeName() == "comment") {ptest->header.comment = child.toElement().text(); continue;}
        if(child.nodeName() == "volumeTube") {ptest->header.Volume_Tube = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "amProgramm")
        {
            ptest->header.program.clear();
            text = child.toElement().text();
            list = text.split("\r\n");
            for(j=0; j<list.size(); j++)
            {
                text = list.at(j);
                ptest->header.program.append(text);
            }
            continue;
        }
        if(child.nodeName() == "properties")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                properties_item = child.childNodes().at(j);
                Name = properties_item.firstChildElement("name").toElement().text();
                Value = properties_item.firstChildElement("value").toElement().text();
                if(Name == "xml_node") continue;
                new_property = false;
                for(k=0; k<ptest->preference_Test.size(); k++)
                {
                    preference_test = ptest->preference_Test.at(k);
                    if(preference_test->name == Name)
                    {
                        preference_test->value = Value;
                        new_property = true;
                        break;
                    }
                }
                if(new_property) continue;

                preference_test = new rt_Preference;
                ptest->preference_Test.append(preference_test);

                preference_test->name = Name;
                preference_test->value = Value;
            }
            continue;
        }
        if(child.nodeName() == "templates")
        {
            // clear all tubes in templates of the test
            for(j=0; j<ptest->tubes.size(); j++) delete ptest->tubes.at(j);
            ptest->tubes.clear();
            // ...

            for(j=0; j<child.childNodes().size(); j++)
            {
                tube = new rt_TubeTest();
                ptest->tubes.append(tube);
                item = child.childNodes().at(j);

                for(k=0; k<item.childNodes().size(); k++)
                {
                    tube_node = item.childNodes().at(k);
                    if(tube_node.nodeName() == "IDTube") {tube->ID_Tube = tube_node.toElement().text().toInt(&ok); continue;}
                    if(tube_node.nodeName() == "color")
                    {
                        text = tube_node.toElement().text();
                        text.remove("$");
                        color = text.toInt(&ok,16);
                        color.getRgb(&r,&g,&b);
                        tube->color = QColor(b,g,r).rgb() & 0xffffff;
                        continue;
                    }

                    if(tube_node.nodeName() == "channels")
                    {
                        for(m=0; m<tube_node.childNodes().size(); m++)
                        {
                            channel = new rt_ChannelTest();
                            tube->channels.append(channel);
                            ch_node = tube_node.childNodes().at(m);
                            channel->ID_Channel = ch_node.firstChildElement("IDChannel").toElement().text().toInt(&ok);
                            channel->name = ch_node.firstChildElement("name").toElement().text();

                            properties = ch_node.firstChildElement("properties");
                            if(!properties.isNull())
                            {
                                for(n=0; n<properties.childNodes().size(); n++)
                                {
                                    preference = new rt_Preference();
                                    channel->preference_ChannelTest.append(preference);
                                    properties_item = properties.childNodes().at(n);
                                    preference->name = properties_item.firstChildElement("name").toElement().text();
                                    preference->value = properties_item.firstChildElement("value").toElement().text();
                                }
                            }
                        }
                    }
                }
            }
            continue;
        }
        if(child.nodeName() == "DTReport")
        {
            for(j=0; j<child.childNodes().size(); j++)
            {
                item = child.childNodes().at(j);
                if(item.nodeName() == "FormID")
                {
                    text = " \r\nDTReport = " + item.toElement().text();
                    ptest->header.comment += text;

                    text = item.toElement().text();
                    ba.clear();
                    ba.append(text.toLatin1());
                    crc16 = qChecksum(ba.data(),ba.size());
                    ptest->header.Type_analysis = id + crc16;
                    break;
                }
            }
        }

    }
}

//-----------------------------------------------------------------------------
//--- Load XML Measure
//-----------------------------------------------------------------------------
void LoadXML_Measure(QDomNode &node, rt_Measurement *measure)
{
    int i,j;
    bool ok;
    QString text;
    QStringList list;

    QDomNode        child;
    QDomNode        item;

    for(i=0; i<node.childNodes().size(); i++)
    {
        child = node.childNodes().at(i);

        if(child.nodeName() == "fn") {measure->fn = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "type_meas") {measure->type_meas = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "block_number") {measure->block_number = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "cycle_rep") {measure->cycle_rep = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "optical_channel") {measure->optical_channel = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "exp_number") {measure->num_exp = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "blk_exp") {measure->blk_exp = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "ovf_exp") {continue;}
        if(child.nodeName() == "expVal") {measure->exp_value = child.toElement().text().toInt(&ok); continue;}
        if(child.nodeName() == "data")
        {
            text = child.toElement().text().trimmed();
            list = text.split(" ");
            for(j=0; j<list.size(); j++)
            {
                measure->measurements.append(list.at(j).toInt(&ok));
            }
        }         
    }

}
//-----------------------------------------------------------------------------
//--- Sleep(int ms)
//-----------------------------------------------------------------------------
void Sleep(int ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, SLOT(quit()));
    loop.exec();
}
//-----------------------------------------------------------------------------
//--- GetRandomString(int count_symbol)
//-----------------------------------------------------------------------------
QString GetRandomString(int count_symbol)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = count_symbol; //12; // assuming you want random strings of 12 characters
    int index;
    QTime time = QTime::currentTime();
    //qsrand((uint)time.msec());
    qsrand((uint)time.msecsSinceStartOfDay());

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    return(randomString);
}
//-----------------------------------------------------------------------------
//--- Convert_IndexToName(int pos, int col)
//-----------------------------------------------------------------------------
QString Convert_IndexToName(int pos, int col)
{
    QString text;

    text = QChar(0x41 + div(pos,col).quot);
    text += QString::number(div(pos,col).rem + 1);

    return(text);
}
//-----------------------------------------------------------------------------
//--- Convert_NameToIndex(QString name, int col)
//-----------------------------------------------------------------------------
int Convert_NameToIndex(QString name, int col)
{
    QChar a = name.at(0);
    int ascii = a.toLatin1();
    QString text = name.mid(1);
    int num = text.toInt();
    int pos = 0;

    if(ascii < 0x41 || ascii > 0x41+16) return(0);

    pos = num + (ascii-0x41)*col - 1;

    return(pos);
}
//-----------------------------------------------------------------------------
//--- FindNameByTest
//-----------------------------------------------------------------------------
QString FindNameByTest(rt_Test *ptest, int id_tube, int id_channel)
{
    int i,j;
    QString res = "";
    QString fluor_name[COUNT_CH] = FLUOR_NAME;

    rt_TubeTest     *tube_test;
    rt_ChannelTest  *channel_test;

    for(i=0; i<ptest->tubes.size(); i++)
    {
        tube_test = ptest->tubes.at(i);
        if(tube_test->ID_Tube == id_tube)
        {
            for(j=0; j<tube_test->channels.size(); j++)
            {
                channel_test = tube_test->channels.at(j);
                if(channel_test->ID_Channel == id_channel)
                {
                    res = channel_test->name;
                    return(res);
                }
            }
        }
    }
    if(res.trimmed() == "" && id_channel < COUNT_CH) res = fluor_name[id_channel];
    return(res);
}
//-----------------------------------------------------------------------------
//--- MakeElement
//-----------------------------------------------------------------------------
QDomElement MakeElement(QDomDocument &doc, QString name, QString text)
{
    QDomElement domElement = doc.createElement(name);
    if (!text.isEmpty())
    {
        QDomText domText = doc.createTextNode(text);
        domElement.appendChild(domText);
    }
    return(domElement);
}
//-----------------------------------------------------------------------------
//--- MakeElementResults
//-----------------------------------------------------------------------------
QDomElement MakeElementResults(QDomDocument &doc, QString name, QVector<QString> *vec)
{
    int i;
    QString     text;
    QStringList list;

    QDomElement domElement = doc.createElement(name);

    for(i=0; i<vec->size(); i++)
    {
        text = vec->at(i);
        if(text.isEmpty()) continue;
        list = text.split("=");

        QDomElement item = doc.createElement("item");
        if(list.count() < 2)
        {
            item.appendChild(MakeElement(doc,"value",text));
        }
        else
        {
            item.appendChild(MakeElement(doc,"name",list.at(0)));
            item.appendChild(MakeElement(doc,"value",list.at(1)));
        }
        domElement.appendChild(item);
    }

    return(domElement);
}
//-----------------------------------------------------------------------------
//--- SaveXML_Test
//-----------------------------------------------------------------------------
QDomElement SaveXML_Test(QDomDocument &doc, rt_Test *ptest)
{
    int i,j,k;
    int active_ch;
    bool ok;
    int r,g,b,key;
    QColor color;

    QString text, str;
    QDomElement res;
    QDomElement DTReport;
    QDomDocument doc_temp;

    rt_Preference   *preference;
    rt_TubeTest     *ptube;
    rt_ChannelTest  *pchannel;

    res = doc.createElement("item");

    //.........................................................................
    if(ptest->preference_Test.size())
    {
       for(i=0; i<ptest->preference_Test.size(); i++)
       {
            preference = ptest->preference_Test.at(i);
            if(preference->name == "xml_node")
            {
                text = preference->value;
                if(!text.isEmpty())
                {
                    doc_temp.setContent(text);
                    res = doc_temp.firstChild().toElement();
                    return(res);
                }
            }
       }
    }
    //.........................................................................

    //--- Header ---
    //res.appendChild(MakeElement(doc,"IDTest",QString::number(ptest->header.ID_Test)));
    res.appendChild(MakeElement(doc,"IDTest", ptest->header.ID_Test));
    res.appendChild(MakeElement(doc,"nameTest", ptest->header.Name_Test));
    res.appendChild(MakeElement(doc,"method", QString::number(ptest->header.Type_analysis)));
    res.appendChild(MakeElement(doc,"volumeTube", QString::number(ptest->header.Volume_Tube)));
    res.appendChild(MakeElement(doc,"activeChannels", QString::number(ptest->header.Active_channel,16)));
    res.appendChild(MakeElement(doc,"comment", ptest->header.comment));
    //--- Programm ---
    text = "";
    QVector<QString> prog = ptest->header.program;
    for(i=0; i<prog.size(); i++)
    {
        str = prog.at(i).trimmed();
        if(str.isEmpty()) continue;
        if(!text.isEmpty()) text += "\r\n";
        text += str;
    }
    res.appendChild(MakeElement(doc, "amProgramm" , text));

    //--- Property of Test ---
    QDomElement property = MakeElement(doc,"properties","");
    for(i=0; i<ptest->preference_Test.size(); i++)
    {
        preference = ptest->preference_Test.at(i);
        if(preference->name.trimmed() == "FormID")
        {
            DTReport = MakeElement(doc,"DTReport","");
            DTReport.appendChild(MakeElement(doc,"FormID",preference->value));
            res.appendChild(DTReport);
            continue;
        }
        if(preference->name.trimmed() == "ReportSettings")
        {
            QDomElement ReportSettings = MakeElement(doc,"ReportSettings","");
            ReportSettings.appendChild(MakeElement(doc,"value",preference->value));
            DTReport.appendChild(ReportSettings);
            continue;
        }

        QDomElement item = MakeElement(doc,"item","");
        item.appendChild(MakeElement(doc,"name",preference->name));
        item.appendChild(MakeElement(doc,"value",preference->value));
        item.appendChild(MakeElement(doc,"unit",preference->unit));
        property.appendChild(item);

        //qDebug() << "Properties Name: " <<  preference->name;
    }
    res.appendChild(property);

    //--- Channels ---
    QDomElement channels = MakeElement(doc,"channels","");
    active_ch = ptest->header.Active_channel;
    for(i=0; i<COUNT_CH; i++)
    {
        if(active_ch & (1<<i*4))
        {
            QDomElement item_TestCh = MakeElement(doc,"item","");
            item_TestCh.appendChild(MakeElement(doc,"IDChannel", QString("%1").arg(i)));
            item_TestCh.appendChild(MakeElement(doc,"number", QString("%1").arg(i)));
            item_TestCh.appendChild(MakeElement(doc,"ffor", QString("%1").arg(i)));
            channels.appendChild(item_TestCh);
        }
    }
    res.appendChild(channels);

    //--- Template ---
    QDomElement templates = MakeElement(doc,"templates","");
    for(i=0; i<ptest->tubes.size(); i++)
    {
        QDomElement item = MakeElement(doc,"item","");
        ptube = ptest->tubes.at(i);
        item.appendChild(MakeElement(doc,"IDTube", QString::number(i)));
        item.appendChild(MakeElement(doc,"name", ptube->name));
        // color
        color = ptube->color;
        color.getRgb(&r,&g,&b);
        key = QColor(b,g,r).rgb() & 0xffffff;
        item.appendChild(MakeElement(doc,"color", QString::number(key,16)));
        //

        QDomElement property = MakeElement(doc,"properties","");
        for(j=0; j<ptube->preference_TubeTest.size(); j++)
        {
            preference = ptube->preference_TubeTest.at(j);
            QDomElement item_tp = MakeElement(doc,"item","");
            item_tp.appendChild(MakeElement(doc,"name", preference->name));
            item_tp.appendChild(MakeElement(doc,"value", preference->value));
            item_tp.appendChild(MakeElement(doc,"unit", preference->unit));
            property.appendChild(item_tp);
        }

        item.appendChild(property);

        QDomElement channels = MakeElement(doc,"channels","");
        for(j=0; j<ptube->channels.size(); j++)
        {
            QDomElement item_ch = MakeElement(doc,"item","");
            pchannel = ptube->channels.at(j);
            item_ch.appendChild(MakeElement(doc,"IDChannel", QString::number(pchannel->ID_Channel)));
            item_ch.appendChild(MakeElement(doc,"name", pchannel->name));

            QDomElement property = MakeElement(doc,"properties","");
            for(k=0; k<pchannel->preference_ChannelTest.size(); k++)
            {
                preference = pchannel->preference_ChannelTest.at(k);
                QDomElement item_chp = MakeElement(doc,"item","");
                item_chp.appendChild(MakeElement(doc,"name",preference->name));
                item_chp.appendChild(MakeElement(doc,"value",preference->value));
                item_chp.appendChild(MakeElement(doc,"unit",preference->unit));
                property.appendChild(item_chp);
            }

            item_ch.appendChild(property);

            channels.appendChild(item_ch);
        }
        item.appendChild(channels);

        templates.appendChild(item);
    }

    res.appendChild(templates);


    return(res);
}
//-----------------------------------------------------------------------------
//--- SaveXML_SourceSet
//-----------------------------------------------------------------------------
QDomElement SaveXML_SourceSet(QDomDocument &doc, rt_GroupSamples *pgroup, rt_Protocol *prot)
{
    int i;
    QString text;

    rt_Preference   *preference;
    rt_Sample       *psample;

    QDomElement res;
    res = doc.createElement("item");

    text = pgroup->ID_Group;
    if(text.isEmpty()) {Sleep(5); text = GetRandomString(10);}
    res.appendChild(MakeElement(doc, "IDGroup", text));
    res.appendChild(MakeElement(doc, "name", pgroup->Unique_NameGroup));

    QDomElement property = MakeElement(doc,"properties","");
    for(i=0; i<pgroup->preference_Group.size(); i++)
    {
        QDomElement item = MakeElement(doc,"item","");
        preference = pgroup->preference_Group.at(i);
        item.appendChild(MakeElement(doc,"name",preference->name));
        item.appendChild(MakeElement(doc,"value",preference->value));
        item.appendChild(MakeElement(doc,"unit",preference->unit));
        property.appendChild(item);
    }
    res.appendChild(property);

    QDomElement samples = doc.createElement("samples");
    for(i=0; i<pgroup->samples.size(); i++)
    {
        psample = pgroup->samples.at(i);
        samples.appendChild(SaveXML_Sample(doc, psample, prot));
    }
    res.appendChild(samples);

    return(res);
}

//-----------------------------------------------------------------------------
//--- SaveXML_Sample
//-----------------------------------------------------------------------------
QDomElement SaveXML_Sample(QDomDocument &doc, rt_Sample *psample, rt_Protocol *p)
{
    int i,j,k;
    rt_Tube         *ptube;
    rt_Channel      *pchannel;
    rt_Preference   *preference;
    int r,g,b,key;
    QColor color;
    int row,col;
    int x,y,pos;

    rt_GroupSamples *group;
    rt_Sample       *sample;

    //... pos_protocol ...
    int pos_protocol = 1;
    bool sts = false;
    foreach(group, p->Plate.groups)
    {
        foreach(sample, group->samples)
        {
            if(sample == psample)
            {
                sts = true;
                break;
            }
            pos_protocol += sample->tubes.size();
        }
        if(sts) break;
    }
    //....................

    int count_tubes = p->count_Tubes;
    p->Plate.PlateSize(count_tubes, row, col);

    QDomElement res = doc.createElement("item");

    res.appendChild(MakeElement(doc, "IDSample", psample->ID_Sample));
    res.appendChild(MakeElement(doc, "IDTest", psample->p_Test->header.ID_Test));
    res.appendChild(MakeElement(doc, "name", psample->Unique_NameSample));

    QDomElement property = MakeElement(doc,"properties","");
    for(i=0; i<psample->preference_Sample.size(); i++)
    {
        QDomElement item = MakeElement(doc,"item","");
        preference = psample->preference_Sample.at(i);
        item.appendChild(MakeElement(doc,"name",preference->name));
        item.appendChild(MakeElement(doc,"value",preference->value));
        item.appendChild(MakeElement(doc,"unit",preference->unit));
        property.appendChild(item);
    }
    res.appendChild(property);

    QDomElement tubes = doc.createElement("tubes");
    for(i=0; i<psample->tubes.size(); i++)
    {
        QDomElement item = doc.createElement("item");
        ptube = psample->tubes.at(i);

        item.appendChild(MakeElement(doc,"IDTube",QString::number(ptube->ID_Tube)));
        item.appendChild(MakeElement(doc,"name",ptube->Unique_NameTube));
        item.appendChild(MakeElement(doc,"pos",QString::number(ptube->pos)));

        pos = ptube->pos;
        x = div(pos,col).rem; // + 1;
        y = div(pos,col).quot; // + 1;
        item.appendChild(MakeElement(doc,"x",QString::number(x)));
        item.appendChild(MakeElement(doc,"y",QString::number(y)));

        item.appendChild(MakeElement(doc,"pos_protocol",QString::number(pos_protocol)));
        pos_protocol++;

        color = ptube->color;
        color.getRgb(&r,&g,&b);
        key = QColor(b,g,r).rgb() & 0xffffff;
        item.appendChild(MakeElement(doc,"color",QString::number(key,16)));

        QDomElement channels = doc.createElement("channels");
        for(j=0; j<ptube->channels.size(); j++)
        {
            pchannel = ptube->channels.at(j);
            QDomElement item_ch = doc.createElement("item");
            item_ch.appendChild(MakeElement(doc,"IDChannel",QString::number(pchannel->ID_Channel)));

            QDomElement property_channel = MakeElement(doc,"properties","");
            for(k=0; k<pchannel->preference_Channel.size(); k++)
            {
                QDomElement item_pro = MakeElement(doc,"item","");
                preference = pchannel->preference_Channel.at(k);
                item_pro.appendChild(MakeElement(doc,"name",preference->name));
                item_pro.appendChild(MakeElement(doc,"value",preference->value));
                item_pro.appendChild(MakeElement(doc,"unit",preference->unit));
                property_channel.appendChild(item_pro);
            }
            item_ch.appendChild(property_channel);

            channels.appendChild(item_ch);
        }
        item.appendChild(channels);

        tubes.appendChild(item);
    }

    res.appendChild(tubes);

    return(res);
}

//-----------------------------------------------------------------------------
//--- SaveXML_Device
//-----------------------------------------------------------------------------
QDomElement SaveXML_Device(QDomDocument &doc, rt_Protocol *p)
{
    int i;

    QDomElement res = doc.createElement("device");

    res.appendChild(MakeElement(doc, "SerialName", p->SerialName));
    res.appendChild(MakeElement(doc, "uC_Versions", p->uC_Versions));
    res.appendChild(MakeElement(doc, "Type_ThermoBlock", p->Type_ThermoBlock));
    res.appendChild(MakeElement(doc, "FluorDevice_MASK", QString::number(p->FluorDevice_MASK,16)));
    res.appendChild(MakeElement(doc, "Optical_MASK", p->DeviceParameters));

    //... Coeff_Spectral ...
    QDomElement coeff_Spectral = doc.createElement("Coeff_Spectral");
    res.appendChild(coeff_Spectral);
    for(i=0; i<p->COEFF_Spectral.size(); i++)
    {
        coeff_Spectral.appendChild(MakeElement(doc,"item",p->COEFF_Spectral.at(i)));
    }
    //... Coeff_UnequalCh ...
    QDomElement coeff_UnequalCh = doc.createElement("Coeff_UnequalCh");
    res.appendChild(coeff_UnequalCh);
    for(i=0; i<p->COEFF_UnequalCh.size(); i++)
    {
        coeff_UnequalCh.appendChild(MakeElement(doc,"item",p->COEFF_UnequalCh.at(i)));
    }
    //... Coeff_Optic ...
    QDomElement coeff_Optic = doc.createElement("Coeff_Optic");
    res.appendChild(coeff_Optic);
    for(i=0; i<p->COEFF_Optic.size(); i++)
    {
        coeff_Optic.appendChild(MakeElement(doc,"item",p->COEFF_Optic.at(i)));
    }


    return(res);
}
//-----------------------------------------------------------------------------
//--- SaveXML_Measurements
//-----------------------------------------------------------------------------
QDomElement SaveXML_Measurements(QDomDocument &doc, rt_Protocol *p)
{
    int i,j,k;
    QString fluor_name[COUNT_CH] = FLUOR_NAME;
    rt_Measurement  *measure;
    QString text;

    int col,row;
    p->Plate.PlateSize(p->count_Tubes, row, col);

    QDomElement res = doc.createElement("measurements");

    for(i=0; i<p->meas.size(); i++)
    {
        QDomElement item = doc.createElement("item");

        measure = p->meas.at(i);

        item.appendChild(MakeElement(doc,"channel",fluor_name[measure->optical_channel] + "_" +
                         QString::number(measure->num_exp)));
        item.appendChild(MakeElement(doc,"fn",QString::number(measure->fn)));
        item.appendChild(MakeElement(doc,"type_meas",QString::number(measure->type_meas)));
        item.appendChild(MakeElement(doc,"block_number",QString::number(measure->block_number)));
        item.appendChild(MakeElement(doc,"cycle_rep",QString::number(measure->cycle_rep)));
        item.appendChild(MakeElement(doc,"optical_channel",QString::number(measure->optical_channel)));
        item.appendChild(MakeElement(doc,"exp_number",QString::number(measure->num_exp)));
        item.appendChild(MakeElement(doc,"blk_exp",QString::number(measure->blk_exp)));
        item.appendChild(MakeElement(doc,"ovf_exp","0"));
        item.appendChild(MakeElement(doc,"expVal",QString::number((double)measure->exp_value,'f',0)));

        text = "\r\n";

        for(j=0; j<measure->measurements.size(); j++)
        {
            k = div(j,col).rem;
            if(!k && j) text += "\r\n";
            text += QString::number((ushort)measure->measurements.at(j)) + " ";
        }
        item.appendChild(MakeElement(doc,"data",text));

        QDomAttr fluor_attr = doc.createAttribute("channel");
        fluor_attr.setValue(fluor_name[measure->optical_channel] + "_" +
                            QString::number(measure->num_exp));

        QDomAttr fn_attr = doc.createAttribute("fn");
        fn_attr.setValue(QString::number(measure->fn));

        res.appendChild(item);
    }

    return(res);
}
//-----------------------------------------------------------------------------
//--- SaveXML_AnalysisVersion
//-----------------------------------------------------------------------------
QDomElement SaveXML_AnalysisVersion(QDomDocument &doc, rt_Protocol *prot)
{
    QDomElement res = doc.createElement("Analysis_Version");

    res.appendChild(MakeElement(doc, "version" , QCoreApplication::applicationVersion()));


    return(res);
}
//-----------------------------------------------------------------------------
//--- Save as XML
//-----------------------------------------------------------------------------
bool SaveAsXML(rt_Protocol *prot, QString fn,  bool only_config)
{
    int i,j,k;
    QDomDocument doc;
    QString text,str;
    int col,row;
    QString fluor_name[COUNT_CH] = FLUOR_NAME;
    bool res = false;


    rt_Test         *ptest;
    rt_GroupSamples *pgroup;
    rt_Measurement  *measure;
    rt_Preference   *preference;

    //if(Callback) Callback(pobj,0,"Save as XML...");
    //qDebug() << "Save as XML...";

    QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    QDomElement  root = doc.createElement("protocol");
    doc.appendChild(root);

    //--- Header ---
    //if(Callback) Callback(pobj,10,"Save as XML (Header)...");
    //qDebug() << "Save as XML  (Header)...";
    root.appendChild(MakeElement(doc, "name", prot->name));
    root.appendChild(MakeElement(doc, "barcode", prot->barcode));
    root.appendChild(MakeElement(doc, "regNumber", prot->regNumber));
    root.appendChild(MakeElement(doc, "nameOperator", prot->owned_by));
    root.appendChild(MakeElement(doc, "created", prot->time_created));
    //root.appendChild(MakeElement(doc, "status", "analysis"));
    switch(prot->state)
    {
    default:
    case mNotExist:     root.appendChild(MakeElement(doc, "status", "notexist"));       break;
    case mWait:         root.appendChild(MakeElement(doc, "status", "wait"));           break;
    case mDrop:         root.appendChild(MakeElement(doc, "status", "drop"));           break;
    case mRun:          root.appendChild(MakeElement(doc, "status", "run"));            break;
    case mData:         root.appendChild(MakeElement(doc, "status", "measurements"));   break;
    case mAnalysis:     root.appendChild(MakeElement(doc, "status", "analysis"));       break;
    case mReAnalysis:   root.appendChild(MakeElement(doc, "status", "reanalysis"));     break;
    }

    root.appendChild(MakeElement(doc, "activeChannels", QString::number(prot->active_Channels,16)));

    prot->Plate.PlateSize(prot->count_Tubes, row, col);
    root.appendChild(MakeElement(doc, "xsize", QString::number(col)));
    root.appendChild(MakeElement(doc, "ysize", QString::number(row)));

    root.appendChild(MakeElement(doc, "volumeTube", ""));

    //--- Programm ---
    //qDebug() << "Save as XML  (Programm)...";
    text = "";
    QVector<QString> prog = prot->program;
    for(i=0; i<prog.size(); i++)
    {
        str = prog.at(i).trimmed();
        if(str.isEmpty()) continue;
        if(!text.isEmpty()) text += "\r\n";
        text += str;
    }
    root.appendChild(MakeElement(doc, "amProgramm" , text));

    //--- Property ---
    //qDebug() << "Save as XML  (Property)...";
    QDomElement property = doc.createElement("properties");
    root.appendChild(property);
    for(i=0; i<prot->preference_Pro.size(); i++)
    {
        preference = prot->preference_Pro.at(i);
        QDomElement item_property = doc.createElement("item");
        item_property.appendChild(MakeElement(doc,"name",preference->name));
        item_property.appendChild(MakeElement(doc,"value",preference->value));
        item_property.appendChild(MakeElement(doc,"unit",preference->unit));
        property.appendChild(item_property);
    }

    //--- Tests ---
    //if(Callback) Callback(pobj,20,"Save as XML (tests)...");
    //qDebug() << "Save as XML  (tests)...";
    QDomElement tests = doc.createElement("tests");
    root.appendChild(tests);

    for(i=0; i<prot->tests.size(); i++)
    {
        ptest = prot->tests.at(i);
        tests.appendChild(SaveXML_Test(doc,ptest));
    }

    //--- sourceSets ---
    //if(Callback) Callback(pobj,30,"Save as XML (samples)...");
    //qDebug() << "Save as XML  (Samples)...";
    QDomElement  SampleSets = doc.createElement("sourceSet");
    root.appendChild(SampleSets);

    for(i=0; i<prot->Plate.groups.size(); i++)
    {
        pgroup = prot->Plate.groups.at(i);
        SampleSets.appendChild(SaveXML_SourceSet(doc, pgroup, prot));
    }

    //--- device parameters ---
    //... device ...
    if(!only_config)
    {
        QDomElement device = SaveXML_Device(doc, prot);
        root.appendChild(device);
    }


    //--- measurements ---
    if(!only_config)
    {
        //if(Callback) Callback(pobj,40,"Save as XML (measurements)...");
        QDomElement  measurements = SaveXML_Measurements(doc, prot);
        root.appendChild(measurements);
    }


    QFile file(fn);
    if(file.open(QIODevice::WriteOnly))
    {
        //qDebug() << "Save as XML  (file open)...";
        QTextStream(&file) << doc.toString();
        file.close();
        res = true;
        //qDebug() << "Save as XML  (file close)...";

        if(!only_config)
        {
            res = SaveResultsXML(prot, fn);
        }
    }
    //else qDebug() << "Save as XML  (file NOT open)...";


    //if(Callback) Callback(pobj,0,"");

    return(res);
}
//-----------------------------------------------------------------------------
//--- SaveResultsXML
//-----------------------------------------------------------------------------
bool SaveResultsXML(rt_Protocol *prot, QString fn, QString fn_out)
{
    int i,j,k,m;
    QDomDocument doc;
    QString text;
    int count;
    bool res = false;

    QDomElement     root;
    QDomElement     sourceSet;
    QDomElement     groups;
    QDomElement     samples;
    QDomNode        sample;
    QDomElement     tubes;
    QDomElement     channels;

    QDomElement     result;
    QDomElement     item;

    rt_GroupSamples *pgroup;
    rt_Sample       *psample;
    rt_Tube         *ptube;
    rt_Channel      *pchannel;

    QVector<QString> Y;

    //if(Callback) Callback(pobj,0,"Save Results XML...");

    QFile file(fn);
    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        if(doc.setContent(&file))
        {
            file.close();

            root = doc.documentElement();

            //--- Change Status ---
            item = root.firstChildElement("status");
            switch(prot->state)
            {
            default:
            case mAnalysis:     result = MakeElement(doc,"status","analysis");
                                break;

            case mReAnalysis:   result = MakeElement(doc,"status","reanalysis");
                                break;
            }
            if(item.isNull())
            {
                root.insertAfter(result, root.firstChildElement("regNumber"));
            }
            else    root.replaceChild(result,item);

            //--- SourceSet ---
            sourceSet = root.firstChildElement("sourceSet");
            count = sourceSet.childNodes().size();
            for(i=0; i<count; i++)
            {
                pgroup = prot->Plate.groups.at(i);
                samples = sourceSet.childNodes().at(i).firstChildElement("samples");
                if(samples.isNull()) continue;
                for(j=0; j<samples.childNodes().size(); j++)
                {
                    sample = samples.childNodes().at(j);
                    psample = pgroup->samples.at(j);
                    Y = psample->result_Sample;

                    result = MakeElementResults(doc,"sample_results",&Y);

                    item = sample.firstChildElement("sample_results");
                    if(item.isNull()) sample.appendChild(result);
                    else sample.replaceChild(result,item);

                    //sample.toElement().attribute("pp","balu");

                    tubes = samples.childNodes().at(j).firstChildElement("tubes");
                    if(tubes.isNull()) continue;
                    for(k=0; k<tubes.childNodes().size(); k++)
                    {
                        ptube = psample->tubes.at(k);
                        Y = ptube->result_Tube;
                        result = MakeElementResults(doc,"tube_results",&Y);

                        item = tubes.childNodes().at(k).firstChildElement("tube_results");
                        if(item.isNull()) tubes.childNodes().at(k).appendChild(result);
                        else tubes.childNodes().at(k).replaceChild(result,item);

                        channels = tubes.childNodes().at(k).firstChildElement("channels");
                        if(channels.isNull()) continue;
                        for(m=0; m<channels.childNodes().size(); m++)
                        {
                            pchannel = ptube->channels.at(m);
                            Y = pchannel->result_Channel;
                            result = MakeElementResults(doc,"channel_results",&Y);

                            item = channels.childNodes().at(m).firstChildElement("channel_results");
                            if(item.isNull()) channels.childNodes().at(m).appendChild(result);
                            else channels.childNodes().at(m).replaceChild(result,item);
                        }
                    }
                }

                //if(Callback) Callback(pobj,(i*100)/count,"Save Results XML...");
                QCoreApplication::processEvents();
            }

            //--- Analysis Curves ---
            /*
            item = root.firstChildElement("Analysis_Curves");
            result = SaveXML_AnalysisCurves(doc, prot);

            if(item.isNull()) root.appendChild(result);
            else root.replaceChild(result,item);

            //--- Analysis Data ---
            item = root.firstChildElement("Analysis_Data");
            result = doc.createElement("Analysis_Data");

            if(item.isNull()) root.appendChild(result);
            else root.replaceChild(result,item);
            */
            //--- Analysis Version ---
            item = root.firstChildElement("Analysis_Version");
            result = SaveXML_AnalysisVersion(doc, prot);

            if(item.isNull()) root.appendChild(result);
            else root.replaceChild(result,item);


            //if(Callback) Callback(pobj,100,"Save Results XML...");
            QCoreApplication::processEvents();

            //---
            if(fn_out.isEmpty()) fn_out = fn;
            QFile file_out(fn_out);
            if(file_out.open(QIODevice::WriteOnly))
            {
                QTextStream(&file_out) << doc.toString();
                file_out.close();
                res = true;
            }
        }
        else file.close();
    }

    //if(Callback) Callback(pobj,0,"");

    return(res);
}
