///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2024 Jon Beniston, M7RCE <jon@beniston.com>                     //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "coaststations.h"

// Map from MMSI to Coast Station Name
// From https://www.itu.int/mmsapp/coaststation/list
const QMap<QString, QString> CoastStations {
    {"003311000", "AASIAAT RADIO"},
    {"004224102", "ABADAN RADIO"},
    {"004224300", "ABBAS RADIO"},
    {"004225300", "ABBAS RADIO"},
    {"002320004", "ABERDEEN"},
    {"006191000", "ABIDJAN RADIO"},
    {"004225310", "ABOMUSA RADIO"},
    {"003451810", "ACAPULCO, GUERRERO RADIO"},
    {"004224311", "AFTAB RADIO"},
    {"006052110", "AIN TAYA RADIO"},
    {"005251558", "AIR BANGIS RADIO"},
    {"002711000", "AKCAKOCA RADIO"},
    {"002711000", "AKDAG RADIO"},
    {"004030000", "AL BIRK RADIO"},
    {"004030000", "AL LITH RADIO"},
    {"004030000", "AL QUNFUDHAH RADIO"},
    {"004030000", "AL WAJH RADIO"},
    {"006221111", "ALEXANDRIA RADIO"},
    {"006052110", "ALGER RADIO"},
    {"002470064", "ALNG SHORE BASE"},
    {"002470063", "ALNG TERMINAL"},
    {"005250006", "AMBOINA RADIO / PKE"},
    {"004225601", "AMIRABAD RADIO"},
    {"002713000", "ANAMUR RADIO"},
    {"002470119", "ANCONA RADIO"},
    {"007250240", "ANCUD RADIO"},
    {"006053814", "ANNABA RADIO"},
    {"002713000", "ANTALYA TURK RADIO"},
    {"007250050", "ANTOFAGASTA ZONAL RADIO"},
    {"002050485", "ANTWERPEN RADIO"},
    {"004224500", "ANZALI RADIO"},
    {"004225500", "ANZALI RADIO"},
    {"004381234", "AQABA COASTAL RADIO STATION/JYO - AQABA PORT CONTROL/JYP"},
    {"002633000", "ARGA"},
    {"007010111", "ARGENTINA RADIO"},
    {"007250010", "ARICA RADIO"},
    {"002734414", "ARKHANGELSK RADIO"},
    {"002241026", "ARRECIFE RADIO"},
    {"004224202", "ASALUYEH RADIO"},
    {"004225202", "ASALUYEH RADIO"},
    {"002391000", "ASPROPYRGOS ATTIKIS RADIO"},
    {"004224501", "ASTARA RADIO"},
    {"002731147", "ASTRAKHAN AMP"},
    {"002734419", "ASTRAKHAN RADIO MRCC"},
    {"002470120", "AUGUSTA RADIO"},
    {"002711000", "AYVALIK RADIO"},
    {"005743040", "BAC LIEU RADIO"},
    {"005741050", "BACH LONG VY RADIO"},
    {"007250370", "BAHIA FELIX RADIO"},
    {"007250450", "BAHIA FILDES RADIO"},
    {"007250470", "BAHIA PARAISO RADIO"},
    {"007354753", "BAHIA RADIO"},
    {"004224301", "BAHONAR RADIO"},
    {"004231000", "BAKU TRAFFIC CONTROL"},
    {"004233000", "BAKU TRAFFIC CONTROL"},
    {"004234000", "BAKU TRAFFIC CONTROL"},
    {"004235000", "BAKU TRAFFIC CONTROL"},
    {"004236000", "BAKU TRAFFIC CONTROL"},
    {"004237000", "BAKU TRAFFIC CONTROL"},
    {"004238000", "BAKU TRAFFIC CONTROL"},
    {"004239000", "BAKU TRAFFIC CONTROL"},
    {"004232000", "BAKU TRAFFIC CONTROL"},
    {"005250009", "BALIKPAPAN RADIO / PKN"},
    {"005250087", "BALIKPAPAN RADIO / PKN2"},
    {"002711000", "BANDIRMA RADIO"},
    {"005671000", "BANGKOK RADIO"},
    {"005251520", "BANJARMASIN RADIO / PKG"},
    {"002620001", "BAR RADIO"},
    {"002620002", "BAR RADIO"},
    {"002620003", "BAR RADIO"},
    {"002470121", "BARI RADIO"},
    {"004123600", "BASUO RADIO"},
    {"005250012", "BATU AMPAR RADIO"},
    {"005251526", "BAU-BAU RADIO"},
    {"004123400", "BEIHAI RADIO"},
    {"005250003", "BELAWAN RADIO / PKB"},
    {"002320021", "BELFAST"},
    {"005741070", "BEN THUY RADIO"},
    {"005250088", "BENETE RADIO"},
    {"005250034", "BENGKALIS RADIO"},
    {"005250062", "BENGKULU RADIO"},
    {"005250014", "BENOA RADIO / PKD5"},
    {"002723672", "BERDYANSK RADIO"},
    {"005250031", "BIAK RADIO / PKY2"},
    {"005251516", "BIMA RADIO"},
    {"005250026", "BINTUNI RADIO"},
    {"005250005", "BITUNG RADIO / PKM"},
    {"002713000", "BODRUM RADIO"},
    {"005250089", "BONTANG RADIO"},
    {"002470094", "BOSA"},
    {"002111240", "BREMEN RESCUE RADIO"},
    {"003621001", "BRIGAND HILL"},
    {"007010001", "BUENOS AIRES PREFECTURA NAVAL RADIO"},
    {"002731243", "BUKHTA SEVER KRASNOYARSK/BUKHTA-SEVER"},
    {"005330195", "BUKIT ANDRASY"},
    {"005330010", "BUKIT BAKAR"},
    {"005330009", "BUKIT BESAR"},
    {"005330189", "BUKIT KAYU MALAM"},
    {"005330185", "BUKIT KELAPA"},
    {"005330013", "BUKIT KERATONG"},
    {"005330186", "BUKIT LIMA"},
    {"005330012", "BUKIT NYABAU"},
    {"004402101", "BUSAN/SUHYUP"},
    {"004402107", "BUSAN/SUHYUP"},
    {"004402111", "BUSAN/SUHYUP"},
    {"004224200", "BUSHEHR RADIO"},
    {"004225200", "BUSHEHR RADIO"},
    {"005743070", "CA MAU RADIO"},
    {"002241024", "CABO DE GATA RADIO"},
    {"002241026", "CABO DE GATA RADIO"},
    {"002241024", "CABO LA NAO RADIO"},
    {"002470122", "CAGLIARI RADIO"},
    {"007250080", "CALDERA RADIO"},
    {"007600125", "CALLAO RADIO"},
    {"005742090", "CAM RANH RADIO"},
    {"002711000", "CAMLICA RADIO"},
    {"005743050", "CAN THO RADIO"},
    {"002633020", "CANDEEIROS"},
    {"004121203", "CANGZHOU"},
    {"004121202", "CAO FEI DIAN"},
    {"006010001", "CAPE TOWN RADIO"},
    {"007250250", "CASTRO RADIO"},
    {"002470095", "CESENATICO"},
    {"004224401", "CHABAHAR RADIO"},
    {"004225400", "CHABAHAR RADIO"},
    {"007250260", "CHAITEN RADIO"},
    {"007250070", "CHANARAL RADIO"},
    {"007600135", "CHANCAY RADIO"},
    {"006052111", "CHERCHELL RADIO"},
    {"003451120", "CHETUMAL, QUINTANA ROO RADIO"},
    {"007600126", "CHIMBOTE RADIO"},
    {"005250033", "CIGADING RADIO"},
    {"005250030", "CILACAP RADIO / PKR3"},
    {"005250089", "CILACAP RADIO / PKR6"},
    {"005250032", "CIREBON RADIO"},
    {"003450710", "CIUDAD DEL CARMEN, CAMPECHE RADIO"},
    {"002470123", "CIVITAVECCHIA RADIO"},
    {"003621111", "COAST GUARD CONTROL"},
    {"003621112", "COAST GUARD CONTROL"},
    {"003621113", "COAST GUARD CONTROL"},
    {"003621114", "COAST GUARD CONTROL"},
    {"003621117", "COAST GUARD CONTROL"},
    {"003621118", "COAST GUARD CONTROL"},
    {"003621119", "COAST GUARD CONTROL"},
    {"003621120", "COAST GUARD CONTROL"},
    {"003450320", "COATZACOALCOS, VERACRUZ RADIO"},
    {"002713000", "COBANDEDE RADIO"},
    {"007010008", "COMODORO RIVADAVIA PREFECTURA NAVAL RADIO"},
    {"005743060", "CON DAO RADIO"},
    {"007250150", "CONSTITUCION RADIO"},
    {"007250110", "COQUIMBO RADIO"},
    {"007250210", "CORRAL RADIO"},
    {"002241022", "CORUNA RADIO"},
    {"003451110", "COZUMEL, QUINTANA ROO RADIO"},
    {"002470124", "CROTONE RADIO"},
    {"005741020", "CUA ONG RADIO"},
    {"005742010", "CUA VIET RADIO"},
    {"002091000", "CYPRUS RADIO"},
    {"005742030", "DA NANG RADIO"},
    {"005251559", "DABO SINGKEP RADIO"},
    {"004121300", "DALIAN RADIO"},
    {"004030000", "DAMMAM RADIO"},
    {"004224203", "DAYER RADIO"},
    {"004225203", "DAYER RADIO"},
    {"002734427", "DE KASTRI TERMINAL"},
    {"002734447", "DE-KASTRI KHAB/DE-KASTRI-RADIOCENTR"},
    {"007250390", "DELGADA RADIO"},
    {"006052112", "DELLYS RADIO"},
    {"004224205", "DEYLAM RADIO"},
    {"004225205", "DEYLAM RADIO"},
    {"007250440", "DIEGO RAMIREZ RADIO"},
    {"002712000", "DIKMENTEPE RADIO"},
    {"002731107", "DIKSON TAO"},
    {"002733717", "DIKSON TAO"},
    {"002713000", "DILEKTEPE RADIO"},
    {"006211000", "DJIBOUTI RADIO"},
    {"004661010", "DOHA RADIO"},
    {"004121402", "DONG YING RADIO"},
    {"004402606", "DONGHAE/SUHYUP"},
    {"004402607", "DONGHAE/SUHYUP"},
    {"002320010", "DOVER"},
    {"004030000", "DUBA RADIO"},
    {"002380300", "DUBROVNIK RADIO"},
    {"005250004", "DUMAI RADIO / PKP"},
    {"005250083", "DUMAI RADIO / PKP4"},
    {"005742040", "DUNG QUAT RADIO"},
    {"002712000", "DUTMEN RADIO"},
    {"007300301", "ECTVM - BARRANQUILLA - CP03"},
    {"007300101", "ECTVM - BUENAVENTURA- CP01"},
    {"007300501", "ECTVM - CARTAGENA - CP05"},
    {"007300901", "ECTVM - COVE�AS - CP09"},
    {"007300401", "ECTVM - SANTA MARTA - CP04"},
    {"007300201", "ECTVM - TUMACO - CP02"},
    {"007300801", "ECTVM - TURBO - CP08"},
    {"004700000", "EMIRATES RADIO"},
    {"004701001", "EMIRATES RESCUE (JRCCAD)"},
    {"005251517", "ENDE RADIO / PKD20"},
    {"003450210", "ENSENADA, BAJA CALIFORNIA RADIO"},
    {"007354752", "ESMERALDAS RADIO"},
    {"002734422", "EYSK RADIO CENTR/EYSK-RADIO-CENTR"},
    {"005250026", "FAK-FAK RADIO"},
    {"002320014", "FALMOUTH"},
    {"007250235", "FARO CORONA RADIO"},
    {"007250400", "FARO DUNGENESS RADIO"},
    {"007250410", "FARO ESPIRITU SANTO RADIO"},
    {"007250350", "FARO EVANGELISTAS RADIO"},
    {"007250360", "FARO FAIRWAY RADIO"},
    {"007250290", "FARO GUAFO RADIO"},
    {"007250310", "FARO RAPER RADIO"},
    {"002633090", "FIGUEIRA DA FOZ"},
    {"002241022", "FINISTERRE RADIO"},
    {"002633050", "FOIA"},
    {"002633010", "FREITA"},
    {"003621001", "FRENCH FORT"},
    {"004122600", "FUZHOU RADIO"},
    {"005330190", "GEBENG"},
    {"004224206", "GENAVEH RADIO"},
    {"004225206", "GENAVEH RADIO"},
    {"002470125", "GENOVA RADIO"},
    {"006054119", "GHAZAOUET RADIO"},
    {"002361001", "GIBRALTAR PORT AUTHORITY"},
    {"002734468", "GORKI LEN"},
    {"002733700", "GORKI LEN"},
    {"006191000", "GRAND LAHOU RADIO"},
    {"004123100", "GUANGZHOU RADIO"},
    {"007354750", "GUAYAQUIL RADIO"},
    {"004400201", "GUNSAN RADIO"},
    {"004400501", "GUNSAN RADIO"},
    {"004403501", "GUNSAN RADIO"},
    {"004402501", "GUNSAN/SUHYUP"},
    {"004402502", "GUNSAN/SUHYUP"},
    {"004402503", "GUNSAN/SUHYUP"},
    {"004402504", "GUNSAN/SUHYUP"},
    {"005330003", "GUNUNG BRINCHANG"},
    {"005330001", "GUNUNG JERAI"},
    {"005330005", "GUNUNG LEDANG"},
    {"005251556", "GUNUNG SITOLI RADIO / PKB29"},
    {"005743090", "HA TIEN RADIO"},
    {"005741040", "HAI PHONG RADIO"},
    {"003160016", "HALIFAX COAST GUARD RADIO"},
    {"004310601", "HIROSHIMA COAST GUARD RADIO"},
    {"004030000", "HMB (AZIZYA) RADIO"},
    {"005743030", "HO CHI MINH RADIO"},
    {"004310101", "HOKKAIDO COAST GUARD RADIO"},
    {"002320018", "HOLYHEAD"},
    {"005741030", "HON GAI RADIO"},
    {"005741080", "HON LA RADIO"},
    {"003669993", "HONOLULU"},
    {"002510100", "HORNAFJOERDUR RADIO"},
    {"007600128", "HUACHO RADIO"},
    {"007250090", "HUASCO RADIO"},
    {"005742020", "HUE RADIO"},
    {"002320007", "HUMBER"},
    {"007600132", "ILO RADIO"},
    {"004400003", "INCHEON RADIO"},
    {"004400004", "INCHEON RADIO"},
    {"004403001", "INCHEON RADIO"},
    {"004402001", "INCHEON/SUHYUP"},
    {"004402002", "INCHEON/SUHYUP"},
    {"004402003", "INCHEON/SUHYUP"},
    {"004402004", "INCHEON/SUHYUP"},
    {"002712000", "INEBOLU RADIO"},
    {"003160023", "IQALUIT COAST GUARD RADIO"},
    {"007250020", "IQUIQUE RADIO"},
    {"007600133", "IQUITOS RADIO"},
    {"002510100", "ISAFJOERDUR RADIO"},
    {"002711000", "ISTANBUL TURK RADIO"},
    {"002715000", "IZMIR TURK RADIO"},
    {"005250000", "JAKARTA RADIO / PKX"},
    {"005250086", "JAKARTA RADIO / PKX2"},
    {"005251510", "JAMBI RADIO"},
    {"004225308", "JASK RADIO"},
    {"005250007", "JAYAPURA RADIO / PNK"},
    {"004030000", "JEDDAH RADIO"},
    {"004400701", "JEJU RADIO"},
    {"004400702", "JEJU RADIO"},
    {"004403701", "JEJU RADIO"},
    {"004402701", "JEJU/SUHYUP"},
    {"004402702", "JEJU/SUHYUP"},
    {"004402703", "JEJU/SUHYUP"},
    {"005251583", "JEPARA RADIO"},
    {"002470096", "JESOLO"},
    {"004126620", "JIANGYIN RADIO"},
    {"004030000", "JIZAN RADIO"},
    {"005030001", "JRCC AUSTRALIA"},
    {"003061000", "JRCC CURACAO/DUTCH CARIBBEAN COAST GUARD"},
    {"002653000", "JRCC SWEDEN"},
    {"002760100", "JRCC TALLINN"},
    {"007250130", "JUAN FERNANDEZ RADIO"},
    {"004030000", "JUBAIL RADIO"},
    {"004402602", "JUMOONJIN/SUHYUP"},
    {"004402604", "JUMOONJIN/SUHYUP"},
    {"004311001", "KAGOSHIMA COAST GUARD RADIO"},
    {"005251514", "KALIANGET RADIO"},
    {"002731188", "KAMENNYY C YNAO"},
    {"002731198", "KAMENNYY C YNAO"},
    {"004400602", "KANGNUNG RADIO"},
    {"004400603", "KANGNUNG RADIO"},
    {"004400604", "KANGNUNG RADIO"},
    {"005251582", "KARIMUNJAWA RADIO"},
    {"002711000", "KARTEPE RADIO"},
    {"002711000", "KAYALIDAG RADIO"},
    {"002713000", "KAZAKIN RADIO"},
    {"005330008", "KEMUNING"},
    {"005250019", "KENDARI RADIO / PKF3"},
    {"005251503", "KETAPANG RADIO"},
    {"004030000", "KHAFJI RADIO"},
    {"004224201", "KHARK RADIO"},
    {"004225201", "KHARK RADIO"},
    {"002734429", "KHOLMSK RADIO"},
    {"004225100", "KHOMEINI RADIO"},
    {"004224103", "KHORMUSA RADIO"},
    {"004224101", "KHORRAMSHAHR RADIO"},
    {"004225101", "KHORRAMSHAHR RADIO"},
    {"005743080", "KIEN GIANG RADIO"},
    {"004224303", "KISH RADIO"},
    {"002770330", "KLAIPEDA RESCUE RADIO"},
    {"004310501", "KOBE COAST GUARD RADIO"},
    {"003669899", "KODIAK RADIO"},
    {"005251575", "KOLAKA RADIO"},
    {"006221112", "KOSSEIR RADIO"},
    {"006191000", "KOUAKRO RADIO"},
    {"002734417", "KRASNOE KAL/KALININGRAD RADIO-SKC"},
    {"005330007", "KUALA ROMPIN"},
    {"005251504", "KUALA TANJUNG RADIO"},
    {"005251511", "KUALA TUNGKAL RADIO"},
    {"005251522", "KUMAI RADIO"},
    {"005250010", "KUPANG RADIO / PKK"},
    {"005259991", "KWANDANG RADIO"},
    {"003160022", "LABRADOR COAST GUARD RADIO"},
    {"002470126", "LAMPEDUSA RADIO"},
    {"002241026", "LAS PALMAS RADIO"},
    {"004680011", "LATTAKIA RADIO"},
    {"004224204", "LAVAR RADIO"},
    {"004225204", "LAVAR RADIO"},
    {"003451610", "LAZARO CARDENAS, MICHOACAN RADIO"},
    {"005250022", "LEMBAR RADIO / PKD3"},
    {"004224302", "LENGEH RADIO"},
    {"003160026", "LES ESCOUMINS COAST GUARD RADIO"},
    {"004122300", "LIANYUNGANG RADIO"},
    {"002470127", "LIVORNO RADIO"},
    {"002050480", "LOMBARDSIJDE RADIO"},
    {"002320063", "LONDON COASTGUARD"},
    {"007250120", "LOS VILOS RADIO"},
    {"005330011", "LOWER SERAPI"},
    {"005250005", "LUWUK RADIO"},
    {"005742050", "LY SON RADIO"},
    {"002191000", "LYNGBY RADIO"},
    {"002241022", "MACHICHACO RADIO"},
    {"002712000", "MACKA R/L"},
    {"002241022", "MADRID RADIO"},
    {"002734416", "MAGADAN 4"},
    {"007250380", "MAGALLANES ZONAL RADIO"},
    {"002711000", "MAHYADAG RADIO"},
    {"004310801", "MAIZURU COAST GUARD RADIO"},
    {"005250002", "MAKASSAR RADIO / PKF"},
    {"002734423", "MAKHACHKALA DAG/MAHACHKALA-RADIOCENTR"},
    {"002734489", "MAKHACHKALA DAG/MAHACHKALA-RADIOCENTR"},
    {"002150100", "MALTA RADIO"},
    {"005251529", "MANADO RADIO"},
    {"007100003", "MANAUS-RADIO (VALDIR LEAL)"},
    {"005250023", "MANOKWARI RADIO"},
    {"007354754", "MANTA RADIO"},
    {"003451410", "MANZANILLO, COLIMA RADIO"},
    {"007010003", "MAR DEL PLATA PREFECTURA NAVAL RADIO"},
    {"007010221", "MAR DEL PLATA RADIO"},
    {"002723650", "MARIUPOL RSC"},
    {"002713000", "MARKIZ RADIO"},
    {"005251518", "MAUMERE RADIO"},
    {"006452700", "MAURITIUS RADIO"},
    {"002470128", "MAZARA DEL VALLO RADIO"},
    {"003450810", "MAZATLAN, SINALOA RADIO"},
    {"007250040", "MEJILLONES RADIO"},
    {"005030126", "MELBOURNE (SANDRINGHAM)"},
    {"007250280", "MELINKA RADIO"},
    {"005251518", "MENENG RADIO"},
    {"005250021", "MERAUKE RADIO"},
    {"002470129", "MESSINA RADIO"},
    {"002320017", "MILFORD HAVEN"},
    {"003660003", "MOBILE, ALABAMA RADIO / WLO"},
    {"004310701", "MOJI COAST GUARD RADIO"},
    {"004400304", "MOKPO RADIO"},
    {"004400307", "MOKPO RADIO"},
    {"004400308", "MOKPO RADIO"},
    {"004400309", "MOKPO RADIO"},
    {"004400310", "MOKPO RADIO"},
    {"004403301", "MOKPO RADIO"},
    {"004402301", "MOKPO/SUHYUP"},
    {"004402302", "MOKPO/SUHYUP"},
    {"004402305", "MOKPO/SUHYUP"},
    {"004402308", "MOKPO/SUHYUP"},
    {"004402309", "MOKPO/SUHYUP"},
    {"004402310", "MOKPO/SUHYUP"},
    {"004402311", "MOKPO/SUHYUP"},
    {"004402312", "MOKPO/SUHYUP"},
    {"007600129", "MOLLENDO RADIO"},
    {"005741010", "MONG CAI RADIO"},
    {"002633060", "MONTE FIGO"},
    {"002633030", "MONTE FUNCHAL"},
    {"007703870", "MONTEVIDEO ARMADA RADIO"},
    {"006054118", "MOSTAGANEM RADIO"},
    {"005061411", "MRCC AYEYARWADY"},
    {"004194401", "MRCC CHENNAI"},
    {"002275300", "MRCC CORSEN"},
    {"006631008", "MRCC DAKAR"},
    {"002275000", "MRCC ETEL"},
    {"002275010", "MRCC ETEL"},
    {"002130100", "MRCC GEORGIA"},
    {"002275100", "MRCC GRIS-NEZ"},
    {"004773500", "MRCC HONG KONG"},
    {"002275200", "MRCC JOBOURG"},
    {"002275400", "MRCC LA GARDE"},
    {"002630100", "MRCC LISBOA"},
    {"002633040", "MRCC LISBOA"},
    {"004550191", "MRCC MALE"},
    {"004192203", "MRCC MUMBAI"},
    {"005401000", "MRCC NOUMEA"},
    {"005461000", "MRCC PAPEETE"},
    {"002040100", "MRCC PONTA DELGADA"},
    {"004194409", "MRCC PORT BLAIR"},
    {"006601000", "MRCC REUNION"},
    {"002470010", "MRCC ROMA"},
    {"002301000", "MRCC TURKU"},
    {"002050480", "MRCC-OOSTENDE RADIO"},
    {"002059981", "MRCC-OOSTENDE RADIO"},
    {"002275420", "MRSC AJACCIO"},
    {"002470017", "MRSC ANCONA"},
    {"004192209", "MRSC ANDROTH"},
    {"002470016", "MRSC BARI"},
    {"004192205", "MRSC BEYPORE"},
    {"002470023", "MRSC CAGLIARI"},
    {"004194408", "MRSC CAMPBELL BAY"},
    {"002470021", "MRSC CATANIA"},
    {"004192203", "MRSC DAHANU"},
    {"004192201", "MRSC DAMAN"},
    {"004194407", "MRSC DIGLIPUR"},
    {"004194404", "MRSC FRAZERGANJ"},
    {"002470011", "MRSC GENOVA"},
    {"004192206", "MRSC GOA"},
    {"004194403", "MRSC GOPALPUR"},
    {"004194404", "MRSC HALDIA"},
    {"002302000", "MRSC HELSINKI"},
    {"004194409", "MRSC HUTBAY"},
    {"004192208", "MRSC JAKHAU"},
    {"004194402", "MRSC KAKINADA"},
    {"004194408", "MRSC KAMORTA"},
    {"004194405", "MRSC KARAIKAL"},
    {"004192204", "MRSC KARWAR"},
    {"004192209", "MRSC KAVARATTI"},
    {"004192205", "MRSC KOCHI"},
    {"004194402", "MRSC KRISHNAPATNAM"},
    {"002470012", "MRSC LIVORNO"},
    {"002500100", "MRSC MALIN HEAD RADIO"},
    {"004194406", "MRSC MANDAPAM"},
    {"004194407", "MRSC MAYABUNDAR"},
    {"004192209", "MRSC MINICOY"},
    {"004192207", "MRSC MUNDRA"},
    {"004192203", "MRSC MURUD JANJIRA"},
    {"002470014", "MRSC NAPOLI"},
    {"004192204", "MRSC NEW MANGALORE"},
    {"004194402", "MRSC NIZAMPATNAM"},
    {"004192207", "MRSC OKHA"},
    {"002470022", "MRSC PALERMO"},
    {"004194403", "MRSC PARADIP"},
    {"004192207", "MRSC PIPAVAV"},
    {"004192202", "MRSC PORBANDAR"},
    {"004194401", "MRSC PUDUCHERRY"},
    {"004192203", "MRSC RATNAGIRI"},
    {"002470018", "MRSC RAVENNA"},
    {"002470015", "MRSC REGGIO CALABRIA"},
    {"002470013", "MRSC ROMA"},
    {"002470020", "MRSC TRIESTE"},
    {"004194405", "MRSC TUTICORIN"},
    {"004192210", "MRSC VADINAR"},
    {"002500200", "MRSC VALENTIA RADIO"},
    {"002470019", "MRSC VENEZIA"},
    {"004192207", "MRSC VERAVAL"},
    {"004194402", "MRSC VISHAKHAPATNAM"},
    {"004192205", "MRSC VIZHINJAM"},
    {"005250546", "MUNTOK RADIO"},
    {"002734441", "MURMANSK RADIO 30"},
    {"002734420", "MURMANSK RADIO MRCC"},
    {"005060200", "MYEIK RADIO"},
    {"004310401", "NAGOYA COAST GUARD RADIO"},
    {"002470130", "NAPOLI RADIO"},
    {"002500300", "NATIONAL MARITIME OPERATIONS CENTRE (MRCC DUBLIN)"},
    {"005251505", "NATUNA RADIO"},
    {"006459022", "NCG"},
    {"004224602", "NEKA RADIO"},
    {"005330183", "NENASI"},
    {"002510100", "NESKAUPSTADUR RADIO"},
    {"002442000", "NETHERLANDS COAST GUARD RADIO"},
    {"005742080", "NHA TRANG RADIO"},
    {"004310901", "NIIGATA COAST GUARD RADIO"},
    {"004122400", "NINGBO RADIO"},
    {"003621001", "NORTH POST RADIO STATION"},
    {"002570000", "NORWEGIAN COASTAL RADIO NORTH"},
    {"002570300", "NORWEGIAN COASTAL RADIO, SOUTH"},
    {"002570000", "NORWEGIAN COASTAL RADIO, SOUTH"},
    {"002731223", "NOVAYA ZEMLYA ARKH/NOVAYA ZEMLYA-RADIO"},
    {"002734411", "NOVOROSSIYSK RADIO MRCC/NOVOROSSIYSK-RADIO-SKC"},
    {"004224600", "NOWSHAHR RADIO"},
    {"004225600", "NOWSHAHR RADIO"},
    {"004030000", "OBHUR RADIO"},
    {"002723660", "ODESSA MRCC"},
    {"004311101", "OKINAWA COAST GUARD RADIO"},
    {"002371000", "OLYMPIA RADIO NOC"},
    {"004610013", "OMAN COAST RADIO/A4A20 (MUSCAT)"},
    {"004610014", "OMAN COAST RADIO/A4A21 (SALALAH)"},
    {"004610015", "OMAN COAST RADIO/A4A22 (KHASAB)"},
    {"004610016", "OMAN COAST RADIO/A4A23 (ASHKARAH)"},
    {"006054117", "ORAN RADIO"},
    {"002713000", "OREN RADIO"},
    {"002734426", "ORLAN RADIO"},
    {"007600121", "PAITA RADIO"},
    {"002713000", "PALAMUT RADIO"},
    {"005251507", "PALEMBANG RADIO"},
    {"002470002", "PALERMO RADIO"},
    {"002241024", "PALMA RADIO"},
    {"005250071", "PALOPO RADIO"},
    {"005251508", "PANGKAL BALAM RADIO"},
    {"005250013", "PANJANG RADIO / PKC4"},
    {"005250018", "PANTOLOAN RADIO"},
    {"005251525", "PARE-PARE RADIO / PKF23"},
    {"007250100", "PASCUA ZONAL RADIO"},
    {"002712000", "PAZAR RADIO"},
    {"005330192", "PENGERANG"},
    {"002470131", "PESCARA RADIO"},
    {"002734418", "PETROPAVLOVSK-KAMCHATSKIY"},
    {"002731117", "PEVEK CHAO"},
    {"002733730", "PEVEK CHAO"},
    {"005742100", "PHAN RANG RADIO"},
    {"005743010", "PHAN THIET RADIO"},
    {"005743110", "PHU QUOC RADIO"},
    {"005742070", "PHU YEN RADIO"},
    {"002633040", "PICOTO"},
    {"007600123", "PIMENTEL RADIO"},
    {"002392000", "PIRAEUS RADIO"},
    {"007600130", "PISCO RADIO"},
    {"003160019", "PLACENTIA COAST GUARD RADIO"},
    {"005250084", "PLAJU RADIO"},
    {"002734442", "PLASTUN RADIO"},
    {"004400401", "POHANG RADIO"},
    {"004400402", "POHANG RADIO"},
    {"004403401", "POHANG RADIO"},
    {"004402402", "POHANG/SUHYUP"},
    {"003621001", "POINT FORTIN"},
    {"002618102", "POLISH RESCUE RADIO"},
    {"002633100", "PONTA DO ALTAR"},
    {"005250016", "PONTIANAK RADIO / PKS"},
    {"003160018", "PORT AUX BASQUES COAST GUARD RADIO"},
    {"004702007", "PORT OF FUJAIRAH"},
    {"004702008", "PORT OF FUJAIRAH"},
    {"006221113", "PORT SAID RADIO"},
    {"002470132", "PORTO CERVO RADIO"},
    {"002470097", "PORTO NOGARO"},
    {"002470133", "PORTO TORRES RADIO"},
    {"002470098", "PORTOSCUSO"},
    {"005251527", "POSO RADIO"},
    {"003160029", "PRESCOTT COAST GUARD RADIO"},
    {"003160013", "PRINCE RUPERT COAST GUARD RADIO"},
    {"003450910", "PROGRESO, YUCATAN RADIO"},
    {"007250294", "PUERTO AGUIRRE RADIO"},
    {"007354757", "PUERTO AYORA RADIO"},
    {"007250300", "PUERTO AYSEN RADIO"},
    {"007354756", "PUERTO BOLIVAR RADIO"},
    {"007250298", "PUERTO CHACABUCO RADIO"},
    {"007250330", "PUERTO EDEN RADIO"},
    {"007250230", "PUERTO MONTT ZONAL RADIO"},
    {"007250340", "PUERTO NATALES RADIO"},
    {"003451210", "PUERTO VALLARTA, JALISCO RADIO"},
    {"007250420", "PUERTO WILLIAMS RADIO"},
    {"005330006", "PULAU TIOMAN"},
    {"007600134", "PUNO RADIO"},
    {"004400101", "PUSAN RADIO"},
    {"004400103", "PUSAN RADIO"},
    {"004400104", "PUSAN RADIO"},
    {"004400105", "PUSAN RADIO"},
    {"004400106", "PUSAN RADIO"},
    {"004403102", "PUSAN RADIO"},
    {"004122200", "QINGDAO RADIO"},
    {"004121200", "QINHUANGDAO RADIO"},
    {"003160027", "QUEBEC COAST GUARD RADIO"},
    {"007250270", "QUELLON RADIO"},
    {"004224304", "QUESHM RADIO"},
    {"007250125", "QUINTERO RADIO"},
    {"005742060", "QUY NHON RADIO"},
    {"004030000", "RABIGH RADIO"},
    {"002733728", "RADUZHNYY MAGADAN"},
    {"003669991", "RCC BOSTON"},
    {"004401002", "RCC DONGHAE"},
    {"004401001", "RCC INCHEON"},
    {"004401005", "RCC JEJU"},
    {"003669997", "RCC MIAMI"},
    {"004401004", "RCC NAMHAE"},
    {"003669998", "RCC NEW ORLEANS"},
    {"003669992", "RCC SAN JUAN"},
    {"004401003", "RCC SEOHAE"},
    {"007100002", "RECIFE BONGI"},
    {"002510100", "REYKJAVIK RADIO"},
    {"004122201", "RI ZHAO"},
    {"002750100", "RIGA RESCUE RADIO"},
    {"002380200", "RIJEKA RADIO"},
    {"007100001", "RIO DE JANEIRO (SANTA CRUZ)"},
    {"007010010", "RIO GALLEGOS PREFECTURA NAVAL RADIO"},
    {"006341000", "RMRCC MOMBASA"},
    {"002470001", "ROMA RADIO"},
    {"003621001", "RUNNEMEDE"},
    {"007250140", "S. ANTONIO RADIO"},
    {"002470134", "S. BENEDETTO DEL TRONTO RADIO"},
    {"007600131", "S. JUAN RADIO"},
    {"007250320", "S. PEDRO RADIO"},
    {"002733700", "S. PETERSBURG RADIO MRCC"},
    {"005251501", "SABANG RADIO / PKA4"},
    {"002731177", "SABETTA PT YNAO"},
    {"002731187", "SABETTA PT YNAO"},
    {"002731197", "SABETTA PT YNAO"},
    {"002733733", "SAKHALIN RADIO SPC"},
    {"007600124", "SALAVERRY RADIO"},
    {"007354755", "SALINAS RADIO"},
    {"005251524", "SAMARINDA RADIO / PKN6"},
    {"004402106", "SAMCHEONPO/SUHYUP"},
    {"004402112", "SAMCHEONPO/SUHYUP"},
    {"005251521", "SAMPIT RADIO"},
    {"002712000", "SAMSUN TURK RADIO"},
    {"007010006", "SAN BLAS PREFECTURA NAVAL RADIO"},
    {"003669990", "SAN FRANCISCO"},
    {"005250025", "SANANA RADIO"},
    {"006191000", "SAN-PEDRO RADIO"},
    {"004123700", "SANYA RADIO"},
    {"002711000", "SARKOY RADIO"},
    {"003160030", "SARNIA COAST GUARD RADIO"},
    {"006191000", "SASSANDRA RADIO"},
    {"005251531", "SAUMLAKI RADIO"},
    {"005250029", "SEI KOLAK KIJANG RADIO"},
    {"005250090", "SEI PAKNING RADIO"},
    {"005250008", "SEMARANG RADIO / PKR"},
    {"004400002", "SEOUL RADIO"},
    {"004122100", "SHANGHAI RADIO"},
    {"004123200", "SHANTOU RADIO"},
    {"004123106", "SHENZHEN RADIO"},
    {"002320001", "SHETLAND"},
    {"004310201", "SHIOGAMA COAST GUARD RADIO"},
    {"004030000", "SHUAIBA RADIO"},
    {"004030000", "SHUQAIQ RADIO"},
    {"005250028", "SIBOLGA RADIO / PKB3"},
    {"002510100", "SIGLUFJOERDUR RADIO"},
    {"005630002", "SINGAPORE PORT OPERATIONS CONTROL"},
    {"002734417", "SINYAVINO KLN/KALININGRAD-1"},
    {"005250047", "SIPORA RADIO"},
    {"002731108", "SOCHI AKHUN MTN KRAS"},
    {"004402603", "SOKCHO/SUHYUP"},
    {"002320011", "SOLENT"},
    {"005250011", "SORONG RADIO / PKY4"},
    {"002380100", "SPLIT RADIO"},
    {"003751001", "ST. VINCENT AND THE GRENADINES COAST GUARD"},
    {"005330196", "STESEN PANTAI KUALA MUDA"},
    {"005330188", "STESEN PEMANCAR PERMATANG PAUH, P. PINANG"},
    {"005330184", "STESEN PEMANCAR STAPOK"},
    {"005330193", "STESEN PEMANCAR TUARAN"},
    {"005330199", "STESEN PENERIMAAN RADIO TANJUNG ARU"},
    {"005330200", "STESEN PENERIMAAN SEMANTAN"},
    {"005330198", "STESEN SATELLITE BUMI BESERAH"},
    {"002320024", "STORNOWAY"},
    {"007600127", "SUPE RADIO"},
    {"005250001", "SURABAYA RADIO / PKD"},
    {"002733733", "SVOBODNYY SAKH"},
    {"003160017", "SYDNEY COAST GUARD RADIO"},
    {"006191000", "TABOU RADIO"},
    {"004402201", "TAEAN/SUHYUP"},
    {"004402202", "TAEAN/SUHYUP"},
    {"004402203", "TAEAN/SUHYUP"},
    {"004402204", "TAEAN/SUHYUP"},
    {"002734487", "TAGANROG RADIO"},
    {"002734487", "TAGANROG ROST/TAGANROG-RADIO-1"},
    {"005250024", "TAHUNA RADIO"},
    {"007600122", "TALARA RADIO"},
    {"007250170", "TALCAHUANO ZONAL RADIO"},
    {"002761000", "TALLINN RADIO"},
    {"007250060", "TALTAL RADIO"},
    {"003450110", "TAMPICO, TAMAULIPAS RADIO"},
    {"005330187", "TANJUNG LOBANG"},
    {"005251506", "TANJUNG UBAN RADIO / PKJ"},
    {"005251502", "TAPAK TUAN RADIO"},
    {"005250017", "TARAKAN RADIO / PKO"},
    {"002241026", "TARIFA RADIO"},
    {"004680012", "TARTOUS RADIO"},
    {"005120010", "TAUPO MARITIME RADIO"},
    {"005251513", "TEGAL RADIO / PKR26"},
    {"005251075", "TELUK BAYUR RADIO / PKP20"},
    {"005250075", "TELUK BAYUR RADIO / PKV"},
    {"005250094", "TEMBILAHAN RADIO"},
    {"006052113", "TENES RADIO"},
    {"005250020", "TERNATE RADIO / PKE5"},
    {"002470099", "TERRASINI"},
    {"005330014", "TG TARAS"},
    {"005741060", "THANH HOA RADIO"},
    {"005743100", "THO CHU RADIO"},
    {"004121100", "TIANJIN RADIO"},
    {"002734449", "TIKSI MRSC"},
    {"002731196", "TIKSI-3 YAK"},
    {"002733718", "TIKSI-3 YAK"},
    {"004225309", "TIYAB RADIO"},
    {"007250030", "TOCOPILLA RADIO"},
    {"004310001", "TOKYO COAST GUARD RADIO"},
    {"005251528", "TOLI-TOLI RADIO"},
    {"004402105", "TONGYEONG/SUHYUP"},
    {"004402108", "TONGYEONG/SUHYUP"},
    {"004402109", "TONGYEONG/SUHYUP"},
    {"004402110", "TONGYEONG/SUHYUP"},
    {"002311000", "TORSHAVN RADIO"},
    {"002470135", "TRIESTE RADIO"},
    {"005330194", "TRIG HILL"},
    {"005251530", "TUAL RADIO"},
    {"002734413", "TUAPSE KRAS/TUAPSE-CENTR"},
    {"002300230", "TURKU RADIO"},
    {"002734448", "UGOLNYE KOPI 3-Y CHAO/MARIYA-RADIO"},
    {"002731178", "UGOLNYE KOPI CHAO"},
    {"004402404", "ULLENG/SUHYUP"},
    {"004402405", "ULLENG/SUHYUP"},
    {"004402406", "ULLENG/SUHYUP"},
    {"004400403", "ULREUNG RADIO"},
    {"004400404", "ULREUNG RADIO"},
    {"004400102", "ULSAN RADIO"},
    {"004402102", "ULSAN/SUHYUP"},
    {"004402104", "ULSAN/SUHYUP"},
    {"005330004", "ULU KALI"},
    {"004030000", "UMM LAJJ RADIO"},
    {"007250220", "VALDIVIA RADIO"},
    {"007251860", "VALPARAISO PLAYA ANCHA RADIO"},
    {"002734421", "VANINO RADIO"},
    {"002070810", "VARNA RADIO"},
    {"003450310", "VERACRUZ, VERACRUZ RADIO"},
    {"002770090", "VESSEL TRAFFIC MONITORING"},
    {"002770100", "VESSEL TRAFFIC MONITORING"},
    {"002770110", "VESSEL TRAFFIC MONITORING"},
    {"002770120", "VESSEL TRAFFIC MONITORING"},
    {"002770130", "VESSEL TRAFFIC MONITORING"},
    {"002510100", "VESTMANNAEYJAR RADIO"},
    {"002633070", "VIANA DO CASTELO"},
    {"003160011", "VICTORIA COAST GUARD RADIO"},
    {"002734412", "VLADIVOSTOCK RADIO MRCC"},
    {"005743020", "VUNG TAU RADIO"},
    {"002734451", "VYSOTSK LEN"},
    {"005788020", "WALLIS RADIO"},
    {"004121403", "WEI FANG"},
    {"004121404", "WEIHAI"},
    {"004402403", "WHOPO/SUHYUP"},
    {"004402407", "WHOPO/SUHYUP"},
    {"004403408", "WHOPO/SUHYUP"},
    {"007250430", "WOLLASTON RADIO"},
    {"004122700", "XIAMEN RADIO"},
    {"004030000", "YANBU RADIO"},
    {"005060100", "YANGON RADIO"},
    {"004121400", "YANTAI RADIO"},
    {"004400305", "YEOSU RADIO"},
    {"004400306", "YEOSU RADIO"},
    {"004402303", "YEOSU/SUHYUP"},
    {"004402304", "YEOSU/SUHYUP"},
    {"004402307", "YEOSU/SUHYUP"},
    {"002712000", "YILDIZTEPE RADIO"},
    {"004310301", "YOKOHAMA COAST GUARD RADIO"},
    {"002713000", "YUMRUTEPE RADIO"},
    {"002711000", "YUSA RADIO"},
    {"002050480", "ZEEBRUGGE RADIO"},
    {"004123300", "ZHANJIANG RADIO"},
    {"004125725", "ZHANJIANG RADIO"},
    {"002712000", "ZONGULDAK RADIO"},
    {"007600120", "ZORRITOS RADIO"},
    // Not from ITU database
    {"004472188", "KUWAIT"},
    {"002241078", "MADRID RADIO"},
    {"002640570", "CONSTANTA RADIO"},
    {"004280001", "HAIFA RADIO"},
    {"004634060", "MRCC KARACHI"}
};
