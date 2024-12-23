
#include "fluid.cpp"
#include <vector>
#include <string>
using namespace std;
string s = "";

FluidFactory Generate() {
    FluidFactory ff = FluidFactory();

ff.registerType<36,84,float,float,float>("f_36_84_float_float_float");
ff.registerType<36,84,float,float,Fixed<31,10,1>>("f_36_84_float_float_Fixed_31_10_1");
ff.registerType<36,84,float,float,Fixed<32,16,0>>("f_36_84_float_float_Fixed_32_16_0");
ff.registerType<36,84,float,float,double>("f_36_84_float_float_double");
ff.registerType<36,84,float,Fixed<31,10,1>,float>("f_36_84_float_Fixed_31_10_1_float");
ff.registerType<36,84,float,Fixed<31,10,1>,Fixed<31,10,1>>("f_36_84_float_Fixed_31_10_1_Fixed_31_10_1");
ff.registerType<36,84,float,Fixed<31,10,1>,Fixed<32,16,0>>("f_36_84_float_Fixed_31_10_1_Fixed_32_16_0");
ff.registerType<36,84,float,Fixed<31,10,1>,double>("f_36_84_float_Fixed_31_10_1_double");
ff.registerType<36,84,float,Fixed<32,16,0>,float>("f_36_84_float_Fixed_32_16_0_float");
ff.registerType<36,84,float,Fixed<32,16,0>,Fixed<31,10,1>>("f_36_84_float_Fixed_32_16_0_Fixed_31_10_1");
ff.registerType<36,84,float,Fixed<32,16,0>,Fixed<32,16,0>>("f_36_84_float_Fixed_32_16_0_Fixed_32_16_0");
ff.registerType<36,84,float,Fixed<32,16,0>,double>("f_36_84_float_Fixed_32_16_0_double");
ff.registerType<36,84,float,double,float>("f_36_84_float_double_float");
ff.registerType<36,84,float,double,Fixed<31,10,1>>("f_36_84_float_double_Fixed_31_10_1");
ff.registerType<36,84,float,double,Fixed<32,16,0>>("f_36_84_float_double_Fixed_32_16_0");
ff.registerType<36,84,float,double,double>("f_36_84_float_double_double");
ff.registerType<36,84,Fixed<31,10,1>,float,float>("f_36_84_Fixed_31_10_1_float_float");
ff.registerType<36,84,Fixed<31,10,1>,float,Fixed<31,10,1>>("f_36_84_Fixed_31_10_1_float_Fixed_31_10_1");
ff.registerType<36,84,Fixed<31,10,1>,float,Fixed<32,16,0>>("f_36_84_Fixed_31_10_1_float_Fixed_32_16_0");
ff.registerType<36,84,Fixed<31,10,1>,float,double>("f_36_84_Fixed_31_10_1_float_double");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<31,10,1>,float>("f_36_84_Fixed_31_10_1_Fixed_31_10_1_float");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<31,10,1>,Fixed<31,10,1>>("f_36_84_Fixed_31_10_1_Fixed_31_10_1_Fixed_31_10_1");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<31,10,1>,Fixed<32,16,0>>("f_36_84_Fixed_31_10_1_Fixed_31_10_1_Fixed_32_16_0");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<31,10,1>,double>("f_36_84_Fixed_31_10_1_Fixed_31_10_1_double");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<32,16,0>,float>("f_36_84_Fixed_31_10_1_Fixed_32_16_0_float");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<32,16,0>,Fixed<31,10,1>>("f_36_84_Fixed_31_10_1_Fixed_32_16_0_Fixed_31_10_1");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<32,16,0>,Fixed<32,16,0>>("f_36_84_Fixed_31_10_1_Fixed_32_16_0_Fixed_32_16_0");
ff.registerType<36,84,Fixed<31,10,1>,Fixed<32,16,0>,double>("f_36_84_Fixed_31_10_1_Fixed_32_16_0_double");
ff.registerType<36,84,Fixed<31,10,1>,double,float>("f_36_84_Fixed_31_10_1_double_float");
ff.registerType<36,84,Fixed<31,10,1>,double,Fixed<31,10,1>>("f_36_84_Fixed_31_10_1_double_Fixed_31_10_1");
ff.registerType<36,84,Fixed<31,10,1>,double,Fixed<32,16,0>>("f_36_84_Fixed_31_10_1_double_Fixed_32_16_0");
ff.registerType<36,84,Fixed<31,10,1>,double,double>("f_36_84_Fixed_31_10_1_double_double");
ff.registerType<36,84,Fixed<32,16,0>,float,float>("f_36_84_Fixed_32_16_0_float_float");
ff.registerType<36,84,Fixed<32,16,0>,float,Fixed<31,10,1>>("f_36_84_Fixed_32_16_0_float_Fixed_31_10_1");
ff.registerType<36,84,Fixed<32,16,0>,float,Fixed<32,16,0>>("f_36_84_Fixed_32_16_0_float_Fixed_32_16_0");
ff.registerType<36,84,Fixed<32,16,0>,float,double>("f_36_84_Fixed_32_16_0_float_double");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<31,10,1>,float>("f_36_84_Fixed_32_16_0_Fixed_31_10_1_float");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<31,10,1>,Fixed<31,10,1>>("f_36_84_Fixed_32_16_0_Fixed_31_10_1_Fixed_31_10_1");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<31,10,1>,Fixed<32,16,0>>("f_36_84_Fixed_32_16_0_Fixed_31_10_1_Fixed_32_16_0");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<31,10,1>,double>("f_36_84_Fixed_32_16_0_Fixed_31_10_1_double");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<32,16,0>,float>("f_36_84_Fixed_32_16_0_Fixed_32_16_0_float");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<32,16,0>,Fixed<31,10,1>>("f_36_84_Fixed_32_16_0_Fixed_32_16_0_Fixed_31_10_1");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<32,16,0>,Fixed<32,16,0>>("f_36_84_Fixed_32_16_0_Fixed_32_16_0_Fixed_32_16_0");
ff.registerType<36,84,Fixed<32,16,0>,Fixed<32,16,0>,double>("f_36_84_Fixed_32_16_0_Fixed_32_16_0_double");
ff.registerType<36,84,Fixed<32,16,0>,double,float>("f_36_84_Fixed_32_16_0_double_float");
ff.registerType<36,84,Fixed<32,16,0>,double,Fixed<31,10,1>>("f_36_84_Fixed_32_16_0_double_Fixed_31_10_1");
ff.registerType<36,84,Fixed<32,16,0>,double,Fixed<32,16,0>>("f_36_84_Fixed_32_16_0_double_Fixed_32_16_0");
ff.registerType<36,84,Fixed<32,16,0>,double,double>("f_36_84_Fixed_32_16_0_double_double");
ff.registerType<36,84,double,float,float>("f_36_84_double_float_float");
ff.registerType<36,84,double,float,Fixed<31,10,1>>("f_36_84_double_float_Fixed_31_10_1");
ff.registerType<36,84,double,float,Fixed<32,16,0>>("f_36_84_double_float_Fixed_32_16_0");
ff.registerType<36,84,double,float,double>("f_36_84_double_float_double");
ff.registerType<36,84,double,Fixed<31,10,1>,float>("f_36_84_double_Fixed_31_10_1_float");
ff.registerType<36,84,double,Fixed<31,10,1>,Fixed<31,10,1>>("f_36_84_double_Fixed_31_10_1_Fixed_31_10_1");
ff.registerType<36,84,double,Fixed<31,10,1>,Fixed<32,16,0>>("f_36_84_double_Fixed_31_10_1_Fixed_32_16_0");
ff.registerType<36,84,double,Fixed<31,10,1>,double>("f_36_84_double_Fixed_31_10_1_double");
ff.registerType<36,84,double,Fixed<32,16,0>,float>("f_36_84_double_Fixed_32_16_0_float");
ff.registerType<36,84,double,Fixed<32,16,0>,Fixed<31,10,1>>("f_36_84_double_Fixed_32_16_0_Fixed_31_10_1");
ff.registerType<36,84,double,Fixed<32,16,0>,Fixed<32,16,0>>("f_36_84_double_Fixed_32_16_0_Fixed_32_16_0");
ff.registerType<36,84,double,Fixed<32,16,0>,double>("f_36_84_double_Fixed_32_16_0_double");
ff.registerType<36,84,double,double,float>("f_36_84_double_double_float");
ff.registerType<36,84,double,double,Fixed<31,10,1>>("f_36_84_double_double_Fixed_31_10_1");
ff.registerType<36,84,double,double,Fixed<32,16,0>>("f_36_84_double_double_Fixed_32_16_0");
ff.registerType<36,84,double,double,double>("f_36_84_double_double_double");

return ff;
}
