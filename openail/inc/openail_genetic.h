/************************************************************************************
**  
*    @copyright (c) 2013-2100, ChengDu Duyer Technology Co., LTD. All Right Reserved.
*
*************************************************************************************/
/**
* @file	    openail_genetic.h
* @version     
* @brief      
* @author   duye
* @date     2014-05-14
* @note 
*
*  1. 2014-05-14 duye Created this file
* 
*/

#pragma once

#include <map>
#include <openail/inc/openail.h>

OPENAIL_NS_BEG

class Genetic
{
public:
    Genetic();
    ~Genetic();
    void selectionoperator();
    void crossoveroperator();
    void mutationoperator();
    void initialpopulation(int, int ,double ,double,double *,double *);           //��Ⱥ��ʼ��
    void generatenextpopulation();          //������һ����Ⱥ
    void evaluatepopulation();           //���۸��壬����Ѹ���
    void calculateobjectvalue();          //����Ŀ�꺯��ֵ
    void calculatefitnessvalue();          //������Ӧ�Ⱥ���ֵ
    void findbestandworstindividual();         //Ѱ����Ѹ����������
    void performevolution();   
    void GetResult(double *);
    void GetPopData(CList <double,double>&);
    void SetFitnessData(CList <double,double>&,CList <double,double>&,CList <double,double>&);

private:
    struct individual
    {
        double chromosome[variablenum];         //Ⱦɫ����볤��Ӧ��Ϊ�����ĸ���
        double value;         
        double fitness;             //��Ӧ��
    };
    
    double variabletop[variablenum];         //����ֵ
    double variablebottom[variablenum];         //����ֵ
    int popsize;              //��Ⱥ��С
    // int generation;              //������
    int best_index;  
    int worst_index;
    double crossoverrate;            //������
    double mutationrate;            //������
    int maxgeneration;             //���������
    struct individual bestindividual;         //��Ѹ���
    struct individual worstindividual;         //������
    struct individual current;              //��ǰ����
    struct individual current1;              //��ǰ����
    struct individual currentbest;          //��ǰ��Ѹ���
    std::map<struct individual, struct individual &> population;   //��Ⱥ
    std::map<struct individual, struct individual &> newpopulation;  //����Ⱥ
    std::map<double, double> cfitness;          //�洢��Ӧ��ֵ
    //����ʹ�����������һ���ṹ��????��Ҫ�������Ⱥ����������ʡ�ռ䡣
};

OPENAIL_NS_END
