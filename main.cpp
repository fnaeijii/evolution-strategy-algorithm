#include "systemc.h"
#include "Chromosome.h"
#include "stim.h"
#include "monitor.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"



int sc_main(int argc, char* argv[]) {
    sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated",
        sc_core::SC_DO_NOTHING);


    sc_signal<int>inputweight[9];
    sc_signal<int>inputPrice[9];
    sc_signal<int> result[9];
    sc_signal<bool> end;

   stim stim("stim");
    stim.inputweight[0](inputweight[0]);
    stim.inputweight[1](inputweight[1]);
    stim.inputweight[2](inputweight[2]);
    stim.inputweight[3](inputweight[3]);
    stim.inputweight[4](inputweight[4]);
    stim.inputweight[5](inputweight[5]);
    stim.inputweight[6](inputweight[6]);
    stim.inputweight[7](inputweight[7]);
    stim.inputweight[8](inputweight[8]);

    stim.inputPrice[0](inputPrice[0]);
    stim.inputPrice[1](inputPrice[1]);
    stim.inputPrice[2](inputPrice[2]);
    stim.inputPrice[3](inputPrice[3]);
    stim.inputPrice[4](inputPrice[4]);
    stim.inputPrice[5](inputPrice[5]);
    stim.inputPrice[6](inputPrice[6]);
    stim.inputPrice[7](inputPrice[7]);
    stim.inputPrice[8](inputPrice[8]);
    stim.end(end);

    Chromosome chrom("chromosome");
    chrom.inputweight[0](inputweight[0]);
    chrom.inputweight[1](inputweight[1]);
    chrom.inputweight[2](inputweight[2]);
    chrom.inputweight[3](inputweight[3]);
    chrom.inputweight[4](inputweight[4]);
    chrom.inputweight[5](inputweight[5]);
    chrom.inputweight[6](inputweight[6]);
    chrom.inputweight[7](inputweight[7]);
    chrom.inputweight[8](inputweight[8]);

    chrom.inputPrice[0](inputPrice[0]);
    chrom.inputPrice[1](inputPrice[1]);
    chrom.inputPrice[2](inputPrice[2]);
    chrom.inputPrice[3](inputPrice[3]);
    chrom.inputPrice[4](inputPrice[4]);
    chrom.inputPrice[5](inputPrice[5]);
    chrom.inputPrice[6](inputPrice[6]);
    chrom.inputPrice[7](inputPrice[7]);
    chrom.inputPrice[8](inputPrice[8]);

    chrom.outputpercent[0](result[0]);
    chrom.outputpercent[1](result[1]);
    chrom.outputpercent[2](result[2]);
    chrom.outputpercent[3](result[3]);
    chrom.outputpercent[4](result[4]);
    chrom.outputpercent[5](result[5]);
    chrom.outputpercent[6](result[6]);
    chrom.outputpercent[7](result[7]);
    chrom.outputpercent[8](result[8]);
    chrom.EndAlgorithm(end);
   

    monitor monitor("result_monitor");
    monitor.output[0](result[0]);
    monitor.output[1](result[1]);
    monitor.output[2](result[2]);
    monitor.output[3](result[3]);
    monitor.output[4](result[4]);
    monitor.output[5](result[5]);
    monitor.output[6](result[6]);
    monitor.output[7](result[7]);
    monitor.output[8](result[8]);
    monitor.EndAlgorithm(end);
     

    sc_start();
    return 0;
}