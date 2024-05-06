#include <iostream>
#include <windows.h>
#include <string>
#include <omp.h>
#include <chrono>
#include "CSVWriter.h"
#include "fibocalc.h"


#include <cstdio>
using namespace std;


//globals--------------------------------


int arrsize;
int nrthreads;
int iterations;
int s = 0;
int t = 0;
std::string csvfilename = "";
std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    // Explicitly disable dynamic teams
//omp_set_num_threads(nrthreads);


//globals--------------------------------


void createarr (int threads, int array) {


#pragma omp parallel for
        for (int i = 0; i < array; i++) {


            int a[] = {1};
            a[i] = 1;


        }




}
void createsmarr (int arrays, int threads){

#pragma omp parallel for num_threads(threads)
for (int i = 0; i < arrays; i++) {

    int a[] = {i};
    a[i] = i;



    }
}
/*
static long fibonaccalc (long n) {

        long i, j;
        if (n<2)
            return n;
        else {
#pragma omp parallel sections num_threads(2)
            {
#pragma omp section{
                i = fibonaccalc(n - 1); }
#pragma omp section
{
            j = fibonaccalc(n - 2)
        }
            }

                return i + j;

        }
}



*/

std::string GetExeFileName() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    return std::string(buffer);
}
std::string GetExePath() {
    std::string f = GetExeFileName();
    return f.substr(0, f.find_last_of("\\/"));
}

void csvwrite(std::string namesrcfile, std::string filename, std::string funcname, int iterations, int threads, int arraysz,double elapsedtime, bool append) {
    CSVWriter csv;

        namesrcfile = namesrcfile.substr(0, namesrcfile.size() - 3);
        csv.newRow() << funcname << iterations << threads << elapsedtime << arraysz;
        string arrstr = to_string(arraysz);
        csv.writeToFile(GetExePath() + namesrcfile + "testfilenr" + filename, true);

}

    int main() {
        int option;

option = 3;
iterations = 1;
arrsize = 8;
nrthreads = 4;
long long n = 6;



        switch (option) {
            case 1: {
                csvfilename = "createar.csv";


                for (int x = 0; x < iterations; x++) {
                     t1 = std::chrono::high_resolution_clock::now();
                    createarr(nrthreads,arrsize);
                     t2 = std::chrono::high_resolution_clock::now();
                    double diffs = ((double)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count())/1000.0;

                    csvwrite("createarr", csvfilename, "TestOMP", x + 1, nrthreads,arrsize, diffs,true);
                }

            }
                break;
            case 2: {
                csvfilename = "smallarray.csv";


                for (int x = 0; x < iterations; x++) {
                     t1 = std::chrono::high_resolution_clock::now();
                    createsmarr(arrsize,nrthreads );
                     t2 = std::chrono::high_resolution_clock::now();
                    double diffs2 = ((double)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count())/1000.0;
                    csvwrite("smallarr", csvfilename, "createsmarr", x + 1, nrthreads,arrsize, diffs2,true);
                }

            }
            break;
            case 3: {
                csvfilename = "fibonaci.csv";


                for (int x = 0; x < iterations; x++) {
                    auto t1 = std::chrono::high_resolution_clock::now();
                    printfib(n, nrthreads);
                    auto t2 = std::chrono::high_resolution_clock::now();
                    double diffs3 =
                            (double)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000;
                    csvwrite("fibonaci", csvfilename, "Fibonaci", x + 1, nrthreads,arrsize, diffs3,true);
                }

            }

                return 0;
        }
    }

