#include <bits/stdc++.h>
using namespace std;

typedef double db;
const db ans[] = {0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,2.000000000,2.000000000,3.618033766,1.381966234,4.732050664,1.267949336,5.791287738,1.208712262,6.828427037,1.171572963,7.854101892,1.145898108,8.872983282,1.127016718,9.887482137,1.112517863,10.898979435,1.101020565,11.908326867,1.091673133,12.916079741,1.083920259,13.922616251,1.077383749,14.928203194,1.071796806,15.933034340,1.066965660,16.937253902,1.062746098,17.940971479,1.059028521,18.944271882,1.055728118,19.947221788,1.052778212,20.949874346,1.050125654,21.952272456,1.047727544,22.954451127,1.045548873,23.956439216,1.043560784,24.958260722,1.041739278,25.959935774,1.040064226,26.961481378,1.038518622,27.962912000,1.037088000,28.964240026,1.035759974,29.965476124,1.034523876,30.966629530,1.033370470,31.967708283,1.032291717,32.968719407,1.031280593,33.969669077,1.030330923,34.970562734,1.029437266,35.971405195,1.028594805,36.972200742,1.027799258,37.972953189,1.027046811,38.973665948,1.026334052,39.974342082,1.025657918,40.974984343,1.025015657,41.975595218,1.024404782,42.976176952,1.023823048,43.976731583,1.023268417,44.977260965,1.022739035,45.977766782,1.022233218,46.978250575,1.021749425,47.978713753,1.021286247,48.979157607,1.020842393,49.979583320,1.020416680,50.979991984,1.020008016,51.980384603,1.019615397,52.980762104,1.019237896,53.981125345,1.018874655,54.981475117,1.018524883,55.981812158,1.018187842,56.982137151,1.017862849,57.982450729,1.017549271,58.982753484,1.017246516,59.983045967,1.016954033,60.983328693,1.016671307,61.983602141,1.016397859,62.983866762,1.016133238,63.984122975,1.015877025,64.984371176,1.015628824,65.984611734,1.015388266,66.984844997,1.015155003,67.985071294,1.014928706,68.985290929,1.014709071,69.985504194,1.014495806,70.985711362,1.014288638,71.985912691,1.014087309,72.986108424,1.013891576,73.986298792,1.013701208,74.986484011,1.013515989,75.986664289,1.013335711,76.986839820,1.013160180,77.987010790,1.012989210,78.987177373,1.012822627,79.987339737,1.012660263,80.987498040,1.012501960,81.987652433,1.012347567,82.987803058,1.012196942,83.987950052,1.012049948,84.988093545,1.011906455,85.988233660,1.011766340,86.988370515,1.011629485,87.988504223,1.011495777,88.988634890,1.011365110,89.988762621,1.011237379,90.988887511,1.011112489,91.989009656,1.010990344,92.989129145,1.010870855,93.989246063,1.010753937,94.989360493,1.010639507,95.989472512,1.010527488,96.989582198,1.010417802,97.989689621,1.010310379,98.989794851,1.010205149,99.989897954,1.010102046,100.989998995,1.010001005,101.990098034,1.009901966,102.990195131,1.009804869,103.990290342,1.009709658,104.990383721,1.009616279,105.990475322,1.009524678,106.990565193,1.009434807,107.990653385,1.009346615,108.990739942,1.009260058,109.990824911,1.009175089,110.990908335,1.009091665,111.990990255,1.009009745,112.991070713,1.008929287,113.991149745,1.008850255,114.991227391,1.008772609,115.991303686,1.008696314,116.991378666,1.008621334,117.991452363,1.008547637,118.991524811,1.008475189,119.991596041,1.008403959,120.991666084,1.008333916,121.991734969,1.008265031,122.991802724,1.008197276,123.991869378,1.008130622,124.991934956,1.008065044,125.991999484,1.008000516,126.992062989,1.007937011,127.992125492,1.007874508,128.992187020,1.007812980,129.992247593,1.007752407,130.992307234,1.007692766,131.992365964,1.007634036,132.992423804,1.007576196,133.992480775,1.007519225,134.992536894,1.007463106,135.992592183,1.007407817,136.992646658,1.007353342,137.992700338,1.007299662,138.992753239,1.007246761,139.992805380,1.007194620,140.992856775,1.007143225,141.992907441,1.007092559,142.992957394,1.007042606,143.993006648,1.006993352,144.993055217,1.006944783,145.993103117,1.006896883,146.993150360,1.006849640,147.993196961,1.006803039,148.993242932,1.006757068,149.993288285,1.006711715,150.993333034,1.006666966,151.993377190,1.006622810,152.993420765,1.006579235,153.993463770,1.006536230,154.993506217,1.006493783,155.993548116,1.006451884,156.993589477,1.006410523,157.993630312,1.006369688,158.993670630,1.006329370,159.993710440,1.006289560,160.993749753,1.006250247,161.993788577,1.006211423,162.993826922,1.006173078,163.993864797,1.006135203,164.993902210,1.006097790,165.993939169,1.006060831,166.993975682,1.006024318,167.994011759,1.005988241,168.994047405,1.005952595,169.994082630,1.005917370,170.994117441,1.005882559,171.994151844,1.005848156,172.994185847,1.005814153,173.994219457,1.005780543,174.994252681,1.005747319,175.994285525,1.005714475,176.994317996,1.005682004,177.994350100,1.005649900,178.994381843,1.005618157,179.994413231,1.005586769,180.994444270,1.005555730,181.994474967,1.005525033,182.994505326,1.005494674,183.994535353,1.005464647,184.994565054,1.005434946,185.994594434,1.005405566,186.994623498,1.005376502,187.994652251,1.005347749,188.994680698,1.005319302,189.994708844,1.005291156,190.994736694,1.005263306,191.994764252,1.005235748,192.994791523,1.005208477,193.994818511,1.005181489,194.994845221,1.005154779,195.994871658,1.005128342,196.994897824,1.005102176,197.994923725,1.005076275,198.994949364,1.005050636,199.994974745,1.005025255,200.994999873,1.005000127,201.995024750,1.004975250,202.995049381,1.004950619,203.995073770,1.004926230,204.995097919,1.004902081,205.995121833,1.004878167,206.995145514,1.004854486,207.995168967,1.004831033,208.995192194,1.004807806,209.995215199,1.004784801,210.995237985,1.004762015,211.995260555,1.004739445,212.995282912,1.004717088,213.995305059,1.004694941,214.995326999,1.004673001,215.995348734,1.004651266,216.995370269,1.004629731,217.995391605,1.004608395,218.995412745,1.004587255,219.995433693,1.004566307,220.995454449,1.004545551,221.995475018,1.004524982,222.995495402,1.004504598,223.995515603,1.004484397,224.995535623,1.004464377,225.995555466,1.004444534,226.995575133,1.004424867,227.995594626,1.004405374,228.995613949,1.004386051,229.995633102,1.004366898,230.995652090,1.004347910,231.995670912,1.004329088,232.995689573,1.004310427,233.995708073,1.004291927,234.995726416,1.004273584,235.995744602,1.004255398,236.995762634,1.004237366,237.995780514,1.004219486,238.995798243,1.004201757,239.995815824,1.004184176,240.995833259,1.004166741,241.995850549,1.004149451,242.995867696,1.004132304,243.995884702,1.004115298,244.995901569,1.004098431,245.995918297,1.004081703,246.995934890,1.004065110,247.995951349,1.004048651,248.995967674,1.004032326,249.995983869,1.004016131,250.995999934,1.004000066,251.996015871,1.003984129,252.996031682,1.003968318,253.996047367,1.003952633,254.996062929,1.003937071,255.996078369,1.003921631,256.996093689,1.003906311,257.996108889,1.003891111,258.996123971,1.003876029,259.996138937,1.003861063,260.996153787,1.003846213,261.996168524,1.003831476,262.996183149,1.003816851,263.996197662,1.003802338,264.996212065,1.003787935,265.996226360,1.003773640,266.996240547,1.003759453,267.996254627,1.003745373,268.996268603,1.003731397,269.996282475,1.003717525,270.996296244,1.003703756,271.996309911,1.003690089,272.996323478,1.003676522,273.996336945,1.003663055,274.996350315,1.003649685,275.996363587,1.003636413,276.996376762,1.003623238,277.996389843,1.003610157,278.996402829,1.003597171,279.996415723,1.003584277,280.996428524,1.003571476,281.996441234,1.003558766,282.996453854,1.003546146,283.996466385,1.003533615,284.996478828,1.003521172,285.996491183,1.003508817,286.996503452,1.003496548,287.996515635,1.003484365,288.996527734,1.003472266,289.996539749,1.003460251,290.996551681,1.003448319,291.996563532,1.003436468,292.996575301,1.003424699,293.996586989,1.003413011,294.996598598,1.003401402,295.996610129,1.003389871,296.996621581,1.003378419,297.996632957,1.003367043,298.996644256,1.003355744,299.996655479,1.003344521,300.996666628,1.003333372,301.996677703,1.003322297,302.996688704,1.003311296,303.996699632,1.003300368,304.996710489,1.003289511,305.996721275,1.003278725,306.996731990,1.003268010,307.996742635,1.003257365,308.996753211,1.003246789,309.996763719,1.003236281,310.996774158,1.003225842,311.996784531,1.003215469,312.996794837,1.003205163,313.996805078,1.003194922,314.996815253,1.003184747,315.996825363,1.003174637,316.996835410,1.003164590,317.996845393,1.003154607,318.996855313,1.003144687,319.996865171,1.003134829,320.996874968,1.003125032,321.996884703,1.003115297,322.996894378,1.003105622,323.996903994,1.003096006,324.996913549,1.003086451,325.996923046,1.003076954,326.996932485,1.003067515,327.996941866,1.003058134,328.996951190,1.003048810,329.996960457,1.003039543,330.996969668,1.003030332,331.996978823,1.003021177,332.996987923,1.003012077,333.996996968,1.003003032,334.997005960,1.002994040,335.997014897,1.002985103,336.997023782,1.002976218,337.997032613,1.002967387,338.997041393,1.002958607,339.997050120,1.002949880,340.997058797,1.002941203,341.997067422,1.002932578,342.997075997,1.002924003,343.997084522,1.002915478,344.997092997,1.002907003,345.997101424,1.002898576,346.997109802,1.002890198,347.997118131,1.002881869,348.997126412,1.002873588,349.997134646,1.002865354,350.997142833,1.002857167,351.997150973,1.002849027,352.997159067,1.002840933,353.997167115,1.002832885,354.997175118,1.002824882,355.997183075,1.002816925,356.997190988,1.002809012,357.997198857,1.002801143,358.997206681,1.002793319,359.997214462,1.002785538,360.997222200,1.002777800,361.997229895,1.002770105,362.997237547,1.002762453,363.997245157,1.002754843,364.997252726,1.002747274,365.997260253,1.002739747,366.997267738,1.002732262,367.997275183,1.002724817,368.997282588,1.002717412,369.997289952,1.002710048,370.997297277,1.002702723,371.997304562,1.002695438,372.997311808,1.002688192,373.997319015,1.002680985,374.997326183,1.002673817,375.997333314,1.002666686,376.997340406,1.002659594,377.997347461,1.002652539,378.997354478,1.002645522,379.997361458,1.002638542,380.997368402,1.002631598,381.997375309,1.002624691,382.997382180,1.002617820,383.997389015,1.002610985,384.997395815,1.002604185,385.997402579,1.002597421,386.997409308,1.002590692,387.997416003,1.002583997,388.997422662,1.002577338,389.997429288,1.002570712,390.997435880,1.002564120,391.997442438,1.002557562,392.997448962,1.002551038,393.997455453,1.002544547,394.997461912,1.002538088,395.997468337,1.002531663,396.997474731,1.002525269,397.997481092,1.002518908,398.997487421,1.002512579,399.997493718,1.002506282,400.997499984,1.002500016,401.997506218,1.002493782,402.997512422,1.002487578,403.997518594,1.002481406,404.997524737,1.002475263,405.997530848,1.002469152,406.997536930,1.002463070,407.997542982,1.002457018,408.997549004,1.002450996,409.997554997,1.002445003,410.997560960,1.002439040,411.997566895,1.002433105,412.997572800,1.002427200,413.997578678,1.002421322,414.997584526,1.002415474,415.997590347,1.002409653,416.997596139,1.002403861,417.997601904,1.002398096,418.997607641,1.002392359,419.997613351,1.002386649,420.997619033,1.002380967,421.997624689,1.002375311,422.997630318,1.002369682,423.997635920,1.002364080,424.997641496,1.002358504,425.997647045,1.002352955,426.997652569,1.002347431,427.997658066,1.002341934,428.997663538,1.002336462,429.997668984,1.002331016,430.997674405,1.002325595,431.997679801,1.002320199,432.997685172,1.002314828,433.997690518,1.002309482,434.997695840,1.002304160,435.997701137,1.002298863,436.997706409,1.002293591,437.997711658,1.002288342,438.997716882,1.002283118,439.997722083,1.002277917,440.997727260,1.002272740,441.997732414,1.002267586,442.997737544,1.002262456,443.997742651,1.002257349,444.997747736,1.002252264,445.997752797,1.002247203,446.997757836,1.002242164,447.997762852,1.002237148,448.997767845,1.002232155,449.997772817,1.002227183,450.997777766,1.002222234,451.997782694,1.002217306,452.997787599,1.002212401,453.997792483,1.002207517,454.997797345,1.002202655,455.997802187,1.002197813,456.997807006,1.002192994,457.997811805,1.002188195,458.997816583,1.002183417,459.997821340,1.002178660,460.997826076,1.002173924,461.997830792,1.002169208,462.997835487,1.002164513,463.997840162,1.002159838,464.997844817,1.002155183,465.997849452,1.002150548,466.997854067,1.002145933,467.997858662,1.002141338,468.997863237,1.002136763,469.997867794,1.002132206,470.997872330,1.002127670,471.997876848,1.002123152,472.997881346,1.002118654,473.997885825,1.002114175,474.997890285,1.002109715,475.997894727,1.002105273,476.997899150,1.002100850,477.997903554,1.002096446,478.997907940,1.002092060,479.997912308,1.002087692,480.997916657,1.002083343,481.997920988,1.002079012,482.997925302,1.002074698,483.997929597,1.002070403,484.997933875,1.002066125,485.997938135,1.002061865,486.997942378,1.002057622,487.997946603,1.002053397,488.997950810,1.002049190,489.997955001,1.002044999,490.997959175,1.002040825,491.997963331,1.002036669,492.997967471,1.002032529,493.997971594,1.002028406,494.997975700,1.002024300,495.997979789,1.002020211,496.997983862,1.002016138,497.997987919,1.002012081,498.997991959,1.002008041,499.997995983,1.002004017,500.997999991,1.002000009,501.998003983,1.001996017,502.998007960,1.001992040,503.998011920,1.001988080,504.998015865,1.001984135,505.998019794,1.001980206,506.998023707,1.001976293,507.998027605,1.001972395,508.998031488,1.001968512,509.998035355,1.001964645,510.998039208,1.001960792,511.998043045,1.001956955,512.998046867,1.001953133,513.998050674,1.001949326,514.998054467,1.001945533,515.998058245,1.001941755,516.998062008,1.001937992,517.998065756,1.001934244,518.998069490,1.001930510,519.998073210,1.001926790,520.998076915,1.001923085,521.998080607,1.001919393,522.998084284,1.001915716,523.998087947,1.001912053,524.998091596,1.001908404,525.998095231,1.001904769,526.998098852,1.001901148,527.998102459,1.001897541,528.998106053,1.001893947,529.998109634,1.001890366,530.998113200,1.001886800,531.998116754,1.001883246,532.998120294,1.001879706,533.998123820,1.001876180,534.998127334,1.001872666,535.998130834,1.001869166,536.998134321,1.001865679,537.998137796,1.001862204,538.998141257,1.001858743,539.998144706,1.001855294,540.998148141,1.001851859,541.998151564,1.001848436,542.998154975,1.001845025,543.998158373,1.001841627,544.998161758,1.001838242,545.998165131,1.001834869,546.998168492,1.001831508,547.998171840,1.001828160,548.998175176,1.001824824,549.998178500,1.001821500,550.998181812,1.001818188,551.998185111,1.001814889,552.998188399,1.001811601,553.998191675,1.001808325,554.998194939,1.001805061,555.998198192,1.001801808,556.998201433,1.001798567,557.998204662,1.001795338,558.998207879,1.001792121,559.998211085,1.001788915,560.998214280,1.001785720,561.998217463,1.001782537,562.998220634,1.001779366,563.998223795,1.001776205,564.998226944,1.001773056,565.998230082,1.001769918,566.998233210,1.001766790,567.998236326,1.001763674,568.998239431,1.001760569,569.998242525,1.001757475,570.998245608,1.001754392,571.998248681,1.001751319,572.998251742,1.001748258,573.998254794,1.001745206,574.998257834,1.001742166,575.998260864,1.001739136,576.998263883,1.001736117,577.998266892,1.001733108,578.998269891,1.001730109,579.998272879,1.001727121,580.998275856,1.001724144,581.998278824,1.001721176,582.998281781,1.001718219,583.998284729,1.001715271,584.998287666,1.001712334,585.998290593,1.001709407,586.998293510,1.001706490,587.998296417,1.001703583,588.998299314,1.001700686,589.998302202,1.001697798,590.998305079,1.001694921,591.998307947,1.001692053,592.998310806,1.001689194,593.998313654,1.001686346,594.998316493,1.001683507,595.998319323,1.001680677,596.998322142,1.001677858,597.998324953,1.001675047,598.998327754,1.001672246,599.998330546,1.001669454,600.998333328,1.001666672,601.998336101,1.001663899,602.998338865,1.001661135,603.998341620,1.001658380,604.998344366,1.001655634,605.998347102,1.001652898,606.998349830,1.001650170,607.998352549,1.001647451,608.998355258,1.001644742,609.998357959,1.001642041,610.998360651,1.001639349,611.998363334,1.001636666,612.998366008,1.001633992,613.998368674,1.001631326,614.998371331,1.001628669,615.998373979,1.001626021,616.998376619,1.001623381,617.998379250,1.001620750,618.998381872,1.001618128,619.998384486,1.001615514,620.998387092,1.001612908,621.998389689,1.001610311,622.998392278,1.001607722,623.998394859,1.001605141,624.998397431,1.001602569,625.998399995,1.001600005,626.998402551,1.001597449,627.998405099,1.001594901,628.998407639,1.001592361,629.998410170,1.001589830,630.998412694,1.001587306,631.998415210,1.001584790,632.998417717,1.001582283,633.998420217,1.001579783,634.998422709,1.001577291,635.998425193,1.001574807,636.998427669,1.001572331,637.998430137,1.001569863,638.998432598,1.001567402,639.998435051,1.001564949,640.998437496,1.001562504,641.998439933,1.001560067,642.998442363,1.001557637,643.998444786,1.001555214,644.998447201,1.001552799,645.998449608,1.001550392,646.998452008,1.001547992,647.998454401,1.001545599,648.998456786,1.001543214,649.998459164,1.001540836,650.998461534,1.001538466,651.998463898,1.001536102,652.998466254,1.001533746,653.998468602,1.001531398,654.998470944,1.001529056,655.998473279,1.001526721,656.998475606,1.001524394,657.998477926,1.001522074,658.998480239,1.001519761,659.998482545,1.001517455,660.998484845,1.001515155,661.998487137,1.001512863,662.998489422,1.001510578,663.998491701,1.001508299,664.998493972,1.001506028,665.998496237,1.001503763,666.998498495,1.001501505,667.998500746,1.001499254,668.998502990,1.001497010,669.998505228,1.001494772,670.998507459,1.001492541,671.998509683,1.001490317,672.998511901,1.001488099,673.998514112,1.001485888,674.998516317,1.001483683,675.998518515,1.001481485,676.998520706,1.001479294,677.998522892,1.001477108,678.998525070,1.001474930,679.998527242,1.001472758,680.998529408,1.001470592,681.998531568,1.001468432,682.998533721,1.001466279,683.998535868,1.001464132,684.998538008,1.001461992,685.998540143,1.001459857,686.998542271,1.001457729,687.998544392,1.001455608,688.998546508,1.001453492,689.998548618,1.001451382,690.998550721,1.001449279,691.998552819,1.001447181,692.998554910,1.001445090,693.998556995,1.001443005,694.998559074,1.001440926,695.998561148,1.001438852,696.998563215,1.001436785,697.998565276,1.001434724,698.998567332,1.001432668,699.998569382,1.001430618,700.998571425,1.001428575,701.998573463,1.001426537,702.998575495,1.001424505,703.998577522,1.001422478,704.998579542,1.001420458,705.998581557,1.001418443,706.998583566,1.001416434,707.998585570,1.001414430,708.998587567,1.001412433,709.998589560,1.001410440,710.998591546,1.001408454,711.998593527,1.001406473,712.998595503,1.001404497,713.998597472,1.001402528,714.998599437,1.001400563,715.998601396,1.001398604,716.998603349,1.001396651,717.998605297,1.001394703,718.998607239,1.001392761,719.998609176,1.001390824,720.998611108,1.001388892,721.998613034,1.001386966,722.998614955,1.001385045,723.998616871,1.001383129,724.998618782,1.001381218,725.998620687,1.001379313,726.998622587,1.001377413,727.998624481,1.001375519,728.998626371,1.001373629,729.998628255,1.001371745,730.998630134,1.001369866,731.998632008,1.001367992,732.998633877,1.001366123,733.998635741,1.001364259,734.998637599,1.001362401,735.998639453,1.001360547,736.998641302,1.001358698,737.998643145,1.001356855,738.998644984,1.001355016,739.998646817,1.001353183,740.998648646,1.001351354,741.998650470,1.001349530,742.998652288,1.001347712,743.998654102,1.001345898,744.998655911,1.001344089,745.998657715,1.001342285,746.998659515,1.001340485,747.998661309,1.001338691,748.998663099,1.001336901,749.998664884,1.001335116,750.998666664,1.001333336,751.998668439,1.001331561,752.998670210,1.001329790,753.998671976,1.001328024,754.998673737,1.001326263,755.998675494,1.001324506,756.998677246,1.001322754,757.998678993,1.001321007,758.998680736,1.001319264,759.998682474,1.001317526,760.998684208,1.001315792,761.998685937,1.001314063,762.998687661,1.001312339,763.998689381,1.001310619,764.998691097,1.001308903,765.998692808,1.001307192,766.998694514,1.001305486,767.998696217,1.001303783,768.998697914,1.001302086,769.998699607,1.001300393,770.998701296,1.001298704,771.998702981,1.001297019,772.998704661,1.001295339,773.998706336,1.001293664,774.998708008,1.001291992,775.998709675,1.001290325,776.998711338,1.001288662,777.998712996,1.001287004,778.998714651,1.001285349,779.998716301,1.001283699,780.998717946,1.001282054,781.998719588,1.001280412,782.998721225,1.001278775,783.998722858,1.001277142,784.998724487,1.001275513,785.998726112,1.001273888,786.998727733,1.001272267,787.998729350,1.001270650,788.998730962,1.001269038,789.998732571,1.001267429,790.998734175,1.001265825,791.998735775,1.001264225,792.998737371,1.001262629,793.998738964,1.001261036,794.998740552,1.001259448,795.998742136,1.001257864,796.998743716,1.001256284,797.998745293,1.001254707,798.998746865,1.001253135,799.998748433,1.001251567,800.998749998,1.001250002,801.998751558,1.001248442,802.998753115,1.001246885,803.998754668,1.001245332,804.998756217,1.001243783,805.998757762,1.001242238,806.998759303,1.001240697,807.998760840,1.001239160,808.998762374,1.001237626,809.998763904,1.001236096,810.998765430,1.001234570,811.998766952,1.001233048,812.998768471,1.001231529,813.998769986,1.001230014,814.998771497,1.001228503,815.998773004,1.001226996,816.998774508,1.001225492,817.998776008,1.001223992,818.998777504,1.001222496,819.998778997,1.001221003,820.998780486,1.001219514,821.998781971,1.001218029,822.998783453,1.001216547,823.998784931,1.001215069,824.998786406,1.001213594,825.998787877,1.001212123,826.998789344,1.001210656,827.998790808,1.001209192,828.998792269,1.001207731,829.998793725,1.001206275,830.998795179,1.001204821,831.998796629,1.001203371,832.998798075,1.001201925,833.998799518,1.001200482,834.998800957,1.001199043,835.998802393,1.001197607,836.998803826,1.001196174,837.998805255,1.001194745,838.998806681,1.001193319,839.998808103,1.001191897,840.998809522,1.001190478,841.998810937,1.001189063,842.998812350,1.001187650,843.998813758,1.001186242,844.998815164,1.001184836,845.998816566,1.001183434,846.998817965,1.001182035,847.998819361,1.001180639,848.998820753,1.001179247,849.998822142,1.001177858,850.998823528,1.001176472,851.998824910,1.001175090,852.998826289,1.001173711,853.998827665,1.001172335,854.998829038,1.001170962,855.998830408,1.001169592,856.998831774,1.001168226,857.998833137,1.001166863,858.998834497,1.001165503,859.998835854,1.001164146,860.998837208,1.001162792,861.998838558,1.001161442,862.998839905,1.001160095,863.998841250,1.001158750,864.998842591,1.001157409,865.998843929,1.001156071,866.998845264,1.001154736,867.998846596,1.001153404,868.998847925,1.001152075,869.998849250,1.001150750,870.998850573,1.001149427,871.998851893,1.001148107,872.998853209,1.001146791,873.998854523,1.001145477,874.998855834,1.001144166,875.998857141,1.001142859,876.998858446,1.001141554,877.998859747,1.001140253,878.998861046,1.001138954,879.998862342,1.001137658,880.998863635,1.001136365,881.998864925,1.001135075,882.998866211,1.001133789,883.998867496,1.001132504,884.998868777,1.001131223,885.998870055,1.001129945,886.998871330,1.001128670,887.998872603,1.001127397,888.998873872,1.001126128,889.998875139,1.001124861,890.998876403,1.001123597,891.998877664,1.001122336,892.998878922,1.001121078,893.998880178,1.001119822,894.998881430,1.001118570,895.998882680,1.001117320,896.998883927,1.001116073,897.998885171,1.001114829,898.998886413,1.001113587,899.998887651,1.001112349,900.998888887,1.001111113,901.998890121,1.001109879,902.998891351,1.001108649,903.998892579,1.001107421,904.998893804,1.001106196,905.998895026,1.001104974,906.998896246,1.001103754,907.998897463,1.001102537,908.998898677,1.001101323,909.998899888,1.001100112,910.998901097,1.001098903,911.998902304,1.001097696,912.998903507,1.001096493,913.998904708,1.001095292,914.998905907,1.001094093,915.998907102,1.001092898,916.998908295,1.001091705,917.998909486,1.001090514,918.998910674,1.001089326,919.998911859,1.001088141,920.998913042,1.001086958,921.998914222,1.001085778,922.998915400,1.001084600,923.998916575,1.001083425,924.998917747,1.001082253,925.998918917,1.001081083,926.998920085,1.001079915,927.998921250,1.001078750,928.998922412,1.001077588,929.998923572,1.001076428,930.998924730,1.001075270,931.998925885,1.001074115,932.998927037,1.001072963,933.998928187,1.001071813,934.998929335,1.001070665,935.998930480,1.001069520,936.998931623,1.001068377,937.998932763,1.001067237,938.998933901,1.001066099,939.998935036,1.001064964,940.998936169,1.001063831,941.998937299,1.001062701,942.998938427,1.001061573,943.998939553,1.001060447,944.998940677,1.001059323,945.998941798,1.001058202,946.998942916,1.001057084,947.998944032,1.001055968,948.998945146,1.001054854,949.998946258,1.001053742,950.998947367,1.001052633,951.998948474,1.001051526,952.998949578,1.001050422,953.998950681,1.001049319,954.998951781,1.001048219,955.998952878,1.001047122,956.998953974,1.001046026,957.998955067,1.001044933,958.998956157,1.001043843,959.998957246,1.001042754,960.998958332,1.001041668,961.998959416,1.001040584,962.998960498,1.001039502,963.998961577,1.001038423,964.998962654,1.001037346,965.998963729,1.001036271,966.998964802,1.001035198,967.998965873,1.001034127,968.998966941,1.001033059,969.998968007,1.001031993,970.998969071,1.001030929,971.998970133,1.001029867,972.998971192,1.001028808,973.998972250,1.001027750,974.998973305,1.001026695,975.998974358,1.001025642,976.998975409,1.001024591,977.998976457,1.001023543,978.998977504,1.001022496,979.998978548,1.001021452,980.998979591,1.001020409,981.998980631,1.001019369,982.998981669,1.001018331,983.998982705,1.001017295,984.998983739,1.001016261,985.998984770,1.001015230,986.998985800,1.001014200,987.998986828,1.001013172,988.998987853,1.001012147,989.998988876,1.001011124,990.998989898,1.001010102,991.998990917,1.001009083,992.998991934,1.001008066,993.998992949,1.001007051,994.998993963,1.001006037,995.998994974,1.001005026,996.998995983,1.001004017,997.998996990,1.001003010,998.998997995,1.001002005};

int main() {
	int T, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		if (x && x < 4) {
			puts("N");
		} else {
			printf("Y %.9f %.9f\n", ans[x << 1], ans[x << 1 | 1]);
		}
	}
	return 0;
}