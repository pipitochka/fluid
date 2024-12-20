
#include "fluid.cpp"
#include <vector>
#include <string>
using namespace std;
string s = "";

FluidFactory Generate() {
    FluidFactory ff = FluidFactory();

ff.registerType<36,84,float,float,float>("f_36_84_float_float_float");
ff.registerType<36,84,float,float,Fixed<32,5>>("f_36_84_float_float_Fixed_32_5");
ff.registerType<36,84,float,float,double>("f_36_84_float_float_double");
ff.registerType<36,84,float,float,Fixed<32,16>>("f_36_84_float_float_Fixed_32_16");
ff.registerType<36,84,float,Fixed<32,5>,float>("f_36_84_float_Fixed_32_5_float");
ff.registerType<36,84,float,Fixed<32,5>,Fixed<32,5>>("f_36_84_float_Fixed_32_5_Fixed_32_5");
ff.registerType<36,84,float,Fixed<32,5>,double>("f_36_84_float_Fixed_32_5_double");
ff.registerType<36,84,float,Fixed<32,5>,Fixed<32,16>>("f_36_84_float_Fixed_32_5_Fixed_32_16");
ff.registerType<36,84,float,double,float>("f_36_84_float_double_float");
ff.registerType<36,84,float,double,Fixed<32,5>>("f_36_84_float_double_Fixed_32_5");
ff.registerType<36,84,float,double,double>("f_36_84_float_double_double");
ff.registerType<36,84,float,double,Fixed<32,16>>("f_36_84_float_double_Fixed_32_16");
ff.registerType<36,84,float,Fixed<32,16>,float>("f_36_84_float_Fixed_32_16_float");
ff.registerType<36,84,float,Fixed<32,16>,Fixed<32,5>>("f_36_84_float_Fixed_32_16_Fixed_32_5");
ff.registerType<36,84,float,Fixed<32,16>,double>("f_36_84_float_Fixed_32_16_double");
ff.registerType<36,84,float,Fixed<32,16>,Fixed<32,16>>("f_36_84_float_Fixed_32_16_Fixed_32_16");
ff.registerType<36,84,Fixed<32,5>,float,float>("f_36_84_Fixed_32_5_float_float");
ff.registerType<36,84,Fixed<32,5>,float,Fixed<32,5>>("f_36_84_Fixed_32_5_float_Fixed_32_5");
ff.registerType<36,84,Fixed<32,5>,float,double>("f_36_84_Fixed_32_5_float_double");
ff.registerType<36,84,Fixed<32,5>,float,Fixed<32,16>>("f_36_84_Fixed_32_5_float_Fixed_32_16");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,5>,float>("f_36_84_Fixed_32_5_Fixed_32_5_float");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,5>,Fixed<32,5>>("f_36_84_Fixed_32_5_Fixed_32_5_Fixed_32_5");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,5>,double>("f_36_84_Fixed_32_5_Fixed_32_5_double");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,5>,Fixed<32,16>>("f_36_84_Fixed_32_5_Fixed_32_5_Fixed_32_16");
ff.registerType<36,84,Fixed<32,5>,double,float>("f_36_84_Fixed_32_5_double_float");
ff.registerType<36,84,Fixed<32,5>,double,Fixed<32,5>>("f_36_84_Fixed_32_5_double_Fixed_32_5");
ff.registerType<36,84,Fixed<32,5>,double,double>("f_36_84_Fixed_32_5_double_double");
ff.registerType<36,84,Fixed<32,5>,double,Fixed<32,16>>("f_36_84_Fixed_32_5_double_Fixed_32_16");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,16>,float>("f_36_84_Fixed_32_5_Fixed_32_16_float");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,16>,Fixed<32,5>>("f_36_84_Fixed_32_5_Fixed_32_16_Fixed_32_5");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,16>,double>("f_36_84_Fixed_32_5_Fixed_32_16_double");
ff.registerType<36,84,Fixed<32,5>,Fixed<32,16>,Fixed<32,16>>("f_36_84_Fixed_32_5_Fixed_32_16_Fixed_32_16");
ff.registerType<36,84,double,float,float>("f_36_84_double_float_float");
ff.registerType<36,84,double,float,Fixed<32,5>>("f_36_84_double_float_Fixed_32_5");
ff.registerType<36,84,double,float,double>("f_36_84_double_float_double");
ff.registerType<36,84,double,float,Fixed<32,16>>("f_36_84_double_float_Fixed_32_16");
ff.registerType<36,84,double,Fixed<32,5>,float>("f_36_84_double_Fixed_32_5_float");
ff.registerType<36,84,double,Fixed<32,5>,Fixed<32,5>>("f_36_84_double_Fixed_32_5_Fixed_32_5");
ff.registerType<36,84,double,Fixed<32,5>,double>("f_36_84_double_Fixed_32_5_double");
ff.registerType<36,84,double,Fixed<32,5>,Fixed<32,16>>("f_36_84_double_Fixed_32_5_Fixed_32_16");
ff.registerType<36,84,double,double,float>("f_36_84_double_double_float");
ff.registerType<36,84,double,double,Fixed<32,5>>("f_36_84_double_double_Fixed_32_5");
ff.registerType<36,84,double,double,double>("f_36_84_double_double_double");
ff.registerType<36,84,double,double,Fixed<32,16>>("f_36_84_double_double_Fixed_32_16");
ff.registerType<36,84,double,Fixed<32,16>,float>("f_36_84_double_Fixed_32_16_float");
ff.registerType<36,84,double,Fixed<32,16>,Fixed<32,5>>("f_36_84_double_Fixed_32_16_Fixed_32_5");
ff.registerType<36,84,double,Fixed<32,16>,double>("f_36_84_double_Fixed_32_16_double");
ff.registerType<36,84,double,Fixed<32,16>,Fixed<32,16>>("f_36_84_double_Fixed_32_16_Fixed_32_16");
ff.registerType<36,84,Fixed<32,16>,float,float>("f_36_84_Fixed_32_16_float_float");
ff.registerType<36,84,Fixed<32,16>,float,Fixed<32,5>>("f_36_84_Fixed_32_16_float_Fixed_32_5");
ff.registerType<36,84,Fixed<32,16>,float,double>("f_36_84_Fixed_32_16_float_double");
ff.registerType<36,84,Fixed<32,16>,float,Fixed<32,16>>("f_36_84_Fixed_32_16_float_Fixed_32_16");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,5>,float>("f_36_84_Fixed_32_16_Fixed_32_5_float");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,5>,Fixed<32,5>>("f_36_84_Fixed_32_16_Fixed_32_5_Fixed_32_5");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,5>,double>("f_36_84_Fixed_32_16_Fixed_32_5_double");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,5>,Fixed<32,16>>("f_36_84_Fixed_32_16_Fixed_32_5_Fixed_32_16");
ff.registerType<36,84,Fixed<32,16>,double,float>("f_36_84_Fixed_32_16_double_float");
ff.registerType<36,84,Fixed<32,16>,double,Fixed<32,5>>("f_36_84_Fixed_32_16_double_Fixed_32_5");
ff.registerType<36,84,Fixed<32,16>,double,double>("f_36_84_Fixed_32_16_double_double");
ff.registerType<36,84,Fixed<32,16>,double,Fixed<32,16>>("f_36_84_Fixed_32_16_double_Fixed_32_16");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,16>,float>("f_36_84_Fixed_32_16_Fixed_32_16_float");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,16>,Fixed<32,5>>("f_36_84_Fixed_32_16_Fixed_32_16_Fixed_32_5");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,16>,double>("f_36_84_Fixed_32_16_Fixed_32_16_double");
ff.registerType<36,84,Fixed<32,16>,Fixed<32,16>,Fixed<32,16>>("f_36_84_Fixed_32_16_Fixed_32_16_Fixed_32_16");

return ff;
}
