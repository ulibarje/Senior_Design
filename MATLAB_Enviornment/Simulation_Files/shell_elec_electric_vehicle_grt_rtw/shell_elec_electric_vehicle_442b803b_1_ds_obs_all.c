/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'shell_elec_electric_vehicle/Solver Configuration'.
 */

#include "ne_ds.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_obs_all.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_ds_struct.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_externals.h"
#include "shell_elec_electric_vehicle_442b803b_1_ds_external_struct.h"

int32_T shell_elec_electric_vehicle_442b803b_1_ds_obs_all(const NeDynamicSystem *
  t0, const NeDynamicSystemInput *t87, NeDsMethodOutput *t88)
{
  PmRealVector out;
  real_T Battery_Controlled_Voltage_Source_p_v;
  real_T Battery_Electrical_model_for_Np_parallel_connected_cells_C1_n_v;
  real_T Battery_Electrical_model_for_Np_parallel_connected_cells_C1_p_v;
  real_T Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss;
  real_T Cooling_system_Radiator_PS_Product_I1;
  real_T DC_DC_converter_averaged_Battery_sensors_Voltage_Sensor_V;
  real_T DC_DC_converter_averaged_Resistor_n_v;
  real_T Differential_pinion_crown_ratio_t_in;
  real_T Energy_based_PMSM_drive_model_Heat_exchanger_PS_Product_I1;
  real_T Energy_based_PMSM_drive_model_Servomotor_damper1_t;
  real_T Energy_based_PMSM_drive_model_Servomotor_gain1_I;
  real_T Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O;
  real_T Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M;
  real_T Longitudinal_vehicle_dynamics_Ideal_Force_Source_S;
  real_T zc_int17;
  boolean_T t23[2];
  real_T t26[1];
  real_T t29[1];
  boolean_T t32[2];
  real_T t42;
  real_T t44;
  real_T t46;
  real_T t48;
  real_T t51;
  void *_in1var[9];
  size_t _in1ivar;
  size_t b__in1ivar;
  real_T _retvar[1];
  void *b__in1var[9];
  size_t c__in1ivar;
  size_t d__in1ivar;
  real_T b__retvar[1];
  void *c__in1var[9];
  size_t e__in1ivar;
  size_t f__in1ivar;
  real_T c__retvar[1];
  void *d__in1var[9];
  size_t g__in1ivar;
  size_t h__in1ivar;
  real_T d__retvar[1];
  void *e__in1var[9];
  size_t i__in1ivar;
  size_t j__in1ivar;
  real_T e__retvar[1];
  void *f__in1var[9];
  size_t k__in1ivar;
  size_t l__in1ivar;
  real_T f__retvar[1];
  void *g__in1var[9];
  size_t m__in1ivar;
  size_t n__in1ivar;
  real_T g__retvar[1];
  void *h__in1var[9];
  size_t o__in1ivar;
  size_t p__in1ivar;
  real_T h__retvar[1];
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_22;
  real_T X_idx_23;
  real_T X_idx_24;
  real_T X_idx_1;
  real_T X_idx_25;
  real_T X_idx_26;
  real_T X_idx_28;
  real_T X_idx_30;
  real_T X_idx_31;
  real_T X_idx_34;
  real_T X_idx_5;
  real_T X_idx_38;
  real_T X_idx_60;
  real_T X_idx_41;
  real_T X_idx_62;
  real_T X_idx_7;
  real_T X_idx_54;
  real_T X_idx_33;
  real_T X_idx_9;
  real_T X_idx_70;
  real_T X_idx_72;
  real_T X_idx_88;
  real_T X_idx_78;
  real_T X_idx_11;
  real_T X_idx_53;
  real_T X_idx_106;
  real_T X_idx_107;
  real_T X_idx_108;
  real_T X_idx_14;
  real_T X_idx_86;
  real_T X_idx_15;
  real_T X_idx_87;
  real_T X_idx_121;
  real_T X_idx_16;
  real_T X_idx_109;
  real_T X_idx_122;
  real_T X_idx_123;
  real_T X_idx_17;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T X_idx_127;
  real_T X_idx_129;
  real_T X_idx_124;
  real_T U_idx_4;
  real_T X_idx_56;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_56;
  int32_T M_idx_67;
  real_T efOut_idx_0;
  real_T X_idx_55;
  real_T X_idx_97;
  int32_T M_idx_52;
  int32_T M_idx_53;
  int32_T M_idx_2;
  int32_T M_idx_13;
  real_T b_efOut_idx_0;
  real_T X_idx_96;
  real_T X_idx_99;
  int32_T M_idx_54;
  int32_T M_idx_55;
  real_T c_efOut_idx_0;
  real_T X_idx_98;
  real_T X_idx_10;
  real_T X_idx_111;
  int32_T M_idx_57;
  int32_T M_idx_58;
  int32_T M_idx_100;
  int32_T M_idx_111;
  real_T X_idx_110;
  real_T X_idx_113;
  int32_T M_idx_59;
  int32_T M_idx_60;
  int32_T M_idx_61;
  int32_T M_idx_62;
  real_T X_idx_112;
  real_T X_idx_58;
  int32_T M_idx_78;
  int32_T M_idx_89;
  real_T f_efOut_idx_0;
  real_T X_idx_13;
  real_T X_idx_57;
  real_T X_idx_6;
  real_T X_idx_74;
  int32_T M_idx_122;
  int32_T M_idx_133;
  real_T X_idx_73;
  real_T X_idx_76;
  int32_T M_idx_24;
  int32_T M_idx_35;
  int32_T M_idx_46;
  int32_T M_idx_51;
  real_T X_idx_75;
  real_T X_idx_8;
  real_T X_idx_27;
  real_T X_idx_29;
  real_T X_idx_2;
  real_T X_idx_32;
  real_T X_idx_3;
  real_T X_idx_35;
  real_T X_idx_36;
  real_T X_idx_37;
  real_T X_idx_39;
  real_T X_idx_40;
  real_T X_idx_42;
  real_T X_idx_43;
  real_T X_idx_44;
  real_T X_idx_45;
  real_T X_idx_46;
  real_T X_idx_47;
  real_T X_idx_4;
  real_T X_idx_49;
  real_T X_idx_48;
  real_T X_idx_50;
  real_T X_idx_51;
  real_T X_idx_52;
  real_T X_idx_63;
  real_T X_idx_59;
  real_T X_idx_61;
  real_T X_idx_64;
  real_T X_idx_65;
  real_T X_idx_66;
  real_T X_idx_67;
  real_T X_idx_68;
  real_T X_idx_69;
  real_T X_idx_71;
  real_T X_idx_80;
  real_T X_idx_77;
  real_T X_idx_79;
  real_T X_idx_81;
  real_T X_idx_82;
  real_T X_idx_83;
  real_T X_idx_84;
  real_T X_idx_85;
  real_T X_idx_89;
  real_T X_idx_90;
  real_T X_idx_91;
  real_T X_idx_92;
  real_T X_idx_93;
  real_T X_idx_94;
  real_T X_idx_95;
  real_T X_idx_100;
  real_T X_idx_101;
  real_T X_idx_102;
  real_T X_idx_103;
  real_T X_idx_104;
  real_T X_idx_105;
  real_T X_idx_12;
  real_T X_idx_114;
  real_T X_idx_115;
  real_T X_idx_116;
  real_T X_idx_117;
  real_T X_idx_118;
  real_T X_idx_119;
  real_T X_idx_120;
  real_T X_idx_18;
  real_T X_idx_125;
  real_T X_idx_126;
  real_T X_idx_19;
  real_T U_idx_3;
  real_T X_idx_128;
  real_T X_idx_20;
  real_T X_idx_21;
  M_idx_0 = t87->mM.mX[0];
  M_idx_1 = t87->mM.mX[1];
  M_idx_2 = t87->mM.mX[2];
  M_idx_13 = t87->mM.mX[13];
  M_idx_24 = t87->mM.mX[24];
  M_idx_35 = t87->mM.mX[35];
  M_idx_46 = t87->mM.mX[46];
  M_idx_51 = t87->mM.mX[51];
  M_idx_52 = t87->mM.mX[52];
  M_idx_53 = t87->mM.mX[53];
  M_idx_54 = t87->mM.mX[54];
  M_idx_55 = t87->mM.mX[55];
  M_idx_56 = t87->mM.mX[56];
  M_idx_57 = t87->mM.mX[57];
  M_idx_58 = t87->mM.mX[58];
  M_idx_59 = t87->mM.mX[59];
  M_idx_60 = t87->mM.mX[60];
  M_idx_61 = t87->mM.mX[61];
  M_idx_62 = t87->mM.mX[62];
  M_idx_67 = t87->mM.mX[67];
  M_idx_78 = t87->mM.mX[78];
  M_idx_89 = t87->mM.mX[89];
  M_idx_100 = t87->mM.mX[100];
  M_idx_111 = t87->mM.mX[111];
  M_idx_122 = t87->mM.mX[122];
  M_idx_133 = t87->mM.mX[133];
  U_idx_0 = t87->mU.mX[0];
  U_idx_1 = t87->mU.mX[1];
  U_idx_2 = t87->mU.mX[2];
  U_idx_3 = t87->mU.mX[3];
  U_idx_4 = t87->mU.mX[4];
  X_idx_0 = t87->mX.mX[0];
  X_idx_1 = t87->mX.mX[1];
  X_idx_2 = t87->mX.mX[2];
  X_idx_3 = t87->mX.mX[3];
  X_idx_4 = t87->mX.mX[4];
  X_idx_5 = t87->mX.mX[5];
  X_idx_6 = t87->mX.mX[6];
  X_idx_7 = t87->mX.mX[7];
  X_idx_8 = t87->mX.mX[8];
  X_idx_9 = t87->mX.mX[9];
  X_idx_10 = t87->mX.mX[10];
  X_idx_11 = t87->mX.mX[11];
  X_idx_12 = t87->mX.mX[12];
  X_idx_13 = t87->mX.mX[13];
  X_idx_14 = t87->mX.mX[14];
  X_idx_15 = t87->mX.mX[15];
  X_idx_16 = t87->mX.mX[16];
  X_idx_17 = t87->mX.mX[17];
  X_idx_18 = t87->mX.mX[18];
  X_idx_19 = t87->mX.mX[19];
  X_idx_20 = t87->mX.mX[20];
  X_idx_21 = t87->mX.mX[21];
  X_idx_22 = t87->mX.mX[22];
  X_idx_23 = t87->mX.mX[23];
  X_idx_24 = t87->mX.mX[24];
  X_idx_25 = t87->mX.mX[25];
  X_idx_26 = t87->mX.mX[26];
  X_idx_27 = t87->mX.mX[27];
  X_idx_28 = t87->mX.mX[28];
  X_idx_29 = t87->mX.mX[29];
  X_idx_30 = t87->mX.mX[30];
  X_idx_31 = t87->mX.mX[31];
  X_idx_32 = t87->mX.mX[32];
  X_idx_33 = t87->mX.mX[33];
  X_idx_34 = t87->mX.mX[34];
  X_idx_35 = t87->mX.mX[35];
  X_idx_36 = t87->mX.mX[36];
  X_idx_37 = t87->mX.mX[37];
  X_idx_38 = t87->mX.mX[38];
  X_idx_39 = t87->mX.mX[39];
  X_idx_40 = t87->mX.mX[40];
  X_idx_41 = t87->mX.mX[41];
  X_idx_42 = t87->mX.mX[42];
  X_idx_43 = t87->mX.mX[43];
  X_idx_44 = t87->mX.mX[44];
  X_idx_45 = t87->mX.mX[45];
  X_idx_46 = t87->mX.mX[46];
  X_idx_47 = t87->mX.mX[47];
  X_idx_48 = t87->mX.mX[48];
  X_idx_49 = t87->mX.mX[49];
  X_idx_50 = t87->mX.mX[50];
  X_idx_51 = t87->mX.mX[51];
  X_idx_52 = t87->mX.mX[52];
  X_idx_53 = t87->mX.mX[53];
  X_idx_54 = t87->mX.mX[54];
  X_idx_55 = t87->mX.mX[55];
  X_idx_56 = t87->mX.mX[56];
  X_idx_57 = t87->mX.mX[57];
  X_idx_58 = t87->mX.mX[58];
  X_idx_59 = t87->mX.mX[59];
  X_idx_60 = t87->mX.mX[60];
  X_idx_61 = t87->mX.mX[61];
  X_idx_62 = t87->mX.mX[62];
  X_idx_63 = t87->mX.mX[63];
  X_idx_64 = t87->mX.mX[64];
  X_idx_65 = t87->mX.mX[65];
  X_idx_66 = t87->mX.mX[66];
  X_idx_67 = t87->mX.mX[67];
  X_idx_68 = t87->mX.mX[68];
  X_idx_69 = t87->mX.mX[69];
  X_idx_70 = t87->mX.mX[70];
  X_idx_71 = t87->mX.mX[71];
  X_idx_72 = t87->mX.mX[72];
  X_idx_73 = t87->mX.mX[73];
  X_idx_74 = t87->mX.mX[74];
  X_idx_75 = t87->mX.mX[75];
  X_idx_76 = t87->mX.mX[76];
  X_idx_77 = t87->mX.mX[77];
  X_idx_78 = t87->mX.mX[78];
  X_idx_79 = t87->mX.mX[79];
  X_idx_80 = t87->mX.mX[80];
  X_idx_81 = t87->mX.mX[81];
  X_idx_82 = t87->mX.mX[82];
  X_idx_83 = t87->mX.mX[83];
  X_idx_84 = t87->mX.mX[84];
  X_idx_85 = t87->mX.mX[85];
  X_idx_86 = t87->mX.mX[86];
  X_idx_87 = t87->mX.mX[87];
  X_idx_88 = t87->mX.mX[88];
  X_idx_89 = t87->mX.mX[89];
  X_idx_90 = t87->mX.mX[90];
  X_idx_91 = t87->mX.mX[91];
  X_idx_92 = t87->mX.mX[92];
  X_idx_93 = t87->mX.mX[93];
  X_idx_94 = t87->mX.mX[94];
  X_idx_95 = t87->mX.mX[95];
  X_idx_96 = t87->mX.mX[96];
  X_idx_97 = t87->mX.mX[97];
  X_idx_98 = t87->mX.mX[98];
  X_idx_99 = t87->mX.mX[99];
  X_idx_100 = t87->mX.mX[100];
  X_idx_101 = t87->mX.mX[101];
  X_idx_102 = t87->mX.mX[102];
  X_idx_103 = t87->mX.mX[103];
  X_idx_104 = t87->mX.mX[104];
  X_idx_105 = t87->mX.mX[105];
  X_idx_106 = t87->mX.mX[106];
  X_idx_107 = t87->mX.mX[107];
  X_idx_108 = t87->mX.mX[108];
  X_idx_109 = t87->mX.mX[109];
  X_idx_110 = t87->mX.mX[110];
  X_idx_111 = t87->mX.mX[111];
  X_idx_112 = t87->mX.mX[112];
  X_idx_113 = t87->mX.mX[113];
  X_idx_114 = t87->mX.mX[114];
  X_idx_115 = t87->mX.mX[115];
  X_idx_116 = t87->mX.mX[116];
  X_idx_117 = t87->mX.mX[117];
  X_idx_118 = t87->mX.mX[118];
  X_idx_119 = t87->mX.mX[119];
  X_idx_120 = t87->mX.mX[120];
  X_idx_121 = t87->mX.mX[121];
  X_idx_122 = t87->mX.mX[122];
  X_idx_123 = t87->mX.mX[123];
  X_idx_124 = t87->mX.mX[124];
  X_idx_125 = t87->mX.mX[125];
  X_idx_126 = t87->mX.mX[126];
  X_idx_127 = t87->mX.mX[127];
  X_idx_128 = t87->mX.mX[128];
  X_idx_129 = t87->mX.mX[129];
  out = t88->mOBS_ALL;
  Battery_Controlled_Voltage_Source_p_v = -X_idx_24 + X_idx_1 + X_idx_25 +
    X_idx_26;
  Battery_Electrical_model_for_Np_parallel_connected_cells_C1_n_v = X_idx_25 +
    X_idx_26;
  Battery_Electrical_model_for_Np_parallel_connected_cells_C1_p_v = X_idx_1 +
    X_idx_25 + X_idx_26;
  Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss = X_idx_30 +
    X_idx_31;
  t42 = X_idx_0 * -0.00050954 + U_idx_0 * 0.00050954;
  Cooling_system_Radiator_PS_Product_I1 = -X_idx_53 + U_idx_0;
  DC_DC_converter_averaged_Battery_sensors_Voltage_Sensor_V = -X_idx_25 / -1.0;
  t44 = X_idx_106 * 0.00026666666666666668 + 400.0;
  DC_DC_converter_averaged_Resistor_n_v = X_idx_106 * 0.0022666666666666668 +
    400.0;
  Differential_pinion_crown_ratio_t_in = X_idx_107 * -0.16666666666666666 +
    X_idx_108 * -0.041666666666666664;
  Energy_based_PMSM_drive_model_Heat_exchanger_PS_Product_I1 = -X_idx_86 +
    X_idx_14;
  t46 = X_idx_109 + X_idx_122;
  Energy_based_PMSM_drive_model_Servomotor_damper1_t = -X_idx_121 + X_idx_123;
  Energy_based_PMSM_drive_model_Servomotor_gain1_I = -X_idx_17 + U_idx_1;
  t48 = X_idx_16 * 0.041666666666666664;
  Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O = X_idx_16 *
    0.041666666666666664 + -U_idx_2;
  Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M = X_idx_16 *
    0.16666666666666666;
  Longitudinal_vehicle_dynamics_Ideal_Force_Source_S = -X_idx_124 + U_idx_4;
  t29[0ULL] = X_idx_56;
  t26[0ULL] = X_idx_54;
  t23[0ULL] = M_idx_0 != 0;
  t23[1ULL] = M_idx_1 != 0;
  t32[0ULL] = M_idx_56 != 0;
  t32[1ULL] = M_idx_67 != 0;
  _in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  _in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  _in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  _in1var[3ULL] = (void *)t29;
  _in1var[4ULL] = (void *)t26;
  _in1var[5ULL] = (void *)t23;
  _in1var[6ULL] = (void *)t32;
  _in1ivar = 11ULL;
  _in1var[7ULL] = (void *)&_in1ivar;
  b__in1ivar = 12ULL;
  _in1var[8ULL] = (void *)&b__in1ivar;
  tlu2_2d_linear_linear_value(&_retvar, &_in1var);
  efOut_idx_0 = _retvar[0];
  t29[0ULL] = X_idx_97;
  t26[0ULL] = X_idx_70;
  t23[0ULL] = M_idx_52 != 0;
  t23[1ULL] = M_idx_53 != 0;
  t32[0ULL] = M_idx_2 != 0;
  t32[1ULL] = M_idx_13 != 0;
  b__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  b__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  b__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  b__in1var[3ULL] = (void *)t29;
  b__in1var[4ULL] = (void *)t26;
  b__in1var[5ULL] = (void *)t23;
  b__in1var[6ULL] = (void *)t32;
  c__in1ivar = 11ULL;
  b__in1var[7ULL] = (void *)&c__in1ivar;
  d__in1ivar = 12ULL;
  b__in1var[8ULL] = (void *)&d__in1ivar;
  tlu2_2d_linear_linear_value(&b__retvar, &b__in1var);
  b_efOut_idx_0 = b__retvar[0];
  t29[0ULL] = X_idx_99;
  t26[0ULL] = X_idx_54;
  t23[0ULL] = M_idx_54 != 0;
  t23[1ULL] = M_idx_55 != 0;
  t32[0ULL] = M_idx_56 != 0;
  t32[1ULL] = M_idx_67 != 0;
  c__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  c__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  c__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  c__in1var[3ULL] = (void *)t29;
  c__in1var[4ULL] = (void *)t26;
  c__in1var[5ULL] = (void *)t23;
  c__in1var[6ULL] = (void *)t32;
  e__in1ivar = 11ULL;
  c__in1var[7ULL] = (void *)&e__in1ivar;
  f__in1ivar = 12ULL;
  c__in1var[8ULL] = (void *)&f__in1ivar;
  tlu2_2d_linear_linear_value(&c__retvar, &c__in1var);
  c_efOut_idx_0 = c__retvar[0];
  b_efOut_idx_0 = (X_idx_96 * b_efOut_idx_0 / 0.05 + X_idx_98 * c_efOut_idx_0 /
                   0.05) / 2.0 * 0.31415926535897931;
  t51 = X_idx_22 / (b_efOut_idx_0 == 0.0 ? 1.0E-16 : b_efOut_idx_0) * 1000.0 - (
    -X_idx_10);
  t29[0ULL] = X_idx_111;
  t26[0ULL] = X_idx_33;
  t23[0ULL] = M_idx_57 != 0;
  t23[1ULL] = M_idx_58 != 0;
  t32[0ULL] = M_idx_100 != 0;
  t32[1ULL] = M_idx_111 != 0;
  d__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  d__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  d__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  d__in1var[3ULL] = (void *)t29;
  d__in1var[4ULL] = (void *)t26;
  d__in1var[5ULL] = (void *)t23;
  d__in1var[6ULL] = (void *)t32;
  g__in1ivar = 11ULL;
  d__in1var[7ULL] = (void *)&g__in1ivar;
  h__in1ivar = 12ULL;
  d__in1var[8ULL] = (void *)&h__in1ivar;
  tlu2_2d_linear_linear_value(&d__retvar, &d__in1var);
  b_efOut_idx_0 = d__retvar[0];
  t29[0ULL] = X_idx_113;
  t26[0ULL] = X_idx_87;
  t23[0ULL] = M_idx_59 != 0;
  t23[1ULL] = M_idx_60 != 0;
  t32[0ULL] = M_idx_61 != 0;
  t32[1ULL] = M_idx_62 != 0;
  e__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  e__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  e__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  e__in1var[3ULL] = (void *)t29;
  e__in1var[4ULL] = (void *)t26;
  e__in1var[5ULL] = (void *)t23;
  e__in1var[6ULL] = (void *)t32;
  i__in1ivar = 11ULL;
  e__in1var[7ULL] = (void *)&i__in1ivar;
  j__in1ivar = 12ULL;
  e__in1var[8ULL] = (void *)&j__in1ivar;
  tlu2_2d_linear_linear_value(&e__retvar, &e__in1var);
  c_efOut_idx_0 = e__retvar[0];
  t29[0ULL] = X_idx_58;
  t26[0ULL] = X_idx_33;
  t23[0ULL] = M_idx_78 != 0;
  t23[1ULL] = M_idx_89 != 0;
  t32[0ULL] = M_idx_100 != 0;
  t32[1ULL] = M_idx_111 != 0;
  f__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  f__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  f__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  f__in1var[3ULL] = (void *)t29;
  f__in1var[4ULL] = (void *)t26;
  f__in1var[5ULL] = (void *)t23;
  f__in1var[6ULL] = (void *)t32;
  k__in1ivar = 11ULL;
  f__in1var[7ULL] = (void *)&k__in1ivar;
  l__in1ivar = 12ULL;
  f__in1var[8ULL] = (void *)&l__in1ivar;
  tlu2_2d_linear_linear_value(&f__retvar, &f__in1var);
  f_efOut_idx_0 = f__retvar[0];
  b_efOut_idx_0 = (X_idx_110 * b_efOut_idx_0 / 0.05 + X_idx_112 * c_efOut_idx_0 /
                   0.05) / 2.0 * 0.062831853071795868;
  zc_int17 = X_idx_109 / (b_efOut_idx_0 == 0.0 ? 1.0E-16 : b_efOut_idx_0) *
    1000.0 - (-X_idx_13);
  b_efOut_idx_0 = (X_idx_55 * efOut_idx_0 / 0.05 + X_idx_57 * f_efOut_idx_0 /
                   0.05) / 2.0 * 0.078539816339744828;
  f_efOut_idx_0 = 0.0 / (b_efOut_idx_0 == 0.0 ? 1.0E-16 : b_efOut_idx_0) *
    1000.0 - (-X_idx_6);
  t29[0ULL] = X_idx_74;
  t26[0ULL] = X_idx_70;
  t23[0ULL] = M_idx_122 != 0;
  t23[1ULL] = M_idx_133 != 0;
  t32[0ULL] = M_idx_2 != 0;
  t32[1ULL] = M_idx_13 != 0;
  g__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  g__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  g__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  g__in1var[3ULL] = (void *)t29;
  g__in1var[4ULL] = (void *)t26;
  g__in1var[5ULL] = (void *)t23;
  g__in1var[6ULL] = (void *)t32;
  m__in1ivar = 11ULL;
  g__in1var[7ULL] = (void *)&m__in1ivar;
  n__in1ivar = 12ULL;
  g__in1var[8ULL] = (void *)&n__in1ivar;
  tlu2_2d_linear_linear_value(&g__retvar, &g__in1var);
  b_efOut_idx_0 = g__retvar[0];
  t29[0ULL] = X_idx_76;
  t26[0ULL] = X_idx_72;
  t23[0ULL] = M_idx_24 != 0;
  t23[1ULL] = M_idx_35 != 0;
  t32[0ULL] = M_idx_46 != 0;
  t32[1ULL] = M_idx_51 != 0;
  h__in1var[0ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable0;
  h__in1var[1ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable1;
  h__in1var[2ULL] = (void *)((_NeDynamicSystem*)(t0))->mTable2;
  h__in1var[3ULL] = (void *)t29;
  h__in1var[4ULL] = (void *)t26;
  h__in1var[5ULL] = (void *)t23;
  h__in1var[6ULL] = (void *)t32;
  o__in1ivar = 11ULL;
  h__in1var[7ULL] = (void *)&o__in1ivar;
  p__in1ivar = 12ULL;
  h__in1var[8ULL] = (void *)&p__in1ivar;
  tlu2_2d_linear_linear_value(&h__retvar, &h__in1var);
  c_efOut_idx_0 = h__retvar[0];
  b_efOut_idx_0 = (X_idx_73 * b_efOut_idx_0 / 0.05 + X_idx_75 * c_efOut_idx_0 /
                   0.05) / 2.0 * 0.078539816339744828;
  b_efOut_idx_0 = 0.0 / (b_efOut_idx_0 == 0.0 ? 1.0E-16 : b_efOut_idx_0) *
    1000.0 - (-X_idx_8);
  out.mX[0] = 0.0;
  out.mX[1] = U_idx_0;
  out.mX[2] = (X_idx_0 * 0.00050954 + -X_idx_22 + U_idx_0 * -0.00050954) *
    1000.0;
  out.mX[3] = U_idx_0;
  out.mX[4] = U_idx_0;
  out.mX[5] = -X_idx_23;
  out.mX[6] = 0.0;
  out.mX[7] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[8] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[9] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[10] = X_idx_27;
  out.mX[11] = X_idx_0;
  out.mX[12] = -X_idx_28 + X_idx_23;
  out.mX[13] = Battery_Electrical_model_for_Np_parallel_connected_cells_C1_n_v;
  out.mX[14] = Battery_Electrical_model_for_Np_parallel_connected_cells_C1_p_v;
  out.mX[15] = X_idx_1;
  out.mX[16] = X_idx_29 * 0.00027777777777777778;
  out.mX[17] = X_idx_2 * 0.00027777777777777778;
  out.mX[18] = X_idx_27;
  out.mX[19] = X_idx_0;
  out.mX[20] = -X_idx_23;
  out.mX[21] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[22] = Battery_Electrical_model_for_Np_parallel_connected_cells_C1_p_v;
  out.mX[23] = X_idx_24;
  out.mX[24] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss;
  out.mX[25] = X_idx_30;
  out.mX[26] = X_idx_31;
  out.mX[27] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss;
  out.mX[28] = X_idx_27;
  out.mX[29] = X_idx_0;
  out.mX[30] = X_idx_23;
  out.mX[31] = X_idx_25;
  out.mX[32] = Battery_Electrical_model_for_Np_parallel_connected_cells_C1_n_v;
  out.mX[33] = X_idx_30;
  out.mX[34] = X_idx_26;
  out.mX[35] = X_idx_27;
  out.mX[36] = X_idx_0;
  out.mX[37] = X_idx_28;
  out.mX[38] = Battery_Electrical_model_for_Np_parallel_connected_cells_C1_n_v;
  out.mX[39] = Battery_Electrical_model_for_Np_parallel_connected_cells_C1_p_v;
  out.mX[40] = X_idx_31;
  out.mX[41] = X_idx_1;
  out.mX[42] = X_idx_0;
  out.mX[43] = X_idx_25;
  out.mX[44] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[45] = X_idx_0;
  out.mX[46] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss;
  out.mX[47] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss *
    50.0;
  out.mX[48] = Battery_Controlled_Voltage_Source_p_v * 0.020408163265306121;
  out.mX[49] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[50] = X_idx_0;
  out.mX[51] = (X_idx_0 * -0.00050954 + X_idx_30 * 0.05 + X_idx_31 * 0.05 +
                U_idx_0 * 0.00050954) * 1000.0;
  out.mX[52] = X_idx_0;
  out.mX[53] = X_idx_0;
  out.mX[54] = 0.0;
  out.mX[55] = X_idx_0;
  out.mX[56] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss *
    50.0;
  out.mX[57] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss *
    50.0;
  out.mX[58] = -(-X_idx_0) / -1.0;
  out.mX[59] = X_idx_0;
  out.mX[60] = 0.0;
  out.mX[61] = 0.0;
  out.mX[62] = X_idx_0;
  out.mX[63] = X_idx_0;
  out.mX[64] = Battery_Electrical_model_for_Np_parallel_connected_cells_Ploss *
    50.0;
  out.mX[65] = X_idx_0;
  out.mX[66] = 0.0;
  out.mX[67] = 0.0;
  out.mX[68] = Battery_Controlled_Voltage_Source_p_v * 0.020408163265306121;
  out.mX[69] = 0.0;
  out.mX[70] = Battery_Controlled_Voltage_Source_p_v;
  out.mX[71] = X_idx_25;
  out.mX[72] = Battery_Controlled_Voltage_Source_p_v * 0.020408163265306121;
  out.mX[73] = X_idx_25;
  out.mX[74] = 0.0;
  out.mX[75] = U_idx_0;
  out.mX[76] = X_idx_0;
  out.mX[77] = t42 * 1000.0;
  out.mX[78] = t42 * 1962.5544608862897;
  out.mX[79] = U_idx_0;
  out.mX[80] = X_idx_32;
  out.mX[81] = X_idx_33 * 0.1;
  out.mX[82] = X_idx_3;
  out.mX[83] = 0.0;
  out.mX[84] = X_idx_34;
  out.mX[85] = X_idx_35;
  out.mX[86] = X_idx_34;
  out.mX[87] = X_idx_32;
  out.mX[88] = X_idx_33 * 0.1;
  out.mX[89] = X_idx_36;
  out.mX[90] = X_idx_37 * 0.1;
  out.mX[91] = X_idx_38;
  out.mX[92] = -X_idx_38;
  out.mX[93] = X_idx_39;
  out.mX[94] = X_idx_40;
  out.mX[95] = X_idx_41;
  out.mX[96] = -X_idx_41;
  out.mX[97] = X_idx_42;
  out.mX[98] = X_idx_43;
  out.mX[99] = X_idx_44;
  out.mX[100] = X_idx_45;
  out.mX[101] = X_idx_46;
  out.mX[102] = 0.0;
  out.mX[103] = 0.0;
  out.mX[104] = X_idx_47;
  out.mX[105] = X_idx_47;
  out.mX[106] = X_idx_36;
  out.mX[107] = X_idx_37 * 0.1;
  out.mX[108] = 0.0;
  out.mX[109] = X_idx_47;
  out.mX[110] = X_idx_34;
  out.mX[111] = 0.0;
  out.mX[112] = X_idx_47;
  out.mX[113] = 0.0;
  out.mX[114] = X_idx_34;
  out.mX[115] = X_idx_4 * 0.001;
  out.mX[116] = X_idx_5;
  out.mX[117] = X_idx_3 * -1000.0;
  out.mX[118] = X_idx_34;
  out.mX[119] = X_idx_49;
  out.mX[120] = X_idx_5 * 0.0078539816339744835 + 0.001;
  out.mX[121] = X_idx_36;
  out.mX[122] = X_idx_37 * 0.1;
  out.mX[123] = X_idx_38;
  out.mX[124] = X_idx_47;
  out.mX[125] = X_idx_48;
  out.mX[126] = X_idx_41;
  out.mX[127] = X_idx_37 * 0.1;
  out.mX[128] = X_idx_50;
  out.mX[129] = X_idx_51;
  out.mX[130] = X_idx_52;
  out.mX[131] = X_idx_53;
  out.mX[132] = X_idx_54 * 0.1;
  out.mX[133] = X_idx_32;
  out.mX[134] = X_idx_33 * 0.1;
  out.mX[135] = f_efOut_idx_0;
  out.mX[136] = X_idx_63;
  out.mX[137] = f_efOut_idx_0;
  out.mX[138] = X_idx_55;
  out.mX[139] = X_idx_57;
  out.mX[140] = 0.0;
  out.mX[141] = (-X_idx_7 + X_idx_54) * 0.1;
  out.mX[142] = (-X_idx_7 + X_idx_33) * 0.1;
  out.mX[143] = X_idx_53;
  out.mX[144] = X_idx_54 * 0.1;
  out.mX[145] = X_idx_32;
  out.mX[146] = X_idx_33 * 0.1;
  out.mX[147] = X_idx_59;
  out.mX[148] = -X_idx_38 + X_idx_60;
  out.mX[149] = X_idx_6;
  out.mX[150] = X_idx_56;
  out.mX[151] = X_idx_58;
  out.mX[152] = X_idx_61;
  out.mX[153] = -X_idx_41 + X_idx_62;
  out.mX[154] = X_idx_7 * 0.1;
  out.mX[155] = X_idx_64;
  out.mX[156] = X_idx_65;
  out.mX[157] = X_idx_66;
  out.mX[158] = X_idx_67;
  out.mX[159] = X_idx_68;
  out.mX[160] = X_idx_69;
  out.mX[161] = X_idx_70 * 0.1;
  out.mX[162] = X_idx_71;
  out.mX[163] = X_idx_72 * 0.1;
  out.mX[164] = b_efOut_idx_0;
  out.mX[165] = X_idx_80;
  out.mX[166] = b_efOut_idx_0;
  out.mX[167] = X_idx_73;
  out.mX[168] = X_idx_75;
  out.mX[169] = 0.0;
  out.mX[170] = (-X_idx_9 + X_idx_70) * 0.1;
  out.mX[171] = (-X_idx_9 + X_idx_72) * 0.1;
  out.mX[172] = X_idx_69;
  out.mX[173] = X_idx_70 * 0.1;
  out.mX[174] = X_idx_71;
  out.mX[175] = X_idx_72 * 0.1;
  out.mX[176] = X_idx_77;
  out.mX[177] = X_idx_78;
  out.mX[178] = X_idx_8;
  out.mX[179] = X_idx_74;
  out.mX[180] = X_idx_76;
  out.mX[181] = X_idx_79;
  out.mX[182] = -0.2;
  out.mX[183] = X_idx_9 * 0.1;
  out.mX[184] = X_idx_81;
  out.mX[185] = X_idx_82;
  out.mX[186] = X_idx_83;
  out.mX[187] = X_idx_84;
  out.mX[188] = X_idx_85;
  out.mX[189] = X_idx_32;
  out.mX[190] = X_idx_33 * 0.1;
  out.mX[191] = f_efOut_idx_0;
  out.mX[192] = f_efOut_idx_0;
  out.mX[193] = b_efOut_idx_0;
  out.mX[194] = b_efOut_idx_0;
  out.mX[195] = X_idx_86;
  out.mX[196] = X_idx_87 * 0.1;
  out.mX[197] = -X_idx_88 + X_idx_78;
  out.mX[198] = X_idx_71;
  out.mX[199] = X_idx_72 * 0.1;
  out.mX[200] = X_idx_86;
  out.mX[201] = X_idx_87 * 0.1;
  out.mX[202] = -X_idx_78;
  out.mX[203] = X_idx_88;
  out.mX[204] = X_idx_89;
  out.mX[205] = X_idx_90;
  out.mX[206] = 0.2;
  out.mX[207] = -0.2;
  out.mX[208] = X_idx_91;
  out.mX[209] = X_idx_92;
  out.mX[210] = X_idx_93;
  out.mX[211] = X_idx_94;
  out.mX[212] = X_idx_95;
  out.mX[213] = X_idx_53;
  out.mX[214] = X_idx_54 * 0.1;
  out.mX[215] = 0.0;
  out.mX[216] = 0.0;
  out.mX[217] = X_idx_69;
  out.mX[218] = X_idx_70 * 0.1;
  out.mX[219] = U_idx_0;
  out.mX[220] = U_idx_0;
  out.mX[221] = t51;
  out.mX[222] = X_idx_22 * 1000.0;
  out.mX[223] = X_idx_22 * 1000.0;
  out.mX[224] = -(U_idx_0 - t51) / -1.0;
  out.mX[225] = X_idx_69;
  out.mX[226] = X_idx_70 * 0.1;
  out.mX[227] = X_idx_53;
  out.mX[228] = X_idx_54 * 0.1;
  out.mX[229] = t51;
  out.mX[230] = X_idx_100;
  out.mX[231] = t51;
  out.mX[232] = X_idx_96;
  out.mX[233] = X_idx_98;
  out.mX[234] = X_idx_22;
  out.mX[235] = (-X_idx_11 + X_idx_70) * 0.1;
  out.mX[236] = (-X_idx_11 + X_idx_54) * 0.1;
  out.mX[237] = X_idx_69;
  out.mX[238] = X_idx_70 * 0.1;
  out.mX[239] = X_idx_53;
  out.mX[240] = X_idx_54 * 0.1;
  out.mX[241] = -X_idx_77;
  out.mX[242] = -X_idx_59;
  out.mX[243] = X_idx_10;
  out.mX[244] = X_idx_97;
  out.mX[245] = X_idx_99;
  out.mX[246] = -X_idx_79;
  out.mX[247] = -X_idx_61;
  out.mX[248] = X_idx_11 * 0.1;
  out.mX[249] = X_idx_101;
  out.mX[250] = X_idx_102;
  out.mX[251] = X_idx_103;
  out.mX[252] = X_idx_104;
  out.mX[253] = X_idx_105;
  out.mX[254] = U_idx_0;
  out.mX[255] = 0.0;
  out.mX[256] = 0.0;
  out.mX[257] = U_idx_0;
  out.mX[258] = U_idx_0;
  out.mX[259] = X_idx_69;
  out.mX[260] = X_idx_70 * 0.1;
  out.mX[261] = X_idx_69;
  out.mX[262] = X_idx_70 * 0.1;
  out.mX[263] = X_idx_79;
  out.mX[264] = X_idx_77 * 1000.0;
  out.mX[265] = X_idx_77;
  out.mX[266] = X_idx_79;
  out.mX[267] = Cooling_system_Radiator_PS_Product_I1;
  out.mX[268] = X_idx_79 * 100.0;
  out.mX[269] = X_idx_22 * 1000.0;
  out.mX[270] = U_idx_0;
  out.mX[271] = X_idx_53;
  out.mX[272] = Cooling_system_Radiator_PS_Product_I1;
  out.mX[273] = X_idx_53;
  out.mX[274] = X_idx_54 * 0.1;
  out.mX[275] = 0.0;
  out.mX[276] = 0.0;
  out.mX[277] = -X_idx_54 / -1.0 * 99999.999999999985;
  out.mX[278] = X_idx_53;
  out.mX[279] = X_idx_79;
  out.mX[280] = X_idx_79 * 100.0;
  out.mX[281] = 0.0;
  out.mX[282] = X_idx_71;
  out.mX[283] = X_idx_72 * 0.1;
  out.mX[284] = X_idx_23;
  out.mX[285] = X_idx_23;
  out.mX[286] = X_idx_25;
  out.mX[287] = X_idx_25;
  out.mX[288] = 0.0;
  out.mX[289] = DC_DC_converter_averaged_Battery_sensors_Voltage_Sensor_V;
  out.mX[290] = 0.0;
  out.mX[291] = 0.0;
  out.mX[292] = X_idx_25;
  out.mX[293] = DC_DC_converter_averaged_Battery_sensors_Voltage_Sensor_V;
  out.mX[294] = 0.0;
  out.mX[295] = X_idx_25;
  out.mX[296] = X_idx_25;
  out.mX[297] = 0.0;
  out.mX[298] = X_idx_23;
  out.mX[299] = X_idx_106;
  out.mX[300] = 0.0;
  out.mX[301] = 0.0;
  out.mX[302] = X_idx_25;
  out.mX[303] = t44;
  out.mX[304] = X_idx_12;
  out.mX[305] = X_idx_25;
  out.mX[306] = t44;
  out.mX[307] = 0.0;
  out.mX[308] = -X_idx_106;
  out.mX[309] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[310] = t44;
  out.mX[311] = X_idx_106 * -0.002;
  out.mX[312] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[313] = X_idx_25;
  out.mX[314] = 0.0;
  out.mX[315] = X_idx_16 * 0.16666666666666666;
  out.mX[316] = X_idx_16;
  out.mX[317] = Differential_pinion_crown_ratio_t_in;
  out.mX[318] = Differential_pinion_crown_ratio_t_in * -6.0;
  out.mX[319] = 0.0;
  out.mX[320] = 0.0;
  out.mX[321] = 0.0;
  out.mX[322] = X_idx_14;
  out.mX[323] = X_idx_14;
  out.mX[324] = zc_int17;
  out.mX[325] = X_idx_109 * 1000.0;
  out.mX[326] = X_idx_109 * 1000.0;
  out.mX[327] = -(X_idx_14 - zc_int17) / -1.0;
  out.mX[328] = X_idx_86;
  out.mX[329] = X_idx_87 * 0.1;
  out.mX[330] = X_idx_14;
  out.mX[331] = 0.0;
  out.mX[332] = 0.0;
  out.mX[333] = X_idx_14;
  out.mX[334] = X_idx_14;
  out.mX[335] = X_idx_32;
  out.mX[336] = X_idx_33 * 0.1;
  out.mX[337] = X_idx_32;
  out.mX[338] = X_idx_33 * 0.1;
  out.mX[339] = X_idx_62;
  out.mX[340] = X_idx_60 * 1000.0;
  out.mX[341] = X_idx_60;
  out.mX[342] = X_idx_62;
  out.mX[343] = X_idx_32;
  out.mX[344] = X_idx_33 * 0.1;
  out.mX[345] = Energy_based_PMSM_drive_model_Heat_exchanger_PS_Product_I1;
  out.mX[346] = X_idx_114;
  out.mX[347] = X_idx_109 * 1000.0;
  out.mX[348] = X_idx_14;
  out.mX[349] = X_idx_86;
  out.mX[350] = Energy_based_PMSM_drive_model_Heat_exchanger_PS_Product_I1;
  out.mX[351] = X_idx_32;
  out.mX[352] = X_idx_33 * 0.1;
  out.mX[353] = X_idx_86;
  out.mX[354] = X_idx_87 * 0.1;
  out.mX[355] = zc_int17;
  out.mX[356] = X_idx_115;
  out.mX[357] = zc_int17;
  out.mX[358] = X_idx_110;
  out.mX[359] = X_idx_112;
  out.mX[360] = X_idx_109;
  out.mX[361] = (-X_idx_15 + X_idx_33) * 0.1;
  out.mX[362] = (-X_idx_15 + X_idx_87) * 0.1;
  out.mX[363] = X_idx_32;
  out.mX[364] = X_idx_33 * 0.1;
  out.mX[365] = X_idx_86;
  out.mX[366] = X_idx_87 * 0.1;
  out.mX[367] = -X_idx_60;
  out.mX[368] = -X_idx_88;
  out.mX[369] = X_idx_13;
  out.mX[370] = X_idx_111;
  out.mX[371] = X_idx_113;
  out.mX[372] = -X_idx_62;
  out.mX[373] = 0.2;
  out.mX[374] = X_idx_15 * 0.1;
  out.mX[375] = X_idx_116;
  out.mX[376] = X_idx_117;
  out.mX[377] = X_idx_118;
  out.mX[378] = X_idx_119;
  out.mX[379] = X_idx_120;
  out.mX[380] = X_idx_86;
  out.mX[381] = X_idx_87 * 0.1;
  out.mX[382] = 0.0;
  out.mX[383] = 0.0;
  out.mX[384] = -X_idx_87 / -1.0 * 99999.999999999985;
  out.mX[385] = X_idx_86;
  out.mX[386] = X_idx_62 * 100.0;
  out.mX[387] = X_idx_114;
  out.mX[388] = X_idx_62;
  out.mX[389] = X_idx_62 * 100.0;
  out.mX[390] = 0.0;
  out.mX[391] = X_idx_86;
  out.mX[392] = X_idx_87 * 0.1;
  out.mX[393] = 0.0;
  out.mX[394] = X_idx_16;
  out.mX[395] = X_idx_107 * 0.16666666666666666 + X_idx_108 *
    0.041666666666666664 + X_idx_121;
  out.mX[396] = X_idx_16 * 9.5492965855137211;
  out.mX[397] = X_idx_32;
  out.mX[398] = X_idx_33 * 0.1;
  out.mX[399] = X_idx_16;
  out.mX[400] = 0.0;
  out.mX[401] = X_idx_14;
  out.mX[402] = X_idx_16;
  out.mX[403] = X_idx_16;
  out.mX[404] = U_idx_1;
  out.mX[405] = 0.0;
  out.mX[406] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[407] = 0.0;
  out.mX[408] = -X_idx_106;
  out.mX[409] = -X_idx_106;
  out.mX[410] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[411] = -DC_DC_converter_averaged_Resistor_n_v / -1.0;
  out.mX[412] = X_idx_14;
  out.mX[413] = t46 * 1000.0;
  out.mX[414] = -X_idx_106;
  out.mX[415] = 0.0;
  out.mX[416] = X_idx_16;
  out.mX[417] = X_idx_123;
  out.mX[418] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[419] = 0.0;
  out.mX[420] = X_idx_16;
  out.mX[421] = Energy_based_PMSM_drive_model_Servomotor_damper1_t;
  out.mX[422] = Energy_based_PMSM_drive_model_Servomotor_damper1_t *
    99999.999999999985;
  out.mX[423] = Energy_based_PMSM_drive_model_Servomotor_gain1_I;
  out.mX[424] = Energy_based_PMSM_drive_model_Servomotor_gain1_I * 50.0;
  out.mX[425] = 0.0;
  out.mX[426] = X_idx_14;
  out.mX[427] = t46 * 1000.0;
  out.mX[428] = t46 * 1000.0;
  out.mX[429] = -(-X_idx_14) / -1.0;
  out.mX[430] = Energy_based_PMSM_drive_model_Servomotor_gain1_I * 50.0;
  out.mX[431] = X_idx_17;
  out.mX[432] = X_idx_17;
  out.mX[433] = U_idx_1;
  out.mX[434] = X_idx_17;
  out.mX[435] = Energy_based_PMSM_drive_model_Servomotor_gain1_I;
  out.mX[436] = X_idx_14;
  out.mX[437] = 0.0;
  out.mX[438] = 0.0;
  out.mX[439] = X_idx_14;
  out.mX[440] = X_idx_14;
  out.mX[441] = X_idx_14;
  out.mX[442] = X_idx_122 * 1000.0;
  out.mX[443] = X_idx_14;
  out.mX[444] = 0.0;
  out.mX[445] = 0.0;
  out.mX[446] = 0.0;
  out.mX[447] = X_idx_16;
  out.mX[448] = X_idx_123;
  out.mX[449] = X_idx_123;
  out.mX[450] = -(-X_idx_16) / -1.0;
  out.mX[451] = 0.0;
  out.mX[452] = X_idx_16;
  out.mX[453] = X_idx_123;
  out.mX[454] = X_idx_17;
  out.mX[455] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[456] = 0.0;
  out.mX[457] = 0.0;
  out.mX[458] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[459] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[460] = X_idx_18;
  out.mX[461] = 0.0;
  out.mX[462] = X_idx_16;
  out.mX[463] = X_idx_16;
  out.mX[464] = X_idx_18;
  out.mX[465] = 0.0;
  out.mX[466] = X_idx_16;
  out.mX[467] = X_idx_16;
  out.mX[468] = X_idx_16;
  out.mX[469] = X_idx_121;
  out.mX[470] = X_idx_121;
  out.mX[471] = 0.0;
  out.mX[472] = X_idx_16;
  out.mX[473] = X_idx_16;
  out.mX[474] = DC_DC_converter_averaged_Resistor_n_v;
  out.mX[475] = 0.0;
  out.mX[476] = X_idx_124;
  out.mX[477] = X_idx_125;
  out.mX[478] = X_idx_126;
  out.mX[479] = X_idx_124;
  out.mX[480] = t48;
  out.mX[481] = U_idx_2;
  out.mX[482] = Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O;
  out.mX[483] = Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O;
  out.mX[484] = X_idx_126 * 1.3061224489795917;
  out.mX[485] = t48;
  out.mX[486] = X_idx_126 * 1.3061224489795917;
  out.mX[487] = X_idx_126;
  out.mX[488] = Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O *
    2.0;
  out.mX[489] = X_idx_127;
  out.mX[490] = 1.0;
  out.mX[491] = X_idx_127;
  out.mX[492] = X_idx_127 + 1.0;
  out.mX[493] = X_idx_127;
  out.mX[494] = 1.0;
  out.mX[495] = X_idx_127 + -1.0;
  out.mX[496] = X_idx_127 + -1.0;
  out.mX[497] = X_idx_127 + 1.0;
  out.mX[498] = X_idx_125;
  out.mX[499] = Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O;
  out.mX[500] = 1.0;
  out.mX[501] = Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O;
  out.mX[502] = Longitudinal_vehicle_dynamics_Aerodynamic_drag_PS_Subtract_O *
    2.0;
  out.mX[503] = X_idx_125;
  out.mX[504] = X_idx_19;
  out.mX[505] = 0.0;
  out.mX[506] = X_idx_16 * 0.16666666666666666;
  out.mX[507] = Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M;
  out.mX[508] = X_idx_19;
  out.mX[509] = 0.0;
  out.mX[510] = Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M;
  out.mX[511] = 0.0;
  out.mX[512] = X_idx_16 * 0.16666666666666666;
  out.mX[513] = X_idx_107;
  out.mX[514] = X_idx_107;
  out.mX[515] = -(-(X_idx_16 * 0.16666666666666666)) / -1.0;
  out.mX[516] = 0.0;
  out.mX[517] = U_idx_3;
  out.mX[518] = X_idx_128;
  out.mX[519] = X_idx_107;
  out.mX[520] = X_idx_16 * 0.16666666666666666;
  out.mX[521] = Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M *
    2.0;
  out.mX[522] = X_idx_129;
  out.mX[523] = 1.0;
  out.mX[524] = X_idx_129;
  out.mX[525] = X_idx_129 + 1.0;
  out.mX[526] = X_idx_129;
  out.mX[527] = 1.0;
  out.mX[528] = X_idx_129 + -1.0;
  out.mX[529] = X_idx_129 + -1.0;
  out.mX[530] = X_idx_129 + 1.0;
  out.mX[531] = X_idx_128;
  out.mX[532] = Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M;
  out.mX[533] = 1.0;
  out.mX[534] = Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M;
  out.mX[535] = Longitudinal_vehicle_dynamics_Braking_torque_Ideal_Rotational_M *
    2.0;
  out.mX[536] = X_idx_128;
  out.mX[537] = 0.0;
  out.mX[538] = X_idx_16 * 0.041666666666666664;
  out.mX[539] = Longitudinal_vehicle_dynamics_Ideal_Force_Source_S;
  out.mX[540] = Longitudinal_vehicle_dynamics_Ideal_Force_Source_S;
  out.mX[541] = -(-(X_idx_16 * 0.041666666666666664)) / -1.0;
  out.mX[542] = 0.0;
  out.mX[543] = X_idx_20;
  out.mX[544] = X_idx_16 * 0.041666666666666664;
  out.mX[545] = t48;
  out.mX[546] = 0.0;
  out.mX[547] = t48;
  out.mX[548] = X_idx_20;
  out.mX[549] = 0.0;
  out.mX[550] = X_idx_16 * 0.041666666666666664;
  out.mX[551] = t48;
  out.mX[552] = 0.0;
  out.mX[553] = U_idx_4;
  out.mX[554] = X_idx_124;
  out.mX[555] = Longitudinal_vehicle_dynamics_Ideal_Force_Source_S;
  out.mX[556] = X_idx_16 * 0.16666666666666666;
  out.mX[557] = X_idx_16 * 0.041666666666666664;
  out.mX[558] = -X_idx_124 + -X_idx_108 + U_idx_4;
  out.mX[559] = X_idx_21;
  out.mX[560] = X_idx_16 * 0.16666666666666666;
  out.mX[561] = X_idx_16 * 0.041666666666666664;
  out.mX[562] = X_idx_108;
  out.mX[563] = X_idx_108 * -0.25;
  out.mX[564] = 0.0;
  (void)t0;
  (void)t88;
  return 0;
}
