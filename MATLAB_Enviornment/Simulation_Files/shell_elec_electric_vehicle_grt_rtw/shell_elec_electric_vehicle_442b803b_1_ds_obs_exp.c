/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */

#include "ne_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_obs_exp.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ds_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_externals.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_external_struct.h"

int32_T shell_elec_electric_vehicle_442b803b_1_ds_obs_exp(const NeDynamicSystem *
  t0, const NeDynamicSystemInput *t2, NeDsMethodOutput *t3)
{
  PmRealVector out;
  real_T DP_R_idx_0;
  (void)t0;
  DP_R_idx_0 = t2->mDP_R.mX[0];
  out = t3->mOBS_EXP;
  out.mX[0] = 293.15;
  out.mX[1] = 293.15;
  out.mX[2] = 0.0;
  out.mX[3] = 0.0;
  out.mX[4] = 0.0;
  out.mX[5] = 0.0;
  out.mX[6] = 0.0;
  out.mX[7] = 0.0;
  out.mX[8] = 0.0;
  out.mX[9] = 0.0;
  out.mX[10] = 1.0;
  out.mX[11] = 293.15;
  out.mX[12] = 0.0;
  out.mX[13] = 0.0;
  out.mX[14] = 0.0;
  out.mX[15] = 0.0;
  out.mX[16] = 31.0;
  out.mX[17] = 156.845;
  out.mX[18] = 1.0;
  out.mX[19] = 293.15;
  out.mX[20] = 0.0;
  out.mX[21] = 0.0;
  out.mX[22] = 0.0;
  out.mX[23] = 0.0;
  out.mX[24] = 0.0;
  out.mX[25] = 0.0;
  out.mX[26] = 0.0;
  out.mX[27] = 0.0;
  out.mX[28] = 1.0;
  out.mX[29] = 293.15;
  out.mX[30] = 0.0;
  out.mX[31] = 0.0;
  out.mX[32] = 0.0;
  out.mX[33] = 0.0;
  out.mX[34] = 0.0;
  out.mX[35] = 1.0;
  out.mX[36] = 293.15;
  out.mX[37] = 0.0;
  out.mX[38] = 0.0;
  out.mX[39] = 0.0;
  out.mX[40] = 0.0;
  out.mX[41] = 0.0;
  out.mX[42] = 0.0;
  out.mX[43] = 0.0;
  out.mX[44] = 0.0;
  out.mX[45] = 0.0;
  out.mX[46] = 0.0;
  out.mX[47] = 293.15;
  out.mX[48] = 0.0;
  out.mX[49] = DP_R_idx_0;
  out.mX[50] = 293.15;
  out.mX[51] = 293.15;
  out.mX[52] = 0.0;
  out.mX[53] = 0.0;
  out.mX[54] = 0.0;
  out.mX[55] = 293.15;
  out.mX[56] = 293.15;
  out.mX[57] = 0.0;
  out.mX[58] = 0.0;
  out.mX[59] = 0.0;
  out.mX[60] = 0.0;
  out.mX[61] = 0.0;
  out.mX[62] = 293.15;
  out.mX[63] = 293.15;
  out.mX[64] = 0.0;
  out.mX[65] = 0.0;
  out.mX[66] = 0.0;
  out.mX[67] = 0.0;
  out.mX[68] = 0.0;
  out.mX[69] = 293.15;
  out.mX[70] = 293.15;
  out.mX[71] = 0.0;
  out.mX[72] = 0.0;
  out.mX[73] = 0.0;
  out.mX[74] = 0.0;
  out.mX[75] = 0.0;
  out.mX[76] = 0.0;
  out.mX[77] = 0.0;
  out.mX[78] = 300.0;
  out.mX[79] = 0.1;
  out.mX[80] = 300.0;
  out.mX[81] = 0.1;
  out.mX[82] = 0.0;
  out.mX[83] = 0.0;
  out.mX[84] = 300.0;
  out.mX[85] = 300.0;
  out.mX[86] = 1.0;
  out.mX[87] = 1.0;
  out.mX[88] = 1000.0;
  out.mX[89] = 1000.0;
  out.mX[90] = 85.0;
  out.mX[91] = 85.0;
  out.mX[92] = 85.0;
  out.mX[93] = 0.0;
  out.mX[94] = 0.0;
  out.mX[95] = 293.15;
  out.mX[96] = 0.0;
  out.mX[97] = 300.0;
  out.mX[98] = 0.1;
  out.mX[99] = 0.0;
  out.mX[100] = 293.15;
  out.mX[101] = 0.0;
  out.mX[102] = 0.0;
  out.mX[103] = 293.15;
  out.mX[104] = 0.0;
  out.mX[105] = 0.0;
  out.mX[106] = 0.85;
  out.mX[107] = 0.2;
  out.mX[108] = 0.0;
  out.mX[109] = 0.0;
  out.mX[110] = 1000.0;
  out.mX[111] = 1.0E-5;
  out.mX[112] = 300.0;
  out.mX[113] = 0.1;
  out.mX[114] = 0.0;
  out.mX[115] = 293.15;
  out.mX[116] = 300.0;
  out.mX[117] = 1.0;
  out.mX[118] = 0.1;
  out.mX[119] = 1000.0;
  out.mX[120] = 85.0;
  out.mX[121] = 85.0;
  out.mX[122] = 300.0;
  out.mX[123] = 0.1;
  out.mX[124] = 300.0;
  out.mX[125] = 0.1;
  out.mX[126] = 293.15;
  out.mX[127] = 1000.0;
  out.mX[128] = 293.15;
  out.mX[129] = 3.66;
  out.mX[130] = 3.66;
  out.mX[131] = 0.0;
  out.mX[132] = 0.0;
  out.mX[133] = 0.0;
  out.mX[134] = 300.0;
  out.mX[135] = 0.1;
  out.mX[136] = 300.0;
  out.mX[137] = 0.1;
  out.mX[138] = 0.0;
  out.mX[139] = 0.0;
  out.mX[140] = 293.15;
  out.mX[141] = 300.0;
  out.mX[142] = 300.0;
  out.mX[143] = 1.0;
  out.mX[144] = 1.0;
  out.mX[145] = 0.101325;
  out.mX[146] = 1000.0;
  out.mX[147] = 1000.0;
  out.mX[148] = 85.0;
  out.mX[149] = 85.0;
  out.mX[150] = 85.0;
  out.mX[151] = 300.0;
  out.mX[152] = 0.1;
  out.mX[153] = 300.0;
  out.mX[154] = 0.1;
  out.mX[155] = 293.15;
  out.mX[156] = 1000.0;
  out.mX[157] = 293.15;
  out.mX[158] = 3.66;
  out.mX[159] = 3.66;
  out.mX[160] = 0.0;
  out.mX[161] = 0.0;
  out.mX[162] = 0.0;
  out.mX[163] = 300.0;
  out.mX[164] = 0.1;
  out.mX[165] = 300.0;
  out.mX[166] = 0.1;
  out.mX[167] = 0.0;
  out.mX[168] = 0.0;
  out.mX[169] = 293.15;
  out.mX[170] = 300.0;
  out.mX[171] = 300.0;
  out.mX[172] = 1.0;
  out.mX[173] = 1.0;
  out.mX[174] = 0.101325;
  out.mX[175] = 1000.0;
  out.mX[176] = 1000.0;
  out.mX[177] = 85.0;
  out.mX[178] = 85.0;
  out.mX[179] = 85.0;
  out.mX[180] = 293.15;
  out.mX[181] = 0.0;
  out.mX[182] = 293.15;
  out.mX[183] = 0.0;
  out.mX[184] = 0.0;
  out.mX[185] = 300.0;
  out.mX[186] = 0.1;
  out.mX[187] = 300.0;
  out.mX[188] = 0.1;
  out.mX[189] = 0.0;
  out.mX[190] = 0.0;
  out.mX[191] = 300.0;
  out.mX[192] = 300.0;
  out.mX[193] = 1.0;
  out.mX[194] = 1.0;
  out.mX[195] = 1000.0;
  out.mX[196] = 1000.0;
  out.mX[197] = 85.0;
  out.mX[198] = 85.0;
  out.mX[199] = 85.0;
  out.mX[200] = 300.0;
  out.mX[201] = 0.1;
  out.mX[202] = 293.15;
  out.mX[203] = 293.15;
  out.mX[204] = 0.0;
  out.mX[205] = 0.0;
  out.mX[206] = 0.0;
  out.mX[207] = 300.0;
  out.mX[208] = 0.1;
  out.mX[209] = 300.0;
  out.mX[210] = 0.1;
  out.mX[211] = 293.15;
  out.mX[212] = 1000.0;
  out.mX[213] = 293.15;
  out.mX[214] = 3.66;
  out.mX[215] = 3.66;
  out.mX[216] = 0.0;
  out.mX[217] = 0.0;
  out.mX[218] = 0.0;
  out.mX[219] = 300.0;
  out.mX[220] = 0.1;
  out.mX[221] = 300.0;
  out.mX[222] = 0.1;
  out.mX[223] = 0.0;
  out.mX[224] = 0.0;
  out.mX[225] = 293.15;
  out.mX[226] = 300.0;
  out.mX[227] = 300.0;
  out.mX[228] = 1.0;
  out.mX[229] = 1.0;
  out.mX[230] = 0.101325;
  out.mX[231] = 1000.0;
  out.mX[232] = 1000.0;
  out.mX[233] = 85.0;
  out.mX[234] = 85.0;
  out.mX[235] = 85.0;
  out.mX[236] = 293.15;
  out.mX[237] = 293.15;
  out.mX[238] = 0.0;
  out.mX[239] = 0.0;
  out.mX[240] = 0.0;
  out.mX[241] = 300.0;
  out.mX[242] = 0.1;
  out.mX[243] = 300.0;
  out.mX[244] = 0.1;
  out.mX[245] = 0.0;
  out.mX[246] = 0.0;
  out.mX[247] = 0.0;
  out.mX[248] = 1.0;
  out.mX[249] = 0.0;
  out.mX[250] = 0.0;
  out.mX[251] = 0.0;
  out.mX[252] = 0.0;
  out.mX[253] = 0.0;
  out.mX[254] = 0.0;
  out.mX[255] = 300.0;
  out.mX[256] = 0.1;
  out.mX[257] = 300.0;
  out.mX[258] = 0.1;
  out.mX[259] = 0.0;
  out.mX[260] = 0.0;
  out.mX[261] = 0.0;
  out.mX[262] = 0.0;
  out.mX[263] = 293.15;
  out.mX[264] = 300.0;
  out.mX[265] = 0.1;
  out.mX[266] = 0.0;
  out.mX[267] = 0.0;
  out.mX[268] = 0.0;
  out.mX[269] = 0.0;
  out.mX[270] = 0.0;
  out.mX[271] = 0.0;
  out.mX[272] = 0.0;
  out.mX[273] = 0.0;
  out.mX[274] = 0.0;
  out.mX[275] = 0.0;
  out.mX[276] = 1.0;
  out.mX[277] = 0.0;
  out.mX[278] = 0.0;
  out.mX[279] = 0.0;
  out.mX[280] = 0.0;
  out.mX[281] = 0.0;
  out.mX[282] = 0.0;
  out.mX[283] = 0.0;
  out.mX[284] = 0.0;
  out.mX[285] = 0.0;
  out.mX[286] = 0.0;
  out.mX[287] = 0.0;
  out.mX[288] = 0.0;
  out.mX[289] = 0.0;
  out.mX[290] = 0.0;
  out.mX[291] = 0.0;
  out.mX[292] = 0.0;
  out.mX[293] = 0.0;
  out.mX[294] = 0.0;
  out.mX[295] = 0.0;
  out.mX[296] = 300.0;
  out.mX[297] = 0.1;
  out.mX[298] = 293.15;
  out.mX[299] = 293.15;
  out.mX[300] = 0.0;
  out.mX[301] = 0.0;
  out.mX[302] = 0.0;
  out.mX[303] = 293.15;
  out.mX[304] = 293.15;
  out.mX[305] = 0.0;
  out.mX[306] = 0.0;
  out.mX[307] = 0.0;
  out.mX[308] = 300.0;
  out.mX[309] = 0.1;
  out.mX[310] = 300.0;
  out.mX[311] = 0.1;
  out.mX[312] = 0.0;
  out.mX[313] = 0.0;
  out.mX[314] = 0.0;
  out.mX[315] = 1.0;
  out.mX[316] = 0.0;
  out.mX[317] = 0.0;
  out.mX[318] = 0.0;
  out.mX[319] = 0.0;
  out.mX[320] = 0.0;
  out.mX[321] = 0.0;
  out.mX[322] = 300.0;
  out.mX[323] = 0.1;
  out.mX[324] = 300.0;
  out.mX[325] = 0.1;
  out.mX[326] = 293.15;
  out.mX[327] = 1000.0;
  out.mX[328] = 293.15;
  out.mX[329] = 3.66;
  out.mX[330] = 3.66;
  out.mX[331] = 0.0;
  out.mX[332] = 0.0;
  out.mX[333] = 0.0;
  out.mX[334] = 300.0;
  out.mX[335] = 0.1;
  out.mX[336] = 300.0;
  out.mX[337] = 0.1;
  out.mX[338] = 0.0;
  out.mX[339] = 0.0;
  out.mX[340] = 293.15;
  out.mX[341] = 300.0;
  out.mX[342] = 300.0;
  out.mX[343] = 1.0;
  out.mX[344] = 1.0;
  out.mX[345] = 0.101325;
  out.mX[346] = 1000.0;
  out.mX[347] = 1000.0;
  out.mX[348] = 85.0;
  out.mX[349] = 85.0;
  out.mX[350] = 85.0;
  out.mX[351] = 300.0;
  out.mX[352] = 0.1;
  out.mX[353] = 300.0;
  out.mX[354] = 0.1;
  out.mX[355] = 0.0;
  out.mX[356] = 0.0;
  out.mX[357] = 0.0;
  out.mX[358] = 0.0;
  out.mX[359] = 0.0;
  out.mX[360] = 0.0;
  out.mX[361] = 293.15;
  out.mX[362] = 0.0;
  out.mX[363] = 0.0;
  out.mX[364] = 0.0;
  out.mX[365] = 0.0;
  out.mX[366] = 0.0;
  out.mX[367] = 293.15;
  out.mX[368] = 0.0;
  out.mX[369] = 0.0;
  out.mX[370] = 0.0;
  out.mX[371] = 0.0;
  out.mX[372] = 0.0;
  out.mX[373] = 0.0;
  out.mX[374] = 0.0;
  out.mX[375] = 0.0;
  out.mX[376] = 0.0;
  out.mX[377] = 0.0;
  out.mX[378] = 298.15;
  out.mX[379] = 0.0;
  out.mX[380] = 0.0;
  out.mX[381] = 0.0;
  out.mX[382] = 0.0;
  out.mX[383] = 0.0;
  out.mX[384] = 100.0;
  out.mX[385] = 0.0;
  out.mX[386] = 0.0;
  out.mX[387] = 0.0;
  out.mX[388] = 0.0;
  out.mX[389] = 0.0;
  out.mX[390] = 0.0;
  out.mX[391] = 293.15;
  out.mX[392] = 293.15;
  out.mX[393] = 0.0;
  out.mX[394] = 0.0;
  out.mX[395] = 0.0;
  out.mX[396] = 0.0;
  out.mX[397] = 0.0;
  out.mX[398] = 0.0;
  out.mX[399] = 0.0;
  out.mX[400] = 0.0;
  out.mX[401] = 0.0;
  out.mX[402] = 293.15;
  out.mX[403] = 293.15;
  out.mX[404] = 0.0;
  out.mX[405] = 0.0;
  out.mX[406] = 0.0;
  out.mX[407] = 293.15;
  out.mX[408] = 0.0;
  out.mX[409] = 293.15;
  out.mX[410] = 293.15;
  out.mX[411] = 293.15;
  out.mX[412] = 0.0;
  out.mX[413] = 0.0;
  out.mX[414] = 0.0;
  out.mX[415] = 0.0;
  out.mX[416] = 0.0;
  out.mX[417] = 0.0;
  out.mX[418] = 0.0;
  out.mX[419] = 0.0;
  out.mX[420] = 0.0;
  out.mX[421] = 0.0;
  out.mX[422] = 0.0;
  out.mX[423] = 0.0;
  out.mX[424] = 0.0;
  out.mX[425] = 0.0;
  out.mX[426] = 0.0;
  out.mX[427] = 0.0;
  out.mX[428] = 0.0;
  out.mX[429] = 0.0;
  out.mX[430] = 0.0;
  out.mX[431] = 0.0;
  out.mX[432] = 0.0;
  out.mX[433] = 0.0;
  out.mX[434] = 0.0;
  out.mX[435] = 0.0;
  out.mX[436] = 0.0;
  out.mX[437] = 0.0;
  out.mX[438] = 0.0;
  out.mX[439] = 0.0;
  out.mX[440] = 0.0;
  out.mX[441] = 0.0;
  out.mX[442] = 0.0;
  out.mX[443] = 0.0;
  out.mX[444] = 0.0;
  out.mX[445] = 1.0;
  out.mX[446] = 1.0;
  out.mX[447] = 0.0;
  out.mX[448] = 0.0;
  out.mX[449] = 0.0;
  out.mX[450] = 1.0;
  out.mX[451] = 1.0;
  out.mX[452] = 0.0;
  out.mX[453] = 0.0;
  out.mX[454] = 0.0;
  out.mX[455] = 0.0;
  out.mX[456] = 0.0;
  out.mX[457] = 0.0;
  out.mX[458] = 0.0;
  out.mX[459] = 0.0;
  out.mX[460] = 0.0;
  out.mX[461] = 0.0;
  out.mX[462] = 0.0;
  out.mX[463] = 0.0;
  out.mX[464] = 0.0;
  out.mX[465] = 0.0;
  out.mX[466] = 0.0;
  out.mX[467] = 0.0;
  out.mX[468] = 0.0;
  out.mX[469] = 0.0;
  out.mX[470] = 0.0;
  out.mX[471] = 0.0;
  out.mX[472] = 0.0;
  out.mX[473] = 0.0;
  out.mX[474] = 0.0;
  out.mX[475] = 0.0;
  out.mX[476] = 0.0;
  out.mX[477] = 0.0;
  out.mX[478] = 0.0;
  out.mX[479] = 0.0;
  out.mX[480] = 0.0;
  out.mX[481] = 0.0;
  out.mX[482] = 1.0;
  out.mX[483] = 1.0;
  out.mX[484] = 0.0;
  out.mX[485] = 0.0;
  out.mX[486] = 0.0;
  out.mX[487] = 0.0;
  out.mX[488] = 0.0;
  out.mX[489] = 0.0;
  out.mX[490] = 0.0;
  out.mX[491] = 0.0;
  out.mX[492] = 0.0;
  out.mX[493] = 0.0;
  out.mX[494] = 0.0;
  out.mX[495] = 0.0;
  out.mX[496] = 0.0;
  out.mX[497] = 0.0;
  out.mX[498] = 0.0;
  out.mX[499] = 0.0;
  out.mX[500] = 0.0;
  out.mX[501] = 0.0;
  out.mX[502] = 0.0;
  out.mX[503] = 0.0;
  out.mX[504] = 0.0;
  out.mX[505] = 0.0;
  out.mX[506] = 0.0;
  out.mX[507] = 0.0;
  out.mX[508] = 0.0;
  out.mX[509] = 0.0;
  out.mX[510] = 0.0;
  out.mX[511] = 0.0;
  out.mX[512] = 0.0;
  out.mX[513] = 0.0;
  out.mX[514] = 0.0;
  out.mX[515] = 0.0;
  out.mX[516] = 0.0;
  out.mX[517] = 0.0;
  out.mX[518] = 0.0;
  out.mX[519] = 0.0;
  out.mX[520] = 0.0;
  out.mX[521] = 0.0;
  out.mX[522] = 0.0;
  out.mX[523] = 293.15;
  (void)t0;
  (void)t3;
  return 0;
}